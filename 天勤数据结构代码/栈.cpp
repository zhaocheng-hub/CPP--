#include <iostream>
using namespace std;
constexpr auto maxSize = 10000;;
//顺序栈★（可能考特殊的顺序栈，例如双向栈） 一样可以使用数组充当
typedef struct SqStack {
	int data[maxSize]; //存放栈元素，数组大小，要开足够大（一般题目给）不给就开足够大，写注释。
	int top;  //栈顶下标（指针）
};

//链栈节点   （同链表，操作不同）
typedef struct LNode {
	int data;  //数据域
	struct LNode *next; //指针域
};

//初始化顺序栈  ,两个栈共用一个存储空间的初始化也要会  数组充当栈的时候也要会
void initStack(SqStack &st) {
	st.top = -1;
}

//判断栈空  如果为空则返回 1，
int isEmpty(SqStack st) {  
	if (st.top == -1) {
		return 1;
	}
	else {
		return 0;
	}
}

//进栈代码
int push(SqStack &st, int x) {
	if (st.top == maxSize - 1) {  //栈不满
		return 0; 
	}
	++(st.top);
	st.data[st.top] = x;
	return 1;
}

//出栈代码
int pop(SqStack &st, int &x) {
	if (st.top == -1) { // 判断栈是否为空，
		return 0;
	}
	x = st.data[st.top];
	--(st.top);
	return 1;
}

//链栈的初始化
void initStack(LNode*&lst) { //因为lst（头,申请）要改变
	LNode* lst = new LNode;  //其实具体情况要看原本的lst有没有空间，此处为已经没有空间（或已经释放掉）情况下的操作
	lst->next = NULL;
}

