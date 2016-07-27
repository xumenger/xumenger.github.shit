#include<stdio.h>

fun(int a)
{
	auto b=0;
	static c=3;
	b++;
	c++;
	return(a+b+c);
}

int main()
{
	int a = 2, i;
	for(i=0; i<3; i++){
		printf("%d ", fun(a));
	}
	printf("\n");
	return 0;
}
