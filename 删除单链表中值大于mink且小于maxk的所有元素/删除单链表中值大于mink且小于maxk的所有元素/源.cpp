//预处理命令
#include<iostream>
#include<stdio.h>
#include<string.h> 
#include<stdlib.h>
using namespace std;

//函数状态定义
#define OK 1
#define TRUE 1
#define FALSE 0
#define ERROR -1
#define OVERFLOW -2

//链表储存结构定义
typedef int Status;
typedef struct ElemType {
	int no;
};
typedef struct LNode {
	ElemType *data;        //结点的数据域
	struct LNode *next; //结点的指针域
}LNode, *LinkList;

//链表的初始化
Status InitList(LinkList &L)
{
	L = new LNode; //生成新结点作为头结点，用头指针L指向头借点
	L->next = NULL;  //头结点的指针域置空
	return OK;
}

//在链表中输入学生信息；
int CreateList_R(LinkList &L, int n)
{
	LinkList r = L;
	for (int i = 0; i<n; i++)
	{
		LinkList p = new LNode;
		p->data = new ElemType;
		cin >> p->data->no;
		p->next = NULL;
		r->next = p;
		r = p;
	}
	return OK;
}
//输出链表中的学生信息
Status PrintList(LinkList L)
{
	LinkList p;
	p = L->next;
	while (p)
	{
		cout << p->data->no << " ";
		p = p->next;
	}
	cout << endl;
	return OK;
}
//删除链表中值大于mink且小于maxk的所有元素
Status Delete(LinkList &L,int mink,int maxk)
{
	LinkList p = L;
	while (p->next)
	{
		if (p->next->data->no < maxk && p->next->data->no > mink)
		{
			LinkList q = p->next;
			p->next = q->next;
			delete q->data;
			delete q;
		}
		p = p->next;
	}
	return OK;
}
//主程序
int main()
{
	LinkList L;  //定义链表L
	int n,mink,maxk;
	InitList(L);   //初始化链表
	cout << "开始构造链表 请输入链表中元素的个数：";
	cin >> n;
	CreateList_R(L, n);  //在链表输入信息
	PrintList(L);
	cout << "请输入要删除链表中的mink和maxk:";
	cin >> mink >> maxk;
	Delete(L,mink,maxk);
	cout << "删除之后的链表元素为:";
	PrintList(L);
}