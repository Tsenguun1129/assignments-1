#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "read_ppm.h"
#include "write_ppm.h"

int main(int argc, char** argv) {
  int width, height;
  char* filename = "feep-raw.ppm";
  struct ppm_pixel* pixels = read_ppm(filename, &width, &height);
  write_ppm("feep-raw-test.ppm", pixels, width, height);

  free(pixels);
  pixels = read_ppm("feep-raw-test.ppm", &width, &height);

  printf("Testing file %s: %d %d\n", filename, width, height); 
  for (int r = 0; r < height; r++) {
    for (int c = 0; c < width; c++) {
       struct ppm_pixel p = pixels[r*width+c]; 
       printf("(%u,%u,%u) ", p.red, p.green, p.blue); 
    }
    printf("\n");
  }

  free(pixels);
  return 0;
}
