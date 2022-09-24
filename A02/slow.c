#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int pause, number_of_characters;
  char word [128];
  int k = 0;

  
  

  printf("Enter your word: "); 
  scanf("%s", word); 

  printf("Number of pauses: "); 
  scanf("%d", &pause); 

  // LENGTH OF WORD
  number_of_characters = strlen(word); 


  char *long_words =  malloc(number_of_characters * (pause  + 1) + 1);



  for (int i = 0; i < number_of_characters; i++) {
    long_words [k] = word[i];

    for (int l = 0; l<pause; l++) {
      k++;
      long_words [k] = '.';
    }
    k++;
   
    long_words [number_of_characters * (pause  + 1)] = '\0';
  }

  printf("%s", long_words);
 



  free(long_words);
  return 0;
}
