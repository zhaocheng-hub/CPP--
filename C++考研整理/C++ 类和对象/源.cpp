//��Ͷ���
#include <iostream>

using namespace std;

class Box         //��Ķ��壬
{
public:     //���г�Ա   �������η���Ҳ����Ϊprivate,protected
	double length;   // ���� ������ԣ�
	double breadth;  // ��� ������ԣ�
	double height;   // �߶� ������ԣ�
	double getVolume(void)    //��ĳ�Ա���� ��Ҳ���������������ⲿ����
	{
		return length * breadth * height;
	}
};
/* ��Ȼ�������ⲿ���壬�����ⲿ���ڲ�ֻ�ܴ���һ�����壬ֻ����һ�ζ��壬
double Box::getVolume(void)    //���ⲿ�����ʱ����Ҫ������������� :: ���������ǰ��Ҫ����������ʾ˭�ĳ�Ա����
{
	return length * breadth * height;
}
*/

int main()
{
	Box Box1;        // ���� Box1������Ϊ Box    ��������
	Box Box2;        // ���� Box2������Ϊ Box    ��������
	double volume = 0.0;     // ���ڴ洢���

	// box 1 ����
	Box1.height = 5.0; 
	Box1.length = 6.0;
	Box1.breadth = 7.0;

	// box 2 ����
	Box2.height = 10.0;
	Box2.length = 12.0;
	Box2.breadth = 13.0;

	// box 1 �����
	volume = Box1.getVolume(); // ���ó�Ա����
	cout << "Box1 �������" << volume << endl;

	// box 2 �����
	volume = Box2.getVolume();
	cout << "Box2 �������" << volume << endl;
	return 0;
}/*
 ���н��
 Box1 �������210
 Box2 �������1560
 */
