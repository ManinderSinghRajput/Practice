#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct node{
  int data;
  struct node *next;
}node;

void print_linked_list(node * head)
{
  printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n");
  node *current=head;
  while(current)
  {
    printf("%d\n",current->data);
    current = current->next;
  }
  printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n");
  return;
}   


node * sort_in_descending_order(node *head)
{
  node *new_head = NULL, *max_prev = head, *current = NULL, *external_current = NULL, *max = NULL;

  while(head)
  {
    max = head;
    current=head;
    while(current->next)
    {
      if(current->next->data > max->data)
      {
        max_prev = current;
	max = current->next;
      }
      current=current->next;
    }
    if(!new_head)
      new_head = max;
    else
      external_current->next =  max;

    if(max == head)
      head=max->next;
    else
      max_prev->next = max->next;

    external_current = max;
  }
  return new_head;
}

int main()
{
  node *head = NULL, *node = NULL, *current = NULL;
  int no_of_nodes = 0,i = 0, data = 0;
  printf("Enter the no of nodes:");
  scanf("%d",&no_of_nodes);
  for(i=0;i<no_of_nodes;i++)
  {
    scanf("%d", &data);
    node = malloc(sizeof(node));
    node->next=NULL;
    node->data=data;
    if(i==0)
      head=node;
    else
      current->next=node;
    current=node;
  }
  printf("\nEntered list is:\n");
  print_linked_list(head);

  printf("\nLinked list in descending order:\n");
  print_linked_list(sort_in_descending_order(head));

  return 0;
}
