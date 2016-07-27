#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	pid_t pid;
	if((pid=fork())==-1){
		printf("error\n");
		exit(1);
	}
	else if(pid == 0){
		printf("child process\n");
		printf("child exit");
		exit(1);
	}
	else{
		printf("parent process\n");
		printf("parent _exit");
		_exit(1);
	}

	return 0;
}
