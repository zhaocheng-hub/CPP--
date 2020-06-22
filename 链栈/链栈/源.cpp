//Ԥ��������
#include<iostream>
#include<stdio.h>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -1

typedef int SElemType;
typedef int Status;
//��ջ�Ĵ���ṹ
typedef struct StackNode {
	SElemType data;
	struct StackNode*next;
}StackNode,*LinkStack;

//��ջ�ĳ�ʼ��
Status InitStack(LinkStack &S) {
	S = NULL;
	return OK;
}
//��ջ����
Status Push(LinkStack &S, SElemType e) {

	LinkStack p = new StackNode;
	p->data = e;
	p->next = S;
	S = p;
	return OK;
}
//��ջ����
Status Pop(LinkStack &S, SElemType &e) {
	LinkStack p;
	if (S == NULL)
		return ERROR;
	e = S->data;
	p = S;
	S = S->next;
	delete p; //�ͷ�ԭջ��Ԫ�صĿռ�
	return OK;
}
//ȡջ��Ԫ��
SElemType GetTop(LinkStack S)
{
	if (S != NULL)
		return S->data;
	return OK;
}
//�����ջ
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
//ʮ������ת��Ϊ�����������Ĳ���
int fun1() {
	LinkStack S;
	int m, n;
	SElemType x;
	InitStack(S);
	cout << "�������ת����ʮ������m��Ҫת��Ϊ��������n:";
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
//����ƥ��
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
		cout << "ƥ��ɹ���" << endl;
	else
		cout << "ƥ��ʧ��" << endl;
	return 0;
}
int main()
{
	fun1();
	char exp[10000];
	cout << "������һ���ַ���:";
	cin >> exp;
	fun2(exp);
}