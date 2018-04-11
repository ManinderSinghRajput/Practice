#include <stdio.h>
#include <stdlib.h>
#define MYSTRING "Hello World\n"

void myprint();

void main()
{
  printf(MYSTRING);
  myprint();
}

void myprint()
{
  printf("myprint func");
  char *ptr = NULL;
  ptr = (char *) malloc(129*1024);
}
