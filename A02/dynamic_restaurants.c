#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Restaurants {
    char name[50];
    int start_time;
    int end_time;
    float rating;
}; 


int main() {
    int number = 1; 
    struct Restaurants *restaurant_data;
    int number_of_restaurants;
    printf("Enter the number of restaurants: "); 
    scanf("%d", &number_of_restaurants);

    restaurant_data = (struct Restaurants*) malloc (number_of_restaurants * sizeof(struct Restaurants));

    for (int i = 0; i < number_of_restaurants; i++) {
      printf("Enter restaurant name: "); 
      scanf(" %[^\n]%*c", (restaurant_data + i) -> name);

      printf("Enter start time: ");
      scanf(" %d%*c", &(restaurant_data + i) -> start_time);

      printf("Enter closing time: "); 
      scanf(" %d%*c", &(restaurant_data + i) -> end_time);

      printf("Enter rating: ");
      scanf(" %f%*c", &(restaurant_data + i) -> rating);
    }

    printf("\n");
    printf("\tWelcome to the Restaurant Directory!");
    printf("\n");

    for(int j = 0; j < number_of_restaurants; j++) {
        printf("\n%d) %-32sOPEN: %d:00 \tCLOSE: %d:00 \tRATING: %.2f\n",
                number, restaurant_data[j].name, restaurant_data[j].start_time, restaurant_data[j].end_time, restaurant_data[j].rating);
                number++;
    }


    free(restaurant_data);


  
}
