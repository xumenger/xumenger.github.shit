#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void mythread(void)
{
	int i;
	for(i=0; i<3; i++){
		printf("This is a pthread.\n");
	}
	pthread_exit("Thank you for the CPU time.\n");
}

int main(void)
{
	pthread_t id;
	int i, ret;
	void *thread_result;
	ret = pthread_create(&id, NULL, (void *)mythread, NULL);
	if(ret != 0){
		printf("Create pthread error\n");
		exit(1);
	}
	for(i=0; i<3; i++){
		printf("This is the main process\n");
	}
	pthread_join(id, &thread_result);
	printf("Thread joined, it returned : %s", (char *)thread_result);
	

	return 0;
}
