#include <stdio.h>

extern void _exit(register int);

int _start()
{
 printf("Hello\n");
 _exit(0);
}
