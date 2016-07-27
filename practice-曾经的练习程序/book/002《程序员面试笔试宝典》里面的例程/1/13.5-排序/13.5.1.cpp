/*
 * 选择排序
 */
/*
 * 选择排序是一种简单直观的排序算法，它的基本原理如下：对于给定的一组
 * 记录，经过第一轮比较后得到最小的记录，然后将该记录与第一个记录位置
 * 进行交换；接着对不包括第一个记录以外的其他记录进行第二轮比较，得到
 * 最小的记录并与第二个记录进行位置交换；重复该过程，直到进行比较的记
 * 只有一个时为止
 */

#include<stdio.h>

void SelectSort(int *a, int n){
	int i,j;
	int temp=0;
	int flag=0;
	for(i=0; i<n-1; i++){
		temp=a[i];
		flag=i;
		for(j=i+1; j<n; j++){
			if(a[j]<temp){
				temp=a[j];
				flag=j;		//需要同时记录最小的数，以及最小的数的下标
			}
		}
		if(flag != i){
			a[flag]=a[i];
			a[i]=temp;
		}
	}
}

int main(){
	int i=0; 
	int a[]={5,4,9,8,7,0,1,3,2};
	int len=sizeof(a)/sizeof(a[0]);
	SelectSort(a, len);
	for(i=0; i<len; i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
