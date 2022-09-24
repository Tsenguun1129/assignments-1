#include <stdio.h>

int find_largest (int storage[]) {

    int largest_number = 0;
    int largest = 0;
 
    int first_number = storage[0];
    int second_number = storage[1];
    int third_number = storage [2];
    int fourth_number = storage [3]; 

     if (first_number == second_number) {
        first_number *= 2;
        if(largest < first_number) {
            largest = first_number;
        } 
    } else if (first_number != second_number) {
        if (first_number == third_number && second_number == 0) {
            first_number *= 2; 
             if(largest < first_number) {
            largest = first_number;
        } 
        } else if (first_number != third_number) {
            if (first_number == fourth_number && second_number == 0 && third_number == 0) {
                first_number *= 2;
                 if(largest < first_number) {
            largest = first_number;
        } 
            }
        }
    }


    if (second_number == first_number) {
        second_number *=2;
         if(largest < second_number) {
            largest = second_number;
        } 
    } else if (second_number != first_number) {
        if (second_number == third_number) {
            second_number *=2;
            if(largest < second_number) {
            largest = second_number;
        } 
        } else if (second_number == fourth_number && third_number == 0) {
            second_number *= 2;
            if(largest < second_number) {
            largest = second_number;
        } 
        }
    }

    if (third_number == first_number && second_number == 0) {
        third_number *=2; 
        if(largest < third_number) {
            largest = third_number;
        } 
    } else if (third_number != first_number) {
        if (third_number == second_number) {
            third_number *= 2; 
             if(largest < third_number) {
            largest = third_number;
        } 
        } else if(third_number == fourth_number) {
            third_number *=2;
             if(largest < third_number) {
            largest = third_number;
        } 
        }
    }

    if (fourth_number == first_number && second_number == 0 && third_number == 0) {
        fourth_number *=2;
         if(largest < fourth_number) {
            largest = fourth_number;
        } 
    } else if (fourth_number == second_number && third_number == 0) {
        fourth_number *=2;
        if(largest < fourth_number) {
            largest = fourth_number;
        }  
    } else if (fourth_number == third_number) {
        fourth_number *=2; 
        if(largest < fourth_number) {
            largest = fourth_number;
        } 
    }

    return largest;

    if (largest == 0) {

    if (first_number >= second_number && first_number >= third_number && first_number >= fourth_number) {
        largest_number = first_number;
    } else if (second_number >= first_number && second_number >= third_number && second_number >= fourth_number) {
        largest_number = second_number;
    } else if (third_number >= first_number && third_number >= second_number && third_number >= fourth_number) {
        largest_number = third_number;
    } else if (fourth_number >= first_number && fourth_number >= second_number && fourth_number >= third_number) {
        largest_number = fourth_number;
    }
    return largest_number;}
}



int main() {
  
  int M [4][4];
  int storage [128]; 
  
  
  int first_row [4], second_row[4], third_row[4], fourth_row [4];
  int first_column [4], second_column [4], third_column [4], fourth_column [4];

  int a, b, c, d, e, f, g, h;

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      printf ("Enter a value for M [%d][%d]: \n", i, j);
      scanf(" %d", &M[i][j]);
    }
  }

  


  first_row [0] = M[0][0];
  first_row [1] = M[0][1];
  first_row [2] = M[0][2];
  first_row [3] = M[0][3];

  second_row [0] = M[1][0];
  second_row [1] = M[1][1];
  second_row [2] = M[1][2];
  second_row [3] = M[1][3];

  third_row [0] = M[2][0];
  third_row [1] = M[2][1];
  third_row [2] = M[2][2];
  third_row [3] = M[2][3];

  fourth_row [0] = M[3][0];
  fourth_row [1] = M[3][1];
  fourth_row [2] = M[3][2];
  second_row [3] = M[3][3];


  first_column [0] = M[0][0];
  first_column [1] = M[1][0];
  first_column [2] = M[2][0];
  first_column [3] = M[3][0];

  second_column [0] = M[0][1];
  second_column [1] = M[1][1];
  second_column [2] = M[2][1];
  second_column [3] = M[3][1];

  third_column [0] = M[0][2];
  third_column [1] = M[1][2];
  third_column [2] = M[2][2];
  third_column [3] = M[3][2];

  fourth_column [0] = M[0][3];
  fourth_column [1] = M[1][3];
  fourth_column [2] = M[2][3];
  fourth_column [3] = M[3][3];



  a = find_largest(first_row);
  b = find_largest(second_row);
  c = find_largest(third_row);
  d = find_largest(fourth_row);

  e = find_largest(first_column);
  f = find_largest(second_column);
  g = find_largest(third_column);
  h = find_largest(fourth_column);

  storage [0] = a;
  storage [1] = b; 
  storage [2] = c; 
  storage [3] = d; 
  storage [4] = e; 
  storage [5] = f; 
  storage [6] = g; 
  storage [7] = h; 

  int max = storage [0];

  for (int i = 1; i < 8; i++) {
    if (storage[i] > max) {
      max = storage[i];
    }
  }
  printf("%d\n", max);

  return 0;
}
