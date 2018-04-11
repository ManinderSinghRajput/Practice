#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node *next;
}node;

void print_list(node* head)
{
  node *current = head;
  while(current)
  {
    printf("%d\n",current->data);
    current=current->next;
  }
}

int get_loop_lenth(node *intersection)
{
  node * current = intersection;
  int counter=0;

  do
  {
    counter++;
    current = current->next;
  }
  while(current != intersection);
  return counter;
}

node *detect_loop_node(node *head)
{
  node  *slow_ptr = head, *fast_ptr = head;
  do
  {
    slow_ptr = slow_ptr->next;
    fast_ptr = fast_ptr->next->next;
  }while(slow_ptr && fast_ptr && fast_ptr->next && slow_ptr != fast_ptr);
  return slow_ptr;
}

int main()
{
  int no_of_nodes, i;
  node *head, *current, *temp_node;
  printf("Enter the no of nodes:");
  scanf("%d",&no_of_nodes);
   
  for(i=0;i<no_of_nodes;i++)
  {
    temp_node=malloc(sizeof(node));
    temp_node->data = i+1;
    temp_node->next = NULL;

    if(i==0)
      head = temp_node;
    else
      current->next = temp_node;

    current = temp_node;
  }

  print_list(head);

  current->next=head->next->next;

  printf("Length of detected loop is %d\n",get_loop_lenth(detect_loop_node(head)));

  return 0;
}

