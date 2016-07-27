/*
 * 如何判断两棵二叉树是否相等
 */
/*
 * 递归方法：A、B两棵树相等，当且仅当rootA->data==rootB->data，而且
 * A和B的左右子树都相等或者左右互换相等
 */
int compTree(TreeNode *tree1, TreeNode *tree2){
	if(!tree1 && !tree2)
		return 1;
	if((tree1&&!tree2)||(!tree1&&tree2))
		return 0;
	if(tree1 && tree2){
		if(tree1->data==tree2->data){
			if(compTree(tree1->leftChild,tree2->leftChild))
				return compTree(tree1->rightChild,tree2->rightChild);
			else if(comTree(tree1->leftChild,tree2->rightChild))
				return compTree(tree1->rightChild,tree2->leftChild);
		}
	}
	return 0;	//结束条件一定要有
}
