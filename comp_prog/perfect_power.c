#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<math.h>

int main()
{
  int x, sqroot, i, power_of_i, count;
  
  printf("Enter the no which need to be analyzed: ");
  scanf("%d",&x);

  sqroot = (int)ceil(sqrt((double)x));

  for(i=2; i<=sqroot; i++)
  {
    power_of_i = i*i;
    count = 2;
    while(power_of_i <= x)
    {
      if(power_of_i == x)
      {
        printf("%d can be represented as %d raise to power %d.\n", x, i, count);
        return 0;
      }
      
      power_of_i *= i;
      count++;
    }
  }
  printf("No is not a perfect square.\n") ;
  return 0;
}

