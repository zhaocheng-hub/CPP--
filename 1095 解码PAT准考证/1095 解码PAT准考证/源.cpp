#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
typedef struct Node{
	char s[15];
	char jibie;
	int kaochang;
	int riqi;
	int kaosheng;
	double chengji;
};
bool cmp(Node a, Node b)
{
	if (a.chengji == b.chengji)
		return strcmp(a.s,b.s)<0;
	else
		return a.chengji > b.chengji;
}
int main()
{
	int n, m,t;
	cin >> n >> m;
	Node a[10001];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].s;
		a[i].jibie = a[i].s[0];
		a[i].kaochang = (a[i].s[1] - '0') * 100 + (a[i].s[2] - '0') * 10 + (a[i].s[3] - '0');
		a[i].riqi = (a[i].s[4] - '0') * 100000 + (a[i].s[5] - '0') * 10000 + (a[i].s[6] - '0') * 1000 + (a[i].s[7] - '0') * 100 + (a[i].s[8] - '0') * 10 + (a[i].s[9] - '0') * 1;
		a[i].kaosheng = (a[i].s[10] - '0') * 100 + (a[i].s[11] - '0') * 10 + (a[i].s[12] - '0') * 1;
		cin >> t;
		a[i].chengji = t;
	}
	int x,l=1;
	for (int i = 0; i < m; i++)
	{
		bool flse = 0;
		cin >> x;
		if (x == 1)
		{
			char y;
			cin >> y;
			cout << "Case " << l<<": 1 " << y << endl;
			sort(a, a + n, cmp);
			for (int j = 0; j < n; j++)
			{
				if (a[j].jibie == y)
				{
					cout << a[j].s << " " << a[j].chengji << endl;
					flse = 1;
				}
			}
		}
		if (x == 2)
		{
			int y, r = 0, z = 0;
			cin >> y;
			cout << "Case " << l << ": 2 " << y << endl;
			for (int j = 0; j < n; j++)
			{
				if (a[j].kaochang == y)
				{
					r++;
					z += a[j].chengji;
				}
			}
			if (r != 0)
			{
				cout << r << " " << z << endl;
				flse = 1;
			}
		}
		if(x==3)
		{
			int f[1001] = { 0 }, g[1001] = {0}, y;
			cin >> y;
			cout << "Case " << l << ": 3 " << y << endl;
			for (int j = 0; j < n; j++)
			{
				if (a[j].riqi == y)
				{
					f[a[j].kaochang]++;
				}
			}
			for (int j = 0; j < 1001; j++)
				g[j] = j;
			for (int j=0;j<1001;j++)
				for (int k = 0; k < 1001; k++)
				{
					if (f[j] > f[k])
					{
						int tl = f[j];
						f[j] = f[k];
						f[k] = tl;
						int t2 = g[j];
						g[j] =g[k];
						g[k] = t2;
					}
				}
			for (int j = 0; j < 1001; j++)
			{
				if (f[j] != 0)
				{
					cout << g[j] << " " << f[j] << endl;
					flse = 1;
				}
			}
		}
		if (flse == 0)
		{
			cout << "NA" << endl;
		}
		l++;
	}
}