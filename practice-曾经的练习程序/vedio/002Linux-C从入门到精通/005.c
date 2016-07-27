#include<stdio.h>

int main()
{
	int i = 0;
	int a[5] = {1,2,3,4,5};
	int *p = a;
	for(i=0; i<5; i++)
		printf("%d\n", p[i]);

	return 0;
}
