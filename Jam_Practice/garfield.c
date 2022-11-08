#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE* fp = fopen("test.txt", "r");
  if (!fp) {
    printf("Cannot open file\n");
    exit(1);
  }

  int ch = 0;
  while (ch != EOF) {
    ch = fgetc(fp);
  }
  fclose(fp);
  free(fp);
}