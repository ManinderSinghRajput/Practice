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

void copy_list(node* head)
{
  node *current = head;
  node *copy_list_head = NULL, *copy_list = NULL, *node = NULL;
  while(current)
  {
    node = malloc(sizeof(node));
    node->next=NULL;
    node->data=current->data;
    if(copy_list_head)
      copy_list->next = node;
    else
      copy_list_head = node;

    copy_list = node;

    current = current->next;
  }
  printf("\nCopied list is:\n");
  print_linked_list(copy_list_head);
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
    node->next=NULL;
    if(i==0)
      head=node;
    else
      current->next=node;
    current=node;
  }
  printf("\nEntered list is:\n");
  print_linked_list(head);

  copy_list(head);

  //remove_duplicate(head);

  /*printf("\nLinked list with unique entries:\n");
  print_linked_list(head);*/

  return 0;
}
