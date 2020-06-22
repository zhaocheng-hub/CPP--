//预处理命令
#include<iostream>
#include<string.h>
using namespace std;
typedef int Status;

#define OK 1
//图的邻接矩阵储存表示
#define MaxInt -1   //表示极大值
#define MVNum 100  //表示最大顶点数 

typedef char VerTexType;
typedef int ArcType;
typedef struct AMGraph{
	VerTexType vexs[MVNum];	 //顶点表
	ArcType arcs[MVNum][MVNum];//邻接矩阵
	int vexnum, arcnum;    //点数和边数
};
//确定点v在图G中的位置，即顶点数组的下标
int LocateVex(AMGraph G,VerTexType v){
	for (int i = 0; i < G.vexnum; ++i) {
		if (G.vexs[i]== v)
			return i;
	}
}
//创建无向网G
Status CreateUDN(AMGraph &G) {
	cout << "请输入总顶点数，总边数：";
	cin >> G.vexnum >> G.arcnum;
	cout << "请依次输入点的信息:";
	for (int i = 0; i < G.vexnum; ++i)
		cin >> G.vexs[i];
	for (int i = 0; i < G.vexnum; ++i) {
		for (int j = 0; j < G.vexnum; ++j) {
			G.arcs[i][j] = MaxInt;
		}
	}
	char v1, v2,i,j;
	int w;
	for (int k = 0; k < G.arcnum; ++k) {
		cout << "请输入一条边依附的两个顶点及权值：";
		cin >> v1 >> v2 >> w;
		i = LocateVex(G, v1),j=LocateVex(G,v2);
		G.arcs[i][j] = w;
		G.arcs[j][i] = w;
	}
	return OK;
}
//深度优先搜索法遍历
bool vis[MVNum] = { false };
int DFS(int u, int depth, AMGraph G) {
	vis[u] = true;
	cout << G.vexs[u] << " ";
	for (int v = 0; v < G.vexnum; v++) {
		if (vis[v] == false && G.arcs[u][v] != MaxInt) {
			DFS(v, depth + 1, G);
		}
	}
	return OK;
}
int DFSTrave(AMGraph G) {
	for (int u = 0; u < G.vexnum; u++) {
		if (vis[u] == false) {
			DFS(u, 1,G);
		}
	}
	return OK;
}
int main() {
	AMGraph G;
	CreateUDN(G);
	cout << "开始深度探索优先遍历图G:";
	DFSTrave(G);
}