#include<stdio.h>

const int MAXN = 1000+10;

int main(){
	int i=5;
	if(i>0){
		main();
		printf("%d", i--);
	}
}
