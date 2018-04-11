#include<stdio.h>

#define ARRAY_LENGTH 20


typedef struct{
  int top;
  int array[ARRAY_LENGTH];
}stack;

typedef enum {false, true} boolean;

void create_stack(stack *s)
{
  s->top=-1;
}

boolean is_full(stack s)
{
  if(s.top == ARRAY_LENGTH-1)
    return true;
  return false;
}

boolean is_empty(stack s)
{
  if(s.top == -1)
    return true;
  return false;
}

void push(stack *s, int data)
{
  s->top++;
  s->array[s->top]=data;
  return;
}

int pop(stack *s)
{
  return (s->array[s->top--]);
}

int peek(stack s)
{
  return (s.array[s.top]);
}

void print_elements(stack s)
{
  int i=0;
  printf("\n*****************************************************************\n");
  printf("Elements of Stacks are :\n");
  for(i=s.top;i>=0;i--)
    printf("%d\n",s.array[i]);
  printf("*****************************************************************\n");
  return;
}

int main()
{
  int choice,data;
  stack s;
  create_stack(&s);
  do
  {
    printf("Options avialable:\n\n");
    printf("1.Push element on stack.\n");
    printf("2.Pop element from stack.\n");
    printf("3.Peek element of stack.\n");
    printf("4.Print elements of stack.\n");
    printf("5.Exit\n");
    printf("Enter your choice between 1-5:");
    scanf("%d",&choice);
    printf("\n");
    switch(choice)
    {
      case 1:
	if(is_full(s))
	  printf("No more element can be pushed on stack as Stack is alredy full.\n");
	else
	{
	  printf("Enter the element value to be pushed over stack:");
	  scanf("%d",&data);
	  push(&s, data);
	}
	break;
      case 2:
	if(is_empty(s))
	  printf("There is no element to pop from stack as stack is empty.\n");
	else
	  printf("Element which is poped from stack is: %d\n",pop(&s));
	break;
      case 3:
	if(is_empty(s))
	  printf("There is no element to peeked from stack as stack is empty.\n");
	else
	  printf("Element at the top of the stack is: %d\n",peek(s));
	break;
      case 4:
	if(is_empty(s))
	  printf("There is no element to peeked from stack as stack is empty.\n");
	else
	  print_elements(s);
	break;
      default:
	if(choice != 5)
	  printf("Invalid choice.\n");
	break;

    }
  }while(choice != 5);
  return 0;
}
