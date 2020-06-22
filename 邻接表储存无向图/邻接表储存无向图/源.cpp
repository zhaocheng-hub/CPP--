//Ԥ��������
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

//���е���ʽ����ṹ
typedef struct QNode {
	QElemType data;
	struct QNode *next;
}*QueuePtr;
typedef struct LinkQueue {
	QueuePtr front;
	QueuePtr rear;
};
//��ʽ���еĳ�ʼ��
Status InitQueue(LinkQueue &Q) {
	Q.front = Q.rear = new QNode;
	Q.front->next = NULL;
	return OK;
}
//���ӵ����
Status EnQueue(LinkQueue &Q, QElemType e) {
	QueuePtr p = new QNode;
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}
//���ӵĳ���
Status DeQueue(LinkQueue &Q, QElemType &e) {
	if (Q.front == Q.rear)  //�ӿ�
		return ERROR;
	QueuePtr p = Q.front->next;
	e = p->data;
	Q.front->next=p->next;
	if (Q.rear = p)
		Q.rear = Q.front;
	delete p;
	return OK;
}
//ȡ��ͷԪ��
QElemType GetHead(LinkQueue Q) {
	if (Q.front != Q.rear)
		return Q.front->next->data;
}

//����ͼ���ڽӱ���
#define MAX_VERTEX_NUM 8 /*����������*/ 
#define VertexType char /*����Ԫ������*/ 
enum BOOlean { False, True };
BOOlean visited[MAX_VERTEX_NUM]; //ȫ�ֱ����������ʱ�־����
typedef struct ArcNode
{
	int adjvex; //������
	struct ArcNode *nextarc;
	int weight; /*�ߵ�Ȩ*/
}ArcNode; /*����*/
typedef struct VNode
{
	VertexType data;
	ArcNode *firstarc;
}VNode/*ͷ���*/, AdjList[MAX_VERTEX_NUM];
typedef struct
{
	AdjList vertices;
	int vexnum, arcnum;/*�����ʵ�������ߵ�ʵ����*/
}ALGraph;
//����ͼ���ڽӱ�
void creat_link(ALGraph *G){
	int i, j;
	ArcNode *s;
	printf("���������붥������������");
	scanf("%d%d", &G->vexnum, &G->arcnum);
	for (i = 0; i<G->vexnum; i++)
	{
		G->vertices[i].data = 'A' + i;
		G->vertices[i].firstarc = NULL;
	}
	for (i = 0; i<G->vexnum;)
	{
		printf("�����붥�����������(���˳���������-1)��");
		scanf("%d", &i);
		if (i == -1) break;
		printf("�����붥����ָ����һ��������������꣺");
		scanf("%d", &j);
		ArcNode* s = new ArcNode;
		s->adjvex = j;
		s->nextarc = G->vertices[i].firstarc;
		G->vertices[i].firstarc = s;
	}
}
// ����ڽӱ�
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
//��ͼG��Ѱ�ҵ�v������ĵ�һ���ڽӶ���
int FirstAdjVex(ALGraph G, int v)
{
	if (!G.vertices[v].firstarc) return 0;
	else return(G.vertices[v].firstarc->adjvex);
}
//��ͼG��Ѱ�ҵ�v������������u����һ���ڽӶ���
int NextAdjVex(ALGraph G, int v, int u)
{
	ArcNode *p;
	p = G.vertices[v].firstarc;
	while (p->adjvex != u) p = p->nextarc; //�ڶ���v�Ļ������ҵ�����u 
	if (p->nextarc == NULL) return 0; //���������һ�����㣬����0 
	else return(p->nextarc->adjvex); //������һ���ڽӶ�������
}

//�����ڽӱ�洢ʵ������ͼ��������ȵݹ����
void DFS(ALGraph G, int i)
{
	int w;
	visited[i] = True; //���ʵ�i������
	printf("%d->", i);
	for (w = FirstAdjVex(G, i); w; w = NextAdjVex(G, i, w))
		if (!visited[w]) DFS(G, w); //����δ���ʵ��ڽӶ���w����DFS 
}
void DFSTraverse(ALGraph G)
{
	int i;
	printf("DFSTraverse:");
	for (i = 0; i<G.vexnum; i++) visited[i] = False; //���ʱ�־�����ʼ��
	for (i = 0; i<G.vexnum; i++)
		if (!visited[i]) DFS(G, i); //����δ���ʵĶ������DFS 
}

//��������ȷǵݹ�ı���ͼG��ʹ�ø�������Q�ͷ��ʱ�־����visited 
void BFSTraverse(ALGraph G)
{
	int i, u, w;
	LinkQueue Q;
	printf("BFSTreverse:");
	for (i = 0; i<G.vexnum; i++) visited[i] = False; //���ʱ�־�����ʼ��
	InitQueue(Q); //��ʼ������
	for (i = 0; i<G.vexnum; i++)
		if (!visited[i])
		{
			visited[i] = True; //���ʶ���i 
			printf("%d->", i);
			EnQueue(Q, i); //�����i�����
			while (!(Q.front == Q.rear)) //�����в��գ�����
			{
				DeQueue(Q, u); //����ͷԪ�س����в���Ϊu 
				for (w = FirstAdjVex(G, u); w; w = NextAdjVex(G, u, w))
					if (!visited[w]) //��u����δ���ʵ��ڽӶ���w���з��ʲ������
					{
						visited[w] = True;
						printf("%d->", w);
						EnQueue(Q, w);
					}
			}
		}
}
