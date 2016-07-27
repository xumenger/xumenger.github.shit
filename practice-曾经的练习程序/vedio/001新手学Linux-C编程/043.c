#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
pthread_mutex_t mutex;
int x;

void thread1(void)
{
	while(x>0){
		pthread_mutex_lock(&mutex);
		printf("Thread 1 is running : x=%d\n", x);
		x--;
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
	pthread_exit(NULL);
}

void thread2(void)
{
	while(x>0){
		pthread_mutex_lock(&mutex);
		printf("Thread 2 is running : x=%d\n", x);
		x--;
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
	pthread_exit(NULL);
}

int main()
{
	pthread_t id1, id2;
	int ret;
	ret = pthread_mutex_init(&mutex, NULL);
	if(ret != 0){
		printf("Mutex initialization failed.\n");
		exit(1);
	}
	x = 10;
	ret = pthread_create(&id1, NULL, (void *)&thread1, NULL);
	if(ret != 0){
		printf("Thread1 create failed.\n");
		exit(1);
	}
	ret = pthread_create(&id2, NULL, (void *)&thread2, NULL);
	if(ret != 0){
		printf("Thread2 create failed.\n");
		exit(1);
	}
	pthread_join(id1, NULL);
	pthread_join(id2, NULL);

	return 0;
}
