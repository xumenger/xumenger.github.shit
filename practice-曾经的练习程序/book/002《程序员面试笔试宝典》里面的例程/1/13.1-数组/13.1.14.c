/*
 * 如何寻找出数列中缺失的数
 */
#include<stdio.h>
#define MAX 5

int main(){
	int array[]={3,2,1,5,6};
	int i;
	int sum=0;
	int temp;
	for(i=0; i<MAX; i++)
		sum+=array[i];
	temp=(MAX+2)*(MAX+1)/2-sum;
	printf("%d\n",temp);
	return 0;
}
