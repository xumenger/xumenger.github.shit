/*
 * 如何进行堆排序
 */
/*
 * 堆是一种特殊的树形数据结构，其每个结点都有一个值，通常提到的堆就是
 * 指一棵完全二叉树，根节点的值小于（或大于）两个子结点的值，同时跟节
 * 点的两个子树也分别是一个堆
 */
/*
 * 堆排序是一树形选择排序，在排序的过程中，将R[1,...,N]看成是一个完全
 * 二叉树的顺序存储结构，利用完全二叉树中双亲结点和孩子结点之间的关系
 * 来选择最小元素。
 */
#include<stdio.h>

void AdjustMinHeap(int *a, int pos, int len){
	int temp;
	int child;
	for(temp=a[pos]; 2*pos+1<=len; pos=child){
		child=2*pos+1;
		if(child<len && a[child]>a[child+1])
			child++;
		if(a[child]<temp)
			a[pos]=a[child];
		else
			break;
	}
	a[pos]=temp;
}

void Swap(int &a, int &b){
	int temp=a;
	a=b;
	b=temp;
}

void MyMinHeapSort(int *array, int len){
	int i;
	for(i=len/2-1; i>=0; i--)
		AdjustMinHeap(array, i, len-1);
	for(i=len-1; i>=0; i--){
		Swap(array[0],array[i]);
		AdjustMinHeap(array, 0, i-1);
	}
}

void PrintArray(int *a, int length){
	int i;
	for(i=0; i<length; i++)
		printf("%d ",a[i]);
	printf("\n");
}

int main(){
	int array[]={0,13,1,14,27,18};
	int length=sizeof(array)/sizeof(array[0]);
	MyMinHeapSort(array,length);
	PrintArray(array,length);
	return 0;
}
