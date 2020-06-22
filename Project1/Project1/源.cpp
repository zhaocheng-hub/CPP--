//Ԥ��������
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#define MAXSIZE 10000 //ѧ������ܴﵽ����󳤶�
using namespace std;

//����״̬����
#define OK 1
#define TRUE 1
#define FALSE 0
#define ERROR -1
#define OVERFLOW -2

//˳���洢�ṹ����
typedef int Status;
typedef int ElemType;
typedef struct {
	char no[20];  //ѧ�����
	char name[50]; //ѧ������
}Student;
typedef struct {
	Student *elem; //����ռ�Ļ���ַ
	int length; //ͼ����е�ǰͼ�����
}SqList;

//˳���ĳ�ʼ��
Status InitList_Sq(SqList &L) {
	//����һ���յ�˳���L
	L.elem = new Student[MAXSIZE];
	if (!L.elem)
		exit(OVERFLOW);//�ڴ����ʧ���˳����쳣�˳���
	L.length = 0; //����ձ���Ϊ0
	return OK;
}
//˳������Ϣ����
Status ListCreate_Sq(SqList &L, int n)
{
	printf("�������������Ա���%d������Ԫ��\n", n);
	for (int i = 1; i <= n; i++)
	{
		cin >> L.elem[i - 1].no;
		cin >> L.elem[i - 1].name;
	}
	L.length = n;
	return OK;
}
//˳����ȡֵ
Status GetElem(SqList L, int i, Student &e) {
	//��ȡ���ݱ�L��i������Ԫ�ز����丳ֵ��e
	if (i<1 || i>L.length)
		return ERROR; //�ж�iֵ�Ƿ�������������򷵻�ERROR
	e = L.elem[i - 1]; //elem[i-1]��Ԫ�����i������Ԫ�ظ�ֵ��e
	return 0;
}
//˳������
int LocateElem_Sq(SqList L, char* e) {
	//�����ݱ�L�в�����e��ͬ��ֵ������Ԫ�ز���������
	for (int i = 0; i < L.length; i++)
		if (strcmp(L.elem[i].no, e) == 0)
			return i + 1;   //���ҳɹ��������i+1
	return 0;
}
//˳������
Status ListInsert_Sq(SqList &L, int i, Student e) {
	//��˳���L�е�i��λ�ò����µ�Ԫ��e
	if ((i < 1) || (i > L.length + 1))
		return ERROR;  //iֵ���Ϸ�
	if (L.length == MAXSIZE)
		return ERROR; //��ǰ����ռ������޷��������
	for (int j = L.length - 1; j >= i - 1; j--)
		L.elem[j + 1] = L.elem[j];  //����λ�ü�֮��Ԫ�غ���
	L.elem[i - 1] = e;
	++L.length;
	return OK;
}

//���˳����ѧ����Ϣ
int PrintList_Sq(SqList L)
{
	for (int i = 1; i <= L.length; i++)
	{
		cout << L.elem[i - 1].no << "  ";
		cout << L.elem[i - 1].name << "\n";
	}
	return OK;
}
void MergeList(SqList &L1, SqList L2)
{
	int m = L1.length,n=L2.length;
	Student e;
	for (int i = 1; i <= n; i++)
	{
		GetElem(L2, i, e);
		if (!LocateElem_Sq(L1, e.no))
			ListInsert_Sq(L1, ++m, e);
	}
}
//������
int main() {
	SqList L1,L2; //�������Ա�l
	InitList_Sq(L1);
	InitList_Sq(L2);
	ListCreate_Sq(L1, 5);
	PrintList_Sq(L1);
	cout << endl;
	ListCreate_Sq(L2, 3);
	PrintList_Sq(L2);
	cout << endl;
	MergeList(L1, L2);
	PrintList_Sq(L1);
}