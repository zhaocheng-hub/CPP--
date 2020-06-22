#include<iostream>
using namespace std;
typedef struct LNode {
	int data;  // �����򣨿������������ͣ�
	struct LNode *next;//ָ���� ���˴�����ָ������ڵ㣩
};
void merge(LNode *A, LNode *B, LNode *&C) {
	LNode *p = A->next; //p��׷�� A����Сֵ�ڵ�
	LNode *q = B->next; //q��׷��B����Сֵ�ڵ�
	LNode *r;  //rʼ��ָ��C���ն˽ڵ㣨���һ���ڵ㣩
	//C = A;   
	C->next = NULL; //��C��ʼ��Ϊһ�������� //���п���
	//free(B); 
	r = C;
	while (p != NULL && q != NULL) {  //p��q����Ϊ�յ�ʱ�򣬽���
		if (p->data <= q->data) {  //���pָ���ֵС����ô��p���뵽r����
			r->next = p;
			p = p->next;   //p���ƣ�
			r = r->next;  //r���ƣ�rʼ��ָ�����һ���ڵ�
		}
		else {
			r->next = q;
			q = q->next;
			r = r->next;
		}
	}
	//r->next = NULL;  // ���п���
	if (p != NULL) {  //��p����ʣ��ڵ㣬���������
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
