#include<stdio.h>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int temp = 4*n-m;
	if(temp%2==1 || temp/2<0 || n-temp/2 <0){
		printf("No answer\n");
		return 0;
	}
	printf("%d %d\n",temp/2, n-temp/2);

	return 0;
}
