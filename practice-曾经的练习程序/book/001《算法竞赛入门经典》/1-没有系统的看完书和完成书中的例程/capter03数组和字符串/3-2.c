#include<stdio.h>
#include<string.h>
#define MAXN 1000+10
/*
 *有n栈灯，编号是1～n，第1个人把所有灯打开，第2个人按下所有编号为2的倍数的开关（关掉这些灯），第3个人按下所有编号是3的倍数的开关（其中关掉的灯将会被打开，开着的灯将会被关上），一次类推。一共有k个人，问最后那些灯开着，

 输入为n和k
 输出为开着的灯的编号
 */
int a[MAXN];
int main(){
	int i,j,n,k,first=1;

	/*
	 *void *memset(void *s,int c,size_t n)
	 总的作用：将已开辟内存空间 s 的首 n 个字节的值设为值 c。
	 */
	memset(a,0,sizeof(a));	
	scanf("%d %d",&n,&k);

	for(i=1;i<=k;i++)
		for(j=1;j<=n;j++)
			if(j%i==0)
				a[j]=!a[j];
	
	for(i=1;i<=n;i++)
		if(a[i]){
			if(first)
				first=0;
			else
				printf(" ");
			printf("%d",i);
		}
	printf("\n");
	return 0;
}
