/*
 * 如何递归实现二叉树的遍历
 */

//先序
void PreOrder(BTree *tree){
	if(tree==NULL)
		return;
	Operator(tree->data);
	if(tree->lchild!=NULL)
		PreOrder(tree->lchild);
	if(tree->rchild!=NULL)
		PreOrder(tree->rchild);
}

//中序
void MidOrder(BTree *tree){
	if(tree==NULL)
		return;
	if(tree->lchild!=NULL)
		MidOrder(tree->lchild);
	Operator(tree->data);
	if(tree->rchild!=NULL)
		MidOrder(tree->rchild);
}

//后序
void PostOrder(BTree *tree){
	if(tree==NULL)
		return;
	if(tree->lchild!=NULL)
		PostOrder(tree->lchild);
	if(tree->rchild!=NULL)
		PostOrder(tree->rchild);
	Operator(tree->data);
}
