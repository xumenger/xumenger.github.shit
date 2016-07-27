/*
 * 如何寻找单链表的中间结点
 */
#include<stdio.h>

struct ListNode{
	int key;
	ListNode *next;
};

void SearchMid(ListNode *head, ListNode *mid){
	ListNode *temp=head;
	while(head->next->next != NULL){
		head=head->next->next;
		temp=temp->next;
		mid=temp;
	}
}
