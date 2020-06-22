#include<iostream>
using namespace std;
constexpr auto maxSize = 10000;;

// 链式树★★★
typedef struct BTNode {
	char data; //数据域
	struct BTNode *lchild;// 左指针域
	struct BTNode *rchild;// 右指针域
};

//二叉排序树★（和链树一样）
typedef struct BTNode1 {
	int key; //关键字
	struct BTNode1 *lchild;// 左指针域
	struct BTNode1 *rchild;// 右指针域
};

//线索树（考纲无，可以了解下）
typedef struct TBTNode {
	char data; //数据域
	int ltag, rtag;//线索标记，=0时则表示对应指针域为指针， =1表示对应指针域为线索，指向该结点的直接前驱（后继）
	struct TBTNode *lchild;// 左指针域
	struct TBTNode *rchild;// 右指针域
};

//★二叉树三种遍历
void Visit(BTNode *p) {
	//某种操作，例如输出等等，
}
void preorder(BTNode *p) { //先序遍历
	if (p != NULL) {
		Visit(p); // 某种操作
		preorder(p->lchild);
		preorder(p->rchild);
	}
}
void inorder(BTNode *p) { //中序遍历
	if (p != NULL) {
		inorder(p->lchild);
		Visit(p);
		inorder(p->rchild);
	}
}
void postorder(BTNode *p) { //后序遍历
	if (p != NULL) {
		postorder(p->lchild);
		postorder(p->rchild);
		Visit(p);
	}
}

//★★ 求表达式(a-(b+c)*(d/e))存储在二叉链表为存储结构的二叉树中，求出该表达式的值
int op(int a, int b, char Op) { //运算函数 完成 a Op b 的运算
	if (Op == '+')
		return a + b;
	if (Op == '-')
		return a - b;
	if (Op == '*')
		return a * b;
	if (Op == '/') {
		if (b == 0) {    //被除数不能为0
			return 0;
		}
		else {
			return a / b;
		}
	}
}
int comp(BTNode *p) {  //仅使用于这一种算式
	int A, B;
	if (p != NULL) {
		if (p->lchild != NULL && p->rchild != NULL) { //左右子树都不为空
			/*后序遍历求其值*/
			A = comp(p->lchild);
			B = comp(p->rchild);
			return op(A, B, p->data);
		}
		else {
			return p->data - '0'; // 如果左右子树都为空，则为数值，直接返回对应数字 （因为定义时是char）

		}
	}
	return 0;  //空树，返回0;
}

//★★★计算二叉树的深度
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

//★★★查找二叉树中 值等于key的节点是否存在，若存在将p指向该节点，否则将q赋值为NULL，data为int型
typedef struct BTNode2 {
	int data; //数据域
	struct BTNode2 *lchild;// 左指针域
	struct BTNode2 *rchild;// 右指针域
};
/*假设二叉树已经存在，且p指向其根节点*/
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

