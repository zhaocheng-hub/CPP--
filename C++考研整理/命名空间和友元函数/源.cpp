/*
�����Ԫ�����Ƕ��������ⲿ������Ȩ�����������˽�У�private����Ա�ͱ�����protected����Ա��
������Ԫ������ԭ��������Ķ����г��ֹ���������Ԫ���������ǳ�Ա������
	Ҫ���ʷ�static��Աʱ����Ҫ������������
	Ҫ����static��Ա��ȫ�ֱ���ʱ������Ҫ������������
	����������Ķ�����ȫ�ֶ�������Ҫ����������.
	����ֱ�ӵ�����Ԫ����������Ҫͨ�������ָ��
*/
#include <iostream>

using namespace std;   //��Ҳ��һ�������ռ䣬ͨ��std  
using std::cout;   //�����ռ�ֻ���� ͨ�� std::cout , cin����Ӱ��

class Box
{
	double width;
public:
	friend void printWidth(Box box); //��Ԫ����
	void setWidth(double wid);
	friend class Bigbox; //������Bigbox�����г�Ա��Ϊ��Box����Ԫ
};
class BigBox
{
public:
	void Print(int width, Box &box)
	{
		// BigBox��Box����Ԫ�࣬������ֱ�ӷ���Box����κγ�Ա
		box.setWidth(width);
		cout << "Width of box : " << width << endl;
	}
};

// ��Ա��������
void Box::setWidth(double wid)
{
	width = wid;
}

// ��ע�⣺printWidth() �����κ���ĳ�Ա����
void printWidth(Box box)
{
	/* ��Ϊ printWidth() �� Box ����Ԫ��������ֱ�ӷ��ʸ�����κγ�Ա */
	cout << "Width of box : " << box.width << endl;
}

// �����������
int main()
{
	Box box;
	BigBox big;

	// ʹ�ó�Ա�������ÿ��
	box.setWidth(10.0);

	// ʹ����Ԫ����������
	printWidth(box);

	// ʹ����Ԫ���еķ������ÿ��
	big.Print(20, box);

	return 0;
}/*
 ���н��
 Width of box : 10
 Width of box : 20
 */