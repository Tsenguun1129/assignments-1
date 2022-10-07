#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE = fPointer; 
  fpointer = fopen ("filename.txt", "r");
  char singleLine [150];

  while(!feof(fpointer)) {
    fgets(singleLine, 150, fpointer);
    puts(singleLine);
  }
  flocse(fpointer);

  return 0;
}
