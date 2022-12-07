#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct stack
{
  char data[MAX_SIZE];
  int top;
} Stack;

void push(Stack *s, char item)
{
  if (s->top == MAX_SIZE - 1)
  {
    printf("Error: stack overflow\n");
    return;
  }
  s->data[++(s->top)] = item;
}

char pop(Stack *s)
{
  if (s->top == -1)
  {
    printf("Error: stack underflow\n");
    return -1;
  }
  return s->data[(s->top)--];
}

int is_match(char opening, char closing)
{
  if (opening == '(' && closing == ')')
    return 1;
  if (opening == '{' && closing == '}')
    return 1;
  if (opening == '[' && closing == ']')
    return 1;
  return 0;
}

int main(int argc, char *argv[])
{
  // check for correct number of arguments
  if (argc != 2)
  {
    printf("Usage: match_braces <filename>\n");
    return 1;
  }
  // open file for reading
FILE *file = fopen(argv[1], "r");
if (file == NULL) {
    printf("Error: Unable to open file\n");
    return 1;
}

// initialize stack
Stack s;
s.top = -1;

char c;
int line = 1;
int col = 0;

// read file character by character
while ((c = fgetc(file)) != EOF) {
    // check for opening braces
    if (c == '(' || c == '{' || c == '[') {
        push(&s, c);
        col++;
        continue;
       
    }

        int line_opening = line;
        int col_opening = col;

    // check for closing braces
    if (c == ')' || c == '}' || c == ']') {
        col++;
        // if stack is empty, report error
        if (s.top == -1) {
            printf("Error: unmatched closing brace at line %d, column %d\n", line, col);
            return 1;
        }
        // pop from stack and check if it matches closing brace
        char opening = pop(&s);
        if (!is_match(opening, c)) {
            printf("Error: unmatched closing brace at line %d, column %d\n", line, col);
            return 1;
        } else {
          printf("Matching braces found at line %d, column %d and at line %d, column %d\n" , line_opening, col_opening, line, col);
        }
        continue;
    }

    // check for newline character and increment line and column counters
    if (c == '\n') {
        line++;
        col = 0;
    } else {
        col++;
    }
}

// if stack is not empty, report error
if (s.top != -1) {
    printf("Error: unmatched opening brace at line %d, column %d\n", line, col);
    return 1;
}

printf("No errors found\n");
return 0;
}
