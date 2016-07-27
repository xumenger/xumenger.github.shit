#include<stdio.h>
//三整数排序（1）：枚举各种情况
//输入三个数：20 7 33
//从小到大输出：7 20 33
//
//问题：比如没有考虑到1 1 1这种三个输入相等的情况
int main(){
	int a, b, c;
	scanf("%d %d %d",&a, &b, &c);
	if(a<b && b<c)
		printf("%d %d %d\n",a, b, c);
	if(a<c && c<b)
		printf("%d %d %d\n",a, c, b);
	if(b<a && c<b)
		printf("%d %d %d\n",c, b, a);
	if(b<c && c<a)
		printf("%d %d %d\n",b, c, a);
	if(c<a && a<b)
		printf("%d %d %d\n",c, a, b);
	if(b<a && a<c)
		printf("%d %d %d\n",b, a, c);

	return 0;
}
