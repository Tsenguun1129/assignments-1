#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include "read_ppm.h"
#include "write_ppm.h"

void refract(struct ppm_pixel *pixels, struct ppm_pixel *palette, int a_col , int a1_col, int b_row, int b1_row,  int size, int maxIterations, float xmin, float ymin, float xmax, float ymax){

for(int i= b_row; i<b1_row; i++){
  for(int j=a_col; j<a1_col; j++){

    float xfrac = ((float) (j))/size;
    float yfrac = ((float) (i))/size;
    float x0 = xmin + xfrac * (xmax - xmin);
    float y0 = ymin + yfrac * (ymax - ymin);
    float x = 0.0;
    float y = 0.0;
    int iter = 0;
    //use the same algorithm provided in assignment
    while (iter < maxIterations && x*x + y*y < 2*2){
      float xtmp = x*x - y*y + x0;
      y = 2*x*y + y0;
      x = xtmp;
      iter++;
    }
    if(iter < maxIterations){ 
      pixels[i*size + j] = palette[iter];
    }
    else{
      pixels[i * size + j].red = 0;
      pixels[i * size + j].green = 0;
      pixels[i * size + j].blue = 0;
    }
  }
}
}
int main(int argc, char* argv[]) {
  int size = 2000;
  float xmin = -2.0;
  float xmax = 0.47;
  float ymin = -1.12;
  float ymax = 1.12;
  int maxIterations = 1000;
  int process = 4;
  int opt;
  while ((opt = getopt(argc, argv, ":s:l:r:t:b:p:")) != -1) {
    switch (opt) {
      case 's': size = atoi(optarg); break;
      case 'l': xmin = atof(optarg); break;
      case 'r': xmax = atof(optarg); break;
      case 't': ymax = atof(optarg); break;
      case 'b': ymin = atof(optarg); break;
      case '?': printf("usage: %s -s <size> -l <xmin> -r <xmax> "
        "-b <ymin> -t <ymax> -p <#process>\n", argv[0]); break;
    }
  }
  printf("Generating mandelbrot w/ size %dx%d\n", size, size);
  printf("# processes = %d\n", process);
  printf("x range = [%.4f,%.4f]\n", xmin, xmax);
  printf("y range = [%.4f,%.4f]\n", ymin, ymax);


double timer;
struct timeval a, b; 
gettimeofday(&a, NULL);
int SHMIDL;
char fp[100];


SHMIDL= shmget(IPC_PRIVATE, sizeof(struct ppm_pixel) * maxIterations, 0644 | IPC_CREAT);
if (SHMIDL == -1) {
  perror("Error: cannot initialize shared memory\n");
  exit(1);
}
struct ppm_pixel *palette = shmat(SHMIDL, NULL, 0);
for(int i=0; i<maxIterations; i++){
  palette[i].red = rand() % 255;
  palette[i].green = rand() %255;
  palette[i].blue = rand()% 255;
}
int shmid;
shmid= shmget(IPC_PRIVATE, sizeof(struct ppm_pixel) * size * size, 0644 | IPC_CREAT);
if (shmid == -1) {
  perror("Error: cannot initialize shared memory\n");
  exit(1);
}
struct ppm_pixel *pixels = shmat(shmid, NULL, 0);
if(pixels ==(void*)-1){
  perror("Error: cannot access shared memory\n");
    exit(1);
}

int blockWidth = size / 2;
int blockHeight = size / 2;

for (int row = 0; row < size; row += blockHeight) {
  for (int col = 0; col < size; col += blockWidth) {
    fflush(stdout);
    int pid = fork();

    if (pid == 0) {
      // calculate the coordinates of the sub-image block
      int a_col = col;
      int b_row = row;
      int a1_col = col + blockWidth;
      int b1_row = row + blockHeight;

      printf("%d)Sub-image block: cols (%d, %d) to rows (%d, %d)\n", getpid(), a_col, a1_col, b_row, b1_row);
      fflush(stdout);

      // generate the mandelbrot set for the sub-image block
      refract(pixels, palette, a_col, a1_col, b_row, b1_row, size, maxIterations, xmin, ymin, xmax, ymax);

      // exit child process
      exit(0);
    } else {
      printf("Launched child process: %d\n", pid);
    }
  }
}
  for (int i = 0; i < 4; i++) {
    int status;
    int pid = wait(&status);
    printf("Child process complete: %d\n", pid);
  }

gettimeofday(&b, NULL);

timer = b.tv_sec - a.tv_sec + (b.tv_usec-a.tv_usec)/1.e6;
int timestamp = time(0);
printf("Computed mandelbrot set (%dx%d) in %f seconds\n", size, size,timer);
  sprintf(fp, "multi-mandelbrot-%d-%d.ppm", size, timestamp);
  printf("Writing file: %s\n", fp);
  write_ppm(fp, pixels, size, size);
  
  // error check  
  if (shmdt(pixels) == -1) {
    perror("Error: cannot detatch from shared memory\n");
    exit(1);
  }
  if (shmctl(shmid, IPC_RMID, 0) == -1) {
    perror("Error: cannot remove shared memory\n");
    exit(1);
  } 

  if (shmdt(palette) == -1) {
    perror("Error: cannot detatch from shared memory\n");
    exit(1);
  }

  if (shmctl(SHMIDL, IPC_RMID, 0) == -1) {
    perror("Error: cannot remove shared memory\n");
    exit(1);
  } 
}  
