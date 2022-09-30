#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Restaurants {
    char name[50];
    int start_time;
    int end_time;
    float rating;
    int key; 
    struct Restaurants *next; 
}; 

struct Restaurants *head = NULL;
//struct Restaurants *current = NULL; 

struct Restaurants* insert_sort (char name[], int start_time, int end_time, float rating, struct Restaurants* head) {
  struct Restaurants *data = (struct Restaurants*) malloc (sizeof(struct Restaurants));
  if (data == NULL) {
    printf("ERROR: Out of space!\n");
    exit(1);
  }

  memset (data -> name, 0, 50);
  strcpy (data -> name, name);
  data -> start_time = start_time;
  data -> end_time = end_time;
  data -> rating = rating; 
  data -> next = NULL;

  //sort
  struct Restaurants *tmp;
  struct Restaurants *tmp1; 
  

  tmp = head; 

  if (head == NULL) {
      return data;
    }

  // case 1 
  if (tmp -> rating < data -> rating) {
      data -> next = tmp; 
      return data;
    }

  // case 2 
  while (tmp->next != NULL && tmp -> rating > data -> rating) {

    tmp1 = tmp; 
    tmp = tmp -> next;
    
  }  

    if (tmp -> next == NULL) {
      tmp -> next = data;
    } else {
      tmp1 -> next = data; 
      data -> next = tmp;
      
    }

    return head;
}
  

  
//clear all the values
void clear (struct Restaurants* head) {
  struct Restaurants *tmp = head;
  while(head -> next != NULL) {
    tmp = tmp -> next;
    free(head);
    head = tmp;
  }
  free(tmp);
}



void print(struct Restaurants* list) {
  int i = 1;
  for (struct Restaurants* data = list; data != NULL; data = data -> next) {
    
    printf ("\n%d) %-32sOPEN: %d:00 \tCLOSE: %d:00 \tRATING: %.2f\n",
                i++, data -> name, data -> start_time, data -> end_time, data -> rating);

  }
}


int main() {

    struct Restaurants *restaurant_data = NULL;


    char name[32]; 
    int start_time;
    int end_time;
    float rating;

    int number_of_restaurants;
    printf("Enter the number of restaurants: "); 
    scanf("%d", &number_of_restaurants);


    for (int i = 0; i < number_of_restaurants; i++) { 
      printf("Enter restaurant name: "); 
      scanf(" %[^\n]%*c", (name));

      printf("Enter start time: ");
      scanf(" %d%*c", &(start_time));

      printf("Enter closing time: "); 
      scanf(" %d%*c", &(end_time));

      printf("Enter rating: ");
      scanf(" %f%*c", &(rating));

      restaurant_data = insert_sort(name, start_time, end_time, rating, restaurant_data);
   
    }

    
    

    printf("\n");
    printf("\tWelcome to the Restaurant Directory!");
    printf("\n");

    print(restaurant_data);


    clear(restaurant_data);


  
}
