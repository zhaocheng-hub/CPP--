/*在 C++ 中，每一个对象都能通过 this 指针来访问自己的地址。
this 指针是所有成员函数的隐含参数。因此，在成员函数内部，它可以用来指向调用对象。
友元函数没有 this 指针，因为友元不是类的成员。只有成员函数才有 this 指针。

一个指向 C++ 类的指针与指向结构的指针类似，访问指向类的指针的成员，需要使用成员访问运算符 ->，
就像访问指向结构的指针一样。与所有的指针一样，您必须在使用指针之前，对指针进行初始化。
*/
#include <iostream>

using namespace std;

class Box
{
public:
	// 构造函数定义
	Box(double l = 2.0, double b = 2.0, double h = 2.0)
	{
		cout << "Constructor called." << endl;
		length = l;
		breadth = b;
		height = h;
	}
	double Volume()
	{
		return length * breadth * height;
	}
	int compare(Box box)
	{
		return this->Volume() > box.Volume();  //this->fun()等价于，调用这个函数的对象->fun()
	}
private:
	double length;     // Length of a box
	double breadth;    // Breadth of a box
	double height;     // Height of a box
};

int main(void)
{
	Box Box1(3.3, 1.2, 1.5);    // Declare box1
	Box Box2(8.5, 6.0, 2.0);    // Declare box2
	Box *ptrBox;

	if (Box1.compare(Box2))   
	{
		cout << "Box2 is smaller than Box1" << endl;
	}
	else
	{
		cout << "Box2 is equal to or larger than Box1" << endl;
	}
	// 保存第一个对象的地址 指向第一个对象的地址
	ptrBox = &Box1;

	// 现在尝试使用成员访问运算符来访问成员
	cout << "Volume of Box1: " << ptrBox->Volume() << endl;

	// 保存第二个对象的地址
	ptrBox = &Box2;

	// 现在尝试使用成员访问运算符来访问成员
	cout << "Volume of Box2: " << ptrBox->Volume() << endl;

	return 0;
}

/*
运行结果
Constructor called.
Constructor called.
Box2 is equal to or larger than Box1
Volume of Box1: 5.94
Volume of Box2: 102
*/