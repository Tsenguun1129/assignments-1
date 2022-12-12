#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include "read_ppm.h"
#include "write_ppm.h"

int main(int argc, char* argv[]) {
  int size = 400;
  float xmin = -2.0;
  float xmax = 0.47;
  float ymin = -1.12;
  float ymax = 1.12;
  int maxIterations = 1000;
  int opt;
  while ((opt = getopt(argc, argv, ":s:l:r:t:b:")) != -1) {
    switch (opt) {
      case 's': size = atoi(optarg); break;
      case 'l': xmin = atof(optarg); break;
      case 'r': xmax = atof(optarg); break;
      case 't': ymax = atof(optarg); break;
      case 'b': ymin = atof(optarg); break;
      case '?': printf("usage: %s -s <size> -l <xmin> -r <xmax> -b <ymin> -t <ymax>\n", argv[0]); break;
    }
  }
  printf("Generating mandelbrot with size %dx%d\n", size, size);
  printf("  X range = [%.4f,%.4f]\n", xmin, xmax);
  printf("  Y range = [%.4f,%.4f]\n", ymin, ymax);




//just wanted to use the clock for fun
srand(clock());

//pallete has the same number of max iterations per instruction. Using calloc to set everything as 0
struct ppm_pixel *palette = calloc(maxIterations, sizeof(struct ppm_pixel));
for(int i=0; i<maxIterations; i++){
  palette[i].red = rand()% 255;
  palette[i].green = rand()% 255;
  palette[i].blue = rand()% 255;
}



double time_check;
struct timeval a, b; 
int current = time(0);
gettimeofday(&a, NULL);
char fp[100];

struct ppm_pixel *pixels = calloc(size * size, sizeof(struct ppm_pixel));

//algorithm given for A09
for(int i = 0; i<size; i++){
  for(int j = 0; j<size; j++){
    float xfrac = (float) (j/size);
    float yfrac = (float) (i/size);
    float x0 = xmin + xfrac * (xmax - xmin);
    float y0 = ymin + yfrac * (ymax - ymin);
  
    float x = 0.0;
    float y = 0.0;
    int iter = 0;
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
      pixels[i*size + j].red = 0;
      pixels[i*size + j].green = 0;
      pixels[i*size + j].blue = 0;
    }
  }
}

//class code
gettimeofday(&b, NULL);
time_check = b.tv_sec - a.tv_sec + (b.tv_usec-a.tv_usec)/1.e6;
printf("Computed mandelbrot set (%dx%d) in %f seconds\n", size, size, time_check);

//writing to a file
  sprintf(fp, "mandelbrot-%d-%d.ppm", size, current);
  printf("Writing file: %s\n", fp);
  write_ppm(fp, pixels, size, size);

//free
  free(pixels);
  free(palette);
}
