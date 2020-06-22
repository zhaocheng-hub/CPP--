/*
类的友元函数是定义在类外部，但有权访问类的所有私有（private）成员和保护（protected）成员。
尽管友元函数的原型有在类的定义中出现过，但是友元函数并不是成员函数。
	要访问非static成员时，需要对象做参数；
	要访问static成员或全局变量时，则不需要对象做参数；
	如果做参数的对象是全局对象，则不需要对象做参数.
	可以直接调用友元函数，不需要通过对象或指针
*/
#include <iostream>

using namespace std;   //这也是一个命名空间，通用std  
using std::cout;   //命名空间只限制 通用 std::cout , cin等无影响

class Box
{
	double width;
public:
	friend void printWidth(Box box); //友元函数
	void setWidth(double wid);
	friend class Bigbox; //声明类Bigbox的所有成员作为类Box的友元
};
class BigBox
{
public:
	void Print(int width, Box &box)
	{
		// BigBox是Box的友元类，它可以直接访问Box类的任何成员
		box.setWidth(width);
		cout << "Width of box : " << width << endl;
	}
};

// 成员函数定义
void Box::setWidth(double wid)
{
	width = wid;
}

// 请注意：printWidth() 不是任何类的成员函数
void printWidth(Box box)
{
	/* 因为 printWidth() 是 Box 的友元，它可以直接访问该类的任何成员 */
	cout << "Width of box : " << box.width << endl;
}

// 程序的主函数
int main()
{
	Box box;
	BigBox big;

	// 使用成员函数设置宽度
	box.setWidth(10.0);

	// 使用友元函数输出宽度
	printWidth(box);

	// 使用友元类中的方法设置宽度
	big.Print(20, box);

	return 0;
}/*
 运行结果
 Width of box : 10
 Width of box : 20
 */