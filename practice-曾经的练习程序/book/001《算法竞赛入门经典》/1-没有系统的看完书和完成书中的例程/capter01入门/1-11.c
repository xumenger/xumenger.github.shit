#include<stdio.h>
//鸡兔同笼问题：输入鸡兔总数n，总腿数m，依次输出鸡兔数量
//列方程n=a+b	m=2a+4b
//求出a=(4*n-m)/2	b=n-a
int main(){
	int a,b,n,m;
	scanf("%d %d",&n,&m);
	a=(4*n-m)/2;
	b=n-a;
	if(m%2==1 || a<0 || b<0)
	//一定要考虑输入不能产生合法输出的情况，这样才能保证程序的全面、安全、正确
		printf("No Answer\n");
	else
		printf("%d %d\n",a,b);
	return 0;
}
