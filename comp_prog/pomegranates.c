#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
  int length_of_interval = 0, number_of_intervals = 0, no_of_piles = 0, i = 0, j = 0;
  
  scanf("%d",&length_of_interval);
  scanf("%d",&number_of_intervals);
  scanf("%d",&no_of_piles);
  
  int no_of_pomer[no_of_piles];
  int phase_one_array[no_of_piles-length_of_interval+1];
  int max=0,max_index=-1, total_sum=0;

  for(i=0;i<no_of_piles;i++)
  {
    scanf("%d",&(no_of_pomer[i]));
  }

  for(i=0;i<=no_of_piles-length_of_interval;i++)
  {
    phase_one_array[i]=0;
    for(j=0;j<length_of_interval; j++)
      phase_one_array[i]+=no_of_pomer[i+j];
    if(max<phase_one_array[i])
    {
      max=phase_one_array[i];
      max_index=i;
    }
  }
  
  total_sum += phase_one_array[max_index];
  for(i=0;i<length_of_interval;i++)
  {
    if(max_index-i >= 0)
      phase_one_array[max_index-i] = -1;
    if(max_index+i<=no_of_piles-length_of_interval)
    phase_one_array[max_index+i] = -1;
  }
  
  
  for(j=1;j<number_of_intervals; j++)
  {
    max=0;
    for(i=0;i<=no_of_piles-length_of_interval;i++)
    {
      if(max<phase_one_array[i])
      {
        max=phase_one_array[i];
        max_index=i;
      }
    } 
    if(phase_one_array[max_index] != -1)
      total_sum += phase_one_array[max_index];
    for(i=0;i<length_of_interval;i++)
    { 
      if(max_index-i >= 0)
        phase_one_array[max_index-i] = -1;
      if(max_index+i<=no_of_piles-length_of_interval)
        phase_one_array[max_index+i] = -1;
    }
  }

  printf("%d\n",total_sum);

  /*for(i=0;i<=no_of_piles-length_of_interval;i++)
  {
    printf("%d\n",phase_one_array[i]);
  }*/
  

  /*for(i=0;i<no_of_piles;i++)
  {
     printf("%d\n",(no_of_pomer[i]));
  }*/
}
