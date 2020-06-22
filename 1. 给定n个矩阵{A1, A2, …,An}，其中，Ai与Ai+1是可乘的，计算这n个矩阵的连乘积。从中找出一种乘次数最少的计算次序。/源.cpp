#include <iostream>
using namespace std;
#define N 1000
int c[N][N] = { -1 }, s[N][N] = { -1 }, p[N];
//c保存第i到第j个矩阵的最小计算次数
//s保存第i到第j个矩阵的最小计算次数的分割点k
//矩阵Ai的大小为,p(i-1)*p[i]
int fun(int i, int j)  //计算从第i个矩阵到第j个矩阵的最小计算次数
{
	if (c[i][j] > 0)  //如果从第i个矩阵到第j个矩阵的最小计算次数已经计算，则返回其值
		return c[i][j];
	if (i == j)   //如果上式为满足且第i个矩阵到第i个矩阵的最小计算次数则为0；
		return 0;
	int u = fun(i, i) + fun(i + 1, j) + p[i - 1] * p[i] * p[j]; //假设第i到第j的最小计算次数时，最佳分割点为i+1
	s[i][j] = i;
	for (int k = i + 1; k < j; k++)  //分割点k依次取值，计算最小计算次数
	{
		int t = fun(i, k) + fun(k + 1, j) + p[i - 1] * p[k] * p[j];
		if (t < u)
		{
			u = t;
			s[i][j] = k;
		}
		c[i][j] = u;  
		return u;
	}
}
int main()
{
	int n, i, j;
	cin >> n;
	for (int i = 0; i <= n; i++)
		cin >> p[i];
	cout << fun(1, n) << endl;
	return 0;
}