//★★假设二叉树采用二叉链表存储结构存储，编写一个程序输出先序（中序，后序）序列中第k个结点的值。
int n = 0; //全局变量
int trave(BTNode *p, int k) { //先序
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
int trave(BTNode *p, int k) {  //中序
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
int trave(BTNode *p, int k) {  //后序
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

//★★层次遍历
void level(BTNode *p) {
	int front, rear; 
	BTNode *que[maxSize];  //定义一个循环队列，记录要访问的层次上的节点
	front = rear = 0;
	BTNode *q; 
	if (q != NULL) {
		rear = (rear + 1) % maxSize;
		que[rear] = p;  //根节点入队
		while (front != rear) {
			front = (front + 1) % maxSize;
			q = que[front];    //队头节点 出队
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

//★★★计算二叉树宽度
typedef struct St {
	BTNode *p;
	int lno;   //节点所在层号
};
int maxNode(BTNode *b) {
	St que[maxSize];    //定义顺序队列
	int front = 0, rear = 0; 
	int Lno,n,max;
	BTNode *q;
	if (b != NULL) {
		++rear;
		que[rear].p = b;  //树根入队 
		que[rear].lno = 1; //层数为1
		while (front != rear) {
			++front;
			q = que[front].p;
			Lno = que[front].lno;   //取当前节点 层号
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
		} //循环结束时，Lno 中保存的时这颗二叉树的最大层数（高度）
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

//二叉树遍历的非递归算法（先，中，后）
void preorderNonrecursion(BTNode *bt) {  //先序遍历
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
void inorderNonrecursion(BTNode *bt) { //中序遍历
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
void postorderNonrecursion(BTNode *bt) { //后序遍历
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

//★根据先序和中序遍历构造出二叉树 
BTNode *CreateBT(char pre[], char in[], int l1, int r1, int l2, int r2) {
	BTNode *s;
	int i;
	if (l1 > r1) {   
		return NULL; 
	}
	BTNode *s = new BTNode;
	s->lchild = s->rchild = NULL;
	for (int i = l2; i < r2; i++) {  //查找等于当前子树根的节点再中序的位置
		if (in[i] == pre[l1]) {
			break;
		}
	}
	s->data = in[i]; 
	s->lchild = CreateBT(pre, in, l1 + 1, l1 + i - 12, 12, i - 1);
	s->rchild = CreateBT(pre, in, l1 + i - 12 + 1, r1, i + 1, r2);
	return s;
}

//★★★计算二叉树所有的节点数
int n = 0;    //非递归
void count(BTNode *p) {
	if (p != NULL) {
		++n;
		count(p->lchild);
		count(p->rchild);
	}
}
int count2(BTNode *p) { //递归
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

//★★★计算二叉树的所有叶子节点数
int n = 0;    //非递归
void count3(BTNode *p) {
	if (p != NULL) {
		if (p->lchild == NULL && p->rchild == NULL) {
			++n;
		}
		count3(p->lchild);
		count3(p->rchild);
	}
}
int count4(BTNode *p) { //递归
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

//★★利用节点的右孩子指针rchild 将一棵二叉树的叶子节点从左往右的顺序串成一个单链表
//（在题目中定义两个指针，head和tail，其中hear 指向第一个叶子节点，head初值为NUll,
// tail指向最后一个叶子节点）
void link(BTNode*p, BTNode*head, BTNode*&tail) {
	if (p != NULL) {
		if (p->lchild == NULL && p->rchild == NULL) {  //叶子节点
			if (head == NULL) {   //第一个节点，
				head = p;
				tail = p;
			}
			else {   //非第一个节点
				tail->rchild = p;
				tail = p;
			}
		}
		link(p->lchild, head, tail);
		link(p->rchild, head, tail);
	}
}

//★★在二叉树的二叉链表存储结构中，增加一个指向双亲结点的parent指针，设计一个算法
//给这个指针赋值，并且输出所有节点到根节点的路径。
typedef struct BTNode3 {
	char data;
	struct BTNode3*parent;
	struct BTNode3*lchild;
	struct BTNode3*rchild; 
};
void triBtree(BTNode3*p, BTNode3 *q) {  //给parent赋值  p为根节点的时候，q应为NULL
	if (p != NULL) {
		p->parent = q; //当前所访问的节点的parent 指向q；
		q = p; 
		triBtree(p->lchild, q);
		triBtree(p->rchild, q);
	}
}
void printPath(BTNode3 *p) { //打印路径
	while (p != NULL) {
		cout << p->data << " " << endl;
		p->parent;
	}
}
void allPath(BTNode3 *p) { //打印所有路径
	if (p != NULL) {
		printPath(p);
		allPath(p->lchild);
		allPath(p->rchild);
	}
}

//★假设先序遍历序列储存在数组中，将其转变为后序遍历
void change(char pre[], int L1, int R1, char post[], int L2, int R2) {
	if (L1 <= R1) {
		post[R2] = pre[L1];   //将 pre的第一个元素放在post的末尾
		change(pre, L1 + 1, (L1 + 1 + R1) / 2, post, L2, (L2 + R2 - 1) / 2);
		change(pre, (L1 + 1 + R1) / 2 + 1, R1, post, (L2 + R2 - 1) / 2 + 1, R2 - 1);
	}
}

//★★★求二叉树中 值为x的节点的层号（高度）
int L = 1; //全局变量
void leno(BTNode *p, char x) {
	if (p != NULL) {
		if (p->data == x) {
			cout << L << endl;
		}
		++L;  //去往下层 
		leno(p->lchild, x);
		leno(p->rchild, x);
		--L;  //回到上层
	}
}

//★双序遍历 （中左中右）
void Double_order(BTNode *t) {
	if (t != NULL) {
		Visit(t);
		Double_order(t->lchild);
		Visit(t);
		Double_order(t->rchild);
	}
}

//★★输出根节点到所有结点的路径
int i;
int top = 0;
char pathstack[maxSize];
void allPath(BTNode *p) {
	if (p != NULL) {
		pathstack[top] = p->data;
		++top;
		if (p->lchild == NULL && p->rchild == NULL) {  //叶子节点
			for (i = 0; i < top; ++i) {
				cout << pathstack[i];   //打印路径
			}
		}
		allPath(p->lchild);
		allPath(p->rchild);
		--top;
	}
}
