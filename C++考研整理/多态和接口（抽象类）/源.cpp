//C++ ��̬��ζ�ŵ��ó�Ա����ʱ������ݵ��ú����Ķ����������ִ�в�ͬ�ĺ�����
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
	�麯�� ���ڻ�����ʹ�ùؼ��� virtual �����ĺ�����
	�������������¶�������ж�����麯��ʱ������߱�������Ҫ��̬���ӵ��ú�����
	������Ҫ�����ڳ������������Ը��������õĶ���������ѡ����õĺ�����
	���ֲ�������Ϊ��̬���ӣ�����ڰ󶨡�
	*/
	virtual int area() //�麯��     //�������virtual Ϊ��̬���� - ���������ڳ���ִ��ǰ��׼�����ˡ���ʱ����Ҳ����Ϊ��󶨣�
	{
		cout << "Parent class area :" << endl;
		return 0;
	}
	virtual int getArea() = 0;  //���麯����û�����壻
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
// �����������
int main()
{
	Shape *shape;
	Rectangle rec(10, 7);
	Triangle  tri(10, 5);
	// �洢���εĵ�ַ
	shape = &rec;
	// ���þ��ε���������� area
	shape->area();
	// �洢�����εĵ�ַ
	shape = &tri;
	// ���������ε���������� area
	shape->area();

	Rectangle Rect;
	Triangle  Tri;

	Rect.setWidth(5);
	Rect.setHeight(7);
	// �����������
	cout << "Total Rectangle area: " << Rect.getArea() << endl;

	Tri.setWidth(5);
	Tri.setHeight(7);
	// �����������
	cout << "Total Triangle area: " << Tri.getArea() << endl;

	return 0;
}
/*
���н��
Rectangle class area :
Triangle class area :
Total Rectangle area: 35
Total Triangle area: 17
*/