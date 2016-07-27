/*
 *如何分别使用递归和非递归实现二分查找算法
 */
/*
 *二分查找的时间复杂度是O(logn)，最坏情况下是O(n)
 */

#include<stdio.h>

//非递归算法
int BinarySearch1(int array[], int len, int findData){
	if(array==NULL || len<=0)	//必须先做判断，才能保证程序的安全
		return -1;
	
	int start=0, end=len-1;
	while(start <= end){
		int mid=start+(end-start)/2;	//debug经历，因为将(end-start)/2误写成(end+start)/2导致出现了错误
		if(array[mid] == findData)
			return mid;
		else if(findData < array[mid])
			end=mid-1;
		else
			start=mid+1;
	}
	return -1;
}

//递归算法
int BinarySearch2(int array[], int findData, int start, int end){
	if(start>end)
		return -1;
	int mid=start+(end-start)/2;

	if(array[mid]==findData)
		return mid;
	else if(findData < array[mid])
		return BinarySearch2(array, findData, start, end-1);
	else
		return BinarySearch2(array, findData, start+1, end);
}
int BinarySearchRecursion(int array[], int len, int findData){
	if(array==NULL || len<=0)
		return -1;
	return BinarySearch2(array, findData, 0, len-1);
}

int main(){
	int array[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	int len=sizeof(array)/sizeof(array[0]);
	int index1 = BinarySearch1(array, len, 4);
	int index2 = BinarySearchRecursion(array, len, 9);
	printf("%d %d\n",index1, index2);
	return 0;
}
