//C++ 多态意味着调用成员函数时，会根据调用函数的对象的类型来执行不同的函数。
#include <iostream> 
using namespace std;

class Shape {
protected:
	int width, height;
public:
	Shape(int a = 0, int b = 0)
	{
		width = a;
		height = b;
	}
	void setWidth(int w)
	{
		width = w;
	}
	void setHeight(int h)
	{
		height = h;
	}
	/*
	虚函数 是在基类中使用关键字 virtual 声明的函数。
	在派生类中重新定义基类中定义的虚函数时，会告诉编译器不要静态链接到该函数。
	我们想要的是在程序中任意点可以根据所调用的对象类型来选择调用的函数，
	这种操作被称为动态链接，或后期绑定。
	*/
	virtual int area() //虚函数     //如果不加virtual 为静态链接 - 函数调用在程序执行前就准备好了。有时候这也被称为早绑定，
	{
		cout << "Parent class area :" << endl;
		return 0;
	}
	virtual int getArea() = 0;  //纯虚函数，没有主体；
};
class Rectangle : public Shape {
public:
	Rectangle(int a = 0, int b = 0) :Shape(a, b) { }
	int area()
	{
		cout << "Rectangle class area :" << endl;
		return (width * height);
	}
	int getArea()
	{
		return (width * height);
	}
};
class Triangle : public Shape {
public:
	Triangle(int a = 0, int b = 0) :Shape(a, b) { }
	int area()
	{
		cout << "Triangle class area :" << endl;
		return (width * height / 2);
	}
	int getArea()
	{
		return (width * height) / 2;
	}
};
// 程序的主函数
int main()
{
	Shape *shape;
	Rectangle rec(10, 7);
	Triangle  tri(10, 5);
	// 存储矩形的地址
	shape = &rec;
	// 调用矩形的求面积函数 area
	shape->area();
	// 存储三角形的地址
	shape = &tri;
	// 调用三角形的求面积函数 area
	shape->area();

	Rectangle Rect;
	Triangle  Tri;

	Rect.setWidth(5);
	Rect.setHeight(7);
	// 输出对象的面积
	cout << "Total Rectangle area: " << Rect.getArea() << endl;

	Tri.setWidth(5);
	Tri.setHeight(7);
	// 输出对象的面积
	cout << "Total Triangle area: " << Tri.getArea() << endl;

	return 0;
}
/*
运行结果
Rectangle class area :
Triangle class area :
Total Rectangle area: 35
Total Triangle area: 17
*/