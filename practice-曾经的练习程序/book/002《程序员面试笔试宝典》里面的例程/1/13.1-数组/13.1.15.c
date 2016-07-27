/*
 * 如何判定数组是否存在重复元素
 */
#include<stdio.h>

int isArrayRepeat(int *a, int n){
	int i=0;
	int j=-1;
	for(i=0; i<n; i++){
		j=a[i];
		if(i==j)
			continue;
		if(a[i]==a[j])
			return 1;
		a[i]=a[j];
		a[j]=j;
	}
	return 0;
}

int main(){
	int result = -1;
	int a[10]={10,9,5,4,7,6,1,3,2,9};
	result=isArrayRepeat(a,10);
	if(result)
		printf("yes\n");
	else
		printf("no\n");
	return 0;
}
