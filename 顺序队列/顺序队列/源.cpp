//预处理命令
#include<iostream>
#include<stdio.h>
using namespace std;

#define OK 1
#define ERROR -1
#define OVERFLOW -1

typedef int QElemType;
typedef int Status;
//队列的顺序储存结构
#define MAXQSIZE 1000
typedef struct SqQueue {
	QElemType *base;
	int front;
	int rear;
};
//顺序队列的初始化
Status InitQueue(SqQueue &Q) {
	Q.base = new QElemType(MAXQSIZE);
	if (!Q.base)
		exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return OK;
}
//求队列的长度
int QueueLength(SqQueue Q) {
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}
//入队
Status EnQueue(SqQueue &Q, QElemType e) {
	if ((Q.rear + 1) % MAXQSIZE == Q.front)   //判断是否队满
		return ERROR;
	Q.base[Q.rear] = e;        //新元素插入队尾
	Q.rear = (Q.rear + 1) % MAXQSIZE; //队尾指针+1
	return OK;
}
//出队
Status DeQueue(SqQueue &Q, QElemType&e) {
	if (Q.front == Q.rear)  //队空
		return ERROR;
	e = Q.base[Q.front];      //保存队头元素
	Q.front = (Q.front + 1) % MAXQSIZE;  //指针+1
	return OK;
}
//取循环队列的头元素
QElemType GetHead(SqQueue Q){
	if (Q.front != Q.rear)
		return Q.base[Q.front];
}
