//Ԥ��������
#include<iostream>
#include<stdio.h>
#include<string.h> 
#include<stdlib.h>
using namespace std;

//����״̬����
#define OK 1
#define TRUE 1
#define FALSE 0
#define ERROR -1
#define OVERFLOW -2

//������ṹ����
typedef int ElemType;
typedef int Status;
typedef struct LNode {
	char no[20];        //����������
	char name[20];
	struct LNode *next; //����ָ����
}LNode, *LinkList;

//����ĳ�ʼ��
Status InitList(LinkList &L)
{
	L = new LNode; //�����½����Ϊͷ��㣬��ͷָ��Lָ��ͷ���
	L->next = NULL;  //ͷ����ָ�����ÿ�
	return OK;
}

//������������ѧ����Ϣ��
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
//�������а�ѧ�Ž��в���
LNode *LocateElem(LinkList L, char *e)
{
	LinkList p;
	p = L->next;   //��ʼ����pָ����Ԫ���
	while (p&&strcmp(p->no, e) != 0)
		p = p->next;
	return p;//���ҳɹ�����ֵΪe�Ľ���ַ������ʧ����ΪNULL
}
//�������в���һ���µ�ѧ����Ϣ
Status ListInsert(LinkList &L, int i, char *no, char *name)
{
	LinkList p;
	int j = 0;
	p = L;
	while (p && (j<i - 1))     //���ҵ�i-1����㣬pָ��ý��
	{
		p = p->next;
		++j;
	}
	if (!p || j>i - 1)
		return ERROR;     //i>n+1����i<1
	LinkList s = new LNode;
	strcpy_s(s->no, no);
	strcpy_s(s->name, name);
	s->next = p->next;
	p->next = s;
	return OK;
}
//��������ɾ��һ�����е�ѧ����Ϣ
Status ListDelete(LinkList &L, int i)
{
	LinkList p = L;
	int j = 0;
	while ((p->next) && (j<i - 1))   //���ҵ�i-1����㣬pָ��ý��
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || (j>i - 1))
		return ERROR;           //��i>n��i<1ʱ��ɾ��λ�ò�����
	LinkList q = p->next;
	p->next = q->next;
	delete q;
	return OK;
}
//��������е�ѧ����Ϣ
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
//������
int main()
{
	LinkList L;  //��������L
	char e1[20], e2[20], e3[20];
	LNode *loc;
	LinkList stu;
	int pos, i;
	InitList(L);   //��ʼ������
	cout << "������Ҫ�������������ѧ����ѧ�ź�����" << endl;
	CreateList_R(L, 2);  //������������ѧ����Ϣ
	PrintList(L);
	cout << "������Ҫ���ҵ�ѧ����ѧ��";
	cin >> e1;
	loc = LocateElem(L, e1);
	cout << loc << "\n";
	cout << "������Ҫ�����λ�ú�����";
	cin >> pos;
	cin >> e2 >> e3;
	ListInsert(L, pos, e2, e3);
	PrintList(L);
	cout << "������Ҫɾ���ĵ�i��Ԫ�أ�";
	cin >> i;
	ListDelete(L, i);
	PrintList(L);
}