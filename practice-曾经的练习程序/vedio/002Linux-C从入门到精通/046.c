#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<sys/types.h>
#include<limits.h>

#define BUFSIZE PIPE_BUF

void err_quit(char *msg)
{
	printf(msg);
	exit(1);
}

int main(void)
{
	int fd[2];
	char buf[BUFSIZE] = "hell my child\n";
	pid_t pid;
	int len;
	if((pipe(fd))<0)
		err_quit("pipe failed\n");
	if((pid=fork())<0)
		err_quit("fork error\n");
	else if(pid > 0){
		close(fd[0]);
		write(fd[1], buf, strlen(buf));
		exit(1);
	}
	else{
		close(fd[1]);
		len = read(fd[0], buf, BUFSIZE);
		if(len<0)
			err_quit("process failed when read a pipe\n");
		else
			write(STDOUT_FILENO, buf, len);
		exit(1);
	}
	return 0;
}
