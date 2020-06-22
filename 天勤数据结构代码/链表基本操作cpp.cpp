#include<iostream>
using namespace std;
//要会根据链表的基本操作进行操作改写，并且包括双链表和循环链表的（没有单链表的重要）

//结构定义
typedef struct LNode {
	int data;  // 数据域（可以是其他类型）
	struct LNode *next;//指针域 （此处代表指向后驱节点）
};

//A和B是两个单链表（带头节点），其中元素递增有序， ★★★
//设置一个算法将A和并合并成一个按元素值非递减有序的链表C，C由A和B节点组成
void merge(LNode *A, LNode *B, LNode *&C) {     //自己尝试下不借助C 写一个将A和B合并到A的
	LNode *p = A->next; //p来追踪 A的最小值节点
	LNode *q = B->next; //q来追踪B的最小值节点
	LNode *r;  //r始终指向C的终端节点（最后一个节点）
	C = A;     //C用A的地址（如果C未申请地址）
	C->next = NULL; //将C初始化为一个空链表 ， 可有可无，建议写上，防止智障老师。
	//free(B);  //可有可无  此时把A也释放了也无妨 
	r = C;   //r指向C的头节点
	while (p != NULL && q != NULL) {  //p和q都不为空的时候，进行
		//下面用的尾插法
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
	if (p != NULL) {  //若p还有剩余节点，则继续插入 注意此处，插入p代表p后面所有节点也随着插入了
		r->next = p;
	}
	if (q != NULL) {  //同上
		r->next = q;
	}
}

//用尾插法建立链表C★★ (注意了解插入即可，让你自己写可能性不大，一般需要借助插入操作）
void createlistR(LNode *&C, int a[], int n) {  //a待插入元素的数组，n元素个数 链表仅当头节点有变化的时候才加&(也就是头节点的地址有变动（申请/释放）才加）
	LNode *s, *r; //s用来指向新申请的节点
	int i;
	LNode* C = new LNode; //申请C的头节点空间；
	C->next = NULL; //这句也不是必须的，但是写上吧，防止智障老师
	r = C;
	for (int i = 0; i < n; i++) {  //开始建立链表 ,注意是怎么插入的
		LNode *s = new LNode; //这个非常重要
		s->data = a[i]; 
		//下面是尾插的核心
		r->next = s; //s插入到r的后面
		r = r->next; //r始终指向终端节点（当前s节点的位置，这个位置每次循环都变）
	}
	r->next = NULL;// 与上面案例不同，这个必须有，上面那个是因为之前的链表结尾有指向NULL的。
}

//头插法建立链表
void createlistF(LNode *&C, int a[], int n) {  //注意，链表仅当头节点有变化的时候才加&
	LNode *s;
	int i;
	LNode* C = new LNode; //申请C的头节点空间;
	C->next = NULL;  //这个和上面的不同，这个是必须的；
	for (int i = 0; i < n; i++) {  //开始建立链表 ,注意是怎么插入的
		LNode *s = new LNode; //这个非常重要
		s->data = a[i];
		//下面是头插的核心
		s->next = C->next; //s所指新节点的指针域next指向C中的开始节点（头节点后一个节点)
		C->next = s;  //  头节点的指针域next指向s节点，使得s成为新的开始（头）节点
	}
}
////A和B是两个单链表（带头节点），其中元素递增有序， ★★★
//设置一个算法将A和并合并成一个按元素值递减有序的链表C，C由A和B节点组成  （注意和上面的区分）
void merge(LNode *A, LNode *B, LNode *&C) {     //自己尝试下不借助C 写一个将A和B合并到A的
	LNode *p = A->next; //p来追踪 A的最小值节点
	LNode *q = B->next; //q来追踪B的最小值节点
	LNode *s;  // s用来充当临时节点作用
	C = A;     //C用A的地址，如果 C未申请地址）
	C->next = NULL; //将C初始化为一个空链表 ，和上述不同，此处必须写
	//free(B);  //可有可无  此时把A也释放了也无妨 
	while (p != NULL && q != NULL) {  //p和q都不为空的时候，进行
		//下面用的头插法
		if (p->data <= q->data) {  //如果p指向的值小，那么将p插入到r后面
			s = p;
			p = p->next;   //p后移， 若不后移则下面操作会断掉p和后面节点的连接
			s->next = C->next;
			C->next = s;  //C链表的第一个节点（头节点的后一个节点）为s；
		}
		else {
			s = q;
			q = q->next;   
			s->next = C->next;
			C->next = s;  
		}
	}
	//注意下面的操作和头插的完全不同！
	while (p!=NULL) {
		s = p;
		p = p->next;
		s->next = C->next;
		C->next = s;
	}
	while (q != NULL) {
		s = q;
		q = q->next;
		s->next = C->next;
		C->next = s;
	}
}

//★★查找链表C（带头节点）中是否存在一个值为x的节点，若存在，则删除该节点并返回1，否则返回0
int findeAndDelete(LNode *C, int x) {
	LNode *p, *q;
	p = C;
	/*查找部分开始*/
	while (p->next != NULL) {
		if (p->next->data == x) {  //注意这句 此时p是 值为x节点的上一个节点
			break;
		}
		p = p->next;
	}
	/*查找部分结束*/
	if (p->next == NULL) {
		return 0;  //没找到
	}
	else {
		/*删除部分开始*/
		q = p->next;
		p->next = p->next->next;
		delete q;
		/*删除部分结束*/
		return 1;
	}
}

//★★★已知递增有序的单链表A、B（A、B中元素个数分别为m、n，且A、B都带有头节点）
//分别存储了一个集合，设计算法以求出两个集合A和B的差集A-B（仅有A在A中出现而不在B中出现的元素所构成的集合）
//将差集保存在链表A中，并保持元素的递增有序性；
void difference(LNode *A, LNode *B) {
	LNode *p = A->next, *q = B->next;
	LNode *pre = A;
	LNode *r;
	while (p != NULL && q != NULL) {
		if (p->data < q->data) {
			pre = p;  //pre始终指向p的上一个节点
			p = p->next;  //p后移
		}
		else if (p->data>q->data) {
			q = q->next;
		}
		else {
			pre->next = p->next;
			r = p;
			p = p->next;
			delete r;  
		}
	}
}
//★★★递增非空单链表，设置一个算发，删除值域相同的节点
void delsll(LNode *L) {
	LNode *p = L->next;
	LNode *q;
	while (p->next != NULL) {
		if (p->data == p->next->data) {
			q = p->next;
			p->next = q->next;
			delete q;
		 }
		else {
			p = p->next;
		}
	}
}
//★★删除单链表(带头节点)中一个最小值的节点
void delminnode(LNode*L) {
	LNode *pre = L, *p = pre->next, *minp = p, *minpre = pre; 
	while(p!=NULL){ //寻找最小值节点，minp以及前驱节点minpre；
		if (p->data < minp->data) {
			minp = p;
			minpre = pre;
		}
		pre = p;
		p = p->next;
	}
	minpre->next = minp->next; //删除*minp节点 
	delete minp;
}
//★★★链表逆序
void reversel(LNode*L) {
	LNode *p = L->next, *q;
	L->next = NULL;    //L充当新链表的表头
	while (p != NULL) { //p节点始终指向旧链表的开始节点  
		/* 头插法 */
		q = p->next; //q节点作为辅助结点来记录p的后继节点的位置
		p->next = L->next; //将p所指的节点插入到新的链表中
		L->next = p;
		p = q;
	}
}
//★★★将一个头节点为A的单链表（数据域为整型）分解成两个单链表A和B，
//使得A链表只含原有链表data域为奇数得节点，而B链表只含有原链表中data域为偶数的节点。保持原来的相对顺序。
void split2(LNode *A, LNode *&B) {
	LNode *p, *q, *r;
	LNode *B = new LNode;
	B->next = NULL; //也可以不写，最好写，每申请一个新节点的时候，将其指针域设置为NULL，
					//可以避免很多因链表终端节点而忘记设置NULL而产生的错误。也防止智障老师
	r = B; 
	p = A; 
	while (p->next != NULL) {  //p始终指向当前节点的前驱节点
		if (p->next->data % 2 == 0) {
			q = p->next; //q指向要从链表取下得节点
			p->next = q->next; 
			q->next = NULL;
			r->next = q;  
			r = q;   //r始终指向B得最后一个节点
		}
		else {
			p = p->next;
		}
	}
}

//★★逆序打印单链表中的数据   //注意也要会链表的反转   
void reprint(LNode *L) {   
	if (L != NULL) {  //注意下面两句顺序
		reprint(L->next); //递归逆序打印开始节点后边的数据
		cout << L->data << "";  //打印开始节点中的数据;
	}
}
//★★★已知有一个带头节点的单链表只给出了头节点head，在不改变链表的前提下，
//设计一个尽可能高效的算发，查找链表中倒数第k个位置上的节点。
//若查找成功，算发输出该结点的data值，并返回1，否则返回0；
int findElem(LNode* head, int k) {  //可以自己尝试一下，先统计出链表的节点个数，然后顺序查找就简单得多
	LNode* p1 = head->next; 
	LNode* p = head;
	int i = 1;
	while (p1 != NULL) {
		p1 = p1->next;
		i++;
		if (i > k) {
			p = p->next; //如果i>k，则p也往后移动
		}
	}
	if (p == head)
		return 0;  //说明链表不足k个节点，
	else {
		cout << p->data;
		return 1;
	}
}

//链表的输出，
void print(LNode *L) {
	L = L->next;
	while (L != NULL) {
		cout << L->data<<" ";
		L = L->next;
	}
	cout << endl;
}
/*用于测试
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
	p->next = p1; p1->next = p2; p2->next = p3;
	q->next = q1; q1->next = q2; q2->next = q3; q3->next = q4;
	p1->data = 1;
	p2->data = 2;
	p3->data = 4;
	q1->data = 3;
	q1->data = 5;
	q1->data = 6;
	q1->data = 7;
	print(p);
	print(q);
	print(r);
	merge(p, q, r);
	print(r);
}
*/
