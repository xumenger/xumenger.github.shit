#include<stdio.h>
#include<signal.h>

void SignHandler(int iSignNum)
{
	printf("Capture signal number : %d\n", iSignNum);
}

int main(void)
{
	signal(SIGINT, SignHandler);
	while(1)
		sleep(1);
	return 0;
}
