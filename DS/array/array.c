#include<stdio.h>

int main()
{
  int no_of_elements_of_array = 0;
  scanf("%d",&no_of_elements_of_array);
  int myarray[no_of_elements_of_array];
  int i=0;
  for(i=0;i<no_of_elements_of_array;i++)
    scanf("%d",&myarray[i]);
  for(i=0;i<no_of_elements_of_array;i++)
    printf("%d ",myarray[i]);
  printf("\n");
  return 0;
}

