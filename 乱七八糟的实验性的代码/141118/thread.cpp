//进程同时创建5个线程，各自调用同一个函数
#include<iostream>
#include<pthread.h>//多线程相关操作头文件，可移植众多平台
using namespace std;
#define NUM_THREADS 5

void* say_hello(void* args){
	cout<<"hello..."<<endl;
}//函数返回的是函数指针，便于后面作为参数

int main(){
	pthread_t tids[NUM_THREADS];	//线程id
	for(int i=0; i<NUM_THREADS; i++){
		int ret = pthread_create(&tids[i], NULL, say_hello, NULL);	//参数：创建的线程id，线程参数，线程运行函数的起始地址，运行函数的参数
		if(ret!=0){//创建线程成功返回0
			cout<<"pthread_create error::error_code="<<ret<<endl;
		}
	}
	pthread_exit(NULL);//等待各个线程退出之后，进程才结束，否则进程强制退出，线程处于未终止的状态
}
