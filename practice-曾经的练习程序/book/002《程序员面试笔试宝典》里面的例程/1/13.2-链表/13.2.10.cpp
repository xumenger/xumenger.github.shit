/*
 * 如何实现单链表交换任意两个元素
 */
#include<iostream>
using namespace std;

struct node{
	int data;
	node *next;
};

//返回钱驱结点
node *FindPre(node *head, node *p){
	node *q=head;
	while(q){
		if(q->next==p)
			return q;
		else
			q=q->next;
	}
	return NULL;
}

node *Swap(node *head, node *p, node *q){
	if(head==NULL || p==NULL || q==NULL){
		cout<<"invalid parameter:NULL"<<endl;
		return head;
	}
	if(p->data==q->data)
		return head;
	if(p->next == q){
		node * pre_p=FindPre(head, p);
		pre_p->next=q;
		p->next=q->next;
		q->next=p;
	}
	else if(q->next==p){
		node *pre_q=FindPre(head, q);
		pre_q->next=p;
		q->next=p->next;
		p->next=q;
	}
	else if(p != q){
		node *pre_p=FindPre(head, p);
		node *pre_q=FindPre(head, q);
		node *after_p=p->next;
		p->next=q->next;
		q->next=after_p;
		pre_p->next=q;
		pre_q->next=p;
	}
	return head;
}
