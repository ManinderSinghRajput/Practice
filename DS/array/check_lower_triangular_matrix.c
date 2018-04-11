#include<stdio.h>

void sum_of_square_of_rows(int no_of_rows_of_matrix, int no_of_cols_of_matrix, int myarray[no_of_rows_of_matrix][no_of_cols_of_matrix])
{
  int i = 0, j = 0, sum_of_square = 0;
  for(i=0;i<no_of_rows_of_matrix;i++)
  {
    sum_of_square = 0;
    for(j=0;j<no_of_cols_of_matrix;j++)
      sum_of_square += myarray[i][j]*myarray[i][j];
    printf("%d\n",sum_of_square);
  }
  return;
}

int check_lower_triangular_matrix(int no_of_rows_of_matrix, int no_of_cols_of_matrix, int myarray[no_of_rows_of_matrix][no_of_cols_of_matrix])
{
  int i = 0, j = 0, true_flag = 1;
  for(i=0;i<no_of_rows_of_matrix;i++)
  {
    for(j=0;j<no_of_cols_of_matrix;j++)
      if(i<j)
	if(myarray[i][j] != 0)
	{
	  true_flag=0;
	  break;
	}
      else
	break;
  }
  return true_flag;
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
      printf("%3d ",myarray[i][j]);
    printf("\n");
  }
  printf("++++++++++++++++++++++++++++++++++++++++++++\n");
  if(check_lower_triangular_matrix(no_of_rows_of_matrix, no_of_cols_of_matrix, myarray))
    printf("True\n");
  else
    printf("False\n");
  //sum_of_square_of_rows(no_of_rows_of_matrix, no_of_cols_of_matrix, myarray);
  return 0;
}

