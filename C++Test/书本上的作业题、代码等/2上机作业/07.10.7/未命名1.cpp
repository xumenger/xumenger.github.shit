#include <string>
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

struct Tnode
{
    string word;
    int count;;
    Tnode *left;
    Tnode *right;
};
struct treenode
{
    string data;
    treenode *left;
    treenode *right;
};
typedef Tnode* PTree;

int main()
{
    
    system("pause");
    return 0;
}

Tnode* InsertLL(PTree pnr,Tnode* pn)
{//将新节点插入到当前节点的左子树，并将原来的内容放在新节点的左支
       
    assert(pnr!=NULL);
    assert(pn!=NULL);
    pn->right=pnr->right;
    pnr->right=pn;
    return pnr;
       
}

Tnode* InsertLR(PTree pnr, Tnode* pn)
{//将新节点插入到当前节点的左子树，并将原来的内容放在新节点的右支
    assert(pnr != NULL);
    assert(pn != NULL);
    pn->left = pnr->right;
    pnr->right = pn;
    return pnr;
}

Tnode* InsertLL_word(PTree pnr, string& word)
{//将新节点插入到当前节点的左子树，并将原来的内容放在新节点的左支
    assert(pnr != NULL);
    Tnode* pn = IniTnode(word);
    return InsertLL(pnr, pn);
}

Tnode* InsertLR_word(PTree pnr, string& word)
{//将新节点插入到当前节点的左子树，并将原来的内容放在新节点的右支
    assert(pnr != NULL);
    Tnode* pn = IniTnode(word);
    return InsertLR(pnr, pn);
}

void FreeTree(PTree toFree)
{//树的回收 
   if(toFree == NULL)
    return ;
    //释放左树
    if(toFree->left != NULL)
    FreeTree(toFree->left);
    //释放右树
    if(toFree->right != NULL)
    FreeTree(toFree->right);
    //释放本节点
    FreeTnode(toFree);   
}

void PrintTreeLMR(const PTree proot)
{//树的中序遍历打印
    if(proot == NULL)
    return ;
    char buf[512];
    //打印左树
    if(proot->left != NULL)
    PrintTreeLMR(proot->left);
    //打印本节点
    cout<<ToString(buf, *proot)<<endl<<"------------------"<<endl;
    //打印右树
    if(proot->right != NULL)
    PrintTreeLMR(proot->right);
 
}
