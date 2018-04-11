#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
  unsigned int i , j, no_of_countries, no_of_ranges, lb, ub, range_counter;
  short do_not_break_flag, test_cases, yes_flag=0, usable_flag;
  char *used;

  scanf("%hi", &test_cases);
  for(i=0;i<test_cases;i++)
  {
    yes_flag=1;
    scanf("%d",&no_of_countries);
    scanf("%d",&no_of_ranges);
    used=malloc(sizeof(char)*no_of_countries);
    memset(used,0,sizeof(char)*no_of_countries);
    for(j = 0;j < no_of_ranges; j++)
    {
      usable_flag=0;
      do_not_break_flag=1;
      scanf("%d", &lb);
      scanf("%d", &ub);
      printf("%d ",lb%no_of_countries);
      printf("%d\n",ub%no_of_countries);
      range_counter = lb%no_of_countries;
//2 3 0 1
      while(do_not_break_flag && yes_flag)
      {
	if(range_counter == ub%no_of_countries)
	  do_not_break_flag=0;
	if(used[range_counter] == 0)
	{
	  usable_flag=1;
	  used[range_counter]=1;
	  break;
	}
	range_counter++;
	if(range_counter==no_of_countries)
	  range_counter -= no_of_countries;
      }
      if(!usable_flag)
	yes_flag=0;
    }
    free(used);
    if(yes_flag)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return;
  
}
