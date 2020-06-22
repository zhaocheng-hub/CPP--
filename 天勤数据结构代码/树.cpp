#include<iostream>
using namespace std;
constexpr auto maxSize = 10000;;

// ��ʽ������
typedef struct BTNode {
	char data; //������
	struct BTNode *lchild;// ��ָ����
	struct BTNode *rchild;// ��ָ����
};

//�����������������һ����
typedef struct BTNode1 {
	int key; //�ؼ���
	struct BTNode1 *lchild;// ��ָ����
	struct BTNode1 *rchild;// ��ָ����
};

//�������������ޣ������˽��£�
typedef struct TBTNode {
	char data; //������
	int ltag, rtag;//������ǣ�=0ʱ���ʾ��Ӧָ����Ϊָ�룬 =1��ʾ��Ӧָ����Ϊ������ָ��ý���ֱ��ǰ������̣�
	struct TBTNode *lchild;// ��ָ����
	struct TBTNode *rchild;// ��ָ����
};

//����������ֱ���
void Visit(BTNode *p) {
	//ĳ�ֲ�������������ȵȣ�
}
void preorder(BTNode *p) { //�������
	if (p != NULL) {
		Visit(p); // ĳ�ֲ���
		preorder(p->lchild);
		preorder(p->rchild);
	}
}
void inorder(BTNode *p) { //�������
	if (p != NULL) {
		inorder(p->lchild);
		Visit(p);
		inorder(p->rchild);
	}
}
void postorder(BTNode *p) { //�������
	if (p != NULL) {
		postorder(p->lchild);
		postorder(p->rchild);
		Visit(p);
	}
}

//��� ����ʽ(a-(b+c)*(d/e))�洢�ڶ�������Ϊ�洢�ṹ�Ķ������У�����ñ��ʽ��ֵ
int op(int a, int b, char Op) { //���㺯�� ��� a Op b ������
	if (Op == '+')
		return a + b;
	if (Op == '-')
		return a - b;
	if (Op == '*')
		return a * b;
	if (Op == '/') {
		if (b == 0) {    //����������Ϊ0
			return 0;
		}
		else {
			return a / b;
		}
	}
}
int comp(BTNode *p) {  //��ʹ������һ����ʽ
	int A, B;
	if (p != NULL) {
		if (p->lchild != NULL && p->rchild != NULL) { //������������Ϊ��
			/*�����������ֵ*/
			A = comp(p->lchild);
			B = comp(p->rchild);
			return op(A, B, p->data);
		}
		else {
			return p->data - '0'; // �������������Ϊ�գ���Ϊ��ֵ��ֱ�ӷ��ض�Ӧ���� ����Ϊ����ʱ��char��

		}
	}
	return 0;  //����������0;
}

//�����������������
int getDepth(BTNode *p) {
	int LD, RD;
	if (p == NULL) {
		return 0;
	}
	else {
		LD = getDepth(p->lchild);
		RD = getDepth(p->rchild);
		return (LD > RD ? LD : RD) + 1;
	}
}

//������Ҷ������� ֵ����key�Ľڵ��Ƿ���ڣ������ڽ�pָ��ýڵ㣬����q��ֵΪNULL��dataΪint��
typedef struct BTNode2 {
	int data; //������
	struct BTNode2 *lchild;// ��ָ����
	struct BTNode2 *rchild;// ��ָ����
};
/*����������Ѿ����ڣ���pָ������ڵ�*/
void search(BTNode2 *p, BTNode2 *&q, int key) {
	if (p != NULL) {
		if (p->data == key) {
			q = p;
		}
		else {
			search(p->lchild, q, key);
			search(p->rchild, q, key);
		}
	}
}

//��������������ö�������洢�ṹ�洢����дһ����������������򣬺��������е�k������ֵ��
int n = 0; //ȫ�ֱ���
int trave(BTNode *p, int k) { //����
	if (p != NULL) {
		++n;
		if (k == n) {
			cout << p->data << endl;
			return 0;
		}
		trave(p->lchild,k);
		trave(p->rchild,k);
	}
}
int trave(BTNode *p, int k) {  //����
	if (p != NULL) {
		trave(p->lchild, k);
		++n;
		if (k == n) {
			cout << p->data << endl;
			return 0;
		}
		trave(p->rchild, k);
	}
}
int trave(BTNode *p, int k) {  //����
	if (p != NULL) {
		trave(p->lchild, k);
		trave(p->rchild, k);
		++n;
		if (k == n) {
			cout << p->data << endl;
			return 0;
		}
	}
}

