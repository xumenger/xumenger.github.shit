#include<stdio.h>

int main(){
	int i, j, n, S=0;
	scanf("%d", &n);
	for(i=0; i<=n; i++){
		int temp = 1;
		for(j=1; j<=i; j++)
			temp*=j;
		S+=temp;
	}
	printf("%d\n", S%1000000);
	return 0;
}
