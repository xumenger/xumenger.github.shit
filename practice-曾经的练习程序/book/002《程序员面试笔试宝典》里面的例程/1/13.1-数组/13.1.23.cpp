/*
 * 如何判断一个整数x是否可以表示成n(n>=2)个连续正整数的和
 */
#include<stdio.h>
#include<math.h>

int main(){
	int m=0, n=0, start=0, end=0, flag=0;
	float temp=0.0;
	printf("请输入要被分解的数：");
	scanf("%d",&m);
	printf("请输入要被分解的数字的个数：");
	scanf("%d",&n);
	temp=(float)m/n-(float)(n-1)/2;
	if(temp==(int)temp){
		for(flag=1,start=(int)temp,end=start+n;start<end;start++)
			printf("%d ",start);
		printf("\n");
	}
	if(flag==0)
		printf("没有符合条件的数\n");
	return 0;
}
