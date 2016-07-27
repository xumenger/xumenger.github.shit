#include<stdio.h>
#include<string.h>

const int MAXD = 20;
int s[1<<MAXD];		//最大节点个数为2^MAXN-1

int main(){
	int D, I;
	while(scanf("%d%d", &D, &I)==2){
		memset(s, 0, sizeof(s));	//开关
		int k, n = (1<<D)-1;
		for(int i=0; i<I; i++){
			k = 1;
			for(;;){
				s[k] = !s[k];
				k=s[k] ? k*2 : k*2+1;
				if(k>n)
					break;
			}
		}
		printf("%d\n", k/2);
	}
	return 0;
}
