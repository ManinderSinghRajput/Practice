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

void remove_duplicate(node *head)
{
  node *current = head;
  node *tmp = NULL;
  node *dup = NULL;

  while(current != NULL && current->next != NULL)
  {
    tmp = current;
    while(tmp->next != NULL)
    {
      if(current->data == tmp->next->data)
      {
	dup = tmp->next;
	tmp->next = tmp->next->next;
	free(dup);
      }
      else
	tmp = tmp->next;
    }
    current = current->next;
  }
  return;
}

void remove_duplicate_by_using_array(node *head)		//not working
{
  int present[1000] = {0};
  node *current = head;
  node *tmp = NULL;
  while(current)
  {
    if(present[current->data] == 1)
    {
      tmp->next = current->next;
      free(current);
      current=tmp->next;
    }
    else
    {
      tmp = current;
      current = current->next;
      present[current->data] = 1;
    }
  }
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

  remove_duplicate(head);

  printf("\nLinked list with unique entries:\n");
  print_linked_list(head);

  return 0;
}
