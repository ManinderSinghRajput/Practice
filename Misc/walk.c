#include<stdio.h>

void main()
{
  int i = 0, j = 0;
  int no_of_tc = 0;
  int name = 0;
  scanf("%d",&no_of_tc);
  int expected[no_of_tc];
  for(i=0;i<no_of_tc;i++)
  {
    scanf("%d", &name);
    scanf("%d", &expected[name-1]);
  }
  for(i=0;i<no_of_tc;i++)
  {
    
    printf("%d %d\n",i+1,expected[i]);
  }
}
