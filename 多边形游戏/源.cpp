
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

#define NMAX 100
int N, m[NMAX + 1][NMAX + 1][2], v[NMAX + 1];
char op[NMAX + 1];

void MinMax(int n, int i, int s, int j, int &minf, int &maxf);
int PloyMax(int n, int& p);

int main()
{
	int p;
	cout << "���������ζ�������" << endl;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cout << "���������ζ���" << i << "��ֵ:" << endl;
		cin >> v[i];
		m[i][1][0] = v[i];
		m[i][1][1] = v[i];
		cout << "���������α�" << i << "�����:" << endl;
		cin >> op[i];
	}
	cout << "�������Ϸ�״�ɾ����" << p << "���ߣ����Ϊ��" << PloyMax(N, p) << endl;
	return 0;
}

void MinMax(int n, int i, int s, int j, int &minf, int &maxf)
{
	int e[5];
	int a = m[i][s][0], b = m[i][s][1];
	int r = (i + s - 1) % n + 1;//����ε�ʵ�ʶ�����
	int c = m[r][j - s][0], d = m[r][j - s][1];

	if (op[r - 1] == '+')
	{
		minf = a + c;
		maxf = b + d;
	}
	else
	{
		e[1] = a * c;
		e[2] = a * d;
		e[3] = b * c;
		e[4] = d * b;
		minf = e[1];
		maxf = e[1];

		for (int r = 2; r<N; r++)
		{
			if (minf>e[r])minf = e[r];
			if (maxf<e[r])maxf = e[r];
		}
	}
}

int PloyMax(int n, int& p)
{
	int minf, maxf;
	for (int j = 2; j <= n; j++) //�������ĳ���(����������Ŀ)
	{
		for (int i = 1; i <= n; i++)//�����״�ɾ����i����
		{
			for (int s = 1; s <= j - 1; s++) //�����Ͽ�λ��
			{
				MinMax(n, i, s, j, minf, maxf);
				if (m[i][j][0]>minf) m[i][j][0] = minf;
				if (m[i][j][1]<maxf) m[i][j][1] = maxf;
			}
		}
	}

	int temp = m[1][n][1];
	p = 1;

	for (int i = 2; i <= n; i++)
	{
		if (temp<m[i][n][1])
		{
			temp = m[i][n][1];
			p = i;
		}
	}
	return temp;
}