#include<stdio.h>

void remove_dup_entries(int myarray[], int * no_of_elements_of_array)
{
  int i = 0, j = 0, k = 0;
  for(i=0;i<*no_of_elements_of_array;i++)
  {
    for(j=i+1;j<*no_of_elements_of_array;)
    {
      if(myarray[i] == myarray[j])
      {
	for(k=j;k<*no_of_elements_of_array - 1;k++)
	  myarray[k]=myarray[k+1];
	(*no_of_elements_of_array)--;
      }
      else
	j++;
    }
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
  remove_dup_entries(myarray, &no_of_elements_of_array);
  printf("==========================================================\n");
  for(i=0;i<no_of_elements_of_array;i++)
    printf("%d ",myarray[i]);
  printf("\n");
  return 0;
}

