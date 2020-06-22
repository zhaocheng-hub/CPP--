#include <iostream>
#include<math.h>
using namespace std;
int main()
{
	int n,t,sum=0;
	bool a[501];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		t = fabs(t);
		if (a[t] == 1)
			sum++;
		else
			a[t] = 1;
	}
	cout << sum;
}