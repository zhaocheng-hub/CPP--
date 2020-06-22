#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
int fun(int a) 
{ 
	if (a <= 1)
		return 0;
	for (int i = 2; i <=sqrt(a); i++)
	{
		if (a%i == 0)
			return 0;
	}
	return 1;

}
int main() 
{
	int n, k;
	bool flse = 0;
	char a[1001];
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i <= n - k; i++)
	{
		long int temp = 1,sum=0;
		for (int j = 0; j < k; j++)
		{
			sum *= temp;
			sum += a[i + j]-'0';
			temp = 10;
		}
		if (fun(sum))
		{
			for (int l = 0; l < k; l++)
				cout << a[i + l];
			flse = 1;
			break;
		}
	}
	if (flse == 0)
		cout << "404";
}