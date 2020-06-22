#include<iostream>
#include<string>
using namespace std;
constexpr auto maxSize = 10000;;
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

