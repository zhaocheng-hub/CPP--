#include<iostream>
using namespace std;
typedef struct LNode {
	int data;  // 数据域（可以是其他类型）
	struct LNode *next;//指针域 （此处代表指向后驱节点）
};
void merge(LNode *A, LNode *B, LNode *&C) {
	LNode *p = A->next; //p来追踪 A的最小值节点
	LNode *q = B->next; //q来追踪B的最小值节点
	LNode *r;  //r始终指向C的终端节点（最后一个节点）
	//C = A;   
	C->next = NULL; //将C初始化为一个空链表 //可有可无
	//free(B); 
	r = C;
	while (p != NULL && q != NULL) {  //p和q都不为空的时候，进行
		if (p->data <= q->data) {  //如果p指向的值小，那么将p插入到r后面
			r->next = p;
			p = p->next;   //p后移，
			r = r->next;  //r后移，r始终指向最后一个节点
		}
		else {
			r->next = q;
			q = q->next;
			r = r->next;
		}
	}
	//r->next = NULL;  // 可有可无
	if (p != NULL) {  //若p还有剩余节点，则继续插入
		r->next = p;
	}
	if (q != NULL) {
		r->next = q;
	}
}
void print(LNode *L) {
	L = L->next;
	while (L != NULL) {
		cout << L->data << " ";
		L = L->next;
	}
	cout << endl;
}
int main() {
	LNode *p = new LNode;
	LNode *q = new LNode;
	LNode *r = new LNode;
	LNode *p1 = new LNode;
	LNode *p2 = new LNode;
	LNode *p3 = new LNode;
	LNode *q1 = new LNode;
	LNode *q2 = new LNode;
	LNode *q3 = new LNode;
	LNode *q4 = new LNode;
	p->next = p1; p1->next = p2; p2->next = p3; p3->next = NULL;
	q->next = q1; q1->next = q2; q2->next = q3; q3->next = q4; q4->next = NULL;
	p1->data = 1;
	p2->data = 2;
	p3->data = 4;
	q1->data = 3;
	q2->data = 5;
	q3->data = 6;
	q4->data = 7;
	print(p);
	print(q);
	merge(p, q, r);
	print(r);
}
