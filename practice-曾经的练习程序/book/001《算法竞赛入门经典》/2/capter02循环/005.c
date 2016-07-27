#include<stdio.h>

int main(){
	int n;
	int i=0;
	scanf("%d", &n);
	for(;;){
		if(n==1){
			printf("%d\n",i);
			break;
		}
		else if(n!=1 && n%2==1){
			n = 3*n + 1;
			i++;
		}
		else{
			n = n/2;
			i++;
		}
	}
	return 0;
}
