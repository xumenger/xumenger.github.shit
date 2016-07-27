/*
 * 如何找出一个数组中第二大的数
 */

#include<stdio.h>
const int MINNUMBER = -32767;
int FindSecMax(int data[], int count){
	int maxnumber = data[0];
	int sec_max = MINNUMBER;
	int i=0;
	for(i=0; i<count; i++){
		if(data[i]>maxnumber){
			sec_max=maxnumber;
			maxnumber=data[i];
		}
		else{
			if(data[i]>sec_max)
				sec_max=data[i];
		}
	}
	return sec_max;
}

int main(){
	int array[]={2,5,6,4,34,32,1,5443,4,23,45,23,3232};
	int length=sizeof(array)/sizeof(array[0]);
	printf("%d\n", FindSecMax(array, length));
	return 0;
}
