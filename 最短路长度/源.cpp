#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXV = 1000;//��󶥵���
const int INF = 1000000;//INFΪһ���㹻�����

int n, m, s, G[MAXV][MAXV];//nΪ��������mΪ������sΪ���
int d[MAXV];//��㵽���������·������
bool vis[MAXV] = { false }; //��Ƿ������飬

void Dijkstra(int s) {
	fill(d, d + MAXV, INF);
	d[s] = 0;//��㵽���������Ȼ��0
	for (int i = 0; i < n; i++) {
		int u = -1, MIN = INF; //uʹd[u]��С��MIN���d[u]��ֵ
		for (int j = 0; j < n; j++) {  //Ѱ����С��u
			if (vis[j] == false && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		}
		//�Ҳ���С��INF��d[u]��˵��ʣ�µĶ�������s����ͨ
		if (u == -1) return;
		vis[u] = true;//���u �Ѿ�����
		for (int v = 0; v < n; v++) {  //���vδ���ʣ� �� u�ܵ���v �� ��uΪ�н�����ʹd[u]����
			if (vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v])
				d[v] = d[u] + G[u][v];  //�Ż�d[v]
		}
	}
}
int main() {
	int u, v, w;
	scanf_s("%d%d%d", &n, &m, &s);//��������������������
	fill(G[0], G[0] + MAXV * MAXV,INF);//��ʼ��ͼG
	for (int i = 0; i < m; i++) {
		scanf_s("%d%d%d", &u, &v, &w); //����u,v,��uv֮���Ȩ
		G[u][v] = w;
	}
	Dijkstra(s);
	for (int i = 0; i < n; i++)
		printf("%d ", d[i]);//������ж������̾���
	return 0;
}
