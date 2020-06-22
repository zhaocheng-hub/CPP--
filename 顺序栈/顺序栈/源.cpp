//预处理命令
#include<iostream>
#include<stdio.h>
using namespace std;

#define OK 1
#define OVERFLOW -1

typedef int SElemType;
typedef int Status;
//顺序栈的储存结构
#define MAXSIZE 10000
typedef struct SqStack {
	SElemType *base;
	SElemType *top;
	int StackSize;   //栈的可用最大容量
}SqStack;

//顺序栈的初始化
Status InitStack(SqStack &S)
{
	S.base = new SElemType[MAXSIZE]; //动态分配一个容量为MAXSIZE的数组空间
	if (!S.base) exit(OVERFLOW);
	S.top = S.base; //top初始为base，空栈
	S.StackSize = MAXSIZE;
	return OK;
}
//判断栈满的操作
Status StackFull(SqStack S)
{
	if (S.base - S.top >= S.StackSize)
		return 1;
	else
		return 0;
}
//判断栈空的操作
Status StackEmpty(SqStack S)
{
	if (S.base == S.top)
		return 1;
	else
		return 0;
}
//入栈操作
Status Push(SqStack &S, SElemType e)
{
	if (StackFull(S)) //判断栈是否满
		cout << "full" << endl;
	else
		*S.top++ = e;   //将元素e压入栈顶，栈顶指针+1
	return 0;
}
//出栈操作
Status Pop(SqStack &S, SElemType &e)
{
	if (StackEmpty(S))
		cout << "empty" << endl;//判断栈是否为空
	else
		e = *--S.top; //栈顶指针-1，将栈顶元素赋值给e
	return 0;
}
//获得栈顶元素
SElemType GetTop(SqStack S)
{
	if (StackEmpty(S)) //判断是否非空
		cout << "empty" << endl;
	return *(S.top - 1);
}
//输出栈中元素操作
Status PrintStack(SqStack S)
{
	SqStack p = S;
	if (StackEmpty(S)) //判断是否非空
		cout << "empty" << endl;
	else
	{
		while (!StackEmpty(p))  //判断是否非空
		{
			cout << GetTop(p) << " ";
			p.top--;           //头指针-1
		}
	}
	return 0;
}
//十进制数转换为其他进制数的操作;
int fun1() {
	SqStack S;
	int m, n,x;
	InitStack(S);
	cout << "请输入待转换的十进制数m和要转换为几进制n:";
	cin >> m >> n;
	while (m) {
		Push(S, m%n);
		m = m / n;
	}
	while (!StackEmpty(S))
	{
		Pop(S, x);
		cout << x << " ";
	}
	PrintStack(S);
	return 0;
}
int fun2(char *exp) {
	SqStack S;
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
		case ')':if (!StackEmpty(S))
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
	if (StackEmpty(S) && State)
		cout << "匹配成功！" << endl;
	else
		cout << "匹配失败" << endl;
	return 0;
}
int main() {
	fun1();
	char exp[10000];
	cout << "请输入一个字符串:";
	cin >> exp;
	fun2(exp);
}