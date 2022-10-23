#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_ppm.h"

// implement one

struct ppm_pixel* read_ppm(const char* filename, int* w, int* h) {
  return NULL;
}

struct ppm_pixel** read_ppm_2d(const char* filename, int* w, int* h) {
  FILE *infile;
char line [1000];
char next_line [1000];

infile = fopen (filename, "r"); 

if(infile == NULL) {
     printf("Error: unable to open file %s\n", filename);
}


fgets(line, sizeof(line), infile); 

if (line[0] != 'P' && line[1] != '6') {
     printf("Format is incorrect");
     return NULL;
} 

fgets (next_line, sizeof(next_line), infile);

while (next_line[0] == '#') {
     fgets (next_line, sizeof(next_line), infile);
}

     sscanf(next_line, "%d %d", w, h);

    
struct ppm_pixel **a; 
a = (struct ppm_pixel **) malloc(sizeof(struct ppm_pixel*) * *h);

for (int i = 0; i< *w * *h; i++) {
     a [i] = (struct ppm_pixel *) malloc (sizeof(struct ppm_pixel) * *w);
} 
}
