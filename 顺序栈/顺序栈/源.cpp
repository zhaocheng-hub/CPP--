//Ԥ��������
#include<iostream>
#include<stdio.h>
using namespace std;

#define OK 1
#define OVERFLOW -1

typedef int SElemType;
typedef int Status;
//˳��ջ�Ĵ���ṹ
#define MAXSIZE 10000
typedef struct SqStack {
	SElemType *base;
	SElemType *top;
	int StackSize;   //ջ�Ŀ����������
}SqStack;

//˳��ջ�ĳ�ʼ��
Status InitStack(SqStack &S)
{
	S.base = new SElemType[MAXSIZE]; //��̬����һ������ΪMAXSIZE������ռ�
	if (!S.base) exit(OVERFLOW);
	S.top = S.base; //top��ʼΪbase����ջ
	S.StackSize = MAXSIZE;
	return OK;
}
//�ж�ջ���Ĳ���
Status StackFull(SqStack S)
{
	if (S.base - S.top >= S.StackSize)
		return 1;
	else
		return 0;
}
//�ж�ջ�յĲ���
Status StackEmpty(SqStack S)
{
	if (S.base == S.top)
		return 1;
	else
		return 0;
}
//��ջ����
Status Push(SqStack &S, SElemType e)
{
	if (StackFull(S)) //�ж�ջ�Ƿ���
		cout << "full" << endl;
	else
		*S.top++ = e;   //��Ԫ��eѹ��ջ����ջ��ָ��+1
	return 0;
}
//��ջ����
Status Pop(SqStack &S, SElemType &e)
{
	if (StackEmpty(S))
		cout << "empty" << endl;//�ж�ջ�Ƿ�Ϊ��
	else
		e = *--S.top; //ջ��ָ��-1����ջ��Ԫ�ظ�ֵ��e
	return 0;
}
//���ջ��Ԫ��
SElemType GetTop(SqStack S)
{
	if (StackEmpty(S)) //�ж��Ƿ�ǿ�
		cout << "empty" << endl;
	return *(S.top - 1);
}
//���ջ��Ԫ�ز���
Status PrintStack(SqStack S)
{
	SqStack p = S;
	if (StackEmpty(S)) //�ж��Ƿ�ǿ�
		cout << "empty" << endl;
	else
	{
		while (!StackEmpty(p))  //�ж��Ƿ�ǿ�
		{
			cout << GetTop(p) << " ";
			p.top--;           //ͷָ��-1
		}
	}
	return 0;
}
//ʮ������ת��Ϊ�����������Ĳ���;
int fun1() {
	SqStack S;
	int m, n,x;
	InitStack(S);
	cout << "�������ת����ʮ������m��Ҫת��Ϊ������n:";
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
		cout << "ƥ��ɹ���" << endl;
	else
		cout << "ƥ��ʧ��" << endl;
	return 0;
}
int main() {
	fun1();
	char exp[10000];
	cout << "������һ���ַ���:";
	cin >> exp;
	fun2(exp);
}