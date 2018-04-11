#include<stdio.h>


void rev_arr_entries(int myarray[], int no_of_elements_of_array)
{
  int i = 0;
  for(i=0;i<no_of_elements_of_array/2;i++)
  {
    myarray[no_of_elements_of_array-i-1] += myarray[i];
    myarray[i] = myarray[no_of_elements_of_array-i-1] - myarray[i];
    myarray[no_of_elements_of_array-i-1] = myarray[no_of_elements_of_array-i-1] - myarray[i];
  }
  return;
}

int main()
{
  int no_of_elements_of_array = 0;
  scanf("%d",&no_of_elements_of_array);
  int myarray[no_of_elements_of_array];
  int i=0;
  for(i=0;i<no_of_elements_of_array;i++)
    scanf("%d",&myarray[i]);
  rev_arr_entries(myarray, no_of_elements_of_array);
  printf("==========================================================\n");
  for(i=0;i<no_of_elements_of_array;i++)
    printf("%d ",myarray[i]);
  printf("\n");
  return 0;
}

