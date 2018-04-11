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
  
  while(current)
  {
    printf("%d\n",current->data);
    current = current->next;
  }
  printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n");
  return;
}   

int compare_nodes(node *head, int data)
{
  node *current=head;
  while(current)
  {
    if(current->data == data)
      return 1;
    current = current->next;
  }
  return 0;
}

int if_ascending(node* head)
{
  node *current = head;
  int data = 0;
  while(current)
  {
    if(current->data<data)
      return 0;
    data = current->data;
    current = current->next;
  }
  return 1;
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
    node->next=NULL;
    if(i==0)
      head=node;
    else
      current->next=node;
    current=node;
  }
  printf("\nEntered list is:\n");
  print_linked_list(head);

  printf("%d\n",if_ascending(head));

  return 0;
}
