/*
 * 如何用递归实现数组求和
 */
/*
 *问题的难点在于如何使用递归上。如果使用递归，则需要考虑如何进行递归执行的开始以及终止条件，
 *首先如果数组的元素个数为0,则和为0；同时如果数组的元素个数为n，那么先求出前n-1个元素的和，
 *再加上a[n-a]即可
 */
#include<stdio.h>

int GetSum(int *a, int n){
	return n==0?0:GetSum(a, n-1)+a[n-1];
}

int main(){
	int a[]={10,1,1,1,10,1,4};
	int length = sizeof(a)/sizeof(a[0]);
	printf("%d\n",GetSum(a, length));
	return 0;
}
