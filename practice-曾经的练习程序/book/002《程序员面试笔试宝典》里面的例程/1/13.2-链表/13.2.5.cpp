/*
 * 如何找出单链表的倒数第k个元素
 */
template<class T>
struct ListNode{
	T data;
	ListNode *next;
};

template<class T>
ListNode<T>* FindElem(ListNode<T> *head, int k){
	ListNode<T> *ptr1, *ptr2;
	ptr1=ptr2=head;
	int i=0;
	for(int i=0; i<k; i++)
		ptr1=ptr1->next;
	while(ptr1!=NULL){
		ptr1=ptr1->next;
		ptr2=ptr2->next;
	}
	return ptr2;
}