//����α���
void level(BTNode *p) {
	int front, rear; 
	BTNode *que[maxSize];  //����һ��ѭ�����У���¼Ҫ���ʵĲ���ϵĽڵ�
	front = rear = 0;
	BTNode *q; 
	if (q != NULL) {
		rear = (rear + 1) % maxSize;
		que[rear] = p;  //���ڵ����
		while (front != rear) {
			front = (front + 1) % maxSize;
			q = que[front];    //��ͷ�ڵ� ����
			Visit(p);
			if (q->lchild != NULL) {
				rear = (rear + 1) % maxSize;
				que[rear] = q->lchild;
			}
			if (q->rchild != NULL) {
				rear = (rear + 1) % maxSize;
				que[rear] = q->lchild;
			}
		}
	}
}

//���������������
typedef struct St {
	BTNode *p;
	int lno;   //�ڵ����ڲ��
};
int maxNode(BTNode *b) {
	St que[maxSize];    //����˳�����
	int front = 0, rear = 0; 
	int Lno,n,max;
	BTNode *q;
	if (b != NULL) {
		++rear;
		que[rear].p = b;  //������� 
		que[rear].lno = 1; //����Ϊ1
		while (front != rear) {
			++front;
			q = que[front].p;
			Lno = que[front].lno;   //ȡ��ǰ�ڵ� ���
			if (q->lchild != NULL) {
				++rear;
				que[rear].p = q->lchild;
				que[rear].lno = Lno + 1;
			}
			if (q->rchild != NULL) {
				++rear;
				que[rear].p = q->rchild;
				que[rear].lno = Lno + 1;
			}
		} //ѭ������ʱ��Lno �б����ʱ��Ŷ����������������߶ȣ�
		max = 0;
		for (int i = 0; i < Lno; ++i) {
			n = 0;
			for (int j = 1; j <= rear; ++j) {
				if (que[j].lno == i) {
					++n;
				}
				if (max < n) {
					max = n;
				}
			}
		}
		return max;
	}
	else
		return 0;
}

//�����������ķǵݹ��㷨���ȣ��У���
void preorderNonrecursion(BTNode *bt) {  //�������
	if (bt != NULL) {
		BTNode *Stack[maxSize]; 
		int top = -1;
		BTNode *p;
		Stack[++top] = bt;
		while (top != -1) {
			p = Stack[top--];
			Visit(p);
			if (p->rchild != NULL) {
				Stack[++top] = p->rchild;
			}
			if (p->lchild != NULL) {
				Stack[++top] = p->lchild;
			}
		}
	}
}
void inorderNonrecursion(BTNode *bt) { //�������
	if (bt != NULL) {
		BTNode *Stack[maxSize];
		int top = -1;
		BTNode *p;
		p = bt;
		while (top != -1||p != NULL) {
			while (p != NULL) {
				Stack[++top] = p;
				p->lchild;
			}
			if (top != -1) {
				p = Stack[top--];
				Visit(p); 
				p = p->rchild;
			}
		}
	}
}
void postorderNonrecursion(BTNode *bt) { //�������
	if (bt != NULL) {
		BTNode *Stack1[maxSize];
		int top1 = -1;
		BTNode *Stack2[maxSize];
		int top2 = -1;
		BTNode *p = NULL;
		Stack1[++top1] = bt;
		while (top1 != -1) {
			p = Stack1[top1--];
			Stack2[++top2] = p;
			if (p->lchild != NULL) {
				Stack1[++top1] = p->lchild;
			}
			if (p->rchild != NULL) {
				Stack2[++top1] = p->rchild;
			}
		}
		while (top2 != -1) {
			p = Stack2[top2--];
			Visit(p); 
		}
	}
}

//���������������������������� 
BTNode *CreateBT(char pre[], char in[], int l1, int r1, int l2, int r2) {
	BTNode *s;
	int i;
	if (l1 > r1) {   
		return NULL; 
	}
	BTNode *s = new BTNode;
	s->lchild = s->rchild = NULL;
	for (int i = l2; i < r2; i++) {  //���ҵ��ڵ�ǰ�������Ľڵ��������λ��
		if (in[i] == pre[l1]) {
			break;
		}
	}
	s->data = in[i]; 
	s->lchild = CreateBT(pre, in, l1 + 1, l1 + i - 12, 12, i - 1);
	s->rchild = CreateBT(pre, in, l1 + i - 12 + 1, r1, i + 1, r2);
	return s;
}

