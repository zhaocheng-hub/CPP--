/*
����������� ++ ���͵ݼ�������� -- ���� C++ ������������Ҫ��һԪ�������
*/
#include <iostream>
using namespace std;

class Time
{
private:
	int hours;             // 0 �� 23
	int minutes;           // 0 �� 59
public:
	// ����Ĺ��캯��
	Time() {
		hours = 0;
		minutes = 0;
	}
	Time(int h, int m) {
		hours = h;
		minutes = m;
	}
	// ��ʾʱ��ķ���
	void displayTime()
	{
		cout << "H: " << hours << " M:" << minutes << endl;
	}
	// ����ǰ׺����������� ++i ��
	Time operator++ ()
	{
		++minutes;          // ����� 1
		if (minutes >= 60)
		{
			++hours;
			minutes -= 60;
		}
		return Time(hours, minutes);
	}
	// ���غ�׺����������� i++ ��
	Time operator++(int)
	{
		// ����ԭʼֵ
		Time T(hours, minutes);
		// ����� 1
		++minutes;
		if (minutes >= 60)
		{
			++hours;
			minutes -= 60;
		}
		// ���ؾɵ�ԭʼֵ
		return T;
	}
};
int main()
{
	Time T1(11, 59), T2(10, 40);

	++T1;                    // T1 �� 1
	T1.displayTime();        // ��ʾ T1
	++T1;                    // T1 �ټ� 1
	T1.displayTime();        // ��ʾ T1

	T2++;                    // T2 �� 1
	T2.displayTime();        // ��ʾ T2
	T2++;                    // T2 �ټ� 1
	T2.displayTime();        // ��ʾ T2
	return 0;
}
/*
���н��
H: 12 M:0
H: 12 M:1
H: 10 M:41
H: 10 M:42
*/