#include<iostream>
#include<string>
using namespace std;
constexpr auto maxSize = 10000;;
//ͼ���ڽӾ����
typedef struct VertexType { //��������
	int no; //������
	string info; //����������Ϣ(һ�������ƣ�����һ������õ�����Ŀ����Ҫ����д��
};
typedef struct MGraph {
	int edges[maxSize][maxSize]; //�ڽӾ����壬 ����Ǵ�Ȩͼ ��Ҫ������ĳ�double/forlt
	int n, e; //������Ŀ�ͱ���
	VertexType vex[maxSize]; //��Žڵ���Ϣ
};

//ͼ���ڽӱ��
typedef struct ArcNode {  //�߱�
	int adjvex; //�ñ���ָ��Ľ���λ��
	struct ArcNode *nextarc; //ָ����һ���ߵ�ָ��
	string info; //�ñߵ�������Ϣ
};
typedef struct VNode {  //���
	char data;  //������Ϣ ��������string 
	ArcNode *firstarc; //ָ���һ���ߵ�ָ�� 
};
typedef struct AGraph {
	VNode adjlist[maxSize];//�ڽӱ�
	int n, e; //�������ͱ���
};

