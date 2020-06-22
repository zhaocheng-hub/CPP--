#include <iostream>
using namespace std;
constexpr auto maxSize = 10000;;
//˳��ջ����ܿ������˳��ջ������˫��ջ�� һ������ʹ������䵱
typedef struct SqStack {
	int data[maxSize]; //���ջԪ�أ������С��Ҫ���㹻��һ����Ŀ���������Ϳ��㹻��дע�͡�
	int top;  //ջ���±ָ꣨�룩
};

//��ջ�ڵ�   ��ͬ����������ͬ��
typedef struct LNode {
	int data;  //������
	struct LNode *next; //ָ����
};

//��ʼ��˳��ջ  ,����ջ����һ���洢�ռ�ĳ�ʼ��ҲҪ��  ����䵱ջ��ʱ��ҲҪ��
void initStack(SqStack &st) {
	st.top = -1;
}

//�ж�ջ��  ���Ϊ���򷵻� 1��
int isEmpty(SqStack st) {  
	if (st.top == -1) {
		return 1;
	}
	else {
		return 0;
	}
}

//��ջ����
int push(SqStack &st, int x) {
	if (st.top == maxSize - 1) {  //ջ����
		return 0; 
	}
	++(st.top);
	st.data[st.top] = x;
	return 1;
}

//��ջ����
int pop(SqStack &st, int &x) {
	if (st.top == -1) { // �ж�ջ�Ƿ�Ϊ�գ�
		return 0;
	}
	x = st.data[st.top];
	--(st.top);
	return 1;
}

//��ջ�ĳ�ʼ��
void initStack(LNode*&lst) { //��Ϊlst��ͷ,���룩Ҫ�ı�
	LNode* lst = new LNode;  //��ʵ�������Ҫ��ԭ����lst��û�пռ䣬�˴�Ϊ�Ѿ�û�пռ䣨���Ѿ��ͷŵ�������µĲ���
	lst->next = NULL;
}

