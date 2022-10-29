#include <stdio.h>
#include <stdlib.h>
#include "read_ppm.h"

int main(int argc, char **argv)
{
  int w, h;
  if (argc != 2)
  {
    printf("usage: decode <file.ppm>\n");
    return 0;
  }

  char *filename = argv[1];

  if (filename == NULL)
  {
    printf("Error. No file loaded");
  }

  struct ppm_pixel *pixels = read_ppm(filename, &w, &h);
  unsigned char *pixels_char = (unsigned char *)pixels;
  printf("Reading %s with height: %d and width: %d\n", filename, h, w);

  int limit = (w * h) * 3;
  int i = 0;
  int size = (w * h * 3) / 8;
  char *array_box = malloc(sizeof(char) * size);
  int j = 0;
  int tracker = 7;

  for (int i = 0; i < size; i++)
  {
    array_box[i] = 0x00;
  }

  printf("Max number of characters in the image: %d\n", size);

  while (i < limit)
  {
    unsigned char a = pixels_char[i];
    unsigned char mask = 0x01;
    unsigned char b = a & mask;
    if (i > 0 && i % 8 == 0)
    {
      j++;
    }

    array_box[j] = array_box[j] | (b << tracker);
    tracker--;

    if (tracker < 0)
    {
      tracker = 7;
    }

    i++;
  }

  printf("%s", array_box);
  printf("\n");

  free(array_box);
  free(pixels);
  return 0;
}
