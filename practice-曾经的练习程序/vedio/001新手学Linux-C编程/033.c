#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#define BUFSIZE 256
int main()
{
	pid_t pid;
	int fd[2];
	int status;
	char buf[BUFSIZE] = "Hello World!\n";
	if(pipe(fd) < 0){
		printf("pipe error.\n");
		exit(1);
	}
	pid = fork();
	if(pid < 0){
		printf("fork error.\n");
		exit(1);
	}
	if(pid == 0){
		close(fd[0]);
		write(fd[1], buf, sizeof(buf));
	}else{
		close(fd[1]);
		read(fd[0], buf, sizeof(buf));
		printf("Received message from child process:\n%s", buf);
		if(pid != wait(&status)){
			/*
			 * 等待子进程的结束
			 */
			printf("wait error.\n");
			exit(1);
		}
	}
	return 0;
}
