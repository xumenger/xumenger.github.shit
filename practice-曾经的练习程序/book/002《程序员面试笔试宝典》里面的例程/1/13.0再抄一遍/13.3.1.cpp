/*
 * 如何统计一行字符串中有多少个单词
 */
#include<stdio.h>

int main(){
	char str[]=" Hello World  Fuck you son  of    bitch ";

	int count=0;
	int i;
	

	for(i=0; str[i]!='\0'; i++){
		if(str[i]!=' ' && (str[i+1]==' ' || str[i+1]=='\0'))
			count++;
	}

	printf("%d\n", count);
		
	return 0;
}
