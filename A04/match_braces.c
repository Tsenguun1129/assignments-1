#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE = fPointer; 
  fpointer = fopen ("filename.txt", "r");
  char singleLine [150];

  while(!feof(fpointer)) {
    fgets(singleLine, 150, fpointer);
    puts(singleLine);
  }
  flocse(fpointer);

  return 0;
FILE *infile;

struct sNode
{
  char data;
  struct sNode *next;
};

char push(struct sNode **top_ref, char new_data);
char pop(struct sNode **top_ref);

int main(int argc, char **argv)
{

  struct sNode *stack = NULL;
  int ch, column;
  int line = 1;

  int ch, first_brace, last_brace, first_brace_column, last_brace_column;
  int column = 1, count_letter = 1;
  char push_letter, pop_letter;

  char *filename = argv[1];

  infile = fopen(filename, "r");
  ch = getc(infile);

  if (infile == NULL)
  {
    printf("Error: unable to open file %s\n", filename);
    exit(1);
  }

  while (ch != EOF)
  {

    ch = getc(infile);
    line++;
    printf("%c", ch);

    if (ch == '\n')
    {
      column++;
      line = 0;
    }

    printf("%d", column);
    count_letter++;

    if (ch == '\n')
    {
      column++;
      count_letter = 1;
    }

    if (ch == '{' || ch == '[' || ch == '(')
    {
      push_letter = push(&stack, ch);
      printf("%c", push_letter);
      first_brace = count_letter;
      first_brace_column = column;
    }

    if (ch == '}' || ch == ']' || ch == ')')
    {
      pop_letter = pop(&stack);
      last_brace = count_letter;
      last_brace_column = column;
      if (push_letter == pop_letter)
      {
        printf("Found matching braces (%d,%d) -> (%d,%d)\n", first_brace, first_brace_column, last_brace, last_brace_column);
      }
      else
      {
        printf("Unmatched brace on Line %d and Column %d\n", first_brace, first_brace_column);
      }
    }
  }
}

char push(struct sNode **top_ref, char new_data)
{
  struct sNode *new_node = (struct sNode *)malloc(sizeof(struct sNode));
  char new_node_print;

  if (new_node == NULL)
  {
    printf("Stack overflow\n");
    getchar();
    exit(0);
  }
  new_node->data = new_data;
  new_node_print = new_node->data;
  new_node->next = (*top_ref);
  (*top_ref) = new_node;
  return new_node_print;
}

char pop(struct sNode **top_ref)
{
  char res;
  struct sNode *top;

  if (*top_ref == NULL)
  {
    printf("Stack overflow\n");
    getchar();
    exit(0);
  }
  else
  {
    top = *top_ref;
    res = top->data;
    *top_ref = top->next;
    free(top);
    return res;
  }
}
