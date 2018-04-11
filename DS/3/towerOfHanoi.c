#include<stdio.h>

void towerOfHanoi(char from, char to, char other, int n)
{
  if(n == 1)
    printf("Move disk from %c to %c\n", from, to);
  else
  {
    towerOfHanoi(from, other, to, n-1);
    towerOfHanoi(from, to, other, 1);
    towerOfHanoi(other, to, from,  n-1);
  }
  return;
}

int main()
{
  int n;
  printf("Enter the no of disks:");
  scanf("%d",&n);
  if(n < 0)
    printf("Invalid Input");
  else
    towerOfHanoi('A', 'C', 'B', n);
  return(0);
}
