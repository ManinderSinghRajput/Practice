#include<stdio.h>

void check_for_saddle(int no_of_rows_of_matrix, int no_of_cols_of_matrix, int myarray[no_of_rows_of_matrix][no_of_cols_of_matrix])
{
  int i = 0, j = 0, is_saddle = 1;
  unsigned int min = -1;
  int temp_row = -1, temp_col = -1;

  for(i=0;i<no_of_rows_of_matrix;i++)
  {
    min = -1;
    is_saddle = 1;
    for(j=0;j<no_of_cols_of_matrix;j++)
    {
      if(min>myarray[i][j])
      {
	min = myarray[i][j];
	temp_row = i;
	temp_col = j;
      }
    }
    for(j=0;j<no_of_rows_of_matrix;j++)
    {
      if(myarray[temp_row][temp_col]<myarray[j][temp_col])
      {
	is_saddle=0;
	break;
      }
    }
    if(is_saddle != 0)
      break;
  }
  if(is_saddle)
    printf("Saddle point exists at row %d and col %d\n",temp_row + 1, temp_col + 1);
  else
    printf("No Saddle point exists");

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
      printf("%3d ",myarray[i][j]);
    printf("\n");
  }
  printf("++++++++++++++++++++++++++++++++++++++++++++\n");
  check_for_saddle(no_of_rows_of_matrix, no_of_cols_of_matrix, myarray);
  return 0;
}

