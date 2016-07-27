/*
 *如何判断一个数组中数值是否连续相邻
 */
#include<stdio.h>

int IsContinuous(int *a, int n){
	int min=-1, max=-1;
	int i=0;
	for(i=0; i<n; i++){
		if(a[i]!=0){
			if(min>a[i] || -1==min)
				min=a[i];
			if(max<a[i] || -1==max)
				max=a[i];
		}
	}
	if(max-min>n-1)
		return 0;
	else 
		return 1;
}

int main(){
	int array[]={8,7,5,0,0,0,6};
	int len=sizeof(array)/sizeof(array[0]);

	if(IsContinuous(array, len)==1)
		printf("连续\n");
	else
		printf("不连续\n");
}
