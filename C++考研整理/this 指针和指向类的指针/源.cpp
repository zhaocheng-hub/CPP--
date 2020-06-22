/*�� C++ �У�ÿһ��������ͨ�� this ָ���������Լ��ĵ�ַ��
this ָ�������г�Ա������������������ˣ��ڳ�Ա�����ڲ�������������ָ����ö���
��Ԫ����û�� this ָ�룬��Ϊ��Ԫ������ĳ�Ա��ֻ�г�Ա�������� this ָ�롣

һ��ָ�� C++ ���ָ����ָ��ṹ��ָ�����ƣ�����ָ�����ָ��ĳ�Ա����Ҫʹ�ó�Ա��������� ->��
�������ָ��ṹ��ָ��һ���������е�ָ��һ������������ʹ��ָ��֮ǰ����ָ����г�ʼ����
*/
#include <iostream>

using namespace std;

class Box
{
public:
	// ���캯������
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
		return this->Volume() > box.Volume();  //this->fun()�ȼ��ڣ�������������Ķ���->fun()
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
	// �����һ������ĵ�ַ ָ���һ������ĵ�ַ
	ptrBox = &Box1;

	// ���ڳ���ʹ�ó�Ա��������������ʳ�Ա
	cout << "Volume of Box1: " << ptrBox->Volume() << endl;

	// ����ڶ�������ĵ�ַ
	ptrBox = &Box2;

	// ���ڳ���ʹ�ó�Ա��������������ʳ�Ա
	cout << "Volume of Box2: " << ptrBox->Volume() << endl;

	return 0;
}

/*
���н��
Constructor called.
Constructor called.
Box2 is equal to or larger than Box1
Volume of Box1: 5.94
Volume of Box2: 102
*/