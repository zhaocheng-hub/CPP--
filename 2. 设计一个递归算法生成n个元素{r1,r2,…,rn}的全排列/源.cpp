#include<iostream>
#include<string>
using namespace std;
void swap(char *a, char *b)
{
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
//全排列函数
void fullPermutation(char *str, int begin, int n)
{
	//递归到最后一个字符时输出当前排列方式并返回
	if (begin == n - 1)
	{
		for (int j = 0; j<n; j++)
		{
			cout << str[j];
		}
		cout << endl;
		return;
	}
	else
	{
		//对后面的字符进行全排列
		for (int i = begin; i<n; i++)
		{
			//将子字符串的每个字符都调换到最前面一次
			swap(&str[begin], &str[i]);
			//对子字符串的子字符串进行全排列计算
			fullPermutation(str, begin + 1, n);
			//调换回来
			swap(&str[begin], &str[i]);
		}
		return;
	}
}
int main()
{
	int n; //n:字符个数
	cout << "输入字符个数:";
	cin >> n;
	char *str = new char[n]; //字符数组
	cout << "输入字符串:" << endl;
	for (int i = 0; i<n; i++)
		cin >> str[i];
	cout << "全排列如下：" << endl;
	fullPermutation(str, 0, n);
	delete[n]str;
	system("pause");
	return 0;
}