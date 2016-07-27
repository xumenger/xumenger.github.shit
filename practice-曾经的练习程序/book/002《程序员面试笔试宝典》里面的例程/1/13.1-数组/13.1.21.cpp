/*
 * 如何计算出序列的前n项数据
 */
#include<stdio.h>

void Generate(int a, int b, int N, int *Q){
	int tmpA, tmpB;
	int i=1;
	int j=1;
	int k=0;
	for(k=0; k<N; k++){
		tmpA=a*i;
		tmpB=b*j;
		if(tmpA<=tmpB){
			Q[k]=tmpA;
			i++;
		}
		else{
			Q[k]=tmpB;
			j++;
		}
	}
}

int main(){
	int a[6];
	int i;
	Generate(3,5,6,a);
	for(i=0;i<6;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
