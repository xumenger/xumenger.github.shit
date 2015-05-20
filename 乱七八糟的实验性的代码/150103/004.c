#include<stdio.h>

int main()
{
	int i = 0;
	while(i<=10){
		printf("%d%%\r", i);
	//	fflush(stdout);
		sleep(1);
		i++;
	}
	printf("\n");
	return 0;
}
