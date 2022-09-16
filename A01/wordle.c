#include <stdio.h>
#include <string.h>
#include <time.h>
#include "words.h" // header that defined chooseWord()

int result (char guess[], char ai_word[]) {
  int results = 0; 
  if(strcmp(guess, ai_word) == 0) {
    results = 1;
  } else {
    results = 0;
  }
  return results;
}

int exist (char guess[], char letter) {

   int status = 0;
  //int k = 0; 


  // while (guess[k] != '\0') {
  //   if (guess[k] == letter) {
  //     printf("%c == %c", guess[k], letter);
  //     status = 100; 
  //     break;
  //   }
  //   k++; 
  // } 

  // return status;

  if(strchr(guess,letter) != NULL) {
    status = 1; 
  }
  return status;

}

int main() {

    char user_word [6];
    int rounds = 0;

    srand(time(0));
    
    char word[6]; 
    strcpy (word, chooseWord());
    printf("cheat:%s\n",word);



    while(rounds != 6) {
      printf("\n");
      printf("Welcome to Wordle!\n");
      printf("Please enter a five letter word:");
      scanf("%s", user_word);


      if (strlen(user_word) < 5) {
        printf("Please enter a word with five letters.");
        break;
      } else if (strlen(user_word) > 5) {
        printf("Please enter a word with five letters.");
        break;
      }

      

      for (int i=0; i<5; i++) {
        int word_exists = exist(user_word, word[i]);

        if(user_word[i] == word[i]) {
          printf("%c %s", user_word[i], "is in the word and in the correct spot!\n");
        } else if (user_word[i] != word[i] && word_exists == 1) {
          printf("%c %s", user_word[i], "is in the word but in the INCORRECT spot.\n");
        } else if (user_word[i] != word[i] && word_exists == 0) {
          printf("%c %s", user_word[i], "is not in the word.\n");
        } else if (result(user_word, word) > 0) {
          printf("You got it!\n");
          break;
        }
      }
      rounds++;
    } 
      return 0;
  
}
