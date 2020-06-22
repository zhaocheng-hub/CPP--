#include <iostream>
using namespace std;
#define N 1000
int c[N][N] = { -1 }, s[N][N] = { -1 }, p[N];
//c�����i����j���������С�������
//s�����i����j���������С��������ķָ��k
//����Ai�Ĵ�СΪ,p(i-1)*p[i]
int fun(int i, int j)  //����ӵ�i�����󵽵�j���������С�������
{
	if (c[i][j] > 0)  //����ӵ�i�����󵽵�j���������С��������Ѿ����㣬�򷵻���ֵ
		return c[i][j];
	if (i == j)   //�����ʽΪ�����ҵ�i�����󵽵�i���������С���������Ϊ0��
		return 0;
	int u = fun(i, i) + fun(i + 1, j) + p[i - 1] * p[i] * p[j]; //�����i����j����С�������ʱ����ѷָ��Ϊi+1
	s[i][j] = i;
	for (int k = i + 1; k < j; k++)  //�ָ��k����ȡֵ��������С�������
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