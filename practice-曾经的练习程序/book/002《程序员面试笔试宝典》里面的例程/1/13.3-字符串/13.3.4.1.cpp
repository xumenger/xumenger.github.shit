/*
 * 如何输出字符串里的所有组合
 */
#include<stdio.h>
#include<string.h>

//使用递归方法
void CombineRecursiveImpl(const char *str, char *begin, char *end){
	if(*str==0){
		*end=0;
		if(begin!=end)
			printf("%s",begin);
		return ;
	}
	CombineRecursiveImpl(str+1, begin, end);
	*end=*str;
	CombineRecursiveImpl(str+1, begin, end+1);
}
void CombineRecursive(const char str[]){
	if(str==NULL)
		return;
	const int MAXLENGTH=64;
	char result[MAXLENGTH];
	CombineResursiveImpl(str,result,result);
}
int main(){
	CombineRecursive("abc");
	printf("\n");
	return 0;
}
