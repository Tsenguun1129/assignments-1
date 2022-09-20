#include <stdio.h>


int main () {
    char word [15];
    char letter [15];
    printf("Enter your word: ");
    scanf("%s", word);

    int shift; 
    printf ("Enter your shift: ");
    scanf ("%d", &shift);
    
    for (int i=0; word[i] != '\0'; i++) {
        letter[i] = word[i] + shift;
    }
    printf("Result: %s ", letter);

    return 0;
}