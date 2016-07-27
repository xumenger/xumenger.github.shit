#include<stdio.h>

int n1(int n){
	int result = 0;
	int i=0;
	for(i=1; i<=n; i++){
		result+=i;
	}

	return result;
}

int n2(int n){
	return n==1 ? 1: n+n2(n-1);
}

int main(){
	int n=10;
	printf("%d %d\n",n1(n), n2(n));
	return 0;
}
