#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<sys/types.h>
#include<limits.h>

#define BUFSIZE PIPE_BUF

int main(void)
{
	int fd[2];
	char buf[BUFSIZE] = "hello my bro\n";
	pid_t pid;
	int len;
	if((pipe(fd))<0){
		printf("error1\n");
		exit(1);
	}
	if((pid = fork())<0){
		printf("error2\n");
		exit(1);
	}
	else if(pid == 0){
		close(fd[0]);
		write(fd[1], buf, strlen(buf));
		exit(1);
	}
	if((pid = fork())<0){
		printf("error3\n");
		exit(1);
	}
	else if(pid > 0){
		close(fd[0]);
		close(fd[1]);
		exit(1);
	}
	else{
		close(fd[1]);
		len = read(fd[0], buf, BUFSIZE);
		write(STDOUT_FILENO, buf, len);
		exit(1);
	}
	return 0;
}
