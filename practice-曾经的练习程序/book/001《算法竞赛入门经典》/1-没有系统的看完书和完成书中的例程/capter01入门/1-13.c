#include<stdio.h>
//三整数排序（2）：枚举各种情况
//输入三个数：20 7 33
//从小到大输出：7 20 33
int main(){
	int a, b, c;
	scanf("%d %d %d",&a, &b, &c);
	if(a<=b && b<=c)
		printf("%d %d %d\n",a, b, c);
	else if(a<=c && c<=b)
		printf("%d %d %d\n",a, c, b);
	else if(b<=a && c<=b)
		printf("%d %d %d\n",c, b, a);
	else if(b<=c && c<=a)
		printf("%d %d %d\n",b, c, a);
	else if(c<=a && a<=b)
		printf("%d %d %d\n",c, a, b);
	else
		printf("%d %d %d\n",b, a, c);

	return 0;
}
