#include<stdio.h>

void print_array_elements(int myarray[], int no_of_elements_of_array)
{
  int i;
  for(i=0;i<no_of_elements_of_array;i++)
    printf("%d ",myarray[i]);
  printf("\n");
  return;
}

void bubble_sort(int myarray[], int no_of_elements_of_array)
{
  int i = 0, j = 0, swap_done=0;
  for(i=0;i<no_of_elements_of_array-1;i++)
  {
    for(j=0;j<no_of_elements_of_array-i-1;j++)
    {
      if(myarray[j] > myarray[j+1])
      {
	myarray[j] = myarray[j] + myarray[j+1];
	myarray[j+1] = myarray[j] - myarray[j+1];
	myarray[j] = myarray[j] - myarray[j+1];
	swap_done=1;
      }
    }
    if(!swap_done)
      break;
    else
      swap_done=0;
  }
}

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
  print_array_elements(myarray, no_of_elements_of_array);

  bubble_sort(myarray, no_of_elements_of_array);

  printf("Sorted array elements are:");
  print_array_elements(myarray, no_of_elements_of_array);

  return 0;
}
