#include<iostream>

//双链表★★（树也是这种）
typedef struct DLNode {
	int data;	//数据域
	struct DLNode *prior;//指针域（指向前驱节点）
	struct DLNode *next; //指针域（指向后驱节点）
};

//采用尾插法建立双链表  （考的可能不大）
void createDlistR(DLNode *&L, int a[], int n) {
	DLNode *s, *r;
	int i;
	DLNode *L = new DLNode;
	L->prior = NULL;
	L->next = NULL;  //可有可无，
	r = L; //和单链表一样，r始终指向终端节点，开始头节点也是尾节点
	for (int i = 0; i < n; i++) {
		DLNode *s = new DLNode; 
		s->data = a[i];
		//插入操作
		r->next = s;
		s->prior = r;
		r = s;
	}
	r->next = NULL; //必须要有
}

//双链表得查找节点算法  
//和单链表并无不同，删除的时候略有不同，

/*插入节点算法  在p所指的节点之后插入一个节点s
s->next = p->next;
s->prior=p;
p->next=s;
s->next->prior=s;  //若p指向最后一个节点，本行可以去掉
*/

