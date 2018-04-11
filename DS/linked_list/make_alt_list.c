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

node * make_list_with_alternate_elements(node *node_item)
{
  node *fast_ptr = node_item, *current = NULL, *temp = NULL;
  node *alt_list = NULL;

  while(fast_ptr)
  {
    temp = malloc(sizeof(node));
    temp->next = NULL;
    temp->data = fast_ptr->data;

    if(alt_list)
      current->next = temp;
    else
      alt_list = temp;

    current = temp;

    if(fast_ptr->next)
      fast_ptr = fast_ptr->next->next;
    else
      break;
  }

  return alt_list;
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

  printf("\nLinked list with alternate entries:\n");
  print_linked_list(make_list_with_alternate_elements(head));

  return 0;
}
