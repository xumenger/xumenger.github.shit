/*
 * 如何找出一个字符串中第一个只出现一次的字符
 */
#include<stdio.h>

char GetChar(char str[]){
	if(str==NULL)
		return 0;
	const int size =256;
	unsigned count[size]={0};
	char buffer[size];
	char *q=buffer;
	for(const char *p=str; *p!=0; ++p)
		if(++count[(unsigned char)*p]==1)
			*q++=*p;
	for(p=buffer; p<q; ++p)
		if(count[(unsigned char)*p]==1)
			return *p;
	return 0;
}

int main(){
	printf("%c\n",GetChar("abac"));
	return 0;
}
