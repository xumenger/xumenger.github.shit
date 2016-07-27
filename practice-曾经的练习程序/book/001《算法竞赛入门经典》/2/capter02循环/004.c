#include<stdio.h>

int main(){
	int x, n, ho, lo;

	for(x=0; ;x++){
		n = x*x;
		if(n<1000)
			continue;
		else if(n>9999)
			break;
		ho = n/100;
		lo = n%100;
		if(ho/10 == ho%10 && lo/10 == lo%10)
			printf("%d\n",n);
	}
	return 0;
}
