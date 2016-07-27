/*
 * 如何找出数列中符合条件的数对的个数
 */
#include<stdio.h>

void FixedSum(int *a, int n, int d){
	int i=0, j=n-1;
	for(i=0,j=n-1;i<n && j>=0 && i<j;){
		if(a[i]+a[j]<d)
			++i;
		else if(a[i]+a[j]==d){
			printf("%d %d\n",a[i],a[j]);
			++i;
			--j;
		}
		else
			--j;
	}
}

int main(){
	int array[]={1,2,3,4,5,6};
	int len=sizeof(array)/sizeof(array[0]);
	FixedSum(array,len,6);
	return 0;
}
