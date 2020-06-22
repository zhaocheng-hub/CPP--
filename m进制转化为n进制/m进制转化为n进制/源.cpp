#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n, m;
	long long int num, num1=0,num_t=0;
	int num2[101];
	cout<< "请分别输入m和n:";
	cin >> m >>n;
	cout << "请输入" << m << "进制下的num:";
	cin >> num;
	int temp = 1;
	while (num != 0)
	{
		num1 += (num % 10)*temp;
		num = num / 10;
		temp *= m;
	}
	do {
		num2[num_t++] = num1 % n;
		num1 = num1 / n;
	} while (num1 != 0);
	for (int i = num_t - 1; i >= 0; i--)
		cout << num2[i];
}