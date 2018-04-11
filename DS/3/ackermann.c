#include<stdio.h>

int ackermann(int x, int y)
{
  if(x == 0)
    return (y+1);
  else if(y == 0)
    return (ackermann(x -1, 1));
  else
    return (ackermann(x - 1, ackermann(x, y - 1)));
}

int main()
{
  int x = 0, y = 0;
  printf("Enter the value of x and y to compute Ackermann Function:");
  scanf("%d %d", &x, &y);
  printf("Value is: %d\n", ackermann(x,y));
}
