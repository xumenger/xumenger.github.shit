/*
 *如何找出数组中重复次数最多的数
 */
/*
 *方法二：使用map映射表，通过引入map表（map是STL的一个关联容器，它提供一对一的数据处理能力，其中第一个为关键字，每个
 *关键字只能在map中出现一次，第二个称为该关键字的值）来记录每一个元素出现的次数，然后判断次数大小，进而找出重复次数
 *最多的元素
 */

#include<iostream>
#include<map>
using namespace std;

bool findMostFrequenceInArray(int *a, int size, int &val){
	if(size==0)
		return false;
	map<int,int> m;	//注意C++中map的使用方法
	for(int i=0; i<size; i++){
		if(++m[a[i]]>=m[val])
			val=a[i];
	}
	return true;
}

int main(){
	int a[]={1,2,3,4,4,4,5,5,5,5,6};;
	int val=0;
	if(findMostFrequenceInArray(a, 11, val))
		cout<<val<<endl;
	int b[]={1,5,4,3,4,4,5,4,5,5,6,6,6,6,6};
	if(findMostFrequenceInArray(b, 15, val))
		cout<<val<<endl;
	return 0;
}
