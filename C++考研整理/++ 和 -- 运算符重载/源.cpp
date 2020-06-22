/*
递增运算符（ ++ ）和递减运算符（ -- ）是 C++ 语言中两个重要的一元运算符。
*/
#include <iostream>
using namespace std;

class Time
{
private:
	int hours;             // 0 到 23
	int minutes;           // 0 到 59
public:
	// 所需的构造函数
	Time() {
		hours = 0;
		minutes = 0;
	}
	Time(int h, int m) {
		hours = h;
		minutes = m;
	}
	// 显示时间的方法
	void displayTime()
	{
		cout << "H: " << hours << " M:" << minutes << endl;
	}
	// 重载前缀递增运算符（ ++i ）
	Time operator++ ()
	{
		++minutes;          // 对象加 1
		if (minutes >= 60)
		{
			++hours;
			minutes -= 60;
		}
		return Time(hours, minutes);
	}
	// 重载后缀递增运算符（ i++ ）
	Time operator++(int)
	{
		// 保存原始值
		Time T(hours, minutes);
		// 对象加 1
		++minutes;
		if (minutes >= 60)
		{
			++hours;
			minutes -= 60;
		}
		// 返回旧的原始值
		return T;
	}
};
int main()
{
	Time T1(11, 59), T2(10, 40);

	++T1;                    // T1 加 1
	T1.displayTime();        // 显示 T1
	++T1;                    // T1 再加 1
	T1.displayTime();        // 显示 T1

	T2++;                    // T2 加 1
	T2.displayTime();        // 显示 T2
	T2++;                    // T2 再加 1
	T2.displayTime();        // 显示 T2
	return 0;
}
/*
运行结果
H: 12 M:0
H: 12 M:1
H: 10 M:41
H: 10 M:42
*/