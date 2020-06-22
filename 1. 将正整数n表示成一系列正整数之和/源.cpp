#include<iostream>
using namespace std;
int fun(int n, int sum, int max, int &ans);
int main()
{
	int n, ans = 0;
	cin >> n;
	fun(n, 0, n, ans);
	cout << ans;
}
int fun(int n, int sum, int max, int &ans)
{
	if (sum == n)
	{
		ans++;
	}
	if (sum < n)
	{
		for (int i = max; i > 0; i--)
		{
			fun(n, i + sum, i, ans);
		}
	}
	return 0;
}