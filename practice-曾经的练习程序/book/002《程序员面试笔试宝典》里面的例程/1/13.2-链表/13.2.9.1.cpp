/*
 * 如何进行单链表排序
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}linklist;

linklist *head = NULL;

linklist *CreateList(int *arr, int len){
	int data;
	linklist *pCurrent, *rear;
	head = (linklist*)malloc(sizeof(linklist));
	rear=head;

	int count=0;
	while(count<len){
		pCurrent=(linklist*)malloc(sizeof(linklist));
		pCurrent->data=arr[count];
		rear->next=pCurrent;
		rear=pCurrent;
		count++;
	}
	rear->next=NULL;
	return head;
}

void ShowList(linklist *p){
	while(p){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

void BubbleSort(linklist *p){	//链表冒泡排序
	linklist *temp = p->next;
	linklist *node = p->next;
	int tmp;
	for(;temp->next;temp=temp->next){
		for(node=p->next; node->next; node=node->next){
			if(node->data > node->next->data){
				tmp=node->data;
				node->data=node->next->data;
				node->next->data=tmp;
			}
		}
	}
}

int main(){
	int array[]={3,4,5,1,2,-1,7};
	CreateList(array,sizeof(array)/sizeof(array[0]));
	ShowList(head->next);

	BubbleSort(head);
	ShowList(head->next);
	return 0;
}
