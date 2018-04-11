#include <stdio.h>

int fibnocci(int n, int val, int prev)
{
  int ret=0;
  if( n == 1 ) return val;
  if( n == 0 ) return prev;
  ret = fibnocci(n - 1, val+prev, val);
  printf("%d\n",ret);
  return ret;
}

int _start()
{
  int n = 2;
  printf("%d\n", fibnocci(n,1,0));
  return 0;
}
