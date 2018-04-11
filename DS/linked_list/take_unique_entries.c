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

int main()
{
  node *head = NULL, *node = NULL, *current = NULL;
  int no_of_nodes = 0,i = 0, data = 0;
  printf("Enter the no of nodes:");
  scanf("%d",&no_of_nodes);
  for(i=0;i<no_of_nodes;i++)
  {
    scanf("%d", &data);
    if(compare_nodes(head, data))
      continue;
    node = malloc(sizeof(node));
    node->next=NULL;
    node->data=data;
    if(i==0)
      head=node;
    else
      current->next=node;
    current=node;
  }
  print_linked_list(head);
  return 0;
}
