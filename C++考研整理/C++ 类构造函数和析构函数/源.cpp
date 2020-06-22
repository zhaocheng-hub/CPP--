//C++ �๹�캯������������
/*
��ʹ�����幹�������������ϵͳҲ��Ĭ���Զ�����һ�����캯������������
*/
#include <iostream>
using namespace std;

class Line{
	public:
		void setLength(double len); //��Ա����
		double getLength(void);
		Line(double len);  // ���ǹ��캯�� ÿ�δ�����Ķ���ʱ������ִ��һ�ι��캯�� ���캯��Ҳ����û�в���
		~Line(); //�����������ڹ��캯����ǰ�����~�������᷵���κ�ֵ��Ҳ���ܴ��κβ����������������������������򣨱���ر��ļ����ͷ��ڴ�ȣ�ǰ�ͷ���Դ��
	private:
		double length;
};

// ��Ա�������壬�������캯��   
Line::Line(double len){
	cout << "Object is being created" << endl; //ÿ�δ�����Ķ��󽫻ᴥ�������
	length = len;      // ��ʼ�� length
}
/*C++ ��ʼ�����Աʱ���ǰ���������˳���ʼ���Ķ����ǰ��ճ����ڳ�ʼ���б��˳���ʼ���ģ�
  ��� ����������˳����д����ʼ���б��˳������ʱӦ������ĺ���ע�͵�������ֻ�ܴ���һ��
*/
Line::Line(double len) : length(len) {   //��ʼ���б�ķ�ʽ����ʼ���ֶ� Ч��ͬ��  �������ʱ���ö��Ÿ��� ����
	cout << "Object is being created" << endl;    
} 
/*������һ���� C�����ж���ֶ� X��Y��Z ����Ҫ���г�ʼ����ͬ��أ�������ʹ��������﷨��ֻ��Ҫ�ڲ�ͬ���ֶ�ʹ�ö��Ž��зָ���
C::C(double a,double b ,double c):X(a),Y(b),Z(c){
	....
}
*/
Line::~Line(void) {
	cout<<"Object is being deleted" << endl;  //�����ڳ��������ִ�У�
}

void Line::setLength(double len)
{
	length = len;
}

double Line::getLength(void)
{
	return length;
}
// �����������	
int main()
{
	Line line(10.0); //�����캯���в���ʱ������������Ҫ��ʼ������

	// ��ȡĬ�����õĳ���
	cout << "Length of line : " << line.getLength() << endl;
	// �ٴ����ó���
	line.setLength(6.0);
	cout << "Length of line : " << line.getLength() << endl;

	return 0;
}
/*
���н��
Object is being created
Length of line : 10
Length of line : 6
Object is being deleted
*/