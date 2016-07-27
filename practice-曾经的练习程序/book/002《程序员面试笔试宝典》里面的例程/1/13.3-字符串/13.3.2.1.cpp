/*
 * 按单词逆序
 */
#include<stdio.h>

void ReverseWord(char *p, char *q){
	while(p<q){
		char t=*p;
		*p++=*q;
		*q--=t;
	}
}
char *Reverse(char *s){
	char *p=s;
	char *q=s;
	while(*q!='\0'){
		if(*q==' '){
			ReverseWord(p,q-1);
			q++;
			p=q;
		}
		else
			q++;
	}
	ReverseWord(p,q-1);
	ReverseWord(s,q-1);
	return s;
}

int main(){
	char a[]="I am glad to see you";
	int len=sizeof(a)/sizeof(a[0]);
	printf("%s\n",Reverse(a));
	return 0;
}
