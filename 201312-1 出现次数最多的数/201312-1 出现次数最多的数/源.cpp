#include<iostream>
using namespace std;
int main() {
	int n,t;
	cin >> n;
	int a[10010] = { 0 };
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		a[t]++;
	}
	int temp=0,j=0;
	for (int i = 0; i <= 10000; i++)
	{
		if (a[i] > temp)
		{
			temp = a[i];
			j = i;
		}
	}
	cout << j;
	return 0;
}