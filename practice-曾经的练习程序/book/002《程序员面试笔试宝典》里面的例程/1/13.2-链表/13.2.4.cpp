/*
 * 如何实现单链表的插入、删除操作
 */

Status InsertList(LinkList head, DataType x, int i){
	ListNode *p;
	p=head;
	int j=1;
	while(p->next && j<i){
		p=p->next;
		++j;
	}
	if(p==NULL){
		printf("Position Error\n");
		return ERROR;
	}
	s=(ListNode *)malloc(sizeof(ListNode));
	s->data=x;
	s->next=p->next;
	p->next=s;
	return OK;
}

Status DeleteList(LinkList head int i){
	ListNode *p,*r;
	p=head;
	int j=1;
	while(p->next && j<i){
		p=p->next;
		++j;
	}
	if(p==NULL || p->next==NULL || j>i){
		printf("Position Error\n");
		return ERROR;
	}
	r=p->next;
	p->next=r->next;
	free(r);	//一定不要忘记了free内存
	return OK;
}
