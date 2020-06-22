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
typedef int ElemType;
typedef int Status;
typedef struct LNode {
	char no[20];        //结点的数据域
	char name[20];
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
		cin >> p->no >> p->name;
		p->next = NULL;
		r->next = p;
		r = p;
	}
	return OK;
}
//在链表中按学号进行查找
LNode *LocateElem(LinkList L, char *e)
{
	LinkList p;
	p = L->next;   //初始化，p指向首元结点
	while (p&&strcmp(p->no, e) != 0)
		p = p->next;
	return p;//查找成功返回值为e的结点地址，查找失败则为NULL
}
//在链表中插入一个新的学生信息
Status ListInsert(LinkList &L, int i, char *no, char *name)
{
	LinkList p;
	int j = 0;
	p = L;
	while (p && (j<i - 1))     //查找第i-1个结点，p指向该结点
	{
		p = p->next;
		++j;
	}
	if (!p || j>i - 1)
		return ERROR;     //i>n+1或者i<1
	LinkList s = new LNode;
	strcpy_s(s->no, no);
	strcpy_s(s->name, name);
	s->next = p->next;
	p->next = s;
	return OK;
}
//在链表中删除一个已有的学生信息
Status ListDelete(LinkList &L, int i)
{
	LinkList p = L;
	int j = 0;
	while ((p->next) && (j<i - 1))   //查找第i-1个结点，p指向该结点
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || (j>i - 1))
		return ERROR;           //当i>n或i<1时，删除位置不合理
	LinkList q = p->next;
	p->next = q->next;
	delete q;
	return OK;
}
//输出链表中的学生信息
Status PrintList(LinkList L)
{
	LinkList p;
	p = L->next;
	while (p)
	{
		cout << p->no << " " << p->name << endl;
		p = p->next;
	}
	return OK;
}
//主程序
int main()
{
	LinkList L;  //定义链表L
	char e1[20], e2[20], e3[20];
	LNode *loc;
	LinkList stu;
	int pos, i;
	InitList(L);   //初始化链表
	cout << "请输入要进行输入的两个学生的学号和姓名" << endl;
	CreateList_R(L, 2);  //在链表中输入学生信息
	PrintList(L);
	cout << "请输入要查找的学生的学号";
	cin >> e1;
	loc = LocateElem(L, e1);
	cout << loc << "\n";
	cout << "请输入要插入的位置和数据";
	cin >> pos;
	cin >> e2 >> e3;
	ListInsert(L, pos, e2, e3);
	PrintList(L);
	cout << "请输入要删除的第i个元素：";
	cin >> i;
	ListDelete(L, i);
	PrintList(L);
}