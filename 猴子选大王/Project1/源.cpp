#include<iostream>
#include<stdio.h>
using namespace std;
typedef struct Node{
	int data;     // ���
	int point;    // ǰһֻ���ӵı��
	int next;     // ��һֻ���ӵı��
}node,*LinkList;
int main() {
	int  n, m;   //nֻ���ӣ�ÿ��m����̭һ����
	cin >> n >> m;
	 LinkList a = new Node[n];  
	for (int i = 1; i <= n; i++) {
		a[i].point = i - 1;
		a[i].data = i;
		a[i].next = i+1;
	}
	//����ͷ��β
	a[1].point = n;    
	a[n].next = 1;
	int t = 0, i = 1;  //���ڼ���
	while (n != 1) {
		t++;             //����
		if (t==m) {      //��������m��ʱ����̭���Ϊi�ĺ���
			t = 0;       //���ñ���
			n--;         //ʣ�����-1��
			int p = a[i].point;    //pΪ���Ϊi�ĺ���ǰ��ĺ��ӵı��
			int q = a[i].next;     //qΪ���Ϊi�ĺ��Ӻ���ĺ��ӵı��
			a[p].next = q;         //���Ϊp�ĺ��ӵĺ�һֻ���Ӹ�Ϊ���q�ĺ���;
			a[q].point = p;        //���Ϊq�ĺ��ӵ�ǰһֻ���Ӹ�Ϊ���p�ĺ��ӣ�
			cout << "��̭���Ϊ" << i << "�ĺ���" << endl;
		}
	    i = a[i].next;  //i��Ϊ���Ϊi���ӵĺ�һֻ����
	}
	cout <<"���Ϊ"<< i <<"�ĺ����Ǵ���"<< endl;
	delete[] a;
	return 0;
}