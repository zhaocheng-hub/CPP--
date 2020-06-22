#include<iostream>
using namespace std;
int fun(int n, char A, char B, char C)//将A上的移动到B上C为中转塔
{
	if (n > 0)
	{
		fun(n - 1, A, C, B);//先将n-1个从A移动到C上面
		cout << "将编号为" << n << "的塔从" << A << "移动到" << B << "上面去" << endl;
		fun(n - 1, C, B, A);//再将n-1个从C移动到B上面
	}
	return 0;
}
int main()
{
	int n;
	char A, B, C;
	cin >> n >> A >> B >> C;
	fun(n, A, B, C);
}