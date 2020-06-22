#include<iostream>
#include<string>
using namespace std;
class point2 {
public:   //类内嵌套需要 定义为public, 继承也可以定义protected，你就都写public
	double x;
	double y;
public:
	point2() {
		this->x = 0.0;
		this->y = 0.0;
	}
	point2(double x, double y) {
		this->x = x;
		this->y = y;
	}
	point2(const point2 &p) {
		this->x = p.x;
		this->y = p.y;
	}
	~point2() {}
	virtual void set(double x, double y) {
		this->x = x;
		this->y = y;
	}
	virtual void print() {
		cout << "x=" << x << " ";
		cout << "y=" << y << endl;
	}
	friend void set(point2 &p, double x, double y) {  //p的值要改变
		p.x = x;
		p.y = y;
	}
	friend void print(point2 p) {
		cout << "x=" << p.x << " ";
		cout << "y=" << p.y << endl;
	}
};
class point3 :public point2 {
public:
	double z;
public:
	point3() :point2() {   //继承的每一步要把参数传给基类
		this->z = 0.0;
	}
	point3(double x, double y, double z) :point2(x, y) {
		this->z = z;
	}
	point3(const point3 &p) :point2(p.x, p.y) {
		this->z = p.z;
	}
	~point3() {}
	virtual void set(double x, double y, double z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
	virtual void print() {
		cout << "x=" << x << " ";
		cout << "y=" << y << " ";
		cout << "z=" << z << endl;
	}
	/*以上是继承的部分，*/
	/* 下面题目没要求可以不用写，因为友元是独立于类外的，不属于继承的部分 */
	friend void set(point3 &p, double x, double y, double z) {  //p的值要改变
		p.x = x;
		p.y = y;
		p.z = z;
	}
	friend void print(point3 p) {
		cout << "x=" << p.x << " ";
		cout << "y=" << p.y << " ";
		cout << "z=" << p.z << endl;
	}
	/*下面是重载*/
	point3 operator- (point3 p) { //类内成员函数重载  其他四则运算不再赘述
		point3 temp;
		temp.x = this->x - p.x;
		temp.y = this->y - p.y;
		temp.z = this->z - p.z;
		return temp;
	}
	friend point3 operator+(point3 p1, point3 p2) { //友元重载
		p1.x += p2.x;  //注意符号
		p1.y += p2.y;
		p1.z += p2.z;
		return p1;
	}
	friend ostream &operator << (ostream& out, point3 &p) { //输出运算符重载
		out << "(" << p.x << "," << p.y << "," << p.z << ")" << endl;
		return out;
	}
};
class point4 :public point3 {
private:   //最后一层了，不会再有继承他得了，也没有套用他的
	double r;
public:
	point4() :point3() {   //继承的每一步要把参数传给基类
		this->r = 0.0;
	}
	point4(double x, double y, double z, double r) :point3(x, y, z) {
		this->r = r;
	}
	point4(const point4 &p) :point3(p.x, p.y, p.z) {
		this->r = p.r;
	}
	~point4() {}
	virtual void set(double x, double y, double z) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->r = r;
	}
	virtual void print() {
		cout << "x=" << x << " ";
		cout << "y=" << y << " ";
		cout << "z=" << z << " ";
		cout << "r=" << r << endl;
	}
	/*以上是继承的部分，*/
	point4 operator++() {//++i 
		++x;
		++y;
		++z;
		++r;
		return *this;
	}
	point4 operator ++(int) {//i++   增加参数是为了区别两个操作
		point4 temp = *this;
		x++;
		y++;
		z++;
		r++;
		return temp;
	}
	friend point4 operator--(point4 p) {//++i
		++p.x;
		++p.y;
		++p.z;
		++p.r;
		return p;
	}
	friend point4 operator--(point4 p, int) {//i++
		point4 temp = *p;
		p.x++;
		p.y++;
		p.z++;
		p.r++;
		return temp;
	}
	friend ostream &operator << (ostream& out, point4 &p) { //输出运算符重载
		out << "(" << p.x << "," << p.y << "," << p.z << " " << p.r << ")" << endl;
		return out;
	}
};
class V {
private:
	point3 p1;
	point3 p2;
public:
	V(point3 p1, point3 p2) {
		this->p1 = p1;
		this->p2 = p2;
	}
	~V() {}
	double fun1() {
		double v = (p1.x - p2.x)*(p1.y - p2.y)*(p1.z - p2.z);
		return v > 0 ? v : -v;
	}
};

int main() {
	/*point2测试*/
	point2 p1(10.0, 10.0), p2;  //两种构造函数
	point2 p3(p1);  //拷贝构造函数 
	p1.print(); //直接调用
	print(p2); //友元调用
	p3.print();
	p1.set(20.0, 20.0);  //成员函数修改值
	set(p2, 30.0, 30.0);//友元函数修改值
	p1.print(); //直接调用
	print(p2); //友元调用
	/*point3测试*/
	cout << "-------------------------------------" << endl;
	point3 p4(10.0, 10.0, 10.0), p5;
	point3 p6(p4);
	p4.print(); //直接调用
	print(p5); //友元调用
	p6.print();
	cout << "----------------------------" << endl;
	p4.set(20.0, 20.0, 20.0);  //成员函数修改值
	set(p5, 30.0, 30.0, 30.0);//友元函数修改值
	p6 = p6 - p5;
	point3 p7 = p4 + p5;
	p4.print(); //直接调用
	print(p5); //友元调用
	cout << p6;
	cout << p7;
	/*point4测试*/
	cout << "--------------------------------------" << endl;
	point4 p8(15.0, 15.0, 15.0, 15.0);
	point2 *p;
	p = &p8;
	p->print();
	p8++; //隐式调用
	point4 p9 = p8.operator++(0); //显示调用
	point4 p10 = ++p8;
	cout << p8;
	cout << p9;
	cout << p10;
	/* V测试*/
	cout << "--------------------------------------" << endl;
	V v(p4, p7);
	cout << v.fun1() << endl;
}