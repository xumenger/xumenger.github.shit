/*
 * 如何从尾到头输出单链表
 */
#include<stdio.h>
struct ListNode{
	int key;
	ListNode *next;
}

//使用递归的方法
void PrintListPeversely(ListNode *head){
	if(head != NULL)
		PrintListPerversely(head->next);
	printf("%d",head->key);
}
