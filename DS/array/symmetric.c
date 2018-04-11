#include<stdio.h>

int is_symmetric(float *myarray, int no)
{
  int i = 0, j = 0, true_flag = 1;
  for(i=0;i<no;i++)
    for(j=0;j<no;j++)
    {
      if(j < i)
      {
	if(*(myarray+(no*i)+j) != *(myarray+(no*j)+i))
	{
	  true_flag=0;
	  break;
	}
      }
      else
	break;
      if(true_flag == 0)
	break;
    }

  return true_flag;
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
  if(is_symmetric(myarray[0], no))
    printf("True\n");
  else
    printf("False\n");
  return 0;
}

