/*
 * 如何合并两个有序链表（非交叉）
 */

Node *MergeRecursive(Node *head1, Node head2){
	if(head1==NULL)
		return head2;
	if(head2==NULL)
		return head1;

	Node *head=NULL;
	if(head1->data<head2->data){
		head=head1;
		head->next=MergeRecursive(head->next, head2);
	}
	else{
		head=head2;
		head->next=MergeRecursive(head1, head->next);
	}
	return head;
}

Node *Merge(Node *head, Node *head1, Node *head2){
	Node *tmp=head;
	while(NULL != head1 && NULL != head2){
		if(head1->data < head2->data){
			tmp->next=head1;
			tmp=head1;
			head1=head1->next;
		}
		else{
			tmp->next=head2;
			tmp=head2;
			head2=head2->next;
		}
	}
	if(NULL != head1)
		tmp->next=head1;
	if(NULL != head2)
		tmp->next=head2;

	return tmp;
}
