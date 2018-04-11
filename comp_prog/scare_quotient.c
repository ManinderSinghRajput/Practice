#include<stdio.h>

int main()
{
  int test_cases=0;
  scanf("%d",&test_cases);
  while(test_cases)
  {
    int no_of_days;
    scanf("%d",&no_of_days);
    int i = 0, j = 0;
    int no_of_choclates[no_of_days];
    for(i=0;i<no_of_days;i++)
      scanf("%d",&no_of_choclates[i]);
    for(i=0;i<no_of_days;i++)
    {
      static int max = 0;
      int score_q = 0;
      int j = 0;
      if(no_of_choclates[i] > max && max != 0)
      {
	printf("%d ", i);
	max = no_of_choclates[i];
      }
      else
      {
        for(j=i;no_of_choclates[j]<=no_of_choclates[i] && j>=0;j--)
	  score_q++;
        printf("%d ",score_q);
      }
    }
    printf("\n");
    test_cases--;
  }
  return 0;
}







