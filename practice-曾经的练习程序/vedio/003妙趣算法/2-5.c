#include<stdio.h>

void bubblesort(int k[], int n)
{
	int i, j, tmp, flag = 1;
	for(i=1; i<=n-1 && flag==1; i++){
		flag = 0;
		for(j=1; j<=n-i; j++){
			if(k[j] < k[j+1]){
				tmp = k[j+1];
				k[j+1] = k[j];
				k[j] = tmp;
				flag = 1;
			}
		}
	}
}
