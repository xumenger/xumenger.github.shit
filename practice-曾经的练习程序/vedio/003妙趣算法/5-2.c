#include<stdio.h>
int gcd(int a, int b)
{
	int min;
	if(a<=0 || b<=0)
		return -1;
	if(a>b)
		min = b;
	else
		min = a;
	while(min){
		if(a%min==0 && b%min==0)
			return min;
		min--;
	}
	return -1;
}

int lcm(int a, int b){
	int max;
	if(a<=0 || b<=0)
		return -1;
	if(a>b)
		max = a;
	else
		max = b;
	while(max){
		if(max%a==0 && max%b==0)
			return max;
		max++;
	}
	return -1;
}

int main()
{
	int a, b;
	printf("Please input two digit for getting GCD and LCM :");
	scanf("%d %d", &a, &b);
	printf("GCD: %d\n", gcd(a, b));
	printf("LCM: %d\n", lcm(a, b));

	return 0;
}
