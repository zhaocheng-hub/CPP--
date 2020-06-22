#include<iostream>
#include<string>
using namespace std;
constexpr auto maxSize = 10000;;  //ͬ #define maxSzie 10000;

//���еĽṹ���������¼����н�����չ��������չ/�ṹ��չ ����ɵģ��������ֱ��Ĭд��

//˳���    ����ʹ��һά�������䵱˳��洢�Ĳ��� �������Ͳ���һ��ʹ�ã�
typedef struct SqList {  
	int data[maxSize]; //���������Ԫ�ظ�����һ���㹻��ģ���Ŀ���ܸ����� ���Ϳ��Ի����������Ϳ���ĿҪ��
	int length; //���˳���ĳ���
};

//���������
typedef struct LNode {
	int data;  // �����򣨿������������ͣ�
	struct LNode *next;//ָ���� ���˴�����ָ������ڵ㣩
};

//˫�������Ҳ�����֣�
typedef struct DLNode {
	int data;	//������
	struct DLNode *prior;//ָ����ָ��ǰ���ڵ㣩
	struct DLNode *next; //ָ����ָ������ڵ㣩
};

//˳��ջ����ܿ������˳��ջ������˫��ջ�� һ������ʹ������䵱
typedef struct SqStack {
	int dada[maxSize]; //���ջԪ�أ������С��Ҫ���㹻��һ����Ŀ���������Ϳ��㹻��дע�͡�
	int top;  //ջ���±ָ꣨�룩
};

//��ջ�ڵ�   ��ͬ����������ͬ��
typedef struct LNode {
	int data;  //������
	struct LNode *next; //ָ����
};

//˳����Сһ�㿼ѭ����  ����ʹ��һά�������䵱����
typedef struct SqQueue{
	int dada[maxSize]; //������ ��Ŷ�Ԫ�ص�����
	int front;  //�����±�
	int rear; //��β�±�
};

//����  (�ر�ע���£��������Ĳ�ͬ����ʱ������Ҳ��Ҫ�õ�����д�����������Ͳ�Ϊ�������͵�ʱ��Ϊ�Լ��������͵�ʱ��C++�������֣�
//  ���ӵĽڵ㶨������Ͷ����Ƿֿ��ģ����������Ľṹ��඼����һ��ģ���ͼҲ�Ƿֿ��ģ�
typedef struct QNode{   //�ӽڵ�
	int data; //������
	struct QNode *next;//ָ����
};
typedef struct LiQueue {  //������
	QNode *front; //��ͷָ��
	QNode *rear;  //��βָ��
};

//˳��洢����  һ�����ʹ���������洢
//��������Ϊ i��ʱ������������Ϊ i*2  ����������Ϊ 2*i+1

//��ʽ������
typedef struct BTNode {
	char data; //������
	struct BTNode *lchild;// ��ָ����
	struct BTNode *rchild;// ��ָ����
};

//�����������������һ����
typedef struct BTNode {
	int key; //�ؼ���
	struct BTNode *lchild;// ��ָ����
	struct BTNode *rchild;// ��ָ����
};

//�������������ޣ������˽��£�
typedef struct TBTNode {
	char data; //������
	int ltag, rtag;//������ǣ�=0ʱ���ʾ��Ӧָ����Ϊָ�룬 =1��ʾ��Ӧָ����Ϊ������ָ��ý���ֱ��ǰ������̣�
	struct TBTNode *lchild;// ��ָ����
	struct TBTNode *rchild;// ��ָ����
};

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