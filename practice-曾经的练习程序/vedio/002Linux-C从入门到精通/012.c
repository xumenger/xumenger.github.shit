#include<stdio.h>
#include<stdlib.h>
int calculate(int x, int y);
int main(void)
{
	int num_1, num_2, result;
	while(1)
	{
		printf("Enter two integer, or use 0 0 to exit:");
		scanf("%d %d", &num_1, &num_2);
		if(num_1==0 && num_2==0)
			exit(0);
		result = calculate(num_1, num_2);
		printf("The result is:%d\n", result);
	}
	return 0;
}
int calculate(int x, int y)
{
	int res;
	res = x*x + y*y;
	return res;
}
