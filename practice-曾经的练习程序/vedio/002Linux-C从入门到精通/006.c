#include<stdio.h>

int main()
{
	int i;
	int a[5] = {0,1,2,3,4};
	int *p = a;
	for(i=0; i<5; i++){
		printf("%d", *(a+i));
		printf("%d\n", *(p+i));
	}
	return 0;
}
