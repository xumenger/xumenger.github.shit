/*
 * 如何将数组的后面m个数移动为前面的m个数
 */
#include<stdio.h>

void func(int *start, int *end){
	while(start < end){
		int temp = *start;
		*start = *end;
		*end = temp;
		++start;
		--end;
	}
}

void f(int n, int m, int *numbers){
	func(numbers, numbers+m-1);	//将前m个数字顺序颠倒
	func(numbers+m, numbers+n-1);//将后n-m个数顺序颠倒
	func(numbers, numbers+n-1);//所有数顺序颠倒
}

int main(){
	int array[]={1,2,3,4,5,6,7,8,9,10};
	int len=sizeof(array)/sizeof(array[0]);
	int i;
	f(len,5,array);
	for(i=0;i<len;i++)
		printf("%d ",array[i]);
	printf("\n");
	return 0;
}
