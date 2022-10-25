#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "read_ppm.h"
#include "write_ppm.h"

int main(int argc, char **argv)
{
  int w;
  int h;
  char *filename = argv[1];
  struct ppm_pixel *pixels;

  if (argc != 2)
  {
    printf("usage: glitch <file.ppm>\n");
    return 0;
  }
  
  pixels = read_ppm(filename, &w, &h); 
  printf("%d\n", h);
  if (pixels == NULL)
  {
    printf("Error, can't open file\n");
    exit(0);
  }
  printf("Reading %s with width %d and heigth %d\n", filename, w, h);
  
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      struct ppm_pixel p = pixels[i*w +j];
      p.red = p.red << (rand() % 2);
      p.green = p.blue << (rand() % 2);
      p.blue = p.green << (rand() % 2);
      pixels [i*w + j] = p;

    }
  }

  char* new_file = malloc(strlen(filename) + 8);
  
  strcpy(new_file, filename);
  new_file[strlen(new_file)-4] = '\0';
  strcat(new_file, "-glitch.ppm");
  printf("Writing file %s\n", new_file);
  write_ppm(new_file, pixels, w, h);

  free(pixels);
  free(new_file);
  return 0;
}

