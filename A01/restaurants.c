#include <stdio.h>
#include <string.h>

struct Restaurants {
    char name[50];
    int start_time;
    int end_time;
    float rating;

};

int main() {
    struct Restaurants restaurantRecord[3] = {  {"Alfrenzo", 9, 22, 4.5}, 
                                                {"Lavazza", 10, 20, 4.2},
                                                {"Bontora", 8, 3, 4.6} };

    int time;

    printf("Please specify your current time: "); 
    scanf("%d", &time);

    printf("\n\t\t\t Your options for today");
    printf("\n");

    for(int i=0; i<3; i++) {
        printf("\n%d %s\t OPEN: %d:00\t CLOSE: %d:00\t RATING: %.2f\n",
                i, restaurantRecord[i].name, restaurantRecord[i].start_time, restaurantRecord[i].end_time, restaurantRecord[i].rating);
    }

    int user_choice;
    printf("\n Enter your choice [0,1,2]: ");
    scanf("%d", &user_choice);
   
    if ((time > restaurantRecord[user_choice].end_time || restaurantRecord[user_choice].start_time > time) && restaurantRecord[user_choice].end_time > 10) {
        printf("\n Sorry they are closed.");
    } else if (time < restaurantRecord[user_choice].end_time && time > restaurantRecord[user_choice].start_time) {
        printf("\n %s %s %s %d %s", "Perfect!", restaurantRecord[user_choice].name, "will be open", restaurantRecord[user_choice].end_time - time, "more hour(s).");
    } else if (restaurantRecord[user_choice].end_time < 10 && time < restaurantRecord[user_choice].end_time) {
        printf("\n %s %s %s %d %s", "Perfect!", restaurantRecord[user_choice].name, "will be open", restaurantRecord[user_choice].end_time - time, "more hour(s).");
    
    }
    return 0;
}