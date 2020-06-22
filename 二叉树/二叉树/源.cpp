//预处理命令
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
using namespace std;
#define OK 1
#define OVERFLOW -2

//二叉链表结构体类型定义
typedef char TElemType;
typedef struct BiTNode {
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;

//以字符串输入形式创建一棵二叉树
int CreateBiTree(BiTree &T) {
	char ch = getchar();
	if (ch == ' ')         //当遇到' '时，令树的根节点为NULL，从而结束该分支的递归
		T = NULL;
	else {
		if (!(T = new BiTNode))
			exit(OVERFLOW);
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return OK;
}
//先序遍历二叉树
int Preorder(BiTree T)
{
	if (T) {
		cout << T->data << " ";
		Preorder(T->lchild);
		Preorder(T->rchild);
	}
	return OK;
}
//中序遍历二叉树
int InOrder(BiTree T) {
	if (T) {
		InOrder(T->lchild);
		cout << T->data << " ";
		InOrder(T->rchild);
	}
	return OK;
}
//后序遍历二叉树
int PostOrder(BiTree T) {
	if (T) {
		PostOrder(T -> lchild);
		PostOrder(T->rchild);
		cout << T->data << " ";
	}
	return OK;
}
//以先序遍历的思想统计二叉树中叶结点的个数
int CountLeaf(BiTree &T, int &count){
	if (T) {
		if ((!T->lchild) && (!T->rchild))
			count++;
		else {
			CountLeaf(T->lchild, count);
			CountLeaf(T->rchild, count);
		}
	}
	return OK;
}
//以先序遍历的思想统计每个结点的孩子结点个数
int ChildrenNode(BiTree T) {
	BiTree p = new BiTNode;
	p = T;
	if (T) {
		int n = 0;
		if (T->lchild)
			n++;
		if (T->rchild)
			n++;
		cout << n << " ";
		ChildrenNode(T->lchild);
		ChildrenNode(T->rchild);
	}
	return OK;
}
//按照先序顺序建立二叉树
int CreateBiTree_2(BiTree &T) 
{
	char c=getchar();
	if (c ==' ')            //当遇到' '时，令树的根节点为NULL，从而结束该分支的递归
		T = NULL;
	else
	{
		T = new BiTNode;
		T->data = c;
		CreateBiTree_2(T->lchild);
		CreateBiTree_2(T->rchild);
	}
	return OK;
}
int main(){
	BiTree T;               //声明一个指向二叉树根节点的指针 
	cout << "以字符串输入方式创建二叉树:";
	CreateBiTree_2(T);
	cout << "二叉树创建完成！" << endl;
	cout << "先序遍历二叉树：" << endl;
	Preorder(T);
	cout << endl;
	cout << "中序遍历二叉树：" << endl;
	InOrder(T);
	cout << endl;
	cout << "后序遍历二叉树：" << endl;
	PostOrder(T);
	cout << endl;
	int count=0;
	CountLeaf(T, count);
	cout << "二叉树的结点个数为:" << count<<endl;
	cout << "二叉树的每个结点的孩子结点个数为:";
	ChildrenNode(T);
	cout << endl;
	return 0;
}