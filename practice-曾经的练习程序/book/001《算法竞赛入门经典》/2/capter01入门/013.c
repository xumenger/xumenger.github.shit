#include<stdio.h>
#include<math.h>
int main(){
	int a, b, c;
	scanf("%d%d%d",&a, &b, &c);

	if(abs(a+b)>c && abs(a+c)>b && abs(b+c)>a)
		printf("yes\n");
	else
		printf("no\n");

	return 0;
}
