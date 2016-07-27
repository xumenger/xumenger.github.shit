/*
 * 如何实现单链表反转
 */
#include<stdio.h>

struct ListNode{
	int key;
	ListNode *next;
};

ListNode *ReverseIteratively(ListNode *head){
	ListNode* pReversedHead = NULL;
	ListNode* pNode = pHead;
	ListNode* pPrev = NULL;
	while(pNode != NULL){
		ListNode *pNext=pNode->next;
		if(pNext==NULL)
			pReversedHead=pNode;
		pNode->next=pPrev;
		pPrev=pNode;
		pNode=pNext;
	}
	return pReversedHead;
}
