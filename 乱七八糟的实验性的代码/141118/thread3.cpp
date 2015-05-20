//之前的运行调用顺序很乱，这是为什么呢？
//这是因为多线程的缘故，主线程还没有开始对i赋值，线程已经开始跑了？
#include<iostream>
#include<pthread.h>

using namespace std;
#define NUM_THREADS 5

void* say_hello(void* args){
	cout<<"hello in thread "<<*((int*)args)<<endl;
}

int main(){
	pthread_t tids[NUM_THREADS];
	int indexes[NUM_THREADS];//用于保存i的值避免被修改

	for(int i=0; i<NUM_THREADS; i++){
		indexes[i] = i;
		int ret = pthread_create(&tids[i], NULL, say_hello, (void*)&(indexes[i]));
		if(ret != 0){
			cout<<"pthread_create error:error_code:"<<ret<<endl;
		}
	}
	for(int i=0; i<NUM_THREADS; i++){
		pthread_join(tids[i], NULL);
		//pthread_join用来等待一个线程的结束，是一个线程阻塞的函数
	}
}

//代码中如果没有pthread_join，主线程会很快结束从而使得整个进程结束，从而使创建的线程没有机会开始执行就结束了。加入pthread_join后，主线程一直等待直到等待的线程结束自己才结束，使创建的线程有机会执行
