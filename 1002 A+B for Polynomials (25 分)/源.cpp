#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int k;
	int exp;
	double coe[1001] = { 0 };
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		double j;
		cin >> exp>>j;
		coe[exp] += j;
	}
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		double j;
		cin >> exp >> j;
		coe[exp] += j;
	}
	int l = 0;
	for (int i = 0; i < 1001; i++)
	{
		if (coe[i] != 0)
			l++;
	}
	cout << l;
	for (int i = 1000; i >=0 ; i--)
	{
		if (coe[i] != 0)
		{
			cout << " " << i;
			printf(" %.1f", coe[i]);
			//cout << " " << coe[i];
		}
	}
}