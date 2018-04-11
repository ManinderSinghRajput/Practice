/*
 * Josephus Problem :
 * It consists of a group of soldiers surronded by a heavy enemy forces and there is only one horse to escape and hence only one soldier can escape. In order to determine which soldier will escape, they form a circle and pick up a number n from a hat. A name is also picked up from the hat. They start counting clockwise around the circle from a soldier whose name is picked up from the hat. And  the soldier on which counter count reaches n is removed from the circle. And the count again starts from the soldier on which count reaches n is removed from the circle. This process goes on till only one soldier is left. This soldier will take the horse and escape. Write a program to solve this problem. Input to your program is list of names of soldiers and number n and the output should be the name of the soldier left.
 *
 * General solution is :
 * josephus(n,k) = (josephus(n-1,k)+k-1) % n + 1
 * josephus(1,k) = 1
 * 
 */
//Implementation of Josephus problem using circular linked list

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

int josephus(node *head, int no_to_skip)
{
  node * current = head, *prev = NULL;
  int counter = 0;
  while(18)
  {
    counter++;

    if(counter==no_to_skip && prev)
    {
      prev->next = current->next;
      free(current);
      current = prev->next;
      counter=0;
    }
    else
    {
      prev = current;
      current = current->next;
    }

    if(current->next == current)
      break;

  }
  return current->data;
}

int main()
{
  int no_of_nodes, i, no_to_skip;
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

  current->next=head;

  printf("Enter the no of nodes to be skipped:");
  scanf("%d",&no_to_skip);

  printf("Node which will survive is :%d\n",josephus(head, no_to_skip));

  return 0;
}

