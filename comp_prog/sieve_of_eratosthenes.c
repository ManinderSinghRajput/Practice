#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>


int main()
{
  int x, i = 0, j = 0, sqroot = 0;
  printf("Enter the no. upto which you wish to find prime no: ");
  scanf("%d",&x);
  int is_prime[x+1];
  sqroot = (int)ceil(sqrt((double)x));
  printf("%d",sqroot);
  memset(is_prime, 1, sizeof(int)*x+1);
  for(i=2; i<=sqroot; i++)
  {
     for(j=i+i;j<x;j+=i)
       is_prime[j]=0;
  }

  //print results
  printf("Following are the prime no's required:\n");
  for(i=2;i<x;i++)
  {
    if(is_prime[i])
      printf("%d ",i);
  }
  printf("\n");
  return 0;
}
