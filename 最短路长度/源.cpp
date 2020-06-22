#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXV = 1000;//最大顶点数
const int INF = 1000000;//INF为一个足够大的数

int n, m, s, G[MAXV][MAXV];//n为顶点数，m为边数，s为起点
int d[MAXV];//起点到达各点的最短路径长度
bool vis[MAXV] = { false }; //标记访问数组，

void Dijkstra(int s) {
	fill(d, d + MAXV, INF);
	d[s] = 0;//起点到自身距离自然是0
	for (int i = 0; i < n; i++) {
		int u = -1, MIN = INF; //u使d[u]最小，MIN存放d[u]的值
		for (int j = 0; j < n; j++) {  //寻找最小的u
			if (vis[j] == false && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		}
		//找不到小于INF的d[u]，说明剩下的顶点和起点s不连通
		if (u == -1) return;
		vis[u] = true;//标记u 已经访问
		for (int v = 0; v < n; v++) {  //如果v未访问， 且 u能到达v 且 以u为中介点可以使d[u]更优
			if (vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v])
				d[v] = d[u] + G[u][v];  //优化d[v]
		}
	}
}
int main() {
	int u, v, w;
	scanf_s("%d%d%d", &n, &m, &s);//顶点个数，边数，起点编号
	fill(G[0], G[0] + MAXV * MAXV,INF);//初始化图G
	for (int i = 0; i < m; i++) {
		scanf_s("%d%d%d", &u, &v, &w); //输入u,v,和uv之间的权
		G[u][v] = w;
	}
	Dijkstra(s);
	for (int i = 0; i < n; i++)
		printf("%d ", d[i]);//输出所有顶点的最短距离
	return 0;
}
