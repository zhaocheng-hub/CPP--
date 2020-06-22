#include <iostream>
#include<algorithm>
using namespace std;
struct Node {
	int no;
	int last;
	int b;  //距离祖先有几代 辈分
}a[100010];
bool cmp(Node x, Node y)
{
	if (x.b != y.b)
		return x.b > y.b;
	else
		return x.no < y.no;
}
int fun1(int i) {
	if (a[i].last == -1)
		return 1;
	if (a[i].b == 0)
		return fun1(a[i].last) + 1;
	else
		return a[i].b;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		a[i].no = i;
		cin >> a[i].last;
		a[i].b = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		if (a[i].b == 0)
		{
			a[i].b = fun1(i);
		}
	}
	int b_max = 0;
	for (int i = 1; i <= n; i++)
	{
		if (b_max < a[i].b)
			b_max = a[i].b;
	}
	cout << b_max << endl;
	bool fals = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i].b == b_max)
		{
			if (fals == 1)
				cout << " ";
			cout << a[i].no;
			fals = 1;
		}
	}
}