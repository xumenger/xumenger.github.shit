#include<stdio.h>
#include<stdlib.h>
#define N 9

typedef struct node
{
	int data[N];
	int length;
} SeqList;

int bi_search(SeqList *p, int k);

int main()
{
	SeqList sl;
	int i, j, k, t;
	printf("input the elements in escendant order:\n");
	i = 0;
	scanf("%d", &(sl.data[i]));
	while(i < N-1){
		scanf("%d", &t);
		if(t > sl.data[i]){
			i++;
			sl.data[i] = t;
		}else{
			printf("error, must bigger than %d\n", sl.data[i]);
		}
	}
	sl.length = N;
	printf("input the key:\n");
	scanf("%d", &k);
	j = bi_search(&sl, k);
	printf("-------------------\n");
	if(j >= 0){
		printf("found : data[%d]\n", j);
	}else{
		printf("%d is not been found\n", k);
	}

	return 0;
}

int bi_search(SeqList *p, int k)
{
	int first = 0;
	int end = p->length;
	int ptr;
	while(first != end){
		ptr = (first + end) / 2;
		if(k == p->data[ptr]){
			printf("%d", ptr);
			return ptr;
		}
		else if(k > p->data[ptr]){
			first = ptr;
		}
		else if(k < p->data[ptr]){
			end = ptr;
		}
	}
	return -1;

}
