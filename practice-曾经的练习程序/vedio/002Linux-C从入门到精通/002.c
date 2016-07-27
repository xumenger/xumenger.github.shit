#include<stdio.h>

int max(int x, int y)
{
	int z;
	z = x>y ? x:y;
	return z;
}

int main()
{
	extern A, B;
	int C = max(A, B);
	printf("max(%d, %d)=%d\n", A, B, C);
	return 0;
}
int A=13, B=14;
