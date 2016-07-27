/*
 *如何用递归算法判断一个数组是否递增
 */
/*
 *因为不能使用常规遍历的方法，必须使用递归，所以设数组为a，则递增数组满足以下条件：
 *1.如果数组的长度为1,则该数组递增，返回true
 *2.如果数组长度为n（n>=2），则先比较最后两个元素是否递增，如果最后两个元素递增，再递归比较去除最后一个元素的前n-1个元素是否递增
 */
#include<stdio.h>

bool isIncrease(int a[], int n){
	if(n==1)
		return true;
	return (a[n-1]>=a[n-2]) && isIncrease(a,n-1);
}

int main(){
	int array[]={1,2,3,3,4,5};
	int len=sizeof(array)/sizeof(array[0]);

	if(isIncrease(array, len))
		printf("数组（1,2,3,3,4,5）是递增的\n");
	else
		printf("不是递增的\n");
	return 0;
}
