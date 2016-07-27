/*
 * 方法二：异或法
 */
/*
 * 根据异或法的计算方法，每两个相异的数执行亦或之后，结果为1，每两个相同
 * 的数异或之后，结果为0,所以数组a[N]的N个数异或的结果与1到N-1异或的结果
 * 再异或，得到的值即为所要求的值
 */

#include<stdio.h>

void xor_findDup(int *a, int N){
	int i;
	int result=0;
	for(i=0; i<N;i++)
		result^=a[i];
	for(i=1;i<N;i++)
		result^=i;
	printf("%d\n",result);
}

int main(){
	int a[]={1,2,3,4,5,6,7,8,1};
	xor_findDup(a,9);
	return 0;
}
