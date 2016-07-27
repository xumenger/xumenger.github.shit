/*
 *在已经有序的数组中，找出给定数字出现的次数
 */
/*
 *该方法要在二分查找的基础上改进（使用二分查找法就是要利用数组已经有序这个优点，所以以后解题，一定要考虑所有给定条件，充分利用）,
 *设数组array为递增序列，需要查找的元素为findData，为了求解给定数字的出现次数，可以分别寻
 *找findData在array中最先出现的位置和最后出现的位置，通过两者相减再加一即可求出。
 *编码的时候，用一个变量last来存储本次查找到的位置，然后根据情况变换查找方向，就可以确定最
 *先出现的位置的下标left和最后出现的位置的下标right的值
 */
#include<stdio.h>

//isLeft标记的值是否在左边
int BinarySearch(int *a, int length, int num, bool isLeft){
	int left=0, right=length-1;
	int last=0;
	while(left <= right){
		int mid=(left+right)/2;
		if(a[mid] < num)
			left = mid+1;
		else if(a[mid] > num)
			right = mid-1;
		else{
			last=mid;
			if(isLeft)
				right=mid-1;
			else
				left=mid+1;
		}
	}
	return last>0?last : -1;
}

int main(){
	int array[]={0,1,2,3,3,3,3,3,3,3,3,3,4,5,6,7,11};
	int Lower = BinarySearch(array,sizeof(array)/sizeof(array[0]),3,true);
	int Upper = BinarySearch(array,sizeof(array)/sizeof(array[0]),3,false);
	printf("%d\n",Upper-Lower+1);
	return 0;
}
