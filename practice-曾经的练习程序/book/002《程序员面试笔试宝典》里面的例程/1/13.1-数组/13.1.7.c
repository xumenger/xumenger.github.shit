/*
 *如何计算两个有序整形数组的交集
 */
/*
 *方法一：采用二路归并来遍历两个数组
 *		设两个数组分别为array1[n1]和array2[n2]，分别以i，j从头开始遍历两个数组。在遍历过程中，如果当前遍历位置的array1[i]和
 *array2[j]相等，则此数为两个数组的交集，记录下来，并继续向后遍历array1和array2.
 *		如果array[i]大于array2[j]，则需要继续向后遍历array2,如果array1[i]小于array2[j]，则需要继续向后遍历array1,直到有一个
 *数组结束遍历为止
 */

#include<stdio.h>
int mixed(int array1[], int n1, int array2[], int n2, int mixed){	//可以使用mixed来保存最后的交集
	int i=0, j=0, k=0;
	while(i<n1 && j<n2){
		if(array1[i]==array2[j]){
			mixed[k++]=array1[i];
			i++;
			j++;
		}
		else if(arrayi[i]>array2[j])
			j++;
		else
			i++;
	}
	return k;
}
