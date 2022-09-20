#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int main() {
    int lower = 3000, upper = 5000; 

    int guess = 0; 
    int AIguess1 = 0; 
    int AIguess2 = 0; 
    int actual_price = 0; 

    srand(time(0));

    AIguess1 = (rand() % (upper - lower + 1) + lower); 
    AIguess2 = (rand() % (upper - lower + 1) + lower);
    actual_price = (rand() % (upper - lower + 1) + lower);

    printf("Welcome to the Price is Right!\n"); 
    printf("Enter a guess to win a luxurious dishwasher: "); 
    scanf("%d", &guess);
    printf("%s %d\n", "Your guess is: ", guess);

    printf("%s %d\n", "AI Contestant #1 guesses:", AIguess1);
    printf("%s %d\n", "AI Contestant #2 guesses:", AIguess2);
    printf("%s %d\n", "The dishwasher cost:", actual_price); 

    int difference1 = actual_price - AIguess1;
    int difference2 = actual_price - AIguess2; 
    int difference_user = actual_price - guess; 

    if (difference1 < 0) {
        difference1 = 9000;
    } else if (difference2 < 0) {
        difference2 = 9000; 
    } else if(difference_user < 0){
        difference_user = 9000;
    }

    if (difference1 < difference2 && difference1 < difference_user ) {
        printf("Congrats! AI Contestant 1 wins\n");
    } else if (difference2 < difference1 && difference2 < difference_user) {
        printf("Congrats! AI Contestant 2 wins\n");
    } else if (difference_user < difference1 && difference_user < difference2) {
        printf("Congrats! You win!");
    } 
    
    
    return 0; 
}