/*
 * 函数指针
 */
#include<stdio.h>

int sum(int a, int b){
	return (a+b);
}

int main(){
	int (*fun)(int, int);
	fun = sum;
	printf("%d\n",fun(30, 90));
	return 0;
}
