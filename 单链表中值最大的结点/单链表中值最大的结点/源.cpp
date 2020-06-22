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
int CreateList_R(LinkList &L,int n)
{
	LinkList r = L;
	for (int i = 0; i<n; i++)
	{
		LinkList p = new LNode;
		p->data = new ElemType;
		cin >>p->data->no;
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
		cout << p->data->no<<"  ";
		p = p->next;
	}
	cout << endl;
	return OK;
}
//���ҳ���Ϊn�ĵ�������ֵ���Ľ��
LNode* FindNode(LinkList L)
{
	LinkList p=L->next, e;
	int max = p->data->no;
	e = p;
	while (p)
	{
		if (max < p->data->no)
		{
			max = p->data->no;
			e = p;
		}
		p = p->next;
	}
	return e;
}
//������
int main()
{
	LinkList L;  //��������L
	int n;
	InitList(L);   //��ʼ������
	cout << "��ʼ�������� ������������Ԫ�صĸ�����" ;
	cin >> n;
	CreateList_R(L,n);  //������������Ϣ
	PrintList(L);
	LNode* e = FindNode(L);
	cout << "����Ϊ" << n << "�ĵ�������ֵ���Ľ��ĵ�ַΪ" << e;
	cout << "��ֵΪ:" << e->data->no << endl;
}