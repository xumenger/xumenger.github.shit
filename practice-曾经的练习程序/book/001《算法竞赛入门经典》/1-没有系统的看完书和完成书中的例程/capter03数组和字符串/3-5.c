/*
 *输入一个字符串，求出其最长的回文子串。
 *子串：在原串中连续出现的字符串片段
 *回文：正着看、倒着看都相同，比如abbbc、acbca……
 *
 * 方案1：
 */
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAXN 5000+1
char buf[MAXN], s[MAXN];
int main(){
	int n,m=0,max=0;
	int i,j,k;
	fgets(buf, sizeof(s), stdin);
	n=strlen(buf);
	for(i=0;i<n;i++)
		if(isalpha(buf[i]))
			s[m++]=toupper(buf[i]);
	for(i=0;i<m;i++)
		for(j=i;j<m;j++){
			int ok=1;
			for(k=i;k<=j;k++)
				if(s[k] != s[i+j-k])
					ok=0;
			if(ok && j-i+1>max)
				max=j-i+1;
		}
	printf("max=%d\n",max);
	return 0;
}
