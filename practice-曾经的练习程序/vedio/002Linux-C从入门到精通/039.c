#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>

int main(void)
{
	printf("Hello, I like Linux C programs\n");
	if(raise(SIGABRT)==-1){
		printf("raise failed\n");
		exit(1);
	}
	printf("Hello, fuck\n");
	return 0;
}
