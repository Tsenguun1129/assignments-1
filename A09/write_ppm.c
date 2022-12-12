#include "write_ppm.h"
#include <stdio.h>
#include <string.h>

void write_ppm(const char* filename, struct ppm_pixel* pixels, int w, int h) {
    FILE *fp; 
    fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Error. %scannot be openned.\n", filename);
        return;
    }

    fprintf(fp, "P6 \n#\n%d %d \n255 \n", w, h);
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            fwrite (&pixels[i*w + j].red, 1, 1, fp);
            fwrite (&pixels[i*w + j].green, 1, 1, fp);
            fwrite (&pixels[i*w + j].blue, 1, 1, fp);

        }
    }
    fclose(fp);

}

void write_ppm_2d(const char* filename, struct ppm_pixel** pxs, int w, int h) {
    FILE *fp; 
    fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Error. %s cannot be openned.\n", filename);
        return;
    }

    fprintf(fp, "P6 \n#\n%d %d \n255 \n", w, h);

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            fwrite (&pxs[i][j].red, 1, 1, fp);
            fwrite (&pxs[i][j].green, 1, 1, fp);
            fwrite (&pxs[i][j].blue, 1, 1, fp);

        }
    }
    fclose(fp);
  
}

