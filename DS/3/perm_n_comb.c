#include<stdio.h>


int factorial(int n)
{
  if(n == 0)
    return 1;
  else
    return(n * factorial(n-1));
}

int permutation(int n, int r)
{
  return(factorial(n)/factorial(n - r));
}

int combination(int n, int r)
{
  return(factorial(n)/(factorial(r)*factorial(n - r)));
}

int main()
{
  int n = 0, no = 0, r = 0;
  do
  {
    printf("Choose the option:\n");
    printf("1.Factorial\n");
    printf("2.Permutation\n");
    printf("3.Combination\n");
    scanf("%d",&n);
    switch(n)
    {
      case 1:
	printf("Enter the no:");
	scanf("%d",&no);
	if(no < 0)
	  printf("Invalid no entered.");
	else
          printf("Factorial of the no %d is %d\n", no, factorial(no));
        break;
      case 2:
	printf("Enter the value of n and r:");
	scanf("%d %d",&no, &r);
	if(no < 0 || r < 0)
	  printf("Enter value of n or r is invalid.\n");
	else
          printf("Value of [%d P %d] is %d\n", no, r, permutation(no, r));
        break;
      case 3:
	printf("Enter the value of n and r:");
	scanf("%d %d",&no, &r);
	if(no < 0 || r < 0)
	  printf("Enter value of n or r is invalid.\n");
	else
	  printf("Value of [%d C %d] is %d\n", no, r, combination(no, r));
        break;
      default :
        printf("Invalid choice, please enter the valid choice\n");
    }
  }while(n > 3 || n < 1);
  return(0);
}

