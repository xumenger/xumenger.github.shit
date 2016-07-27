/*
 * 如何判断二叉树是不是平衡二叉树
 */
/*
 * 平衡二叉树：每个节点的左右子树的高度差小于等于1,只需在计算二叉树的
 * 高度时，同时判断左右子树的高度差即可
 */

int TreeHeight(const Node *root, bool &balanced){
	const int LHeight=root->left ? TreeHeight(root->left, balanced)+1 :0;
	if(!balanced)
		return 0;
	const int RHeight=root->right ? TreeHeight(root->right, balanced)+1 : 0;
	if(!balanced)
		return 0;

	const int diff = LHeight-RHeight;
	if(diff<-1 || diff>1)
		balanced = false;
	return(LHeight>RHeight ? LHeight : RHeight);
}

bool IsBalancedTree(const Node *root){
	bool balanced = true;
	if(root)
		TreeHeight(root, balanced);
	return balanced;
}
