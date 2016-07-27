#include<stdio.h>

int main(void)
{
	int i = 2;
	printf("i=%d\n", i);
	printf("i+=(i++)\n");
	i+=i++;
	printf("i=%d\n", i);

	return 0;
}
