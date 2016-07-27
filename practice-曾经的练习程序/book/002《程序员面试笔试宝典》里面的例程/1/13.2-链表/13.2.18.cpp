/*
 * 如何删除结点的前驱结点
 */
void DeleteNode(ListNode *s){
	ListNode *p, *q; 
	p=s;
	while(p->next->next!=s){
		q=p;
		p=p->next;
	}
	q->next=s;
	free(p);	//!!!!!!!!!!特别重要的一步
}
