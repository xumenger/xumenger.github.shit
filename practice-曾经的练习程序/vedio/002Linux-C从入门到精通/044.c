#include<signal.h>
#include<stdio.h>
#include<unistd.h>

void SignHandler(int iSignNo)
{
	printf("fuck world %d\n", iSignNo);
}

int main(void)
{
	signal(SIGALRM, SignHandler);
	alarm(3);
	printf("Before pause()\n");
	pause();
	printf("After pause()\n");
	return 0;
}
