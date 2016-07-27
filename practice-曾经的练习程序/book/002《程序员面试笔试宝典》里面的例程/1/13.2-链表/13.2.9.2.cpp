/*
 * 实现链表排序：归并排序
 */

#include<iostream>
#define MAXSIZE 1024
#define LENGTH 8

using namespace std;

typedef struct{
	int r[MAXSIZE+1];
	int length;
}SqList;

void Merge(SqList SR, SqList &TR, int i, int m, int n){
	int j,k;
	for(j=m+1,k=i; i<=m&&j<=n; k++){
		if(SR.r[i]<=SR.r[j])
			TR.r[k]=SR.r[i++];
		else
			TR.r[k]=SR.r[j++];
	}
	while(i<=m)
		TR.r[k++]=SR.r[i++];
	while(j<=n)
		TR.r[k++]=SR.r[j++];
}

void MSort(SqList SR, SqList &TR1, int s, int t){
	int m;
	SqList TR2;
	if(s==t)
		TR1.r[s]=SR.r[t];
	else{
		m=(s+t)/2;
		MSort(SR, TR2, s, m);
		MSort(SR, TR2, m+1, t);
		Merge(TR2, TR1, s, m, t);
	}
}

void MergeSort(SqList &L){
	MSort(L,L,1,L.length);
}

int main(){
	int i;
	SqList L={{0,49,38,65,97,76,13,27},LENGTH};
	MergeSort(L);
	for(i=1; i<L.length; i++)
		cout<<L.r[i]<<" ";
	cout<<endl;
	return 0;
}
