/*
 * 如何查找字符串中每个字符出现的个数
 */

#include<stdio.h>

int main(){
	char *str="AbcABca";
	int count[256]={0};
	for(char *p=str; *p; p++)
		count[*p]++;
	int i=0;
	for(i=0; i<256; i++){
		if(count[i]>0)
			printf("The count of %c is %d\n",i,count[i]);
	}
	return 0;
}
