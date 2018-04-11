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


node * merge_sorted_list(node *node_of_first, node *node_of_second)
{
  node *merged_list = NULL, *current = NULL, *temp = NULL;

  while(node_of_first != NULL && node_of_second != NULL)
  {
    temp = malloc(sizeof(node));
    temp->next=NULL;
    if(node_of_first->data < node_of_second->data)
    {
      temp->data=node_of_first->data;
      node_of_first=node_of_first->next;
    }
    else
    {
      temp->data=node_of_second->data;
      node_of_second=node_of_second->next;
    }
    if(merged_list == NULL)
      merged_list = temp;
    else
      current->next = temp;

    current = temp;
  }

  if(node_of_first != NULL)
  {
    while(node_of_first)
    {
      temp = malloc(sizeof(node));
      temp->next=NULL;
      temp->data=node_of_first->data;
      node_of_first=node_of_first->next;
      if(merged_list == NULL)
	merged_list = temp;
      else
        current->next = temp;
    }
  }
  else
  {
    while(node_of_second)
    {
      temp = malloc(sizeof(node));
      temp->next=NULL;
      temp->data=node_of_second->data;
      node_of_second=node_of_second->next;
      if(merged_list == NULL)
	merged_list = temp;
      else
	current->next = temp;
      current = temp;
    }
  }
  return(merged_list);

}


int main()
{
  node *head_for_first = NULL, *head_for_second = NULL, *node = NULL, *current = NULL;
  int no_of_nodes_for_first = 0,no_of_nodes_for_second = 0,i = 0, data = 0;
  printf("Enter the no of nodes of list1:");
  scanf("%d",&no_of_nodes_for_first);
  printf("Enter the nodes of list1:");
  for(i=0;i<no_of_nodes_for_first;i++)
  {
    scanf("%d", &data);
    if(current && data < current->data)
    {
      printf("Please enter the sorted list\n");
      exit(-1);
    }
    node = malloc(sizeof(node));
    node->next=NULL;
    node->data=data;
    if(i==0)
      head_for_first=node;
    else
      current->next=node;
    current=node;
  }

  current=NULL;

  printf("Enter the no of nodes of list2:");
  scanf("%d",&no_of_nodes_for_second);
  printf("Enter the nodes of list2:");
  for(i=0;i<no_of_nodes_for_second;i++)
  {
    scanf("%d", &data);
    if(current && data < current->data)
    {
      printf("Please enter the sorted list\n");
      exit(-1);
    }
    node = malloc(sizeof(node));
    node->next=NULL;
    node->data=data;
    if(i==0)
      head_for_second=node;
    else
      current->next=node;
    current=node;
  }

  printf("\nEntered first list is:\n");
  print_linked_list(head_for_first);

  printf("\nEntered second list is:\n");
  print_linked_list(head_for_second);

  print_linked_list(merge_sorted_list(head_for_first, head_for_second));
  //remove_duplicate(head);
  //printf("\nLinked list with unique entries:\n");
  //print_linked_list(head);

  return 0;
}
