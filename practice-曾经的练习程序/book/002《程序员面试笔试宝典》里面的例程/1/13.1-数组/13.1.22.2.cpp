/*
 * 找出数组中单独出现的两个数字
 */
#include<stdio.h>

void findOnce(int data[], int n, int &num1, int &num2){
	if(n<5)
		return;
	int r1=0;
	int i=0;
	for(i=0; i<n; i++)
		r1^=data[i];
	int bitNum=0;
	while(!(r1 & 0x1)){
		r1>>=1;
		++bitNum;
	}
	int flag=(1<<bitNum);
	num1=0;
	num2=0;
	int j=0;
	for(j=0;j<n;j++){
		if(data[j]&flag)
			num1^=data[j];
		else
			num2^=data[j];
	}
}

int main(){
	int array[]={1,2,3,2,4,3,5,1};
	int num1,num2;
	findOnce(array, sizeof(array)/sizeof(arra[0]),num1,num2);
	printf("%d %d\n",num1,num2);
	return 0;
}
