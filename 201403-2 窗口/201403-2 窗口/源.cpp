#include<iostream>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	int x1[11] = { 0 }, x2[11] = { 0 }, y1[11] = { 0 }, y2[11] = { 0 };
	for (int i = 0; i < n; i++)
	{
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
	}
	for (int i = 0; i < m; i++)
	{
		int sum=0,x,y;
		cin >> x >> y;
		for (int j = 0; j < n; j++)
		{
			if (x >= x1[j] && x <= x2[j] && y >= y1[j] && y <= y2[j])
			{
				cout << j + 1 << endl;
				sum++;
				break;
			}
		}
		if (sum == 0)
			cout << "IGNORED";
	}
}