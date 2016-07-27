/*
 * 如何寻找数组中的最小值和最大值
 */
/*
 *为什么g++能编译通过，但是gcc却不能
 */

#include<stdio.h>

void GetMaxAndMin(int *arr, int len, int &Max, int &Min){
	//注意Max与Min使用的是引用
	Max=arr[0];
	Min=arr[0];
	int i=0;
	for(i=2; i<len-1;i=i+2){
		if(i==len-1){
			if(arr[i]>Max)
				Max=arr[i];
			if(arr[i]<Min)
				Min=arr[i];
		}
		if(arr[i]>arr[i+1]){
			if(arr[i]>Max)
				Max=arr[i];
			if(arr[i+1]<Min)
				Min=arr[i+1];
		}
		if(arr[i]<arr[i+1]){
			if(arr[i+1]>Max)
				Max=arr[i+1];
			if(arr[i]<Min)
				Min=arr[i];
		}
	}
}

int main(){
	int max,min;
	int data[]={8,6,5,2,3,9,4,1,7};
	int num=sizeof(data)/sizeof(data[0]);
	GetMaxAndMin(data,num,max,min);	//注意在函数定义时Max与Min使用引用，在具体调用时候传参数直接传自身就好
	printf("MAX:%d\n",max);
	printf("MIN:%d\n",min);
	return 0;
}
