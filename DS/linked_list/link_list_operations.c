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

void* return_predecessor(node *head, int data)
{
  node* current = head;
  while(current->next)
  {
    if(current->next->data == data)
      return (void*)current;
    current = current->next;
  }
  return NULL;
}

void* return_successor(node *head, int data)
{ 
  node* current = head;
  while(current)
  { 
    if(current->data == data)
      return (void*)current->next;
    current = current->next;
  } 
  return NULL;
}

void* return_first_element(node *head)
{
  return (void*)head;
}

void* return_last_element(node *head)
{
  node* current = head;
  while(current)
  {
    if(current->next == NULL)
      return (void*)current;
    current=current->next;
  }
  return NULL;
}

void delete_alternate_nodes(node *head)
{
  node *current = head, *fast_ptr = NULL;
  while(current && current->next)
  {  
    fast_ptr = current->next->next;
    free(current->next);
    current->next = fast_ptr;
    current=current->next;
  }
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

  printf("Enter the data element on which you want to perform operations:");
  scanf("%d",&data);

  printf("Location of Successor of the element entered: %p\n",return_successor(head, data));
  printf("Predecessor of the element entered: %p\n",return_predecessor(head, data));
  printf("Location of first element: %p\n",return_first_element(head));
  printf("Location of last element: %p\n",return_last_element(head));

  delete_alternate_nodes(head);

  print_linked_list(head);

  return 0;
}
