#include<stdio.h>

void binary_search(int myarray[], int no_of_elements_of_array, int item)
{
  int lb = 0;
  int ub = no_of_elements_of_array - 1;
  int mid = (lb+ub)/2;
  while(lb <= ub && myarray[mid] != item)
  {
    if(myarray[mid]<item)
      lb=mid+1;
    else
      ub= mid-1;
    mid = (lb + ub) /2;
  }
  if(lb>ub)
    printf("Entered item is not in the array.\n");
  else
    printf("Entered item is at the index %d.\n",mid+1);
  return;
}

int main()
{
  int no_of_elements_of_array = 0, item=0;
  printf("Enter the no of array elements:");
  scanf("%d",&no_of_elements_of_array);
  int myarray[no_of_elements_of_array];
  int i=0;
  printf("Enter the sorted array elements(ascending):");
  for(i=0;i<no_of_elements_of_array;i++)
    scanf("%d",&myarray[i]);
  printf("Entered array elements is:");
  for(i=0;i<no_of_elements_of_array;i++)
    printf("%d ",myarray[i]);
  printf("\n");
  printf("Enter the element to be searched:");
  scanf("%d", &item);

  binary_search(myarray, no_of_elements_of_array, item);

  return 0;
}
