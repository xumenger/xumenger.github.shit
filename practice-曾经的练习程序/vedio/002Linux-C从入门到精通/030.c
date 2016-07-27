#include<stdio.h>
#include<unistd.h>
int main(void)
{
	char *envp[]={"PATH=/tmp","USER=root","STATUS=testing",NULL};
	char *argv_execv[]={"echo","excuted by execv",NULL};
	char *argv_execvp[]={"echo","executed by execvp",NULL};
	char *argv_execve[]={"env",NULL};
	if(fork()==0){
		if(execl("/bin/echo","echo","executed by execl",NULL))
			perror("Err on esecl\n");
	}
	if(fork()==0){
		if(execlp("echo","echo","executed by execlp",NULL))
			perror("Err on execlp\n");
	}
	if(fork()==0){
		if(execle("/usr/bin/env","env",NULL,envp))
			perror("Err on execle\n");
	}
	if(fork()==0){
		if(execv("/bin/echo",argv_execv))
			perror("Err on execv\n");
	}
	if(fork()==0){
		if(execvp("echo",argv_execvp))
			perror("Err on execvp\n");
	}
	if(fork()==0){
		if(execve("/usr/bin/env",argv_execve,envp));
	}
	return 0;
}
