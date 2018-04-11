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
  if(head == NULL)
    return;
  do
  {
    printf("%d\n",current->data);
    current = current->next;
  }
  while(current != head);
  printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n");
  return;
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
    node->data=data;
    if(i==0)
      head=node;
    else
      current->next=node;
    node->next=head;
    current=node;
  }
  printf("\nEntered list is:\n");
  print_linked_list(head);

  return 0;
}
