#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

char random_c (double value) {

  
  char status = 'o';

  double whole = value * 100; 
  int number = (rand() % 100);
  if (number < whole) {
    status = 'X';
  } if (number > whole) {
    status = '.';
  }
  return status;
}


void x_generation (char **storage, int m, int n) {
  int count_of_x = 0;
 
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (storage[i][j] != 'X') {
        if (i != 0 && storage[i-1][j] == 'X') {
          count_of_x++;
        } if (j != 0 && storage[i][j-1] == 'X') {
          count_of_x++;
        } if (j != m - 1 && storage[i][j+1] == 'X') {
          count_of_x++;
        } if (i != n - 1 && storage[i+1][j] == 'X') {
          count_of_x++;
        } if (i != n -1 && j != m - 1 && storage[i+1][j+1] == 'X') {
          count_of_x++;
        } if (i != n - 1 && j != 0 && storage[i+1][j-1] == 'X') {
          count_of_x++;
        } if ( i != 0 && j != m - 1 && storage[i-1][j+1] == 'X') {
          count_of_x++;
        } if ( i != 0 && j != 0 && storage[i-1][j-1] == 'X') {
          count_of_x++;
        } 
      

      if (count_of_x == 8) {
        storage[i][j] = '8';
      } else if (count_of_x == 7) {
        storage[i][j] = '7';
      } else if (count_of_x == 6) {
        storage[i][j] = '6';
      } else if (count_of_x == 5) {
        storage[i][j] = '5';
      } else if (count_of_x == 4) {
        storage[i][j] = '4';
      } else if (count_of_x == 3) {
        storage[i][j] = '3';
      } else if (count_of_x == 2) {
        storage[i][j] = '2';
      } else if (count_of_x == 1) {
        storage[i][j] = '1';
      } else if (count_of_x == 0) {
        storage[i][j] = '0';
      }
      }
      count_of_x = 0;
    }
  }

 

}
int main(int argc, char *argv[]) {
srand(time(0));


char *a = argv[1];
int m = atoi(a);

char *b = argv[2];
int n = atoi(b);

char *c = argv[3];
double p = atof(c);

int number_elements = m * n;


char **storage = (char**) calloc(number_elements, sizeof(char*));

for (int i = 0; i < number_elements; i++) {
  storage[i] = (char*) calloc(number_elements, sizeof(char));
}

for (int i = 0; i<m; i++) {
  for (int j = 0; j < n; j++) {
    storage[i][j] = random_c(p);
  }
}

//printing the 2d array with mines
printf("\n");

for (int i = 0; i< m; i++) {
  for (int j = 0; j < n; j++) {
    printf("%c",storage[i][j]);
  }
  printf("\n");
}

printf("\n");

x_generation(storage, m, n);

//printing the 2d array after revealing the N of mines
for (int i = 0; i< m; i++) {
  for (int j = 0; j < n; j++) {
    printf("%c",storage[i][j]);
  }
  printf("\n");
}




//FREE STORAGE
for (int j = 0; j < number_elements; j++) {
  free(storage[j]);
}
free(storage);


  return 0;
}

