/*
 * 如何重新排列使得数组左边为奇数，右边为偶数
 */
#include<stdio.h>

void Swap(int &a, int &b){
	int temp = a; 
	a = b;
	b = temp;
}

void Reverse(int arr[], int n){
	if(arr==NULL || n<=0)
		return ;

	int i=0;
	int j=n-1;

	for(; i<j;){
		if(arr[i]%2 == 0){
			if(arr[j]%2 == 1){
				Swap(arr[i], arr[j]);
				i++;
				j--;
			}
			else
				j--;
		}
		else
			i++;
	}
}

int main(){
	int arr[]={1,2,3,4,5,6,7,8,9};
	int len=sizeof(arr)/sizeof(arr[0]);

	int i=0;
	for(i=0; i<len; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");

	Reverse(arr, len);

	for(i=0; i<len; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");

	return 0;
}
