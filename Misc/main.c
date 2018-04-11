#include<stdio.h>
#include<unistd.h>

void main()
{
  int i = 0;
  int j = 0;
  for(i=0;i<4;i++)
  {
    fork();
    printf("Hello %d\n",j++);
  }
  return;
}

