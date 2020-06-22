//Ԥ��������
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
using namespace std;
#define OK 1
#define OVERFLOW -2

//��������ṹ�����Ͷ���
typedef char TElemType;
typedef struct BiTNode {
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;

//���ַ���������ʽ����һ�ö�����
int CreateBiTree(BiTree &T) {
	char ch = getchar();
	if (ch == ' ')         //������' 'ʱ�������ĸ��ڵ�ΪNULL���Ӷ������÷�֧�ĵݹ�
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
//�������������
int Preorder(BiTree T)
{
	if (T) {
		cout << T->data << " ";
		Preorder(T->lchild);
		Preorder(T->rchild);
	}
	return OK;
}
//�������������
int InOrder(BiTree T) {
	if (T) {
		InOrder(T->lchild);
		cout << T->data << " ";
		InOrder(T->rchild);
	}
	return OK;
}
//�������������
int PostOrder(BiTree T) {
	if (T) {
		PostOrder(T -> lchild);
		PostOrder(T->rchild);
		cout << T->data << " ";
	}
	return OK;
}
//�����������˼��ͳ�ƶ�������Ҷ���ĸ���
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
//�����������˼��ͳ��ÿ�����ĺ��ӽ�����
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
//��������˳����������
int CreateBiTree_2(BiTree &T) 
{
	char c=getchar();
	if (c ==' ')            //������' 'ʱ�������ĸ��ڵ�ΪNULL���Ӷ������÷�֧�ĵݹ�
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
	BiTree T;               //����һ��ָ����������ڵ��ָ�� 
	cout << "���ַ������뷽ʽ����������:";
	CreateBiTree_2(T);
	cout << "������������ɣ�" << endl;
	cout << "���������������" << endl;
	Preorder(T);
	cout << endl;
	cout << "���������������" << endl;
	InOrder(T);
	cout << endl;
	cout << "���������������" << endl;
	PostOrder(T);
	cout << endl;
	int count=0;
	CountLeaf(T, count);
	cout << "�������Ľ�����Ϊ:" << count<<endl;
	cout << "��������ÿ�����ĺ��ӽ�����Ϊ:";
	ChildrenNode(T);
	cout << endl;
	return 0;
}