/*
��������Է��ʻ��������еķ�˽�г�Ա����˻����Ա������뱻������ĳ�Ա�������ʣ���Ӧ�ڻ���������Ϊ private��
���ǿ��Ը��ݷ���Ȩ���ܽ����ͬ�ķ������ͣ�������ʾ��
	���ʸ���	  public	protected	private
	ͬһ�������	yes  	yes	        yes     
	���������		yes		yes			no        ��������ʸ���ġ�������Դ �Ƿ�����
	�ⲿ�������	yes		no			no

һ��������̳������еĻ��෽����������������⣺
	����Ĺ��캯�������������Ϳ������캯����
	����������������
	�������Ԫ������
*/
#include <iostream>

using namespace std;

// ���� Shape
class Shape
{
public:  //���г�Ա�ڳ���������ⲿ�ǿɷ��ʵġ������Բ�ʹ���κγ�Ա���������úͻ�ȡ���б�����ֵ ����.��������
	void setWidth(int w)
	{
		width = w;
	}
	void setHeight(int h)
	{
		height = h;
	}
protected:  //������Ա����������˽�г�Աʮ�����ƣ�����һ�㲻ͬ��������Ա�������ࣨ�����ࣩ���ǿɷ��ʵġ�
	int width;  //���Ա���������з���
	int height;
private:  //˽�г�Ա��������������ⲿ�ǲ��ɷ��ʵģ������ǲ��ɲ鿴�ġ�ֻ�������Ԫ�������Է���˽�г�Ա��
	double length; // ����ʹ����ĳ�Ա��������˽�г�Ա���з��ʺ��޸�
};
// ���� PaintCost
class PaintCost
{
public:
	int getCost(int area)
	{
		return area * 70;
	}
};

/* ������  Rectanle���� �̳���Shape��PaintCost������ ��Ҳ������private��protected
	���м̳У�public������һ���������Թ��л���ʱ������Ĺ��г�ԱҲ��������Ĺ��г�Ա������ı�����ԱҲ��������ı�����Ա�������˽�г�Ա����ֱ�ӱ���������ʣ����ǿ���ͨ�����û���Ĺ��кͱ�����Ա�����ʡ�
	�����̳У�protected���� ��һ���������Ա�������ʱ������Ĺ��кͱ�����Ա����Ϊ������ı�����Ա��
	˽�м̳У�private������һ����������˽�л���ʱ������Ĺ��кͱ�����Ա����Ϊ�������˽�г�Ա��
*/
class Rectangle : public Shape, public PaintCost  //Rectanle�̳���Shape��PaintCost������
{
public:
	int getArea()
	{
		return (width * height);
	}
};

//�ֽ���

class A {
public:
	int a;
	A() { //���캯��
		a1 = 1;
		a2 = 2;
		a3 = 3;
		a = 4;
	}
	void fun() {
		cout << a << endl;    //��ȷ
		cout << a1 << endl;   //��ȷ
		cout << a2 << endl;   //��ȷ
		cout << a3 << endl;   //��ȷ
	}
public:
	int a1;
protected:
	int a2;
private:
	int a3;
};
//�����̳� 
class B : public A {
public:
	int a;
	B(int i) { //���캯��
		A();
		a = i;
	}
	void fun() {
		cout << a << endl;       //��ȷ��public��Ա
		cout << a1 << endl;       //��ȷ�������public��Ա����������������public��Ա��
		cout << a2 << endl;       //��ȷ�������protected��Ա����������������protected���Ա���������ʡ�
		cout << a3 << endl;       //���󣬻����private��Ա���ܱ���������ʡ�
	}
};
//�����̳�
class B : protected A {
public:
	int a;
	B(int i) {
		A();
		a = i;
	}
	void fun() {
		cout << a << endl;       //��ȷ��public��Ա��
		cout << a1 << endl;       //��ȷ�������public��Ա�����������б����protected�����Ա���������ʡ�
		cout << a2 << endl;       //��ȷ�������protected��Ա�����������л���protected�����Ա���������ʡ�
		cout << a3 << endl;       //���󣬻����private��Ա���ܱ���������ʡ�
	}
};
//˽�м̳�
class B : private A {
public:
	int a;
	B(int i) {
		A();
		a = i;
	}
	void fun() {
		cout << a << endl;       //��ȷ��public��Ա��
		cout << a1 << endl;       //��ȷ������public��Ա,���������б����private,���Ա���������ʡ�
		cout << a2 << endl;       //��ȷ�������protected��Ա�����������б����private,���Ա���������ʡ�
		cout << a3 << endl;       //���󣬻����private��Ա���ܱ���������ʡ�
	}
};


int main(void)
{
	//�̳в���
	Rectangle Rect;
	int area;

	Rect.setWidth(5);
	Rect.setHeight(7);
	area = Rect.getArea();
	// �����������
	cout << "Total area: " << Rect.getArea() << endl;
	// ����ܻ���
	cout << "Total paint cost: $" << Rect.getCost(area) << endl;
	//�����̳�
	B b(10);
	cout << b.a << endl;
	cout << b.a1 << endl;   //��ȷ
	cout << b.a2 << endl;   //�������ⲻ�ܷ���protected��Ա
	cout << b.a3 << endl;   //�������ⲻ�ܷ���private��Ա
	//�����̳�
	B b(10);
	cout << b.a << endl;       //��ȷ��public��Ա
	cout << b.a1 << endl;      //����protected��Ա������������ʡ�  �˴������˸ı�
	cout << b.a2 << endl;      //����protected��Ա������������ʡ�
	cout << b.a3 << endl;      //����private��Ա�������������
	//˽�м̳�
	B b(10);
	cout << b.a << endl;       //��ȷ��public��Ա
	cout << b.a1 << endl;      //����private��Ա������������ʡ�
	cout << b.a2 << endl;      //����, private��Ա������������ʡ�   
	cout << b.a3 << endl;      //����private��Ա������������ʡ�
	return 0;
}
/*
�ϲ��ֵ����н��
Total area: 35
Total paint cost: $2450
*/