#include <iostream>
using namespace std;
int main() 
{
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int k,temp=0;
		cin >> k;
		for (int j = 1; j < 10; j++)
		{
			if (j*k*k % 1000 == k|| j * k*k %100==k|| j * k*k %10==k)
			{
				temp = j;
				break;
			}
		}
		if (temp == 0)
			cout << "No" << endl;
		else
			cout << temp << " " << temp * k*k << endl;
	}
}