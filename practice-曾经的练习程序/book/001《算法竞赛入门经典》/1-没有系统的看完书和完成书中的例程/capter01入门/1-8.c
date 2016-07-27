#include<stdio.h>
//变量交换（1）：三变量法
int main(){
	int a, b;
	scanf("%d %d",&a,&b);
	int t=a;
	a=b;
	b=t;
	printf("%d %d\n",a,b);
	return 0;
}
