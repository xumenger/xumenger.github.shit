#include<stdio.h>

int max(int a, int b)
{
	int z;
	z = a>b ? a:b;
	return z;
}

int main()
{
	int (*fun)(int , int );
	fun = max;	/*等价的方式是fun = &max*/
	int a = 10;
	int b = 11;
	int z = (*fun)(a, b);/*等价的方式是int z = fun(a, b);*/
	printf("%d\n", z);
	return 0;
}
