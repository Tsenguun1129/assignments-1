#include <stdio.h>
#include <string.h>

int main() {
  char name[16];
  for (int i = 0; i < strlen(name) - 1; i++) {
    name[i] = i+'a';
  }
  name[15] = '\0';
  printf("Name is %s\n", name);
  return 0;
}