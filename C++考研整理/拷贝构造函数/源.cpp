/*拷贝构造函数是一种特殊的构造函数，它在创建对象时，是使用同一类中之前创建的对象来初始化新创建的对象。拷贝构造函数通常用于：
	通过使用另一个同类型的对象来初始化新创建的对象。
	复制对象把它作为参数传递给函数。
	复制对象，并从函数返回这个对象。
	如果在类中没有定义拷贝构造函数，编译器会自行定义一个。如果类带有指针变量，并有动态内存分配，则它必须有一个拷贝构造函数
*/
#include <iostream>

using namespace std;

class Line
{
public:
	int getLength(void);
	Line(int len);             // 简单的构造函数
	Line(const Line &obj);      // 拷贝构造函数
	~Line();                     // 析构函数

private:
	int *ptr;  //声明一个整型指针变量 ptr
};

// 成员函数定义，包括构造函数
Line::Line(int len)   //构造函数
{ 
	cout << "调用构造函数" << endl;
	// 为指针分配内存
	ptr = new int;    //申请动态分配一个 int 型存储区,并将首地址赋给 ptr
	*ptr = len;
}

Line::Line(const Line &obj) //拷贝构造函数
{
	cout << "调用拷贝构造函数并为指针 ptr 分配内存" << endl;
	//为指针分配内存， 下面为不同点
	ptr = new int;
	*ptr = *obj.ptr; // 拷贝值    将obj的值传给ptr
}

Line::~Line(void)
{
	cout << "释放内存" << endl;
	delete ptr;
}
int Line::getLength(void)
{
	return *ptr;
}

void display(Line obj)  //注意这个不是类的成员函数，需要调用形参
{
	cout << "line 大小 : " << obj.getLength() << endl;
}

// 程序的主函数
int main()
{
	Line line1(10); 
	cout << "       " << endl;
	Line line2 = line1; // 这里也调用了拷贝构造函数
	//此处隔开看的比较明白， 
	cout << "       " << endl;
	display(line1);    // 复制对象把它作为参数传递给函数，使用结束后释放内存 
	//此处隔开看的比较明白，
	cout << "        " << endl;
	display(line2);
	//此处隔开看的比较明白，
	cout << "        " << endl;
}

/*
运行结果
调用构造函数

调用拷贝构造函数并为指针 ptr 分配内存

调用拷贝构造函数并为指针 ptr 分配内存
line 大小 : 10
释放内存

调用拷贝构造函数并为指针 ptr 分配内存
line 大小 : 10
释放内存

释放内存
释放内存
请按任意键继续. . .

*/