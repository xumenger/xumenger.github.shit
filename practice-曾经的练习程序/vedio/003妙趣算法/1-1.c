#include<stdio.h>
#include<stdlib.h>
#define MaxSize 10

void insertElem(int Sqlist[], int *len, int i, int x)
{
	int t;
	if(*len==MaxSize || i<1 || i>*len+1){
		printf("This insert is illegal\n");
		return ;
	}
	for(t=*len-1; t>=i-1; t--)
		Sqlist[t+1] = Sqlist[t];
	Sqlist[i-1] = x;
	*len = *len+1;
}

void DelElem(int Sqlist[], int *len, int i)
{
	int j;
	if(i<1 || i>*len){
		printf("This delete is illegal\n");
		return ;
	}
	for(j=i; j<=*len-1; j++)
		Sqlist[j-1] = Sqlist[j];
	*len = *len-1;
}

int main()
{
	int Sqlist[MaxSize];
	int len;
	int i;
	len = 6;
	for(i=0; i<6; i++)
		scanf("%d", &Sqlist[i]);
	printf("\nThe spare length is %d\n", MaxSize-len);
	insertElem(Sqlist, &len, 3, 0);
	for(i=0; i<len; i++)
		printf("%d ", Sqlist[i]);
	printf("\nThe spare length is %d\n", MaxSize-len);
	insertElem(Sqlist, &len, 11, 0);
	DelElem(Sqlist, &len, 5);
	for(i=0; i<len; i++)
		printf("%d ", Sqlist[i]);
	printf("\nThe spare length is %d\n", MaxSize-len);
	return 0;
}
