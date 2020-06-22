//预处理命令
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#define MAXSIZE 10000 //学生表可能达到的最大长度
using namespace std;

//函数状态定义
#define OK 1
#define TRUE 1
#define FALSE 0
#define ERROR -1
#define OVERFLOW -2

//顺序表存储结构定义
typedef int Status;
typedef int ElemType;
typedef struct { 
	char no[20];  //学生编号
	char name[50]; //学生姓名
}Student;
typedef struct {
	Student *elem; //储存空间的基地址
	int length; //图书表中当前图书个数
}SqList;

//顺序表的初始化
Status InitList_Sq(SqList &L) {
	//构造一个空的顺序表L
	L.elem = new Student[MAXSIZE];
	if (!L.elem)
		exit(OVERFLOW);//内存分配失败退出（异常退出）
	L.length = 0; //定义空表长度为0
	return OK;
}
//顺序表的信息输入
Status ListCreate_Sq(SqList &L, int n)
{
	printf("请依次输入线性表中%d个数据元素",n);
	for (int i = 1; i <= n; i++)
	{
		cin >> L.elem[i - 1].no;
		cin >> L.elem[i - 1].name;
	}
	L.length = n;
	return OK;
}
//顺序表的取值
Status GetElem(SqList L, int i, Student &e) {
	//提取数据表L第i个数据元素并将其赋值给e
	if (i<1 || i>L.length)
		return ERROR; //判断i值是否合理，若不合理则返回ERROR
	e = L.elem[i - 1]; //elem[i-1]单元储存第i个数据元素赋值给e
	return 0;
}
//顺序表查找
int LocateElem_Sq(SqList L, char* e){
	//在数据表L中查找与e相同的值的数据元素并返回其标号
	for (int i = 0; i < L.length; i++)
		if (strcmp(L.elem[i].no ,e)==0)
			return i+1 ;   //查找成功返回序号i+1
	return 0;
}

//顺序表插入
Status ListInsert_Sq(SqList &L,int i,Student e){
	//在顺序表L中第i个位置插入新的元素e
	if ((i < 1) || (i > L.length + 1))
		return ERROR;  //i值不合法
	if (L.length == MAXSIZE)
		return ERROR; //当前储存空间已满无法继续添加
	for (int j = L.length - 1; j >= i - 1; j--)
		L.elem[j + 1] = L.elem[j];  //插入位置及之后元素后移
	L.elem[i - 1] = e;
	++L.length;
	return OK;
}
//顺序表的删除
Status ListDelete_Sq(SqList &L, int i) {
	// 在顺序表L中删除第i个元素
	if ((i < 1) || (i > L.length)||(L.length==0))
		return ERROR;  //i值不合法
	for (int j = i; j <= L.length; j++)
		L.elem[j - 1] = L.elem[j]; //删除元素之后元素前移
	--L.length;
	return OK;
}
//输出顺序表的学生信息
int PrintList_Sq(SqList L)
{
	for (int i = 1; i <= L.length; i++)
	{
		cout << L.elem[i - 1].no << "  ";
		cout << L.elem[i - 1].name << "\n";
	}
	return OK;
}
//主程序
int main() {
	SqList L; //定义线性表l
	char e1[20];
	int loc, pos, i; 
	Student stu, e2;
	InitList_Sq(L);
	ListCreate_Sq(L, 2);
	PrintList_Sq(L);
	cout << "请输入要查找的学生的学号";
	cin >> e1;
	loc = LocateElem_Sq(L,e1);
	cout << loc << "\n";
	cout << "请输入要插入的位置和数据";
	cin >> pos;
	cin >> stu.no >> stu.name;
	ListInsert_Sq(L, pos, stu);
	PrintList_Sq(L);
	cout << "请输入要删除第几个元素:";
	cin >> i;
	ListDelete_Sq(L, i);
	PrintList_Sq(L);
}