//判断栈空
int isEmpty(LNode *lst) {
	if (lst->next == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

//★进栈
void push(LNode *lst, int x) {
	LNode *p = new LNode; //定义p并指向 申请LNode类型节点的地址
	p->next = NULL;
	/*下面就是链表的头插法*/
	p->data = x;
	p->next = lst->next;
	lst->next = p;
}

//★出栈代码
int pop(LNode *lst, int &x) {  //x的值需要改变 &
	LNode *p;
	if (lst->next == NULL) {  //判断是否队空
		return 0;
	}
	/*下面就是单链表的删除操作*/
	p = lst->next;
	x = p->data;
	lst->next = p->next;
	delete p;
	return 1;
}

//★顺序栈的应用 （括号匹配）
int match(char exp[], int n) {
	char stack[maxSize];  //初始化
	int top = -1;
	for (int i = 1; i < n; ++i) {
		if (exp[i] == '(') {
			stack[++top] = '(';   //先加再用
		}
		if (exp[i] == ')') {
			if (top == -1)    //栈空
				return 0; //返回不匹配
			else
				--top;  //出栈
		}
	}
	if (top == -1)  //栈空（所有括号都匹配掉） 
		return 1; //匹配
	else
		return 0;
}

//编写一个函数，求后缀式的数值，其后缀式存储于exp字符数组中，exp中最后一个字符为‘\0’作为结束符
// 假设后缀式中的数字都只有一位，出现的除法运算，都为整除运算，
// 注意这是后缀式的，如果还要特别注意下前缀式的（要会写）， 这个不强求背诵，可以不被
int op(int a, char Op, int b) { //运算函数 完成 a Op b 的运算
	if (Op == '+')
		return a + b;
	if (Op == '-')
		return a - b;
	if (Op == '*')
		return a * b;
	if (Op == '/') {
		if (b == 0) {    //被除数不能为0
			return 0; 
		}
		else {
			return a / b;
		}
	}
}
int com(char exp[]) {
	int a, b, c;  
	int stack[maxSize];  //注意此处是int型
	int top = -1;
	char Op; //取运算符
	for (int i = 0; exp[i] != '\0'; ++i) {
		if (exp[i] >= '0'&&exp[i] <= '9') { //如果是数字则入栈
			stack[++top] = exp[i] - '0'; //char向int 转化
		}
		else {  //如果是运算符
			Op = exp[i];
			b = stack[top--]; //出栈
			a = stack[top--];
			c = op(a, Op, b); //运算
			stack[++top] = c;//进栈
		}
	}
	return stack[top];
}

//★用不带头结点的单链表储存链栈，设计初始化栈，判断栈是否为空，进栈和出栈相应操作
// 建议自己写一个带头结点的， 不带的考的可能性很低
void initStack1(LNode *&lst) {//初始化
	lst = NULL;
}
int isEmpty1(LNode *lst) { //判断栈是否为空
	if (lst == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}
void push1(LNode *&lst, int x) { //进栈
	LNode *p = new LNode;
	p->next = NULL;
	p->data = x;
	/*插入操作*/
	p->next = lst;
	lst = p;
}
int pop1(LNode *&lst, int &x) {
	LNode *p;
	if (lst == NULL) {
		return 0;
	}
	p = lst;
	/*删除节点操作*/
	x = p->data;
	lst = p->next;
	delete p;
	return 1;
}

//★★共享栈 栈S0，S1公用一个存储区，设计共享栈相关入栈，出栈，操作的算法
typedef struct SqStack1 { //共享栈结构定义
	int elem[maxSize]; //栈空间
	int top[2];  //两个栈顶标志
};
int push(SqStack1 &st, int stNo, int x) {  //入栈操作；stNo 是栈的编号，指示元素x在哪入栈
	if (st.top[0] + 1 < st.top[1]) {  //栈不满
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
			return 0;  //编号错误   
		}
	}
	else {
		return 0; //共享栈满
	}
}
int pop(SqStack1 &st, int stNo, int &x) { //出栈操作
	if (stNo == 0) {
		if (st.top[0] != -1) {  //判空
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

//★★用两个栈s1和s2来模拟一个队列，栈中元素为int型，栈中元素最多为manSize，已知三个定义如下
//posh(ST, x); 元素x入栈
//pop(ST,&x); 元素x出栈
//isEmpty(ST); 判断ST栈是否为空。
//如何利用栈的运算实现该队列的3个运算，enQueue（元素入队），deQueue（元素出队列）
//isQueueEmpty（判断队列是否为空，空返回1）；
int enQueue(SqStack &s1, SqStack &s2, int x) {  //入栈
	int y;
	if (s1.top == maxSize - 1) {
		if (!isEmpty(s2)) {  //s1满，s2非空，这时s1不能再入栈
			return 0; 
		}
		else if (isEmpty(s2)) {  //若s2为空，则将s1退栈，在入栈
			while (!isEmpty(s1)) {
				pop(s1, y);
				push(s2, y);
			}
			push(s1, x);//x入栈
			return 1;
		}
	}
	else {
		push(s1, x);  //s1不满，x直接入栈
		return 1;
	}
}
int deQueue(SqStack &s2, SqStack &s1, int &x) { //出栈
	int y;
	if (!isEmpty(s2)) { //栈s2不空，直接出队，返回1
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
			pop(s2, x); //s2出栈，实现出队列
			return 1;
		}
	}
}
int isQueueEmpty(SqStack s1, SqStack s2) { //判断队是否为空
	if (isEmpty(s1) && isEmpty(s2)) {
		return 1;
	}
	else {
		return 0;
	}
}

//写一个算法 判断入栈和出栈序列是否合法
int juge(char ch[]) {
	int i = 0, I = 0, O = 0;  //I:入栈总次数， O出栈总次数
	while (ch[i] != '\0') {
		if (ch[i] == 'I') {
			I++;
		}
		if (ch[i] == 'O') {
			O++;
		}
		if (O > I) {
			return 0;    //出栈次数大于入栈次数时
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

//★★假设以带头结点的循环链表表示队列，并且只设一个指针指向队尾节点，但不设头指针
//请写出相应的入对和出队算法
void enQueue(LNode *&rear, int x) {  //入队算法
	LNode *s = new LNode;
	s->data = x;
	s->next = rear->next;
	rear->next = s;
	rear = s;
}
int deQueue(LNode *&rear, int &x) {  //出队算法
	LNode *s;
	if (rear->next == rear) {
		return 0;
	}
	else {
		s = rear->next->next;  //s指向开始节点
		rear->next->next = s->next;
		x = s->data;
		if (s == rear) {   //如果出栈后为空
			rear = rear->next;//指向头节点
		}
		delete s;
		return 0;
	}
}

//★★设计一个算法，将一个非负十进制整数N转换为一个二进制数
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

//★★编写以恶搞算法，检查一个程序中的花括号，方括号，原括号是否匹配，若全部匹配则返回1否则返回0；
//对于程序中出现的单引号和双引号内的字符不进行括号配对检查，单引号和双引号必然配对出现
/*假设 stack时已经定义好的顺序栈结构体，可以直接调用的元素进栈/出栈，取栈顶元素，判断栈空的函数如下
void push(stack &S,char ch);
void pop(stack &S,char &ch);
void getTop(stack S,char &ch);
int isEmpty(stack S); //若栈空则返回1，否则返回0
*/
int bracketsCheck(char f[]) {  
	//待输入
}

