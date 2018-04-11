#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct node{
  int data;
  struct node *next;
}node;

node *head = NULL;

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

void reverse_linked_list(node *prev_ptr, node * node_item)
{
  node *next_ptr = node_item->next;
  if(!(node_item->next))
  {
    head = node_item;
  }
  else
  {
    reverse_linked_list(node_item, node_item->next);
  }

  if(prev_ptr)
    node_item->next = prev_ptr;
  else
    node_item->next = NULL;

  return;
}

int main()
{
  node *node = NULL, *current = NULL;
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

  reverse_linked_list(NULL, head);

  printf("\nReverse linked list:\n");
  print_linked_list(head);

  return 0;
}
