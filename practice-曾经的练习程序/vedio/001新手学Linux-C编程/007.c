#include<stdio.h>

void printinfo(){
	printf("1+2+3+...+10=");
}

int main()
{
	int i;
	int sum;
	for(i=1; i<=10; i++){
		sum += i;
	}

	printinfo();
	printf("%d\n", sum);

	return 0;
}
