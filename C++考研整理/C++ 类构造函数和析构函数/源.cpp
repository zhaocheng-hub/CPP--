//C++ 类构造函数和析构函数
/*
即使不定义构造和析构函数，系统也会默认自动构造一个构造函数和析构函数
*/
#include <iostream>
using namespace std;

class Line{
	public:
		void setLength(double len); //成员函数
		double getLength(void);
		Line(double len);  // 这是构造函数 每次创建类的对象时，都会执行一次构造函数 构造函数也可以没有参数
		~Line(); //析构函数，在构造函数的前面加上~，它不会返回任何值，也不能带任何参数，析构函数有助于在跳出程序（比如关闭文件、释放内存等）前释放资源。
	private:
		double length;
};

// 成员函数定义，包括构造函数   
Line::Line(double len){
	cout << "Object is being created" << endl; //每次创建类的对象将会触发该语句
	length = len;      // 初始化 length
}
/*C++ 初始化类成员时，是按照声明的顺序初始化的而不是按照出现在初始化列表的顺序初始化的！
  最好 按照声明的顺序来写，初始化列表的顺序。运行时应把下面的函数注释掉，两者只能存在一种
*/
Line::Line(double len) : length(len) {   //初始化列表的方式来初始化字段 效果同上  多个参数时，用逗号隔开 如下
	cout << "Object is being created" << endl;    
} 
/*假设有一个类 C，具有多个字段 X、Y、Z 等需要进行初始化，同理地，您可以使用上面的语法，只需要在不同的字段使用逗号进行分隔，
C::C(double a,double b ,double c):X(a),Y(b),Z(c){
	....
}
*/
Line::~Line(void) {
	cout<<"Object is being deleted" << endl;  //将会在程序结束后执行，
}

void Line::setLength(double len)
{
	length = len;
}

double Line::getLength(void)
{
	return length;
}
// 程序的主函数	
int main()
{
	Line line(10.0); //当构造函数有参数时，创建对象需要初始化参数

	// 获取默认设置的长度
	cout << "Length of line : " << line.getLength() << endl;
	// 再次设置长度
	line.setLength(6.0);
	cout << "Length of line : " << line.getLength() << endl;

	return 0;
}
/*
运行结果
Object is being created
Length of line : 10
Length of line : 6
Object is being deleted
*/