#include<iostream>

//˫�������Ҳ�����֣�
typedef struct DLNode {
	int data;	//������
	struct DLNode *prior;//ָ����ָ��ǰ���ڵ㣩
	struct DLNode *next; //ָ����ָ������ڵ㣩
};

//����β�巨����˫����  �����Ŀ��ܲ���
void createDlistR(DLNode *&L, int a[], int n) {
	DLNode *s, *r;
	int i;
	DLNode *L = new DLNode;
	L->prior = NULL;
	L->next = NULL;  //���п��ޣ�
	r = L; //�͵�����һ����rʼ��ָ���ն˽ڵ㣬��ʼͷ�ڵ�Ҳ��β�ڵ�
	for (int i = 0; i < n; i++) {
		DLNode *s = new DLNode; 
		s->data = a[i];
		//�������
		r->next = s;
		s->prior = r;
		r = s;
	}
	r->next = NULL; //����Ҫ��
}

//˫����ò��ҽڵ��㷨  
//�͵������޲�ͬ��ɾ����ʱ�����в�ͬ��

/*����ڵ��㷨  ��p��ָ�Ľڵ�֮�����һ���ڵ�s
s->next = p->next;
s->prior=p;
p->next=s;
s->next->prior=s;  //��pָ�����һ���ڵ㣬���п���ȥ��
*/

