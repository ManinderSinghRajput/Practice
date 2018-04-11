#include "heymath.h"
#include <stdio.h>
#include <unistd.h>
 
int main()
{
  int x= 10, y = 20;
  printf("\n%d + %d = %d\n", x, y, add(x, y));
  printf("\n%d - %d = %d\n", x, y, sub(x, y));
  sleep(30);
  return 0;
}
