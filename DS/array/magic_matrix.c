#include<stdio.h>

void make_magic_matrix(int no, int myarray[no][no])
{
  int i = 0, j = no/2,val = 1;
  while(val <= no*no)
  {
    myarray[i][j] = val;
    if(val%no==0)
      i += 1;
    else
    {
      i = no+i-1;
      if(i>=no)
        i -= no;
      j = no+j-1;
      if(j>=no)
        j -= no;
    }
    val++;
  }
}

int main()
{
  int no = 0;
  printf("Enter the no of rows/cols of square matrix:");
  scanf("%d",&no);
  if(no%2==0)
  {
    printf("Entered value should be odd only\n");
    return -1;
  }
  int myarray[no][no];
  int i=0,j=0;
  for(i=0;i<no;i++)
    for(j=0;j<no;j++)
      myarray[i][j]=0;
  printf("++++++++++++++++++++++++++++++++++++++++++++\n");
  make_magic_matrix(no, myarray);
  for(i=0;i<no;i++)
  {
    for(j=0;j<no;j++)
      printf("%3d ",myarray[i][j]);
    printf("\n");
  }
  printf("++++++++++++++++++++++++++++++++++++++++++++\n");
  //sum_of_square_of_rows(no_of_rows_of_matrix, no_of_cols_of_matrix, myarray);
  return 0;
}

