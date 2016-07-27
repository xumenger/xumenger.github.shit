#include<stdio.h>

int main(){
	int a, b, c;
	scanf("%d%d%d",&a, &b, &c);
	float result1 = ((float)a+(float)b+(float)c)/3;
	float result2 = (a+b+c)/3.0;

	printf("%.3lf %.3lf\n",result1, result2);
	return 0;
}
