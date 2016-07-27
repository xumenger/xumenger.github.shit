/*
 * 如何进行插入排序
 */
/*
 * 对于给定的一组记录，初始时假设第一个记录自成一个有序序列，其余的记录
 * 为无序序列；接着从第二个记录开始，按照记录的大小依次将当前的记录插入
 * 到之前的有序序列中，直到最后一个记录插入到有序序列中为止
 */

#include<stdio.h>

void InsertSort(int arr[], int len){
	int i,j;
	int temp;
	for(i=0; i<len; i++){
		temp=arr[i];
		for(j=i-1; j>=0; j--){
			if(temp<arr[j])
				arr[j+1]=arr[j];
			else
				break;
		}
		arr[j+1]=temp;	//第一次不小心将j+1写成j+i，导致数组越界，能编译通过，但是运行就报错了，还是细节！！！
	}
}

int main(){
	int i=0;
	int a[]={5,4,9,8,6,0,1,3,2};
	int len=sizeof(a)/sizeof(a[0]);
	InsertSort(a, len);
	for(i=0; i<len; i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
