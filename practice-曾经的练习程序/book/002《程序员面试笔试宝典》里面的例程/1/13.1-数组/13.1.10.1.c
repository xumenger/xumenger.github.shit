/*
 * 如何找出数组中唯一的重复元素，要求时间复杂度为O(n)，空间复杂度为O(1)
 * 条件：数组a[N]，1至N-1这N-1个数存储在a[N]中，其中某个数重复了一次
 */
/*
 * 方法一：采用数学求和法，因为只有一个数字重复一次，而数又是连续的。根据
 * 累加和原理，对数组的所有项求和，然后减去1至N-1的和，即为所求的重复数
 */


#include<stdio.h>

void xor_findDup(int *a, int N){
	int temp1=0;
	int temp2=0;
	int i=0;
	for(i=0; i<N-1; i++){
		temp1+=(i+1);
		temp2+=a[i];
	}
	temp2+=a[N-1];
	int result=temp2-temp1;
	printf("%d\n",result);
}

int main(){
	int a[]={1,2,2,3,4,5,6,7};
	xor_findDup(a,8);
	return 0;
}
