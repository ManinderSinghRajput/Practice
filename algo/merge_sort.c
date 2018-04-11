#include<stdio.h>

void print_array_elements(int myarray[], int no_of_elements_of_array)
{
  int i;
  for(i=0;i<no_of_elements_of_array;i++)
    printf("%d ",myarray[i]);
  printf("\n");
  return;
}

void merge_sort_internal(int myarray[], int lb, int m, int ub)
{
  int count_a = m - lb + 1, count_b = ub - m;
  int counter_a = 0, counter_b = 0;
  int i, k = lb;
  int a[count_a] , b[count_b]; 

  for(i=0;i<count_a;i++)
    a[i]=myarray[lb + i];
  for(i=0;i<count_b;i++)
    b[i]=myarray[m+1+i];

  while(counter_a < count_a && counter_b < count_b)
  {
    if(a[counter_a] <= b[counter_b])
    {
      myarray[k] = a[counter_a];
      counter_a++;
    }
    else
    {
      myarray[k] = b[counter_b];
      counter_b++;
    }
    k++;
  }
  while(counter_a < count_a)
  {
    myarray[k] = a[counter_a];
    k++;
    counter_a++;
  }
  while(counter_b < count_b)
  {
    myarray[k] = b[counter_b];
    k++;
    counter_b++;
  }

  return;
}

void merge_sort(int myarray[], int start, int end)
{
  if(start < end)
  {
    int m = start + (end - start) / 2;
    merge_sort(myarray, start, m);
    merge_sort(myarray, m+1, end);
    merge_sort_internal(myarray, start, m, end);
  }
  return;
}


int main()
{
  int no_of_elements_of_array = 0, item=0, na, nb;
  printf("Enter the no of array elements:");
  scanf("%d",&no_of_elements_of_array);
  int myarray[no_of_elements_of_array];

  int i=0;
  printf("Enter the array elements:");
  for(i=0;i<no_of_elements_of_array;i++)
    scanf("%d",&myarray[i]);

  printf("Entered array elements of array:");
  print_array_elements(myarray, no_of_elements_of_array);

  merge_sort(myarray, 0, no_of_elements_of_array-1);

  printf("Merge sorted array is:");
  print_array_elements(myarray, no_of_elements_of_array);

  return 0;
}
