/*
 * 如何检查字符是不是整数？如果是，返回其整数值
 */

#include<stdio.h>
#include<ctype.h>

int cheak(int p){
	int c=p;
	if(isdigit(p))
		c=p-48;
	return c;
}

int main(){
	int c;
	while((c=getchar())!=EOF){
		getchar();
		c=cheak(c);
		if(isalpha(c))
			printf("不是\n");
		else
			printf("是：%d\n",c);
	}
}
