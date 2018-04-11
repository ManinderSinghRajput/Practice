#include<stdio.h>

void transpose_square_matrix(float *myarray, int no)
{
  int i = 0, j = 0;
  for(i=0;i<no;i++)
    for(j=0;j<no;j++)
    {
      if(i < j)
      {
	*(myarray+(no*i)+j) += *(myarray+(no*j)+i);
	*(myarray+(no*j)+i) = *(myarray+(no*i)+j) - *(myarray+(no*j)+i);
	*(myarray+(no*i)+j) = *(myarray+(no*i)+j) - *(myarray+(no*j)+i);
      }
    }

  return;
}

int main()
{
  int no = 0;
  printf("Enter the no of rows/cols of square matrix:");
  scanf("%d",&no);
  float myarray[no][no];
  int i=0,j=0;
  for(i=0;i<no;i++)
    for(j=0;j<no;j++)
      scanf("%f",&myarray[i][j]);
  printf("++++++++++++++++++++++++++++++++++++++++++++\n");
  for(i=0;i<no;i++)
  {
    for(j=0;j<no;j++)
      printf("%f ",myarray[i][j]);
    printf("\n");
  }
  printf("++++++++++++++++++++++++++++++++++++++++++++\n");
  transpose_square_matrix(myarray[0], no);
  printf("++++++++++++++++++++++++++++++++++++++++++++\n");
  for(i=0;i<no;i++)
  {
    for(j=0;j<no;j++)
      printf("%f ",myarray[i][j]);
    printf("\n");
  }
  //sum_of_square_of_rows(no_of_rows_of_matrix, no_of_cols_of_matrix, myarray);
  return 0;
}

