//Ԥ��������
#include<iostream>
#include<string.h>
using namespace std;
typedef int Status;

#define OK 1
//ͼ���ڽӾ��󴢴��ʾ
#define MaxInt -1   //��ʾ����ֵ
#define MVNum 100  //��ʾ��󶥵��� 

typedef char VerTexType;
typedef int ArcType;
typedef struct AMGraph{
	VerTexType vexs[MVNum];	 //�����
	ArcType arcs[MVNum][MVNum];//�ڽӾ���
	int vexnum, arcnum;    //�����ͱ���
};
//ȷ����v��ͼG�е�λ�ã�������������±�
int LocateVex(AMGraph G,VerTexType v){
	for (int i = 0; i < G.vexnum; ++i) {
		if (G.vexs[i]== v)
			return i;
	}
}
//����������G
Status CreateUDN(AMGraph &G) {
	cout << "�������ܶ��������ܱ�����";
	cin >> G.vexnum >> G.arcnum;
	cout << "��������������Ϣ:";
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
		cout << "������һ�����������������㼰Ȩֵ��";
		cin >> v1 >> v2 >> w;
		i = LocateVex(G, v1),j=LocateVex(G,v2);
		G.arcs[i][j] = w;
		G.arcs[j][i] = w;
	}
	return OK;
}
//�����������������
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
	cout << "��ʼ���̽�����ȱ���ͼG:";
	DFSTrave(G);
}