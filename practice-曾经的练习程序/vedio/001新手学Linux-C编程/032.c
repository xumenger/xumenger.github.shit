#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#define MAXFILE 1024

int main()
{
	pid_t pid;
	FILE * fp;
	int i;
	char *buf = "This is a Dameon\n";
	pid = fork();
	if(pid < 0){
		printf("fork error\n");
		exit(1);
	}
	if( pid > 0){
		exit(0);
	}
	setsid();
	for(i=0; i<MAXFILE; i++)
		close(i);
	chdir("/tmp");
	umask(0);
	signal(SIGCHLD, SIG_IGN);
	while(1){
		fp = fopen("/tmp/test", "a");
		if(fp == NULL){
			perror("Open test failed");
			exit(1);
		}
		fputs(buf, fp);
		fclose(fp);
		sleep(1);
	}
}
