#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	pid_t pid;
	int status, i = -1;
	pid = fork();
	if(pid < 0){
		printf("fork error.\n");
		exit(1);
	}
	if(pid == 0){
		printf("This is the child process.\n");
	}else{
		sleep(1);
		printf("This is the parent process.\n");
		printf("Waiting for child process...\n");
		if(pid != wait(&status)){
			printf("wait error.\n");
			exit(1);
		}
		if(~WIFEXITED(status)){
			i = WEXITSTATUS(status);
		}
		printf("chils's pid = %d\n", pid);
		printf("exit status = %d\n", i);
	}
	return 0;
}
