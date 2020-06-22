#include<iostream>
#include<string>
using namespace std;
constexpr auto maxSize = 10000;;  //同 #define maxSzie 10000;

//所有的结构都是在以下几种中进行拓展（操作拓展/结构拓展 来完成的，如果不会直接默写）

//顺序表    往往使用一维数组来充当顺序存储的操作 （往往和查找一起使用）
typedef struct SqList {  
	int data[maxSize]; //这里的数字元素个数开一个足够大的（题目可能给）。 类型可以换成其他类型看题目要求
	int length; //存放顺序表的长度
};

//单链表★★★
typedef struct LNode {
	int data;  // 数据域（可以是其他类型）
	struct LNode *next;//指针域 （此处代表指向后驱节点）
};

//双链表★★（树也是这种）
typedef struct DLNode {
	int data;	//数据域
	struct DLNode *prior;//指针域（指向前驱节点）
	struct DLNode *next; //指针域（指向后驱节点）
};

//顺序栈★（可能考特殊的顺序栈，例如双向栈） 一样可以使用数组充当
typedef struct SqStack {
	int dada[maxSize]; //存放栈元素，数组大小，要开足够大（一般题目给）不给就开足够大，写注释。
	int top;  //栈顶下标（指针）
};

//链栈节点   （同链表，操作不同）
typedef struct LNode {
	int data;  //数据域
	struct LNode *next; //指针域
};

//顺序队列★（一般考循环）  往往使用一维数组来充当队列
typedef struct SqQueue{
	int dada[maxSize]; //数据域 存放队元素的数组
	int front;  //队首下标
	int rear; //队尾下标
};

//链队  (特别注意下，和其他的不同，有时候链表也需要用到这种写法（数据类型不为基本类型的时候，为自己定义类型的时候）C++常用这种）
//  链队的节点定义和类型定义是分开的，其他基础的结构大多都是在一起的，（图也是分开的）
typedef struct QNode{   //队节点
	int data; //数据域
	struct QNode *next;//指针域
};
typedef struct LiQueue {  //队类型
	QNode *front; //队头指针
	QNode *rear;  //队尾指针
};

//顺序存储的树  一般情况使用数组来存储
//顶点坐标为 i的时候，左子树坐标为 i*2  右子树坐标为 2*i+1

//链式树★★★
typedef struct BTNode {
	char data; //数据域
	struct BTNode *lchild;// 左指针域
	struct BTNode *rchild;// 右指针域
};

//二叉排序树★（和链树一样）
typedef struct BTNode {
	int key; //关键字
	struct BTNode *lchild;// 左指针域
	struct BTNode *rchild;// 右指针域
};

//线索树（考纲无，可以了解下）
typedef struct TBTNode {
	char data; //数据域
	int ltag, rtag;//线索标记，=0时则表示对应指针域为指针， =1表示对应指针域为线索，指向该结点的直接前驱（后继）
	struct TBTNode *lchild;// 左指针域
	struct TBTNode *rchild;// 右指针域
};

//图：邻接矩阵★
typedef struct VertexType { //顶点类型
	int no; //顶点编号
	string info; //顶点其他信息(一般是名称），（一般很少用到，题目不做要求不用写）
};
typedef struct MGraph {
	int edges[maxSize][maxSize]; //邻接矩阵定义， 如果是带权图 需要视情况改成double/forlt
	int n, e; //顶点数目和边数
	VertexType vex[maxSize]; //存放节点信息
};

//图：邻接表★
typedef struct ArcNode {  //边表
	int adjvex; //该边所指向的结点的位置
	struct ArcNode *nextarc; //指向下一条边的指针
	string info; //该边的其他信息
};
typedef struct VNode {  //点表
	char data;  //顶点信息 ，可以用string 
	ArcNode *firstarc; //指向第一条边的指针 
};
typedef struct AGraph {
	VNode adjlist[maxSize];//邻接表
	int n, e; //顶点数和边数
};