#include <stdio.h>
#include <stdlib.h>
#include "read_ppm.h"

char converter(int rgb)
{
  if (rgb == 0 && rgb <= 25)
  {
    return '@';
  }
  else if (rgb >= 26 && rgb <= 50)
  {
    return '#';
  }
  else if (rgb >= 51 && rgb <= 75)
  {
    return '%';
  }
  else if (rgb >= 76 && rgb <= 100)
  {
    return '*';
  }
  else if (rgb >= 101 && rgb <= 125)
  {
    return 'o';
  }
  else if (rgb >= 126 && rgb <= 150)
  {
    return ';';
  }
  else if (rgb >= 151 && rgb <= 175)
  {
    return ':';
  }
  else if (rgb >= 176 && rgb <= 200)
  {
    return ',';
  }
  else if (rgb >= 201 && rgb <= 225)
  {
    return '.';
  }
  else
  {
    return ' ';
  }
}

int main(int argc, char **argv)
{
  int w, h, r, g, b, rgb;
  struct ppm_pixel **example;
  char *file = argv[1];

  if (argc != 2)
  {
    printf("usage: ascii_image <file.ppm>\n");
    return 0;
  }

  example = read_ppm_2d(file, &w, &h);
  printf("Opening file: %s\n", file);
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      struct ppm_pixel a = example[i][j];
      r = (int)a.red;
      g = (int)a.green;
      b = (int)a.blue;
      rgb = (r + g + b) / 3;
      char symbol = converter(rgb);
      printf("%c", symbol);
      //printf("(%u, %u, %u) ", a.red, a.green, a.blue);
    }
    printf("\n");
  }
  free(example);

  return 0;

  return 0;
}
