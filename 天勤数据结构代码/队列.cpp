#include <iostream>
using namespace std;
constexpr auto maxSize = 10000;;
//˳����Сһ�㿼ѭ����  ����ʹ��һά�������䵱����
typedef struct SqQueue{
	int data[maxSize]; //������ ��Ŷ�Ԫ�ص�����
	int front;  //�����±�
	int rear; //��β�±�
};

//����  (�ر�ע���£��������Ĳ�ͬ����ʱ������Ҳ��Ҫ�õ�����д�����������Ͳ�Ϊ�������͵�ʱ��Ϊ�Լ��������͵�ʱ��C++�������֣�
//  ���ӵĽڵ㶨������Ͷ����Ƿֿ��ģ����������Ľṹ��඼����һ��ģ���ͼҲ�Ƿֿ��ģ�
typedef struct QNode {   //�ӽڵ�
	int data; //������
	struct QNode *next;//ָ����
};
typedef struct LiQueue {  //������
	QNode *front; //��ͷָ��
	QNode *rear;  //��βָ��
};

//��ʼ����
void initQueue(SqQueue &qu) {
	qu.front = qu.rear = 0;  
}

//�ж϶ӿ�  ���򷵻�1
int isQueueEmpty(SqQueue qu){
	if (qu.front == qu.rear) { //
		return 1;
	}
	else {
		return 0;
	}
}

//�����㷨
int enQueue(SqQueue &qu, int x) {
	if ((qu.rear + 1) % maxSize == qu.front) { //�ж϶���
		return 0;
	}
	qu.rear = (qu.rear + 1) % maxSize;
	qu.data[qu.rear] = x;
	return 1;
}

//�����㷨
int deQueue(SqQueue &qu, int &x) {
	if (qu.front == qu.rear) { //�ж϶ӿ�
		return 0;
	}
	qu.front = (qu.front + 1) % maxSize;
	x = qu.data[qu.front];
	return 1;
} 

//��ʼ������
void initQueue(LiQueue *&lqu) {
	LiQueue *lqu = new LiQueue;
	lqu->front = lqu->rear = NULL;
}

//�ж����ӿ� ,�ӿշ���1
int isQueueEmpty(LiQueue *lqu) {
	if (lqu->rear == NULL || lqu->front == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

//������㷨
void enQueue(LiQueue *lqu, int x) {
	QNode *p = new QNode;
	p->data = x;
	p->next = NULL;
	if (lqu->rear == NULL) {    //����βΪ���� �ڵ�Ҳ�Ƕ��׽ڵ�
		lqu->front = lqu->rear = p;
	}
	else {
		lqu->rear->next = p;
		lqu->rear = p;
	}
}

//������㷨
int deQueuq(LiQueue *lqu, int &x) {
	QNode *p;
	if (lqu->rear == NULL) {  //�ӿ�
		return 0;
	}
	else {
		p = lqu->front;
	}
	if (lqu->front == lqu->rear) {  //����ֻ��һ��Ԫ��
		lqu->front = lqu->rear = NULL;
	}
	else {
		lqu->front = lqu->front->next;
	}
	x = p->data;
	delete p;
	return 1;
}

//���������ѭ���������˶����Խ��в����ɾ��������Ҫ��д��ѭ�����е����Ͷ���
// �ֱ�д���Ӷ�βɾ���Ͷ�ͷ������㷨��
typedef struct cycqueue {
	int data[maxSize];
	int front, rear;
};
int deQueue(cycqueue &Q, int x) { //����  �Ӷ�β����
	if (Q.front == Q.rear) {  //�ӿ�
		return 0;
	}
	else {
		x = Q.data[Q.rear];
		Q.rear = (Q.rear - 1 + maxSize) % maxSize;
		return 1;
	}
}
int enQueue(cycqueue &Q, int x) {  //��ͷ���
	if (Q.rear == (Q.front - 1 + maxSize) % maxSize) {
		return 0;
	}
	else {
		Q.data[Q.front] = x;
		Q.front = (Q.front - 1 + maxSize) % maxSize;
		return 1;
	}
}

//������һ��ѭ�����У���front �� rear�ֱ���Ϊ��ͷ�Ͷ�βָ�룬������һ����־tag��ʾ�����ǿջ��ǲ���
//Լ����tagΪ0ʱ�ӿգ���tagΪ1ʱ�Ӳ��գ������Ϳ�����Ϊ������������
//Ҫ����ƶ��еĽṹ����ػ��������㷨��������Ԫ��Ϊint�ͣ�
typedef struct Queue {
	int data[maxSize];
	int front, rear;
	int tag;
};
void initQueue(Queue &qu) {  //��ʼ��
	qu.front = qu.rear = 0;
	qu.tag = 0;
}
int isQueueEmpty(Queue qu) {  //�ж϶��Ƿ�Ϊ�� 
	if (qu.front == qu.rear &&qu.tag == 0) {  //Ϊ��
		return 1;
	}
	else {
		return 0;
	}
}
int QueueFull(Queue qu) {  //�ж��Ƿ����
	if (qu.tag == 1 && qu.front == qu.rear) {
		return 1;
	}
	else {
		return 0;
	}
}
int enQueue(Queue &qu, int x) { //Ԫ�ؽ���
	if (QueueFull(qu) == 1) {
		return 0;
	}
	else {
		qu.rear = (qu.rear + 1) % maxSize;
		qu.data[qu.rear] = x;
		qu.tag = 1;  //�����Ԫ�ؾͲ����ܿ�
		return 1;
	}
}
int deQueue(Queue &qu, int &x) { //Ԫ�س���
	if (isQueueEmpty(qu) == 1) {
		return 0;
	}
	else {
		qu.front = (qu.front + 1)&maxSize;
		x = qu.data[qu.front];
		qu.tag = 0;  //�г���Ԫ�ؾͲ�������
		return 1;
	}
}

