#include<stdio.h>

int main()
{
  int no_of_elements_of_array = 0, item=0;
  printf("Enter the no of array elements:");
  scanf("%d",&no_of_elements_of_array);
  int myarray[no_of_elements_of_array];
  int i=0;
  printf("Enter the array elements:");
  for(i=0;i<no_of_elements_of_array;i++)
    scanf("%d",&myarray[i]);
  printf("Entered array elements is:");
  for(i=0;i<no_of_elements_of_array;i++)
    printf("%d ",myarray[i]);
  printf("\n");
  printf("Enter the element to be searched:");
  scanf("%d",&item);
  for(i=0;i<no_of_elements_of_array;i++)
    if(myarray[i]==item)
      printf("Entered item is at index: %d\n", i+1);
  return 0;
}
