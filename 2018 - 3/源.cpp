#include<iostream>
using namespace std;

class Base {
public:
	void fun() { cout << "Base::fun" << endl; }
};

class Derived :public Base {
public:
	void fun() {
		Base::fun();
		cout << "Derived::fun()" << endl;
	}
};

int main() {
	Base b, *pb;
	Derived d;
	pb = &d;
	cout << endl;
	b.fun();
	d.fun();
	cout << endl;
	pb->fun();
	pb = &b;
	pb->fun();
}