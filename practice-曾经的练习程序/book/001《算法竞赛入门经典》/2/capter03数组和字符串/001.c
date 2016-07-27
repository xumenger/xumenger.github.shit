#include<stdio.h>

#define MAXN 100+10
int a[MAXN];

int main(){
	int i, x, n=0;
	while(scanf("%d", &x)==1)
		a[n++]=x;

	for(i=0;i<n;i++)
		printf("%d ", a[n-i-1]);

	return 0;
}
