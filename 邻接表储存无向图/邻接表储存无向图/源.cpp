//预处理命令
#include <stdio.h> 
#include<stdlib.h> 
using namespace std;
#define TRUE 1 
#define FALSE 0 
#define OK 1
#define ERROR -1
#define OVERFLOW -1

typedef int QElemType;
typedef int Status;

//队列的链式储存结构
typedef struct QNode {
	QElemType data;
	struct QNode *next;
}*QueuePtr;
typedef struct LinkQueue {
	QueuePtr front;
	QueuePtr rear;
};
//链式队列的初始化
Status InitQueue(LinkQueue &Q) {
	Q.front = Q.rear = new QNode;
	Q.front->next = NULL;
	return OK;
}
//链队的入队
Status EnQueue(LinkQueue &Q, QElemType e) {
	QueuePtr p = new QNode;
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}
//链队的出队
Status DeQueue(LinkQueue &Q, QElemType &e) {
	if (Q.front == Q.rear)  //队空
		return ERROR;
	QueuePtr p = Q.front->next;
	e = p->data;
	Q.front->next=p->next;
	if (Q.rear = p)
		Q.rear = Q.front;
	delete p;
	return OK;
}
//取队头元素
QElemType GetHead(LinkQueue Q) {
	if (Q.front != Q.rear)
		return Q.front->next->data;
}

//无向图的邻接表定义
#define MAX_VERTEX_NUM 8 /*顶点最大个数*/ 
#define VertexType char /*顶点元素类型*/ 
enum BOOlean { False, True };
BOOlean visited[MAX_VERTEX_NUM]; //全局变量——访问标志数组
typedef struct ArcNode
{
	int adjvex; //顶点编号
	struct ArcNode *nextarc;
	int weight; /*边的权*/
}ArcNode; /*表结点*/
typedef struct VNode
{
	VertexType data;
	ArcNode *firstarc;
}VNode/*头结点*/, AdjList[MAX_VERTEX_NUM];
typedef struct
{
	AdjList vertices;
	int vexnum, arcnum;/*顶点的实际数，边的实际数*/
}ALGraph;
//建立图的邻接表
void creat_link(ALGraph *G){
	int i, j;
	ArcNode *s;
	printf("请依次输入顶点数、边数：");
	scanf("%d%d", &G->vexnum, &G->arcnum);
	for (i = 0; i<G->vexnum; i++)
	{
		G->vertices[i].data = 'A' + i;
		G->vertices[i].firstarc = NULL;
	}
	for (i = 0; i<G->vexnum;)
	{
		printf("请输入顶点的数组坐标(若退出，请输入-1)：");
		scanf("%d", &i);
		if (i == -1) break;
		printf("请输入顶点所指向下一个顶点的数组坐标：");
		scanf("%d", &j);
		ArcNode* s = new ArcNode;
		s->adjvex = j;
		s->nextarc = G->vertices[i].firstarc;
		G->vertices[i].firstarc = s;
	}
}
// 输出邻接表
void visit(ALGraph G)
{
	int i;
	ArcNode *p;
	printf("%4s%6s%18s\n", "NO", "data", "adjvexs of arcs");
	for (i = 0; i<G.vexnum; i++)
	{
		printf("%4d%5c", i, G.vertices[i].data);
		for (p = G.vertices[i].firstarc; p; p = p->nextarc)
			printf("%3d", p->adjvex);
		printf("\n");
	}
}
//在图G中寻找第v个顶点的第一个邻接顶点
int FirstAdjVex(ALGraph G, int v)
{
	if (!G.vertices[v].firstarc) return 0;
	else return(G.vertices[v].firstarc->adjvex);
}
//在图G中寻找第v个顶点的相对于u的下一个邻接顶点
int NextAdjVex(ALGraph G, int v, int u)
{
	ArcNode *p;
	p = G.vertices[v].firstarc;
	while (p->adjvex != u) p = p->nextarc; //在顶点v的弧链中找到顶点u 
	if (p->nextarc == NULL) return 0; //若已是最后一个顶点，返回0 
	else return(p->nextarc->adjvex); //返回下一个邻接顶点的序号
}

//采用邻接表存储实现无向图的深度优先递归遍历
void DFS(ALGraph G, int i)
{
	int w;
	visited[i] = True; //访问第i个顶点
	printf("%d->", i);
	for (w = FirstAdjVex(G, i); w; w = NextAdjVex(G, i, w))
		if (!visited[w]) DFS(G, w); //对尚未访问的邻接顶点w调用DFS 
}
void DFSTraverse(ALGraph G)
{
	int i;
	printf("DFSTraverse:");
	for (i = 0; i<G.vexnum; i++) visited[i] = False; //访问标志数组初始化
	for (i = 0; i<G.vexnum; i++)
		if (!visited[i]) DFS(G, i); //对尚未访问的顶点调用DFS 
}

//按广度优先非递归的遍历图G，使用辅助队列Q和访问标志数组visited 
void BFSTraverse(ALGraph G)
{
	int i, u, w;
	LinkQueue Q;
	printf("BFSTreverse:");
	for (i = 0; i<G.vexnum; i++) visited[i] = False; //访问标志数组初始化
	InitQueue(Q); //初始化队列
	for (i = 0; i<G.vexnum; i++)
		if (!visited[i])
		{
			visited[i] = True; //访问顶点i 
			printf("%d->", i);
			EnQueue(Q, i); //将序号i入队列
			while (!(Q.front == Q.rear)) //若队列不空，继续
			{
				DeQueue(Q, u); //将队头元素出队列并置为u 
				for (w = FirstAdjVex(G, u); w; w = NextAdjVex(G, u, w))
					if (!visited[w]) //对u的尚未访问的邻接顶点w进行访问并入队列
					{
						visited[w] = True;
						printf("%d->", w);
						EnQueue(Q, w);
					}
			}
		}
}
