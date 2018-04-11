#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>


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

int get_priority(char op)
{
  if(op == '/' || op == '*' || op == '%')
    return(1);

  return(0); 
}

void infix_to_postfix(char *exp)
{
  stack *local_stack;
  create_stack(&local_stack);
  char local_exp[1024] = {0};
  char *local_exp_ptr = local_exp;
  while(*exp)
  {
    if(*exp == ' ' || *exp == '\t')
    {
      exp++;
      continue;
    }
    else if(*exp == '(')
      push(&local_stack, *exp);
    else if(*exp == ')')
    {
      while( !is_empty(local_stack) && peek(local_stack) != '(')
      {
        *local_exp_ptr = pop(&local_stack);
        local_exp_ptr++;
        *local_exp_ptr = ' ';
        local_exp_ptr++;
      }
      pop(&local_stack);
    }
    else if(isdigit(*exp) || isalpha(*exp))
    {
      *local_exp_ptr = *exp;
      local_exp_ptr++;
      *local_exp_ptr = ' ';
      local_exp_ptr++;
    }
    else if( *exp == '+' || *exp == '-' || *exp == '*' || *exp == '/' || *exp == '%')
    {
      while( !is_empty(local_stack) && peek(local_stack) != '(' && (get_priority(peek(local_stack))) >= (get_priority(*exp)))
      {
        *local_exp_ptr = pop(&local_stack);
        local_exp_ptr++;
        *local_exp_ptr = ' ';
        local_exp_ptr++;
      } 
      push(&local_stack, *exp);
    }
    else
    {
      printf("Incorrect element in expression. \n");
      dispose_stack(&local_stack);
      exit(-1);
    }
    exp++;
  }
  while(!is_empty(local_stack) && peek(local_stack) != '(')
  {
    *local_exp_ptr = pop(&local_stack);
    local_exp_ptr++;
    *local_exp_ptr = ' ';
    local_exp_ptr++;
  }
  *local_exp_ptr='\0';
  printf("Postfix expression is: %s\n",local_exp);
  return;
}


int main()
{
  char exp[1024] = {0};
  printf("Enter the infix expression to be converted in postfix expression:");
  //scanf("%s",exp);
  gets(exp);
  printf("Entered expression is:%s\n",exp);
  evaluate_expression(exp);
  infix_to_postfix(exp);
  return 0;
}
