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
typedef int Status;
typedef struct ElemType {
	int no;
};
typedef struct LNode {
	ElemType *data;        //����������
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
		p->data = new ElemType;
		cin >> p->data->no;
		p->next = NULL;
		r->next = p;
		r = p;
	}
	return OK;
}
//��������е�ѧ����Ϣ
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
//ɾ��������ֵ����mink��С��maxk������Ԫ��
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
//������
int main()
{
	LinkList L;  //��������L
	int n,mink,maxk;
	InitList(L);   //��ʼ������
	cout << "��ʼ�������� ������������Ԫ�صĸ�����";
	cin >> n;
	CreateList_R(L, n);  //������������Ϣ
	PrintList(L);
	cout << "������Ҫɾ�������е�mink��maxk:";
	cin >> mink >> maxk;
	Delete(L,mink,maxk);
	cout << "ɾ��֮�������Ԫ��Ϊ:";
	PrintList(L);
}