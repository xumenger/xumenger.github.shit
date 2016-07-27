#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main(void)
{
	pid_t pc, pr;
	if((pc=fork())<0){
		printf("fork error 1\n");
		exit(1);
	}
	else if(pc == 0){
		printf("This is child process with pid of %d\n", getpid());
		sleep(10);
	}
	else{
		pr = wait(NULL);
		printf("I catch a child process with pid of %d\n", pr);
	}
	exit(0);
}
