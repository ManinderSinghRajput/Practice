#include<stdio.h>
#include<stdlib.h>

typedef struct Tree_node{
	int data;
	struct Tree_node *left;
	struct Tree_node *right;
}Tree_node;

void insert(Tree_node **node, int data)
{
  Tree_node *temp = NULL;
  if(!(*node))
  {
    temp = (Tree_node *)malloc(sizeof(Tree_node));
    if(!temp){
      printf("Unable to assign memory to new node. Exiting....");
      exit(-1);
    }
    temp->left = temp->right = NULL;
    temp->data = data; 
    *node = temp;
  }
  else
  {
    if(data <= (*node)->data)
      insert(&(*node)->left,data);
    else
      insert(&(*node)->right,data);
  }
}

void print_inorder(Tree_node *node){
  if(node){
    if(node->left)
      print_inorder(node->left);
    printf("%d ",node->data);
    if(node->right)
      print_inorder(node->right);
  }
}

void print_preorder(Tree_node *node){
  if(node){
    printf("%d ",node->data);
    if(node->left)
      print_preorder(node->left);
    if(node->right)
      print_preorder(node->right);
  }
}


void print_postorder(Tree_node *node){
  if(node){
    if(node->left)
      print_postorder(node->left);
    if(node->right)
      print_postorder(node->right);
    printf("%d ",node->data);
  }
}

int main(){
  Tree_node *root = NULL;
  int no_of_nodes = 0;
  int val = 0;

  printf("Enter the total no of nodes of trees:");
  scanf("%d",&no_of_nodes);
  if(!no_of_nodes){
    printf("Empty tree. Returning.\n");
    return -1;
  }
  printf("Enter the nodes values newline seprated:");
  while(no_of_nodes)
  {
    scanf("%d",&val);
    insert(&root,val);
    no_of_nodes--;
  }
  printf("Preorder Traversal: ");
  print_preorder(root);
  printf("\n");
  printf("Inorder Traversal: ");
  print_inorder(root);
  printf("\n");
  printf("Postorder Traversal: ");
  print_postorder(root);
  printf("\n");
  return 0;
}
