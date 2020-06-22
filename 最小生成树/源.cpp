#include <iostream>
#include <algorithm>
using namespace std;
const int MAXV = 1000;//��󶥵���
const int INF = 10000000;//��INFΪһ���ܴ����

int n, m, G[MAXV][MAXV]; //nΪ����,maxvΪ��󶥵���
int d[MAXV];//�����뼯��S����̾��룻
bool vis[MAXV] = { false }; //��Ƿ�������;

int prim() { //Ĭ��0Ϊ���Ժţ�����������С�������ı�Ȩ֮��
	fill(d, d + MAXV, INF);
	d[0] = 0;//����������Ϊ0;
	int ans = 0; //��С�������ı�Ȩ֮��;
	for (int i = 0; i < n; i++) {
		int u = -1, MIN = INF;//uʹd[u[��С��MIN��Ÿ���С��d[u];
		for (int j = 0; j < n; j++) {//�ҵ�δ���ʵĶ�����d[]��С��
			if (vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		//�Ҳ�����С��d[u],��ʣ�µĶ���ͼ���S����ͨ
		if (u == -1) return -1;
		vis[u] = true;//����Է���
		ans += d[u];//���뼯��S������С�ı߼�����С������
		printf("���ӵ�%d����\n", u);
		printf("��ʱ����Ϊ%d\n", ans);
		for (int v = 0; v < n; v++) { //�Ż�d[v]
			if (vis[v] == false && G[u][v] != INF  &&G[u][v] < d[v]) {
				printf("���µ�%d��%d�ľ���", v, u);
				d[v] = G[u][v];
			}
		}
	}
	return ans; 
}
int main() {
	int u, v, w;
	scanf_s("%d%d", &n, &m);//��������������������
	fill(G[0], G[0] + MAXV * MAXV, INF);//��ʼ��ͼG
	for (int i = 0; i < m; i++) {
		scanf_s("%d%d%d", &u, &v, &w); //����u,v,��uv֮���Ȩ
		G[u][v] =G[v][u]= w;
	}
	int ans = prim();
	printf("%d\n", ans);
	return 0;
}