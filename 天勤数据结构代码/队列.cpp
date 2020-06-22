#include <iostream>
using namespace std;
constexpr auto maxSize = 10000;;
//顺序队列★（一般考循环）  往往使用一维数组来充当队列
typedef struct SqQueue{
	int data[maxSize]; //数据域 存放队元素的数组
	int front;  //队首下标
	int rear; //队尾下标
};

//链队  (特别注意下，和其他的不同，有时候链表也需要用到这种写法（数据类型不为基本类型的时候，为自己定义类型的时候）C++常用这种）
//  链队的节点定义和类型定义是分开的，其他基础的结构大多都是在一起的，（图也是分开的）
typedef struct QNode {   //队节点
	int data; //数据域
	struct QNode *next;//指针域
};
typedef struct LiQueue {  //队类型
	QNode *front; //队头指针
	QNode *rear;  //队尾指针
};

//初始化队
void initQueue(SqQueue &qu) {
	qu.front = qu.rear = 0;  
}

//判断队空  空则返回1
int isQueueEmpty(SqQueue qu){
	if (qu.front == qu.rear) { //
		return 1;
	}
	else {
		return 0;
	}
}

//进队算法
int enQueue(SqQueue &qu, int x) {
	if ((qu.rear + 1) % maxSize == qu.front) { //判断对满
		return 0;
	}
	qu.rear = (qu.rear + 1) % maxSize;
	qu.data[qu.rear] = x;
	return 1;
}

//出队算法
int deQueue(SqQueue &qu, int &x) {
	if (qu.front == qu.rear) { //判断队空
		return 0;
	}
	qu.front = (qu.front + 1) % maxSize;
	x = qu.data[qu.front];
	return 1;
} 

//初始化链队
void initQueue(LiQueue *&lqu) {
	LiQueue *lqu = new LiQueue;
	lqu->front = lqu->rear = NULL;
}

//判断链队空 ,队空返回1
int isQueueEmpty(LiQueue *lqu) {
	if (lqu->rear == NULL || lqu->front == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

//★入队算法
void enQueue(LiQueue *lqu, int x) {
	QNode *p = new QNode;
	p->data = x;
	p->next = NULL;
	if (lqu->rear == NULL) {    //若队尾为空则 节点也是队首节点
		lqu->front = lqu->rear = p;
	}
	else {
		lqu->rear->next = p;
		lqu->rear = p;
	}
}

//★出队算法
int deQueuq(LiQueue *lqu, int &x) {
	QNode *p;
	if (lqu->rear == NULL) {  //队空
		return 0;
	}
	else {
		p = lqu->front;
	}
	if (lqu->front == lqu->rear) {  //队中只有一个元素
		lqu->front = lqu->rear = NULL;
	}
	else {
		lqu->front = lqu->front->next;
	}
	x = p->data;
	delete p;
	return 1;
}

//如果允许在循环队列两端都可以进行插入和删除操作，要求，写出循环队列的类型定义
// 分别写出从队尾删除和对头插入的算法。
typedef struct cycqueue {
	int data[maxSize];
	int front, rear;
};
int deQueue(cycqueue &Q, int x) { //出队  从队尾出队
	if (Q.front == Q.rear) {  //队空
		return 0;
	}
	else {
		x = Q.data[Q.rear];
		Q.rear = (Q.rear - 1 + maxSize) % maxSize;
		return 1;
	}
}
int enQueue(cycqueue &Q, int x) {  //队头入队
	if (Q.rear == (Q.front - 1 + maxSize) % maxSize) {
		return 0;
	}
	else {
		Q.data[Q.front] = x;
		Q.front = (Q.front - 1 + maxSize) % maxSize;
		return 1;
	}
}

//★★设计一个循环队列，用front 和 rear分别作为队头和队尾指针，另外用一个标志tag表示队列是空还是不空
//约定当tag为0时队空，当tag为1时队不空，这样就可以作为队满的条件，
//要求设计队列的结构和相关基本运算算法。（队列元素为int型）
typedef struct Queue {
	int data[maxSize];
	int front, rear;
	int tag;
};
void initQueue(Queue &qu) {  //初始化
	qu.front = qu.rear = 0;
	qu.tag = 0;
}
int isQueueEmpty(Queue qu) {  //判断队是否为空 
	if (qu.front == qu.rear &&qu.tag == 0) {  //为空
		return 1;
	}
	else {
		return 0;
	}
}
int QueueFull(Queue qu) {  //判断是否队满
	if (qu.tag == 1 && qu.front == qu.rear) {
		return 1;
	}
	else {
		return 0;
	}
}
int enQueue(Queue &qu, int x) { //元素进队
	if (QueueFull(qu) == 1) {
		return 0;
	}
	else {
		qu.rear = (qu.rear + 1) % maxSize;
		qu.data[qu.rear] = x;
		qu.tag = 1;  //有入队元素就不可能空
		return 1;
	}
}
int deQueue(Queue &qu, int &x) { //元素出队
	if (isQueueEmpty(qu) == 1) {
		return 0;
	}
	else {
		qu.front = (qu.front + 1)&maxSize;
		x = qu.data[qu.front];
		qu.tag = 0;  //有出对元素就不可能满
		return 1;
	}
}

