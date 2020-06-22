//预处理命令
#include<iostream>
#include<stdio.h>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -1

typedef int SElemType;
typedef int Status;
//链栈的储存结构
typedef struct StackNode {
	SElemType data;
	struct StackNode*next;
}StackNode,*LinkStack;

//链栈的初始化
Status InitStack(LinkStack &S) {
	S = NULL;
	return OK;
}
//入栈操作
Status Push(LinkStack &S, SElemType e) {

	LinkStack p = new StackNode;
	p->data = e;
	p->next = S;
	S = p;
	return OK;
}
//出栈操作
Status Pop(LinkStack &S, SElemType &e) {
	LinkStack p;
	if (S == NULL)
		return ERROR;
	e = S->data;
	p = S;
	S = S->next;
	delete p; //释放原栈顶元素的空间
	return OK;
}
//取栈顶元素
SElemType GetTop(LinkStack S)
{
	if (S != NULL)
		return S->data;
	return OK;
}
//输出链栈
Status PrintStack(LinkStack S)
{
	LinkStack p = S;
	if (p == NULL)
		cout << "empty" << endl;
	while (p)
	{
		cout << GetTop(p) << " ";
		p = p->next;
	}
	return OK;
}
//十进制数转换为其他进制数的操作
int fun1() {
	LinkStack S;
	int m, n;
	SElemType x;
	InitStack(S);
	cout << "请输入待转换的十进制数m和要转换为几进制数n:";
	cin >> m >> n;
	while (m) {
		Push(S, m%n);
		m = m / n;
	}
	while (S)
	{
		Pop(S, x);
		cout << x << " ";
	}
	PrintStack(S);
	return 0;
}
//括号匹配
int fun2(char *exp) {
	LinkStack S;
	int State = 1, i = 0;
	SElemType x;
	InitStack(S);
	while (i < strlen(exp) && State)
	{

		switch (exp[i])
		{
		case '(':Push(S, exp[i]);
			i++;
			break;
		case ')':if (S!=NULL)
		{
			Pop(S, x);
			i++;
		}
				 else
					 State = 0;
			break;
		default :
			i++;
		}
    }
	if (S == NULL && State)
		cout << "匹配成功！" << endl;
	else
		cout << "匹配失败" << endl;
	return 0;
}
int main()
{
	fun1();
	char exp[10000];
	cout << "请输入一个字符串:";
	cin >> exp;
	fun2(exp);
}