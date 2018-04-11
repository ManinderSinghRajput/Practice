#include<stdio.h>
#include<stdlib.h>


typedef struct node{
  int info;
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

void push(stack **top, int data)
{
  stack *temp;
  temp = (stack *)malloc(sizeof(stack));
  temp->info = data;
  temp->next = *top;
  *top = temp;
  return;
}

int pop(stack **top)
{
  int data = 0;
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
    printf("%d\n",current->info);
    current=current->next;
  }
  printf("*****************************************************************\n");
  return;
}


int main()
{
  int choice,data;
  stack *top = NULL;
  //create_stack(top);
  do
  {
    printf("Options avialable:\n\n");
    printf("1.Push element on stack.\n");
    printf("2.Pop element from stack.\n");
    printf("3.Peek element of stack.\n");
    printf("4.Print elements of stack.\n");
    printf("5.Dispose Stack.\n");
    printf("6.Exit\n");
    printf("Enter your choice between 1-6:");
    scanf("%d",&choice);
    printf("\n");
    switch(choice)
    {
      case 1:
	printf("Enter the element value to be pushed over stack:");
	scanf("%d",&data);
	push(&top, data);
	break;
      case 2:
	if(is_empty(top))
	  printf("There is no element to pop from stack as stack is empty.\n");
	else
	  printf("Element which is poped from stack is: %d\n",pop(&top));
	break;
      case 3:
	if(is_empty(top))
	  printf("There is no element to peeked from stack as stack is empty.\n");
	else
	  printf("Element at the top of the stack is: %d\n",peek(top));
	break;
      case 4:
	if(is_empty(top))
	  printf("There is no element to peeked from stack as stack is empty.\n");
	else
	  print_elements(top);
	break;
      case 5:
	if(is_empty(top))
	  printf("Stack is already empty, no need to dispose.\n");
	else
	  dispose_stack(&top);
	break;;
      default:
	if(choice != 6)
	  printf("Invalid choice.\n");
	break;

    }
  }while(choice != 6);
  return 0;
}
