#include<stdio.h>
/*
 *读入一些整数，逆序输出到一行中。已知整数不超过100个
 */
#define MAXN 100 + 10
int a[MAXN];
int main(){
	int i, x, n=0;
	do{	//实现当输入0的时候结束输入，开始逆序输出
		scanf("%d",&x);
		a[n++]=x;
	}while(x!=0);

	for(i=n-1; i>=1;i--)
		printf("%d ",a[i]);
	printf("%d\n",a[0]);
	return 0;
}