//�ж�ջ��
int isEmpty(LNode *lst) {
	if (lst->next == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

//���ջ
void push(LNode *lst, int x) {
	LNode *p = new LNode; //����p��ָ�� ����LNode���ͽڵ�ĵ�ַ
	p->next = NULL;
	/*������������ͷ�巨*/
	p->data = x;
	p->next = lst->next;
	lst->next = p;
}

//���ջ����
int pop(LNode *lst, int &x) {  //x��ֵ��Ҫ�ı� &
	LNode *p;
	if (lst->next == NULL) {  //�ж��Ƿ�ӿ�
		return 0;
	}
	/*������ǵ������ɾ������*/
	p = lst->next;
	x = p->data;
	lst->next = p->next;
	delete p;
	return 1;
}

//��˳��ջ��Ӧ�� ������ƥ�䣩
int match(char exp[], int n) {
	char stack[maxSize];  //��ʼ��
	int top = -1;
	for (int i = 1; i < n; ++i) {
		if (exp[i] == '(') {
			stack[++top] = '(';   //�ȼ�����
		}
		if (exp[i] == ')') {
			if (top == -1)    //ջ��
				return 0; //���ز�ƥ��
			else
				--top;  //��ջ
		}
	}
	if (top == -1)  //ջ�գ��������Ŷ�ƥ����� 
		return 1; //ƥ��
	else
		return 0;
}

//��дһ�����������׺ʽ����ֵ�����׺ʽ�洢��exp�ַ������У�exp�����һ���ַ�Ϊ��\0����Ϊ������
// �����׺ʽ�е����ֶ�ֻ��һλ�����ֵĳ������㣬��Ϊ�������㣬
// ע�����Ǻ�׺ʽ�ģ������Ҫ�ر�ע����ǰ׺ʽ�ģ�Ҫ��д���� �����ǿ���У����Բ���
int op(int a, char Op, int b) { //���㺯�� ��� a Op b ������
	if (Op == '+')
		return a + b;
	if (Op == '-')
		return a - b;
	if (Op == '*')
		return a * b;
	if (Op == '/') {
		if (b == 0) {    //����������Ϊ0
			return 0; 
		}
		else {
			return a / b;
		}
	}
}
int com(char exp[]) {
	int a, b, c;  
	int stack[maxSize];  //ע��˴���int��
	int top = -1;
	char Op; //ȡ�����
	for (int i = 0; exp[i] != '\0'; ++i) {
		if (exp[i] >= '0'&&exp[i] <= '9') { //�������������ջ
			stack[++top] = exp[i] - '0'; //char��int ת��
		}
		else {  //����������
			Op = exp[i];
			b = stack[top--]; //��ջ
			a = stack[top--];
			c = op(a, Op, b); //����
			stack[++top] = c;//��ջ
		}
	}
	return stack[top];
}

//���ò���ͷ���ĵ���������ջ����Ƴ�ʼ��ջ���ж�ջ�Ƿ�Ϊ�գ���ջ�ͳ�ջ��Ӧ����
// �����Լ�дһ����ͷ���ģ� �����Ŀ��Ŀ����Ժܵ�
void initStack1(LNode *&lst) {//��ʼ��
	lst = NULL;
}
int isEmpty1(LNode *lst) { //�ж�ջ�Ƿ�Ϊ��
	if (lst == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}
void push1(LNode *&lst, int x) { //��ջ
	LNode *p = new LNode;
	p->next = NULL;
	p->data = x;
	/*�������*/
	p->next = lst;
	lst = p;
}
int pop1(LNode *&lst, int &x) {
	LNode *p;
	if (lst == NULL) {
		return 0;
	}
	p = lst;
	/*ɾ���ڵ����*/
	x = p->data;
	lst = p->next;
	delete p;
	return 1;
}

//��ﹲ��ջ ջS0��S1����һ���洢������ƹ���ջ�����ջ����ջ���������㷨
typedef struct SqStack1 { //����ջ�ṹ����
	int elem[maxSize]; //ջ�ռ�
	int top[2];  //����ջ����־
};
int push(SqStack1 &st, int stNo, int x) {  //��ջ������stNo ��ջ�ı�ţ�ָʾԪ��x������ջ
	if (st.top[0] + 1 < st.top[1]) {  //ջ����
		if (stNo == 0) {
			++(st.top[0]);
			st.elem[st.top[0]] = x;
			return 1;
		}
		else if (stNo == 1) {
			--(st.top[1]);
			st.elem[st.top[1]] = x;
			return 1;
		}
		else {
			return 0;  //��Ŵ���   
		}
	}
	else {
		return 0; //����ջ��
	}
}
int pop(SqStack1 &st, int stNo, int &x) { //��ջ����
	if (stNo == 0) {
		if (st.top[0] != -1) {  //�п�
			x = st.elem[st.top[0]];
			--(st.top[0]);
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (stNo == 1) {
		if (st.top[1] != maxSize) {
			x = st.elem[st.top[1]];
			++(st.top[1]);
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		return -1;
	}
}

//���������ջs1��s2��ģ��һ�����У�ջ��Ԫ��Ϊint�ͣ�ջ��Ԫ�����ΪmanSize����֪������������
//posh(ST, x); Ԫ��x��ջ
//pop(ST,&x); Ԫ��x��ջ
//isEmpty(ST); �ж�STջ�Ƿ�Ϊ�ա�
//�������ջ������ʵ�ָö��е�3�����㣬enQueue��Ԫ����ӣ���deQueue��Ԫ�س����У�
//isQueueEmpty���ж϶����Ƿ�Ϊ�գ��շ���1����
int enQueue(SqStack &s1, SqStack &s2, int x) {  //��ջ
	int y;
	if (s1.top == maxSize - 1) {
		if (!isEmpty(s2)) {  //s1����s2�ǿգ���ʱs1��������ջ
			return 0; 
		}
		else if (isEmpty(s2)) {  //��s2Ϊ�գ���s1��ջ������ջ
			while (!isEmpty(s1)) {
				pop(s1, y);
				push(s2, y);
			}
			push(s1, x);//x��ջ
			return 1;
		}
	}
	else {
		push(s1, x);  //s1������xֱ����ջ
		return 1;
	}
}
int deQueue(SqStack &s2, SqStack &s1, int &x) { //��ջ
	int y;
	if (!isEmpty(s2)) { //ջs2���գ�ֱ�ӳ��ӣ�����1
		pop(s2, x);
		return 1;
	}
	else {
		if (isEmpty(s1)) {
			return 0;
		}
		else {
			while (!isEmpty(s1)) {
				pop(s1, y);
				push(s2, y);
			}
			pop(s2, x); //s2��ջ��ʵ�ֳ�����
			return 1;
		}
	}
}
int isQueueEmpty(SqStack s1, SqStack s2) { //�ж϶��Ƿ�Ϊ��
	if (isEmpty(s1) && isEmpty(s2)) {
		return 1;
	}
	else {
		return 0;
	}
}

//дһ���㷨 �ж���ջ�ͳ�ջ�����Ƿ�Ϸ�
int juge(char ch[]) {
	int i = 0, I = 0, O = 0;  //I:��ջ�ܴ����� O��ջ�ܴ���
	while (ch[i] != '\0') {
		if (ch[i] == 'I') {
			I++;
		}
		if (ch[i] == 'O') {
			O++;
		}
		if (O > I) {
			return 0;    //��ջ����������ջ����ʱ
		}
		++i;
	}
	if (I != 0) {
		return 0;
	}
	else {
		return 1;
	}
}

//�������Դ�ͷ����ѭ�������ʾ���У�����ֻ��һ��ָ��ָ���β�ڵ㣬������ͷָ��
//��д����Ӧ����Ժͳ����㷨
void enQueue(LNode *&rear, int x) {  //����㷨
	LNode *s = new LNode;
	s->data = x;
	s->next = rear->next;
	rear->next = s;
	rear = s;
}
int deQueue(LNode *&rear, int &x) {  //�����㷨
	LNode *s;
	if (rear->next == rear) {
		return 0;
	}
	else {
		s = rear->next->next;  //sָ��ʼ�ڵ�
		rear->next->next = s->next;
		x = s->data;
		if (s == rear) {   //�����ջ��Ϊ��
			rear = rear->next;//ָ��ͷ�ڵ�
		}
		delete s;
		return 0;
	}
}

//������һ���㷨����һ���Ǹ�ʮ��������Nת��Ϊһ����������
int BaseTrans(int N) {
	int i, result = 0;
	int stack[maxSize], top = -1;
	while (N != 0) {
		i = N % 2;
		N = N / 2;
		stack[++top] = i;
	}
	while (top != -1) {
		i = stack[top];
		--top;
		result = result * 10 + i;
	}
	return result;
}

//����д�Զ���㷨�����һ�������еĻ����ţ������ţ�ԭ�����Ƿ�ƥ�䣬��ȫ��ƥ���򷵻�1���򷵻�0��
//���ڳ����г��ֵĵ����ź�˫�����ڵ��ַ�������������Լ�飬�����ź�˫���ű�Ȼ��Գ���
/*���� stackʱ�Ѿ�����õ�˳��ջ�ṹ�壬����ֱ�ӵ��õ�Ԫ�ؽ�ջ/��ջ��ȡջ��Ԫ�أ��ж�ջ�յĺ�������
void push(stack &S,char ch);
void pop(stack &S,char &ch);
void getTop(stack S,char &ch);
int isEmpty(stack S); //��ջ���򷵻�1�����򷵻�0
*/
int bracketsCheck(char f[]) {  
	//������
}

