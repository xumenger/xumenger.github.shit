/*
 * 如何将字符串逆序
 */
#include<stdio.h>

//普通逆序
char *Reverse1(char *s){
	char *q=s;
	while(*q++)
		;
	q-=2;
	char *p=new char[sizeof(char)*(q-s+2)];

	char *r = p;

	//逆序存储
	while(q>=s)
		*p++=*q--;
	*p='\0';
	return r;
}

//原地逆序（两个指针）
char Reverse2(char *s){
	char *p=s;
	char *q=s;
	while(*q)
		++q;
	q--;
	while(q>p){
		char t=*p;
		*p++=*q;
		*q--=t;
	}
	return s;
}

//原地逆序（递归）
char *Reverse3(char *s, int left, int right){
	if(left>=right)
		return s;
	char t=s[left];
	s[left]=s[right];
	s[right]=t;
	Reverse3(s,left+1,right-1);
}

//原地逆序（非递归）
char *Reverse4(char *s, int left, int right){
	while(left<right){
		char t=s[left];
		s[left]=s[right];
		s[right--]=t;
	}
	return s;
}
