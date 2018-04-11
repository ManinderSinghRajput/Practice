#include<stdio.h>



/*
 * Using Euclid's algorithm:
 * It uses a division algorithm such as long division in combination with the observation that the gcd of two numbers also divides the 
 * difference. To compute gcd(48,18), divide 48 by 18 to get a quotient of 2 and remainder of 12. Then divide 18 by 12 to get a quotient of 1
 * and a remainder of 6. Then divide 12 by 6 to get a remainder of 0, which means that 6 is the gcd. Note that we ignored the quotient in each
 * step except to notice when the remainder reach 0, signalling that we had arrived at the answer.
 * Formally the algorithm can be described as:
 * gcd(a,0) = a
 * gcd(a,b) = gcd(b,a mod b),
 * where,
 * a mod b = a - b[a/b]
 * if the arguments are both greater than 0 then the algorithm can be written in more elementary terms as follows:
 * gcd(a,a) = a,
 * gcd(a,b) = gcd(a-b,b) , if(a>b)
 * gcd(a,b) = gcd(a,b-a) , if(a<b)
 */

int gcd(int first, int second)
{
  int remainder = 0;
  remainder  = first % second;
  if(remainder == 0)
    return second;
  return (gcd(second, remainder));
}


int main()
{
  int first = 0, second = 0, gcd_out = 0;
  printf("Enter two no's:");
  scanf("%d",&first);
  scanf("%d",&second);
  if( first == 0)
    gcd_out = second;
  else if(second == 0)
    gcd_out = first;
  else
    gcd_out = gcd(first,second);
  printf("GCD for values %d and %d is %d\n", first, second, gcd_out);
  return 0;
}

