#include<stdio.h>

void dec_to_bin(int n)
{
  if(n < 2)
    printf("%d",n);
  else
  {
    dec_to_bin(n/2);
    printf("%d",n%2);
  }
  return;
}


int main()
{

  int n = 0;
  printf("Enter the decimal no to be converted:");
  scanf("%d",&n);
  if(n < 0)
    printf("Invalid Input");
  else
    dec_to_bin(n);
  printf("\n");
  return(0);
}
