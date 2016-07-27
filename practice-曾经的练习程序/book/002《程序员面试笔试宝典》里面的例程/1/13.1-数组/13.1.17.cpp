/*
 *如何把一个整形数组中重复的数字去掉
 */
#include<stdio.h>
#include<stdlib.h>

int int_cmp(const void *a, const void *b){
	const int *ia=(const int *)a;
	const int *ib=(const int *)b;
	return *ia-*ib;
}

int unique(int *array, int number){
	int k=0;
	for(int i=1; i<number; i++){
		if(array[k]!=array[i]){
			array[k+1]=array[i];
			k++;
		}
	}
	return (k+1);
}

int Unique_QuickSortMethod(int *arr, int elements){
	//C语言自带的排序函数
	qsort(arr, elements, sizeof(int), int_cmp);
	return unique(arr,elements);
}

int main(){
	int array[5]={1,2,1,2,3};
	int len = sizeof(array)/sizeof(array[0]);
	int size=Unique_QuickSortMethod(array,len);
	int i=0;
	for(i=0;i<size;i++)
		printf("%d ",array[i]);
	printf("\n");
	return 0;
}
