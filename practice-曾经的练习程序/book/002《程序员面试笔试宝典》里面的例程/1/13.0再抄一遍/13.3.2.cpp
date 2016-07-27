/*
 * 如何将一个字符串逆序
 */
#include<stdio.h>

char *Reverse(char *str){
	char *pBegin=str;
	char *pEnd = str;
	for(;*pEnd!='\0';)
		pEnd++;
	pEnd--;

	for(; pBegin<pEnd;){
		char temp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = temp;
		pBegin ++;
		pEnd --;
	}

	return str;
}

int main(){
	char str[]="I love you!";

	printf("%s\n", str);

	printf("%s\n", Reverse(str));

	return 0;
}
