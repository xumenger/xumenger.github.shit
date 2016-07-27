#include<stdio.h>
bin_search(int A[], int n, int key)
{
	int low, high, mid;
	low = 0;
	high = n-1;
	while(low<=high){
		mid = (low+high)/2;
		if(A[mid] == key)
			return mid;
		if(A[mid] < key)
			low = mid + 1;
		if(A[mid] > key)
			high = mid-1;
	}
	return -1;
}
