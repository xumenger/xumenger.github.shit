#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(void)
{
	pid_t pc, pr;
	if((pc=fork())==-1){
		printf("fork error\n");
		exit(1);
	}else if(pc==0){
		sleep(10);
		exit(1);
	}
	
	do{
		pr = waitpid(pc, NULL, WNOHANG);
		if(pr == 0){
			printf("No child exited\n");
			sleep(1);
		}
	}while(pr==0);

	if(pr == pc){
		printf("successfully\n");
	}else{
		printf("error fucked\n");
	}
	return 0;
}
