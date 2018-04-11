#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>


typedef struct node{
  float info;
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

void push(stack **top, float data)
{
  stack *temp;
  temp = (stack *)malloc(sizeof(stack));
  temp->info = data;
  temp->next = *top;
  *top = temp;
  return;
}

float pop(stack **top)
{
  float data = 0.00;
  stack * temp;
  temp = *top;
  data = (*top)->info;
  *top = (*top)->next;
  free(temp);
  return (data);
}

float peek(stack *top)
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


void postfix_evaluator(char *post_exp)
{
  stack *local_stack;
  create_stack(&local_stack);
  float op1, op2, value;
  
  while(*post_exp)
  {
    if(*post_exp == ' ' || *post_exp == '\t' || *post_exp == ',')
    {
      post_exp++;
      continue;
    }
    if(isdigit(*post_exp)) 
      push(&local_stack, atof(post_exp));
    else
    {
      op2 = pop(&local_stack);
      op1 = pop(&local_stack);
     
      switch(*post_exp)
      {
        case '+' : value = op1 + op2;
          break;
        case '-' : value = op1 - op2;
          break;
        case '/' : value = op1 / op2;
          break;
        case '*' : value = op1 * op2;
          break;
        case '%' : value = (int)op1 % (int)op2;
          break;
        default : printf("Illegal operation");
          dispose_stack(&local_stack);
          break;
      }
      push(&local_stack, value);
    }
    post_exp++;
  }
  printf("Result: %.4f\n",pop(&local_stack));
  dispose_stack(&local_stack);
  return;
}


int main()
{
  char post_exp[1024] = {0};
  printf("Enter the postfix expression to be evaluated:");
  //scanf("%s",exp);
  gets(post_exp);
  printf("Entered expression is:%s\n",post_exp);
  postfix_evaluator(post_exp);
  return 0;
}
