//Ԥ��������
#include<iostream>
#include<stdio.h>
using namespace std;

#define OK 1
#define ERROR -1

typedef int ElemType;
typedef int Status;
//������Ĵ���ṹ
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}*LinkList;
//����Ͷ��еĴ���ṹ
typedef struct LQ {
	LinkList Link;  //����ͷָ��
	LinkList rear;  //��βָ��
}*Lq;
//��ʼ��
Status InitList(Lq &L) {
	L = new LQ;
	LinkList p= new LNode;
	L->Link = p;
	L->Link->next = NULL;
	L->rear = L->Link; //�ö�βָ��ָ�������ͷ�ڵ�
	return OK;
}
//β�巨��ʼ������
Status CreateList_R(Lq &L){
	int i;
	cout << "������Ҫ������Ԫ�ظ���:";
	cin >> i;
	cout << "����������Ԫ�ص�������:" << endl;
	for (int j = 0; j < i; j++) {
		LinkList p = new LNode;
		cin >> p->data;
		p->next = NULL;
		L->rear->next = p;
		L->rear = p;
	}
	return OK;
}
//�ÿն���
Status Empty(Lq &L){
	L->Link->next = NULL;
	L->rear = L->Link;
	return OK;
}
//�ж϶����Ƿ�Ϊ��
bool Determine(Lq L) {
	if (L->Link->next == NULL)  //��Ϊ���򷵻�1��֮����0
		return 1;
	else
		return 0;
}
//���
Status EnQueue(Lq &L,ElemType e) {
	LinkList p = new LNode;
	p->data = e;
	p->next = NULL;
	L->rear->next = p;
	L->rear = p;
	return OK;
}
//����
Status DeQueue(Lq &L, ElemType &e) {
	if (Determine(L))
		return ERROR;
	LinkList p = L->Link->next;
	L->Link->next = p->next;
	e = p->data;
	if (p == L->rear)
		Empty(L);
	delete p;
	return OK;
}
//�������Ԫ��
Status Print(Lq L) {
	LinkList p = L->Link ->next;
	while(p){
		cout << p->data<<" ";
		p = p->next;
	}
	return OK;
}
int main() {
	Lq L;
	ElemType e;
	InitList(L);
	cout << "��ʼ����ɣ���ʼβ�巨��������" << endl;
	CreateList_R(L);
	cout << "��������Ҫ��ӵ�Ԫ��e:";
	cin >> e;
	EnQueue(L, e);
	cout << "��ʼ����һ��Ԫ�� ";
	DeQueue(L, e);
	cout << "����Ԫ��Ϊ:" << e << endl;
	cout << "������ʣ��Ԫ��Ϊ;";
	Print(L);
	cout << endl;
	cout << "��ʼ�ÿն���" << endl;
	Empty(L);
	if (Determine(L) == 1)
		cout << "�Ѿ��ɹ��ÿն���" << endl;
	else
		cout << "�ÿ�ʧ��" << endl;
}