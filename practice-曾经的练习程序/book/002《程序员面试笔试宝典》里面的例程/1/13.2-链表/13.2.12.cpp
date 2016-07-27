/*
 * 如何判断两个单链表（无环）是否交叉
 */

bool IsIntersect(Node *list1, Node *list2, Node*& value){
	value = NULL;
	if(list1==NULL || list2==NULL)
		return false;
	Node *temp1=list1, *temp2=list2;
	int size1=0, size2=0;
	while(temp1->next){
		temp1=temp1->next;
		++size1;
	}
	while(temp2->next){
		temp2=temp2->next;
		++size2;
	}

	if(temp1==temp2){
		if(size1>size2){
			while(size1-size2>0){
				list1=list1->next;
				--size1;
			}
		}
		if(size2>size1){
			while(size2-size1>0){
				list2=list2->next;
				--size2;
			}
		}
		while(list1 != list2){
			list1=list1->next;
			list2=list2->next;
		}
		value=list1;
		return true;
	}
	else
		return false;
}

