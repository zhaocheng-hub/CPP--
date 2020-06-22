#include <iostream>
using namespace std;
int main()
{
	int n,a[1001];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int max = 0, area = 0;
	for (int i = 0; i < n; i++)
	{
		int low = a[i];
		for (int j = i; j < n; j++)
		{
			if (a[j] < low)
				low = a[j];
			area = (j - i + 1)*low;
			if (area > max)
				max = area;
		}
	}
	cout << max;
}