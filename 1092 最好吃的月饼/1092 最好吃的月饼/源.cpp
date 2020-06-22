#include<iostream>
#include<algorithm>
using namespace std;
typedef struct Node {
	int no;
	long int num;
};
bool cmp(Node a, Node b)
{
	if (a.num != b.num)
		return a.num > b.num;
	else
		return a.no < b.no;

}
int main()
{
	int n, m, t, k = 1;
	cin >> n >> m;
	Node a[1010];
	for (int i = 0; i < 1001; i++)
	{
		a[i].no = i + 1;
		a[i].num = 0;
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> t;
			a[j].num += t;
		}
	}
	sort(a, a + n, cmp);
	cout << a[0].num << endl;
	for (int i = 0; i < n; i++)
	{
		if (i != 0)
			cout << " ";
		if (a[i].num == a[i + 1].num)
		{
			cout << a[i].no;
		}
		else
		{
			cout << a[i].no;
			break;
		}
	}
}