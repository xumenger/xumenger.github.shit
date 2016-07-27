/*
 * 如何找出一个字符串中第一个只出现一次的字符
 */

#include<stdio.h>

int main(){
	char *str;
	scanf("%s",str);

	int i=0;
	int count[256];
	for(i=0; i<256; i++){
		count[i]=0;
	}

	for(i=0; str[i]!='\0';i++){
		count[(int)str[i]]++;
	}

	for(i=0; str[i]!='\0'; i++){
		if(count[(int)str[i]]==1){
			printf("%c是第一个只出现一次的字符\n", str[i]);
			break;
		}
	}

	return 0;
}
