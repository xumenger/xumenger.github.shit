/*
 * 如何找出数组中只出现一次的数字
 */
#include<stdio.h>

int findNotDouble(int a[], int n){
	int result=a[0];
	int i;
	for(i=1; i<n; i++)
		result^=a[i];
	return result;
}

int main(){
	int arr[]={1,1,2,3,3,4,5,4,5};
	int len = sizeof(arr)/sizeof(arr[0]);
	printf("%d\n",findNotDouble(arr, len));
	return 0;
}
