#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<sys/types.h>

void sigroutine(int dunno)
{
	switch(dunno){
		case 1:
			printf("Capture SIGHUP signal, the signal number is %d\n", dunno);
			break;
		case 2:
			printf("Capture SIGINT signal, the signal number is %d\n", dunno);
			break;
		case 3:
			printf("Capture SIGQUIT signal, the signal number is %d\n", dunno);
			break;
	}
	return ;
}

int main(void)
{
	printf("process ID id %d\n", getpid());
	if(signal(SIGHUP, sigroutine)==SIG_ERR){
		printf("Could not register signal handler for SIGHUP\n");
	}
	if(signal(SIGINT, sigroutine)==SIG_ERR){
		printf("Could not register signal handler for SIGINT\n");

	}
	if(signal(SIGQUIT, sigroutine)==SIG_ERR){
		printf("Could not register signal handler for SIGQUIT\n");
	}
	while(1)
		sleep(1);

	return 0;
}
