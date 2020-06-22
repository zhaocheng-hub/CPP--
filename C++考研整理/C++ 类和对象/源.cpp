//类和对象
#include <iostream>

using namespace std;

class Box         //类的定义，
{
public:     //公有成员   访问修饰符，也可以为private,protected
	double length;   // 长度 类的属性，
	double breadth;  // 宽度 类的属性，
	double height;   // 高度 类的属性，
	double getVolume(void)    //类的成员函数 ，也可以先声明后再外部定义
	{
		return length * breadth * height;
	}
};
/* 虽然可以在外部定义，但是外部和内部只能存在一个定义，只能有一次定义，
double Box::getVolume(void)    //在外部定义的时候需要加上作用域符号 :: 作用域符号前需要加类名来表示谁的成员函数
{
	return length * breadth * height;
}
*/

int main()
{
	Box Box1;        // 声明 Box1，类型为 Box    创建对象
	Box Box2;        // 声明 Box2，类型为 Box    创建对象
	double volume = 0.0;     // 用于存储体积

	// box 1 详述
	Box1.height = 5.0; 
	Box1.length = 6.0;
	Box1.breadth = 7.0;

	// box 2 详述
	Box2.height = 10.0;
	Box2.length = 12.0;
	Box2.breadth = 13.0;

	// box 1 的体积
	volume = Box1.getVolume(); // 调用成员函数
	cout << "Box1 的体积：" << volume << endl;

	// box 2 的体积
	volume = Box2.getVolume();
	cout << "Box2 的体积：" << volume << endl;
	return 0;
}/*
 运行结果
 Box1 的体积：210
 Box2 的体积：1560
 */
