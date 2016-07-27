#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
void sig_handler(int sig)
{
	switch(sig){
		case 2:
			printf("Received signal : SIGINT\n");
			break;
		case 3:
			printf("Received signal : SIGQUIT\n");
			break;
		default:
			;
	}
	return ;
}

int main()
{
	printf("PID : %d\n", getpid());
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);

	return 0;
}
