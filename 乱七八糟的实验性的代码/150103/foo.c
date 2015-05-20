#include<stdio.h>

void foo(void);

long a = 0;
int main()
{
	foo();
	return 0;
}

void foo()
{
	printf("foo() %ld\n", a);
	a++;
	foo();
}
