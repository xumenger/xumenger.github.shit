/*
 * 如何使用非递归算法求二叉树的深度
 */

typedef struct Node{
	char data;
	struct Node *LChild;
	struct Node *RChild;
	struct Node *Parent;
}BNode, *BTree;

//递归方法
//后序遍历求，先求出左子树的深度，在求出右子树的深度，最后去较大者加1
//即为二叉树深度

int PostTreeDepth(BTree root){
	int leftheight, rightheight, max;
	if(root!=NULL){
		leftheight=PostTreeDepth(root->LChild);
		rightheight=PostTreeDepth(root->RChild);
		max=leftheight>rightheight ? leftheight : rightheight;
		return (max+1);
	}
	else
		return 0;
}
