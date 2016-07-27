#include<stdio.h>

int main(void)
{
	int i, j, tmp;
	int N = 5;
	int a[5] = {20,37,11,42,29};
	for(i=0; i<N; i++){
		for(j=0; j<N-i-1; j++){
			if(a[j]>a[j+1]){
				tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			}
		}
	}
	for(i=0; i<N; i++)
		printf("%d\n", a[i]);
	return 0;
}
