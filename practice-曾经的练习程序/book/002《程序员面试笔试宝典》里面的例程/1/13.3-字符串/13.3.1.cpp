/*
 * 如何统计一行字符串里面有多少个单词
 */

#include<stdio.h>
#define BUFFERSIZE 1024

int main(){
	char string[BUFFERSIZE];
	int i, count=0, word=0;
	char c;
	gets(string);
	for(i=0; (s=string[i])!='\0'; i++){
		if(c==' ')
			word =0;
		else if(word==0){
			word=1;
			count++;
		}
	}
	printf("一共有单词%d个\n", count);
	return 0;
}
