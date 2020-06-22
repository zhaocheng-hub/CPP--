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

//初始化线性表 
Status InitList_Sq(SqList &L) {
	L.elem = new ElemType[MAXSIZE];
	if (!L.elem)
		exit(OVERFLOW);
	L.length = 0;
	return OK;
}
//创建链表
Status ListCreate_Sq(SqList &L) {
	int n;
	cout << "开始创建一个顺序表！" << endl;
	cout << "输入顺序表中的元素个数:";
	cin >> n;
	L.length = n;
	for (int i = 1; i <= n; i++) {
		cout << "请输入第" << i << "个元素的值：";
		cin >> L.elem[i];
	}
	return OK;
}
//顺序表的取值
Status GetElem_Sq(SqList L, int i, ElemType &e) {
	if (i<1 || i>L.length)
		return ERROR;
	e = L.elem[i];
	return 0;
}
//顺序表的查找
Status LocateElem_Sq(SqList L, ElemType e) {
	for (int i = 1; i <= L.length; i++)
		if (L.elem[i] == e)
			return i;
	return 0;
}
//顺序表插入
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
//输出顺序表的信息
Status PrintList_Sq(SqList L) {
	for (int i = 1; i <= L.length; i++) {
		cout << L.elem[i] << " ";
	}
	cout << endl;
	return OK;
	
}
//线性表的合并
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
	cout << "第个顺序表中的元素为:";
	PrintList_Sq(L1);
	ListCreate_Sq(L2);
	cout << "第二个顺序表中的元素为:";
	PrintList_Sq(L2);
	MergeList_Sq(L1, L2);
	cout << "L1与L2和并之后的元素为:";
	PrintList_Sq(L1);
	sort(L1.elem, L1.elem+L1.length + 1, cmp);
	cout << "排序后的顺序表序列为:";
	PrintList_Sq(L1);
}