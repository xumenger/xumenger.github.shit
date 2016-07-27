#include<stdio.h>
//变量交换（2）：两变量法
int main(){
	int a,b;
	scanf("%d %d",&a, &b);
	a=a+b;
	b=a-b;
	a=a-b;
	printf("%d %d\n",a,b);
	return 0;
}
