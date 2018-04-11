#include<stdio.h>

void sum_of_square_of_cols(int no_of_rows_of_matrix, int no_of_cols_of_matrix, int myarray[no_of_rows_of_matrix][no_of_cols_of_matrix])
{
  int i = 0, j = 0, sum_of_square = 0;
  for(i=0;i<no_of_cols_of_matrix;i++)
  {
    sum_of_square = 0;
    for(j=0;j<no_of_rows_of_matrix;j++)
      sum_of_square += myarray[j][i]*myarray[j][i];
    printf("%d\n",sum_of_square);
  }
  return;
}

int main()
{
  int no_of_rows_of_matrix = 0, no_of_cols_of_matrix = 0;
  printf("Enter the no of rows:");
  scanf("%d",&no_of_rows_of_matrix);
  printf("Enter the no of cols:");
  scanf("%d",&no_of_cols_of_matrix);
  int myarray[no_of_rows_of_matrix][no_of_cols_of_matrix];
  int i=0,j=0;
  for(i=0;i<no_of_rows_of_matrix;i++)
    for(j=0;j<no_of_cols_of_matrix;j++)
      scanf("%d",&myarray[i][j]);
  printf("++++++++++++++++++++++++++++++++++++++++++++\n");
  for(i=0;i<no_of_rows_of_matrix;i++)
  {
    for(j=0;j<no_of_cols_of_matrix;j++)
      printf("%d ",myarray[i][j]);
    printf("\n");
  }
  printf("++++++++++++++++++++++++++++++++++++++++++++\n");
  sum_of_square_of_cols(no_of_rows_of_matrix, no_of_cols_of_matrix, myarray);
  return 0;
}

