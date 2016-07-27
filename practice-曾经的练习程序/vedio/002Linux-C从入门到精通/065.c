#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void)
{
	int pid;
	int var;
	var = 88;
	if((pid = vfork())<0){
		printf("vfork error");
		exit(-1);
	}else if(pid == 0){
		var ++;
		//return 0;
		printf("fuck");
	}
	printf("pid = %d, var = %d\n", getpid(), var);
	exit(0);
}
