/*
 * 方法三：位图法。	首先申请一个长度为N-1且均为'0'的字符串，然后从头开始
 * 遍历数组a[N]，取每个数组元素a[i]的值，将其对应的字符串中的相应位置置
 * 1,如果已经置过1,那么该数就是重复的数。由于采用位图法，所以空间复杂度
 * 较大，为O(n)。
 */
#include<stdio.h>
#define sum(x) (x*(x+1)/2)

void xor_findDup(int *arr, int NUM){
	int *arrayflag = (int *)malloc(NUM*sizeof(int));
	int i=1;
	while(i<NUM){
		arrayflag[i]=0;
		i++;
	}
	for(i=0; i<NUM; i++){	
		if(arrayflag[arr[i]]==0)
			arrayflag[arr[i]]=1;
		else{
			printf("%d\n",arr[i]);
			return;
		}
	}
}

int main(){
	int a[]={1,2,1,3,4};
	xor_findDup(a,5);
	return 0;
}
