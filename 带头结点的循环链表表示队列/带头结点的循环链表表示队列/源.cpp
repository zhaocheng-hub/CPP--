//预处理命令
#include<iostream>
#include<stdio.h>
using namespace std;

#define OK 1
#define ERROR -1

typedef int ElemType;
typedef int Status;
//单链表的储存结构
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}*LinkList;
//链表和队列的储存结构
typedef struct LQ {
	LinkList Link;  //链表头指针
	LinkList rear;  //队尾指针
}*Lq;
//初始化
Status InitList(Lq &L) {
	L = new LQ;
	LinkList p= new LNode;
	L->Link = p;
	L->Link->next = NULL;
	L->rear = L->Link; //让队尾指针指向链表的头节点
	return OK;
}
//尾插法初始化链表
Status CreateList_R(Lq &L){
	int i;
	cout << "请输入要建立的元素个数:";
	cin >> i;
	cout << "请依次输入元素的数据域:" << endl;
	for (int j = 0; j < i; j++) {
		LinkList p = new LNode;
		cin >> p->data;
		p->next = NULL;
		L->rear->next = p;
		L->rear = p;
	}
	return OK;
}
//置空队列
Status Empty(Lq &L){
	L->Link->next = NULL;
	L->rear = L->Link;
	return OK;
}
//判断队列是否为空
bool Determine(Lq L) {
	if (L->Link->next == NULL)  //若为空则返回1反之返回0
		return 1;
	else
		return 0;
}
//入队
Status EnQueue(Lq &L,ElemType e) {
	LinkList p = new LNode;
	p->data = e;
	p->next = NULL;
	L->rear->next = p;
	L->rear = p;
	return OK;
}
//出队
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
//输出队列元素
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
	cout << "初始化完成，开始尾插法创建队列" << endl;
	CreateList_R(L);
	cout << "请输入需要入队的元素e:";
	cin >> e;
	EnQueue(L, e);
	cout << "开始出队一个元素 ";
	DeQueue(L, e);
	cout << "出队元素为:" << e << endl;
	cout << "队列中剩余元素为;";
	Print(L);
	cout << endl;
	cout << "开始置空队列" << endl;
	Empty(L);
	if (Determine(L) == 1)
		cout << "已经成功置空队列" << endl;
	else
		cout << "置空失败" << endl;
}