#include <stdio.h>
#include <stdlib.h>
#include "read_ppm.h"

int main() {
  // load feep-raw and print out the grid of pixels
  int w, h; 
  struct ppm_pixel** example;
  example = read_ppm_2d ("feep-raw.ppm", &w, &h);
  free(example);
  
  return 0;
}

