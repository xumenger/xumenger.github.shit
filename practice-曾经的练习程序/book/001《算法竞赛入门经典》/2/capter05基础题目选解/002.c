#include<stdio.h>
int main(){
	int c;
	int flag=1;
	while((c=getchar())!=EOF){
		if(flag==1 && c=='"'){
			printf("``");
			flag = 0;
		}
		else if(flag==0 && c=='"'){
			putchar(c);
			flag = 1;
		}
		else
			putchar(c);
	}
	return 0;
}
