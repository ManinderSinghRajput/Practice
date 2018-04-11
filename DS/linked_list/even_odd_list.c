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

void make_and_print_even_odd_list(node * head)
{
  node *current = head, *head_even = NULL, *head_odd = NULL, *current_odd = NULL, *current_even = NULL, *temp = NULL;

  while(current)
  {
    if(current->data % 2 == 0)
    {
      if(!head_even)
	head_even = current;
      else
	current_even->next = current;
      current_even = current;
    }
    else
    {
      if(!head_odd)
	head_odd = current;
      else
	current_odd->next = current;
      current_odd = current;
    }
    temp = current;
    current = current->next;
    temp->next = NULL;
  }
  
  printf("List of even nodes is:\n");
  print_linked_list(head_even);
  printf("List of odd nodes is:\n");
  print_linked_list(head_odd);

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

  make_and_print_even_odd_list(head);

  return 0;
}
