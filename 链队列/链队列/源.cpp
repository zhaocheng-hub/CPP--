//Ԥ��������
#include<iostream>
#include<stdio.h>
using namespace std;

#define OK 1
#define ERROR -1
#define OVERFLOW -1

typedef int QElemType;
typedef int Status;
//���е���ʽ����ṹ
typedef struct QNode {
	QElemType data;
	struct QNode *next;
}*QueuePtr;
typedef struct LinkQueue{
	QueuePtr front;
	QueuePtr rear;
};
//��ʽ���еĳ�ʼ��
Status InitQueue(LinkQueue &Q) {
	Q.front = Q.rear =new QNode;
	Q.front->next = NULL;
	return OK;
}
//���ӵ����
Status EnQueue(LinkQueue &Q,QElemType e) {
	QueuePtr p = new QNode;
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}
//���ӵĳ���
Status DeQueue(LinkQueue &Q, QElemType &e) {
	if (Q.front == Q.rear)  //�ӿ�
		return ERROR;
	QueuePtr p = Q.front->next;
	e = p->data;
	Q.front->next=p->next;
	if (Q.rear = p)
		Q.rear = Q.front;
	delete p;
	return OK;
}
//ȡ��ͷԪ��
QElemType GetHead(LinkQueue Q) {
	if (Q.front != Q.rear)
		return Q.front->next->data;
