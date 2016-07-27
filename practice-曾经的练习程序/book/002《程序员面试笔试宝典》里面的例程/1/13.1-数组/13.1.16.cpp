/*
 * 如何重新排列数组使数组左边为奇数，右边为偶数
 */
#include<stdio.h>

using namespace std;

void Swap(int &a, int &b){	//注意这个交换的函数使用了引用（）
	int temp=a;
	a=b;
	b=temp;
}

void ReverseArray(int arr[], int len){
	int begin = 0;
	int end = len-1;
	while(begin<end){
		while(arr[begin]%2==1 && end>begin)
			++begin;
		while(arr[end]%2==0 && end>begin)
			--end;
		Swap(arr[begin],arr[end]);
	}
}

int main(){
	int array[]={1,23,2,34,21,45,26,22,66,74,91,17,64};
	int len=sizeof(array)/sizeof(array[0]);
	int i=0;
	printf("原数组为：");
	for(i=0; i<len; i++)
		printf("%d ",array[i]);
	ReverseArray(array,len);
	printf("\n变换后的数组是：");
	for(i=0; i<len; i++)
		printf("%d ",array[i]);
	printf("\n");
	return 0;
}
