#include<stdio.h>
#include<stdlib.h>


typedef struct node{
  char info;
  struct  node *next;
}stack;

typedef enum {false, true} boolean;

void create_stack(stack **top)
{
  *top=NULL;
}

boolean is_empty(stack *top)
{
  if(top == NULL)
    return true;
  return false;
}

void push(stack **top, char data)
{
  stack *temp;
  temp = (stack *)malloc(sizeof(stack));
  temp->info = data;
  temp->next = *top;
  *top = temp;
  return;
}

char pop(stack **top)
{
  char data = '\0';
  stack * temp;
  temp = *top;
  data = (*top)->info;
  *top = (*top)->next;
  free(temp);
  return (data);
}

int peek(stack *top)
{
  return (top->info);
}

void dispose_stack(stack **top)
{
  stack *current = *top,*temp =NULL;
  while(current)
  {
    temp = current;
    current=current->next;
    free(temp);
  }
  *top=NULL;
  return;
}

void print_elements(stack *top)
{
  stack *current = top;

  printf("\n*****************************************************************\n");
  printf("Elements of Stacks are :\n");
  while(current)
  {
    printf("%c\n",current->info);
    current=current->next;
  }
  printf("*****************************************************************\n");
  return;
}

char get_matching_symbol(char expr)
{
  char matching_char = '\0';
  switch(expr)
  {
    case ')':
      matching_char='(';
      break;
    case '(':
      matching_char=')';
      break;
    case '}':
      matching_char='{';
      break;
    case '{':
      matching_char='}';
      break;
    case '[':
      matching_char=']';
      break;
    case ']':
      matching_char='[';
      break;
  }
  return matching_char;
}

void evaluate_expression(char *exp)
{
  stack *top;
  create_stack(&top);
  while(*exp)
  {
    if(*exp == '(' || *exp == '[' || *exp == '{' )
      push(&top, *exp);
    else if(*exp == ')' || *exp == ']' || *exp == '}')
    {
      if(is_empty(top))
      {
	printf("Error: no matching opening symbol.\n");
	dispose_stack(&top);
	return;
      }
      else
      {
        char poped_character = '\0';
        poped_character = pop(&top);
        if(poped_character != get_matching_symbol(*exp))
        {
	  printf("Incorrect nesting of symbols.\n");
	  dispose_stack(&top);
	  return;
        }
      }
    }
    else if(*exp == '\'' || *exp == '`' || *exp == '"' )
    {
      if(!is_empty(top) && peek(top) == *exp)
        pop(&top);
      else
        push(&top, *exp);
    }
    else if(*exp == '\\')
    {
      push(&top, *exp);
    }
    else
    {
      if(!is_empty(top) && peek(top) == '\\')
        pop(&top);
    }
    exp++;
  }

  if(!is_empty(top))
  {
    printf("Missing closing symbol(s)\n");
    dispose_stack(&top);
  }
  else
    printf("Input expression is ok!!\n");
  return;
}


int main()
{
  char exp[1024] = {0};
  printf("Enter the expression to be evaluated:");
  scanf("%s",exp);
  printf("Entered expression is:%s\n",exp);
  evaluate_expression(exp);
  return 0;
}
