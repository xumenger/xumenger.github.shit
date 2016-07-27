/*
 *如何在O(n)的时间复杂度内找出数组中出现次数超过一半的数
 */
/*
 *方法一：每次取出两个不同的数，剩下的数字中出现次数超过一般的数字肯定还是比其他数字多，将规模缩小化。
 *如果每次删除两个不同的数（不管包不包括最高频数），那么在剩余的数字中，原来最高频数的出现的概率一样
 *超过了50%，不断重复这个过程，最后剩下的将全是同样的数字，即最高频数，这种方法避免了排序，时间复杂度为O(n)
 */

#include<stdio.h>

int FindMostApperse(int *num, int len){
	int candidate = 0;
	int count = 0;
	int i = 0;
	for(i=0; i<len; i++){
		if(count == 0){
			candidate = num[i];
			count = 1;
		}
		else{
			if(candidate == num[i])
				count++;
			else
				count--;
		}
	}
	return candidate;
}

int main(){
	int arr[] = {2,1,1,2,3,1,1,1};
	int len = sizeof(arr)/sizeof(arr[0]);
	printf("%d\n", FindMostApperse(arr, len));
	return 0;
}
