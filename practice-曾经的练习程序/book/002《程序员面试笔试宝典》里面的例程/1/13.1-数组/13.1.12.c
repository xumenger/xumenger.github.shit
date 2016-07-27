/*
 *如何找出数组中出现奇数次的元素
 */
#include<stdio.h>

int FindElementWithOddCount(int *a, int n){
	int r=a[0];
	int i=0;
	for(i=1;i<n;i++)	//第一次时错误的从i=0开始，应该从i=1开始才对
		r^=a[i];
	return r;
}

int main(){
	int array[]={1,2,3,4,5,6,1,2,3,4,5};
	int len=sizeof(array)/sizeof(array[0]);
	printf("%d\n",FindElementWithOddCount(array,len));
	return 0;
}
