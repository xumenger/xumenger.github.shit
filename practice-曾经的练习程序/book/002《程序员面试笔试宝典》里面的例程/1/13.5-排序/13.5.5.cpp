/*
 * 如何进行快速排序
 */
/*
 * 快速排序是一种非常高效的排序算法，它采用“分而治之”的思想，把大的拆分
 * 为小的，小的在拆为更小的。
 * 其原理是：对于一组给定的记录，通过一趟排序后，将原序列分为两部分，其
 * 中前部分的所有记录小于后部分的所有记录，然后再依次对前后两部分的记录
 * 进行快速排序。递归该过程，直到所有的记录有序为止
 */

#include<stdio.h>

void Sort(int array[], int low, int high){
	int i,j;
	int index;
	if(low>=high)
		return ;
	i=low;
	j=high;
	index=array[i];
	while(i<j){
		while(i<j && array[j]>=index)
			j--;
		if(i<j)
			array[i++]=array[j];
		while(i<j && array[i]<index)
			i++;
		if(i<j)
			array[j--]=array[i];
	}
	array[i]=index;
	Sort(array,low, i-1);
	Sort(array,i+1, high);
}

void QuickSort(int array[], int len){
	Sort(array, 0, len-1);
}

int main(){
	int i=0;
	int a[]={5,4,9,8,7,6,0,1,2,3};
	int len=sizeof(a)/sizeof(a[0]);
	QuickSort(a, len);
	for(i=0;i<len;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
