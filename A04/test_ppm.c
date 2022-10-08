#include <stdio.h>
#include <stdlib.h>
#include "read_ppm.h"

int main() {
  // load feep-raw and print out the grid of pixels
  int w, h; 
  struct ppm_pixel** example;
  example = read_ppm_2d ("feep-raw.ppm", &w, &h);
  printf("%s", "Opening file: feep-raw.ppm\n");
  for (int i = 0; i<h; i++) {
    for (int j = 0; j<w; j++) {
      struct ppm_pixel a = example[i][j];
      printf("(%u, %u, %u) ", a.red, a.green, a.blue);
    }
    printf("\n");
  }
  free(example);
  
  return 0;
}

