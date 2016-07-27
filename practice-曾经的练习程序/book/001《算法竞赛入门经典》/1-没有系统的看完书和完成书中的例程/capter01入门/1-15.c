#include<stdio.h>
//
int main(){
	int a,b,c,x,y,z;
	//printf("%d",z);	如果没有初始化，将会默认为0

	scanf("%d %d %d",&a,&b,&c);

	x=a;	//x用来存储最小值
	if(b<x)
		x=b;
	if(c<x)
		x=c;
	z=a;	//z用来存储最大值
	if(b>z)
		z=b;
	if(c>z)
		z=c;

	y=a+b+c-x-z;

	printf("%d %d %d\n",x,y,z);
	return 0;
}
