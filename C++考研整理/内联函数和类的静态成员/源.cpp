/*
C++ 内联函数是通常与类一起使用。如果一个函数是内联的，那么在编译时，编译器会把该函数的代码副本放置在每个调用该函数的地方。

	引入内联函数的目的是为了解决程序中函数调用的效率问题，这么说吧，程序在编译器编译的时候，编译器将程序中出现的内联函数的调用表达式用内联函数的函数体进行替换，而对于其他的函数，都是在运行时候才被替代。这其实就是个空间代价换时间的i节省。所以内联函数一般都是1-5行的小函数。在使用内联函数时要留神：

	1.在内联函数内不允许使用循环语句和开关语句；
	2.内联函数的定义必须出现在内联函数第一次调用之前；
	3.类结构中所在的类说明内部定义的函数是内联函数。

我们可以使用 static 关键字来把类成员定义为静态的。当我们声明类的成员为静态时，这意味着无论创建多少个类的对象，静态成员都只有一个副本。

静态成员在类的所有对象中是共享的。如果不存在其他的初始化语句，在创建第一个对象时，所有的静态数据都会被初始化为零。
我们不能把静态成员的初始化放置在类的定义中，但是可以在类的外部通过使用范围解析运算符 :: 来重新声明静态变量从而对它进行初始化，

如果把函数成员声明为静态的，就可以把函数与类的任何特定对象独立开来。静态成员函数即使在类对象不存在的情况下也能被调用，
静态成员函数只能访问静态成员数据、其他静态成员函数和类外部的其他函数。
静态成员函数有一个类范围，他们不能访问类的 this 指针。您可以使用静态成员函数来判断类的某些对象是否已被创建。静态函数只要使用类名加范围解析运算符 :: 就可以访问。

静态成员函数与普通成员函数的区别：
	静态成员函数没有 this 指针，只能访问静态成员（包括静态成员变量和静态成员函数）。
	普通成员函数有 this 指针，可以访问类中的任意成员；而静态成员函数没有 this 指针。
*/
#include <iostream>

using namespace std;

class Box
{
public:
	static int objectCount; //静态的成员 该类的所有对象共用此成员
	// 构造函数定义
	Box(double l = 2.0, double b = 2.0, double h = 2.0) //构造函数
	{
		cout << "Constructor called." << endl;
		length = l;
		breadth = b;
		height = h;
		// 每次创建对象时增加 1
		objectCount++;
	}
	double Volume()
	{
		return length * breadth * height;
	}
	static int getCount() {
		return objectCount;
	}
private:
	double length;     // 长度
	double breadth;    // 宽度
	double height;     // 高度
};

// 初始化类 Box 的静态成员   静态成员的初始化只能放在类的外面
int Box::objectCount = 0;

//内联函数定义	
inline int Max(int x, int y)
{
	return (x > y) ? x : y;
}
int main(void)
{
	//内联函数部分
	cout << "Max (20,10): " << Max(20, 10) << endl;
	cout << "Max (0,200): " << Max(0, 200) << endl;
	cout << "Max (100,1010): " << Max(100, 1010) << endl;
	cout << endl;

	//静态成员部分
	// 在创建对象之前输出对象的总数
	cout << "Inital Stage Count: " << Box::getCount() << endl;
	Box Box1(3.3, 1.2, 1.5);    // 声明 box1
	Box Box2(8.5, 6.0, 2.0);    // 声明 box2


	// 在创建对象之后输出对象的总数
	cout << "Final Stage Count: " << Box::getCount() << endl; //使用静态成员函数
	cout << "Total objects: " << Box::objectCount << endl; //使用静态成员

	return 0;
}
/*
运行结果
Max (20,10): 20
Max (0,200): 200
Max (100,1010): 1010

Inital Stage Count: 0
Constructor called.
Constructor called.
Final Stage Count: 2
Total objects: 2
*/