#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

pthread_mutex_t mutex;
pthread_cond_t cond;
int x;

void producer(void)
{
	while(1){
		pthread_mutex_lock(&mutex);
		int i;
		for(i=0; i<3-x; i++){
			x++;
			printf("Producing : x=%d \n", x);
			sleep(1);
		}
		if(x >= 3){
			pthread_cond_signal(&cond);
			printf("Producing completed.\n", x);
		}
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
	pthread_exit(NULL);
}

void consumer(void)
{
	while(1){
		pthread_mutex_lock(&mutex);
		while(x < 3){
			pthread_cond_wait(&cond, &mutex);
			printf("Start consuming.\n");
		}
		while(x > 0){
			x--;
			printf("Consuming : x=%d \n", x);
			sleep(1);
		}
		pthread_mutex_unlock(&mutex);
	}
	pthread_exit(NULL);
}

int main(void)
{
	pthread_t id1, id2;
	int ret;
	ret = pthread_mutex_init(&mutex, NULL);
	if(ret != 0){
		printf("Mutex initialization failed.\n");
		exit(1);
	}
	ret = pthread_cond_init(&cond, NULL);
	if(ret != 0){
		printf("Conditions initialization failed.\n");
		exit(1);
	}
	ret = pthread_create(&id1, NULL, (void *)&producer, NULL);
	if(ret != 0){
		printf("Thread Producer create failed.\n");
		exit(1);
	}
	ret = pthread_create(&id2, NULL, (void *)&consumer, NULL);
	if(ret != 0){
		printf("Thread Consumer create failed.\n");
		exit(1);
	}
	pthread_join(id1, NULL);
	pthread_join(id2, NULL);
	return 0;
}
