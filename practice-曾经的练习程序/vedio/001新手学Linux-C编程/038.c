#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#define TIME_OUT 5

void sig_handler(int sig)
{
	printf("Receive signal : SIGINT\n");
	return ;
}

int main()
{
	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set, SIGINT);
	signal(SIGINT, sig_handler);

	while(1){
		sigprocmask(SIG_BLOCK, &set, NULL);
		printf("SIGINT is bolcked,\n");
		sleep(TIME_OUT);
		sigprocmask(SIG_UNBLOCK, &set, NULL);
		printf("SIGINT is unblocked,\n");
		sleep(TIME_OUT);
	}

	return 0;
}
