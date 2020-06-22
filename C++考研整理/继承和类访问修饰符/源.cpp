/*
派生类可以访问基类中所有的非私有成员。因此基类成员如果不想被派生类的成员函数访问，则应在基类中声明为 private。
我们可以根据访问权限总结出不同的访问类型，如下所示：
	访问该类	  public	protected	private
	同一个类访问	yes  	yes	        yes     
	派生类访问		yes		yes			no        派生类访问该类的。。。资源 是否允许
	外部的类访问	yes		no			no

一个派生类继承了所有的基类方法，但下列情况除外：
	基类的构造函数、析构函数和拷贝构造函数。
	基类的重载运算符。
	基类的友元函数。
*/
#include <iostream>

using namespace std;

// 基类 Shape
class Shape
{
public:  //公有成员在程序中类的外部是可访问的。您可以不使用任何成员函数来设置和获取公有变量的值 类名.变量即可
	void setWidth(int w)
	{
		width = w;
	}
	void setHeight(int h)
	{
		height = h;
	}
protected:  //保护成员变量或函数与私有成员十分相似，但有一点不同，保护成员在派生类（即子类）中是可访问的。
	int width;  //可以被派生类进行访问
	int height;
private:  //私有成员变量或函数在类的外部是不可访问的，甚至是不可查看的。只有类和友元函数可以访问私有成员。
	double length; // 可以使用类的成员函数来对私有成员进行访问和修改
};
// 基类 PaintCost
class PaintCost
{
public:
	int getCost(int area)
	{
		return area * 70;
	}
};

/* 派生类  Rectanle公共 继承了Shape和PaintCost两个类 ，也可以是private货protected
	公有继承（public）：当一个类派生自公有基类时，基类的公有成员也是派生类的公有成员，基类的保护成员也是派生类的保护成员，基类的私有成员不能直接被派生类访问，但是可以通过调用基类的公有和保护成员来访问。
	保护继承（protected）： 当一个类派生自保护基类时，基类的公有和保护成员将成为派生类的保护成员。
	私有继承（private）：当一个类派生自私有基类时，基类的公有和保护成员将成为派生类的私有成员。
*/
class Rectangle : public Shape, public PaintCost  //Rectanle继承了Shape和PaintCost两个类
{
public:
	int getArea()
	{
		return (width * height);
	}
};

//分解线

class A {
public:
	int a;
	A() { //构造函数
		a1 = 1;
		a2 = 2;
		a3 = 3;
		a = 4;
	}
	void fun() {
		cout << a << endl;    //正确
		cout << a1 << endl;   //正确
		cout << a2 << endl;   //正确
		cout << a3 << endl;   //正确
	}
public:
	int a1;
protected:
	int a2;
private:
	int a3;
};
//公共继承 
class B : public A {
public:
	int a;
	B(int i) { //构造函数
		A();
		a = i;
	}
	void fun() {
		cout << a << endl;       //正确，public成员
		cout << a1 << endl;       //正确，基类的public成员，在派生类中仍是public成员。
		cout << a2 << endl;       //正确，基类的protected成员，在派生类中仍是protected可以被派生类访问。
		cout << a3 << endl;       //错误，基类的private成员不能被派生类访问。
	}
};
//保护继承
class B : protected A {
public:
	int a;
	B(int i) {
		A();
		a = i;
	}
	void fun() {
		cout << a << endl;       //正确，public成员。
		cout << a1 << endl;       //正确，基类的public成员，在派生类中变成了protected，可以被派生类访问。
		cout << a2 << endl;       //正确，基类的protected成员，在派生类中还是protected，可以被派生类访问。
		cout << a3 << endl;       //错误，基类的private成员不能被派生类访问。
	}
};
//私有继承
class B : private A {
public:
	int a;
	B(int i) {
		A();
		a = i;
	}
	void fun() {
		cout << a << endl;       //正确，public成员。
		cout << a1 << endl;       //正确，基类public成员,在派生类中变成了private,可以被派生类访问。
		cout << a2 << endl;       //正确，基类的protected成员，在派生类中变成了private,可以被派生类访问。
		cout << a3 << endl;       //错误，基类的private成员不能被派生类访问。
	}
};


int main(void)
{
	//继承部分
	Rectangle Rect;
	int area;

	Rect.setWidth(5);
	Rect.setHeight(7);
	area = Rect.getArea();
	// 输出对象的面积
	cout << "Total area: " << Rect.getArea() << endl;
	// 输出总花费
	cout << "Total paint cost: $" << Rect.getCost(area) << endl;
	//公共继承
	B b(10);
	cout << b.a << endl;
	cout << b.a1 << endl;   //正确
	cout << b.a2 << endl;   //错误，类外不能访问protected成员
	cout << b.a3 << endl;   //错误，类外不能访问private成员
	//保护继承
	B b(10);
	cout << b.a << endl;       //正确。public成员
	cout << b.a1 << endl;      //错误，protected成员不能在类外访问。  此处发生了改变
	cout << b.a2 << endl;      //错误，protected成员不能在类外访问。
	cout << b.a3 << endl;      //错误，private成员不能在类外访问
	//私有继承
	B b(10);
	cout << b.a << endl;       //正确。public成员
	cout << b.a1 << endl;      //错误，private成员不能在类外访问。
	cout << b.a2 << endl;      //错误, private成员不能在类外访问。   
	cout << b.a3 << endl;      //错误，private成员不能在类外访问。
	return 0;
}
/*
上部分的运行结果
Total area: 35
Total paint cost: $2450
*/