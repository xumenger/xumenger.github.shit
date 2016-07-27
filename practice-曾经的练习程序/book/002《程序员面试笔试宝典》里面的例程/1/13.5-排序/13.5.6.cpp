/*
 * 如何进行希尔排序
 */
/*
 * 希尔排序也称为“缩小增量排序”。他的基本原理是：首先将待排序的元素分为
 * 多个子序列，使得每个子序列的元素个数相对较少，对各个子序列进行直接插
 * 入排序，待整个待排序序列“基本有序”后，再对所有元素进行一次直接插入排
 * 序
 */
#include<stdio.h>

void ShellSort(int array[], int length){
	int i,j;
	int h;
	int temp;
	for(h=length/2; h>0; h=h/2){
		for(i=h; i<length; i++){
			temp=array[i];
			for(j=i-h; j>=0; j-=h){
				if(temp<array[j])
					array[j+h]=array[j];
				else
					break;
			}
			array[j+h]=temp;
		}
	}
}

int main(){
	int i=0;
	int a[]={5,4,9,8,6,0,1,3,2};
	int len=sizeof(a)/sizeof(a[0]);
	ShellSort(a,len);
	for(i=0; i<len; i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
