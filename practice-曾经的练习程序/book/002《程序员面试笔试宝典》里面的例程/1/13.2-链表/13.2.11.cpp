/*
 * 如何检验一个较大的链表是否有环
 */
struct listtype{
	int data;
	struct listtype *next;
};

typedef struct listtype *list;

int isLoop(list sll){
	list fast=sll;
	list slow=sll;
	if(fast==NULL){	//安全性检验
		return -1;
	}

	while(fast && fast->next){
		fast=fast->next->next;
		slow=slow->next;
		if(fast==slow)
			return 1;
	}
	return !(fast==NULL)||(fast->next==NULL);
}
