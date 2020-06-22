#include<stdio.h>
#include<iostream>
#include<algorithm>
#define MAXSIZE 10001
using namespace std;

#define OK 1
#define FALSE 0
#define ERROR -1

typedef int ElemType;
typedef int Status;

typedef struct {
	ElemType *elem;
	int length;
}SqList;

//��ʼ�����Ա� 
Status InitList_Sq(SqList &L) {
	L.elem = new ElemType[MAXSIZE];
	if (!L.elem)
		exit(OVERFLOW);
	L.length = 0;
	return OK;
}
//��������
Status ListCreate_Sq(SqList &L) {
	int n;
	cout << "��ʼ����һ��˳���" << endl;
	cout << "����˳����е�Ԫ�ظ���:";
	cin >> n;
	L.length = n;
	for (int i = 1; i <= n; i++) {
		cout << "�������" << i << "��Ԫ�ص�ֵ��";
		cin >> L.elem[i];
	}
	return OK;
}
//˳����ȡֵ
Status GetElem_Sq(SqList L, int i, ElemType &e) {
	if (i<1 || i>L.length)
		return ERROR;
	e = L.elem[i];
	return 0;
}
//˳���Ĳ���
Status LocateElem_Sq(SqList L, ElemType e) {
	for (int i = 1; i <= L.length; i++)
		if (L.elem[i] == e)
			return i;
	return 0;
}
//˳������
Status ListInsert_Sq(SqList &L, int i, ElemType e) {
	if ((i < 1) || (i > L.length+1))
		return ERROR;
	if (L.length == MAXSIZE-1)
		return ERROR;
	for (int j = L.length; j >= i ; j--)
		L.elem[j + 1] = L.elem[j];
	L.elem[i] = e;
	++L.length;
	return OK;
}
//���˳������Ϣ
Status PrintList_Sq(SqList L) {
	for (int i = 1; i <= L.length; i++) {
		cout << L.elem[i] << " ";
	}
	cout << endl;
	return OK;
	
}
//���Ա�ĺϲ�
Status MergeList_Sq(SqList &L1, SqList L2) {
	int m = L1.length;
	int n = L2.length;
	ElemType e;
	for (int i = 1; i <= n; i++) {
		GetElem_Sq(L2, i, e);
		if (!LocateElem_Sq(L1, e))
			ListInsert_Sq(L1, ++m, e);
	}
	return OK;
}

bool cmp(ElemType a, ElemType b){
	return a < b;
}
int main(){
	SqList L1,L2;
	InitList_Sq(L1);
	InitList_Sq(L2);
	ListCreate_Sq(L1);
	cout << "�ڸ�˳����е�Ԫ��Ϊ:";
	PrintList_Sq(L1);
	ListCreate_Sq(L2);
	cout << "�ڶ���˳����е�Ԫ��Ϊ:";
	PrintList_Sq(L2);
	MergeList_Sq(L1, L2);
	cout << "L1��L2�Ͳ�֮���Ԫ��Ϊ:";
	PrintList_Sq(L1);
	sort(L1.elem, L1.elem+L1.length + 1, cmp);
	cout << "������˳�������Ϊ:";
	PrintList_Sq(L1);
}