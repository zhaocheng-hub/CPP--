//预处理命令
#include<iostream>
#include<stdio.h>
using namespace std;

#define OK 1
#define ERROR -1
#define OVERFLOW -1

typedef int QElemType;
typedef int Status;
//队列的链式储存结构
typedef struct QNode {
	QElemType data;
	struct QNode *next;
}*QueuePtr;
typedef struct LinkQueue{
	QueuePtr front;
	QueuePtr rear;
};
//链式队列的初始化
Status InitQueue(LinkQueue &Q) {
	Q.front = Q.rear =new QNode;
	Q.front->next = NULL;
	return OK;
}
//链队的入队
Status EnQueue(LinkQueue &Q,QElemType e) {
	QueuePtr p = new QNode;
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}
//链队的出队
Status DeQueue(LinkQueue &Q, QElemType &e) {
	if (Q.front == Q.rear)  //队空
		return ERROR;
	QueuePtr p = Q.front->next;
	e = p->data;
	Q.front->next=p->next;
	if (Q.rear = p)
		Q.rear = Q.front;
	delete p;
	return OK;
}
//取队头元素
QElemType GetHead(LinkQueue Q) {
	if (Q.front != Q.rear)
		return Q.front->next->data;
