/*
 *如何找出数组中重复次数最多的数
 */
/*
 *方法一：以空间换时间，可以定义一个数组int count[MAX]，其中MAX是需要查询数组中的那个最大的数，并将该数组的元素
 *都初始化为0,然后执行for(i=0; i<100; i++) count[A[i]]++的操作，再在count中找最大的数，即为重复次数最多的数
 */
#include<stdio.h>
int GetMaxNum(int *arr, int len, int &num){
	int index=arr[0];
	int i;
	for(i=0; i<len; i++){
		if(arr[i]>index){
			index=arr[i];
			num =i;
		}
	}
	return index;
}

int main(){
	int array[]={1,1,2,2,4,4,4,4,5,5,6,6};
	int length=sizeof(array)/sizeof(int);
	int i;
	int num=0;
	int *count = new int[GetMaxNum(array, length, num)];	//注意new的使用方法
	for(i=0; i<length; i++)
		count[i]=0;
	for(i=0; i<length; i++)
		count[array[i]]++;
	printf("最多出现的次数是 %d\n",GetMaxNum(count,GetMaxNum(array,length,num),num));
	printf("这个数是 %d\n", num);
	return 0;
}
