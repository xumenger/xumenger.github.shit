#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	pid_t pid;
	int status;
	pid = vfork();
	if(pid < 0){
		printf("vfork error\n");
		exit(1);
	}
	if(pid == 0){
		execlp("ps", "ps", "-o", "pid,ppid,comm", NULL);
		/*
		 *错将"pid,ppid,comm"写成"pid, ppid, comm"，因为多写了空格导致运行出错
		 */
	}else{
		if(pid != wait(&status)){
			printf("wait error \n");
			exit(1);
		}
		printf("Done\n");
	}
	return 0;
}
