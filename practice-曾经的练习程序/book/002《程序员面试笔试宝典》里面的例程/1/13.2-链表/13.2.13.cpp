/*
 * 如何删除单链表中的重复结点
 */
link delSame1(link head){
	link pointer, temp=head;

	if(head->next==NULL)
		return head;
	head->next = delSame(head-next);
	pointer=head->next;
	while(pointer != NULL){
		if(head->number==pointer->number){
			temp->next=pointer->next;
			free(pointer);	//!!!!!!!
			pointer=temp->next;
		}
		else{
			pointer=pointer->next;
			temp=temp->next;
		}
	}
	return head;
}