//���������������еĽڵ���
int n = 0;    //�ǵݹ�
void count(BTNode *p) {
	if (p != NULL) {
		++n;
		count(p->lchild);
		count(p->rchild);
	}
}
int count2(BTNode *p) { //�ݹ�
	int n1, n2;
	if (p == NULL) {
		return 0;
	}
	else {
		n1 = count2(p->lchild);
		n2 = count2(p->rchild);
		return n1 + n2 + 1;
	}
}

//������������������Ҷ�ӽڵ���
int n = 0;    //�ǵݹ�
void count3(BTNode *p) {
	if (p != NULL) {
		if (p->lchild == NULL && p->rchild == NULL) {
			++n;
		}
		count3(p->lchild);
		count3(p->rchild);
	}
}
int count4(BTNode *p) { //�ݹ�
	int n1, n2;
	if (p == NULL) {
		return 0;
	}
	else if (p->lchild == NULL && p->rchild == NULL) {
		return 1;
	}
	else {
		n1 = count4(p->lchild);
		n2 = count4(p->rchild);
		return n1 + n2;
	}
}

//������ýڵ���Һ���ָ��rchild ��һ�ö�������Ҷ�ӽڵ�������ҵ�˳�򴮳�һ��������
//������Ŀ�ж�������ָ�룬head��tail������hear ָ���һ��Ҷ�ӽڵ㣬head��ֵΪNUll,
// tailָ�����һ��Ҷ�ӽڵ㣩
void link(BTNode*p, BTNode*head, BTNode*&tail) {
	if (p != NULL) {
		if (p->lchild == NULL && p->rchild == NULL) {  //Ҷ�ӽڵ�
			if (head == NULL) {   //��һ���ڵ㣬
				head = p;
				tail = p;
			}
			else {   //�ǵ�һ���ڵ�
				tail->rchild = p;
				tail = p;
			}
		}
		link(p->lchild, head, tail);
		link(p->rchild, head, tail);
	}
}

//����ڶ������Ķ�������洢�ṹ�У�����һ��ָ��˫�׽���parentָ�룬���һ���㷨
//�����ָ�븳ֵ������������нڵ㵽���ڵ��·����
typedef struct BTNode3 {
	char data;
	struct BTNode3*parent;
	struct BTNode3*lchild;
	struct BTNode3*rchild; 
};
void triBtree(BTNode3*p, BTNode3 *q) {  //��parent��ֵ  pΪ���ڵ��ʱ��qӦΪNULL
	if (p != NULL) {
		p->parent = q; //��ǰ�����ʵĽڵ��parent ָ��q��
		q = p; 
		triBtree(p->lchild, q);
		triBtree(p->rchild, q);
	}
}
void printPath(BTNode3 *p) { //��ӡ·��
	while (p != NULL) {
		cout << p->data << " " << endl;
		p->parent;
	}
}
void allPath(BTNode3 *p) { //��ӡ����·��
	if (p != NULL) {
		printPath(p);
		allPath(p->lchild);
		allPath(p->rchild);
	}
}

//���������������д����������У�����ת��Ϊ�������
void change(char pre[], int L1, int R1, char post[], int L2, int R2) {
	if (L1 <= R1) {
		post[R2] = pre[L1];   //�� pre�ĵ�һ��Ԫ�ط���post��ĩβ
		change(pre, L1 + 1, (L1 + 1 + R1) / 2, post, L2, (L2 + R2 - 1) / 2);
		change(pre, (L1 + 1 + R1) / 2 + 1, R1, post, (L2 + R2 - 1) / 2 + 1, R2 - 1);
	}
}

//������������� ֵΪx�Ľڵ�Ĳ�ţ��߶ȣ�
int L = 1; //ȫ�ֱ���
void leno(BTNode *p, char x) {
	if (p != NULL) {
		if (p->data == x) {
			cout << L << endl;
		}
		++L;  //ȥ���²� 
		leno(p->lchild, x);
		leno(p->rchild, x);
		--L;  //�ص��ϲ�
	}
}

//��˫����� ���������ң�
void Double_order(BTNode *t) {
	if (t != NULL) {
		Visit(t);
		Double_order(t->lchild);
		Visit(t);
		Double_order(t->rchild);
	}
}

//���������ڵ㵽���н���·��
int i;
int top = 0;
char pathstack[maxSize];
void allPath(BTNode *p) {
	if (p != NULL) {
		pathstack[top] = p->data;
		++top;
		if (p->lchild == NULL && p->rchild == NULL) {  //Ҷ�ӽڵ�
			for (i = 0; i < top; ++i) {
				cout << pathstack[i];   //��ӡ·��
			}
		}
		allPath(p->lchild);
		allPath(p->rchild);
		--top;
	}
}
