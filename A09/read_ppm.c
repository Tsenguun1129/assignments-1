#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_ppm.h"

struct ppm_pixel *read_ppm(const char *filename, int *w, int *h)
{
     FILE *fp;
     fp = fopen(filename, "r");
     if (fp == NULL)
     {
          printf("Error: unable to open file %s\n", filename);
          return NULL;
     }

     char image[100];
     char c[2];

     fgets(image, 100, fp);
     sscanf(image, "%s", c);

     if (c[0] != 'P' || c[1] != '6')
     {
          printf("error");
          return NULL;
     }

     fgets(image, 100, fp);
     while (image[0] == '#')
     {
          fgets(image, 100, fp);
     }

     sscanf(image, "%d %d", w, h);
     struct ppm_pixel *array = malloc(sizeof(struct ppm_pixel) * (*w) * (*h));
     if (!array)
     {
          printf("unable to allocate memory\n");
          return NULL;
     }
     fgets(image, 100, fp);
     fread(array, sizeof(struct ppm_pixel), (*w) * (*h), fp);
     fclose(fp);

     return array;
}

struct ppm_pixel** read_ppm_2d(const char* filename, int* w, int* h) {

    FILE *infile;
     char line[1000];
     char next_line[1000];

     infile = fopen(filename, "r");

     if (infile == NULL)
     {
          printf("Error: unable to open file %s\n", filename);
     }

     fgets(line, sizeof(line), infile);

     if (line[0] != 'P' && line[1] != '6')
     {
          printf("Format is incorrect");
          return NULL;
     }

     fgets(next_line, sizeof(next_line), infile);

     while (next_line[0] == '#')
     {
          fgets(next_line, sizeof(next_line), infile);
     }

     sscanf(next_line, "%d %d", w, h);
     fgets(next_line, sizeof(next_line), infile);


     struct ppm_pixel **a;
     a = (struct ppm_pixel **)malloc(sizeof(struct ppm_pixel *) * *h);

     for (int i = 0; i < *h; i++)
     {
          a[i] = (struct ppm_pixel *)malloc(sizeof(struct ppm_pixel) * *w);
          fread((a[i]), sizeof(struct ppm_pixel), *w, infile);
     } 
     return a;
}

