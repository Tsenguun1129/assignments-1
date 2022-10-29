#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "read_ppm.h"
#include "write_ppm.h"

int main(int argc, char **argv)
{

  char *filename = argv[1];
  char phrase[100];
  int total, w, h;
  int i = 0;
  int j = 0;
  int tracker = 7;

  if (filename == NULL)
  {
    printf("Error. No file loaded");
  }

  if (argc != 2)
  {
    printf("usage: encode <file.ppm>\n");
    return 0;
  }

  printf("Reading file called %s with height: %d and width: %d\n", filename, h, w);
  printf("Enter a phrase: ");
  scanf("%[^\n]%*c", phrase);

  total = strlen(phrase);

  struct ppm_pixel *pixels = read_ppm(filename, &w, &h);

  unsigned char *pixels_char = (unsigned char *)pixels;

  while (i <= total)
  {
    unsigned char letter = phrase[i];
    unsigned char mask = 0x01;

    unsigned char l = 0xFE;
    while (j < 8)
    {
      unsigned char letter_masked = letter & (mask << tracker);
      unsigned char letter_opposite = letter_masked >> tracker;

      tracker--;

      if (letter_opposite)
      {
        pixels_char[i * 8 + j] = pixels_char[i * 8 + j] | letter_opposite;
      }
      else
      {
        pixels_char[i * 8 + j] = pixels_char[i * 8 + j] & l;
      }
      //printf("%02x\n", pixels_char[i*8 + j]);

      if (tracker < 0)
      {
        tracker = 7;
      }
      j++;
    }
    j = 0;
    i++;
  }
  // for (int i= 0; i < 32; i++) {
  //   printf("%02x, ", pixels_char[i]);
  // }
  // printf("\n");
  // for (int i= 0; i < 10; i++) {
  //   printf("%02x, %02x, %02x, ", pixels[i].red, pixels[i].green, pixels[i].blue);
  // }
  char *new_file = malloc(strlen(filename) + 8);

  strcpy(new_file, filename);
  new_file[strlen(new_file) - 4] = '\0';
  strcat(new_file, "-encode.ppm");
  printf("Writing file %s\n", new_file);
  write_ppm(new_file, (struct ppm_pixel *)pixels_char, w, h);

  free(pixels);
  free(new_file);
  return 0;
}
