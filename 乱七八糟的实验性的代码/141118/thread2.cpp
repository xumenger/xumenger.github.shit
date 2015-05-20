//如何在线程调用函数时传入参数呢？
#include<iostream>
#include<pthread.h>

using namespace std;
#define NUM_THREADS 5

void* say_hello(void* args){
	int i = *((int*)args);//对传入的参数进行强制类型转换，由无类型指针转变为整型指针，再用*读取其内容
	cout<<"hello in "<<i<<endl;
}

int main(){
	pthread_t tids[NUM_THREADS];
	cout<<"hello in main.."<<endl;
	for(int i=0; i<NUM_THREADS; i++){
		int ret = pthread_create(&tids[i], NULL, say_hello, (void*)&i);//最后的参数是传入到say_hello函数的参数
		cout<<"Current pthread id = "<<tids[i]<<endl;
		if(ret != 0){
			cout<<"pthread_create error:error_code:"<<ret<<endl;
		}
	}
	pthread_exit(NULL);
}
