//Ԥ��������
#include<iostream>
#include<stdio.h>
using namespace std;

#define OK 1
#define ERROR -1
#define OVERFLOW -1

typedef int QElemType;
typedef int Status;
//���е�˳�򴢴�ṹ
#define MAXQSIZE 1000
typedef struct SqQueue {
	QElemType *base;
	int front;
	int rear;
};
//˳����еĳ�ʼ��
Status InitQueue(SqQueue &Q) {
	Q.base = new QElemType(MAXQSIZE);
	if (!Q.base)
		exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return OK;
}
//����еĳ���
int QueueLength(SqQueue Q) {
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}
//���
Status EnQueue(SqQueue &Q, QElemType e) {
	if ((Q.rear + 1) % MAXQSIZE == Q.front)   //�ж��Ƿ����
		return ERROR;
	Q.base[Q.rear] = e;        //��Ԫ�ز����β
	Q.rear = (Q.rear + 1) % MAXQSIZE; //��βָ��+1
	return OK;
}
//����
Status DeQueue(SqQueue &Q, QElemType&e) {
	if (Q.front == Q.rear)  //�ӿ�
		return ERROR;
	e = Q.base[Q.front];      //�����ͷԪ��
	Q.front = (Q.front + 1) % MAXQSIZE;  //ָ��+1
	return OK;
}
//ȡѭ�����е�ͷԪ��
QElemType GetHead(SqQueue Q){
	if (Q.front != Q.rear)
		return Q.base[Q.front];
}
