//find the minimal between 2 int number
#include<stdio.h>
int min(int x, int y);
int main(){
	int num1, num2, min_num;
	printf("Please input the first number:\n");
	scanf("%d", &num1);
	printf("Please input the second number:\n");
	scanf("%d", &num2);
	min_num = min(num1, num2);
	printf("The minimal one is %d\n", min_num);
	return 0;
}
int min(int x, int y){
	if(x>y)
		return y;
	else
		return x;
}
