#include<iostream>
using namespace std;
int main()
{
	char a, b;
	int i = 0;
	char c[1000];
	bool d[300] = {0};
	bool r = 1;
	while ((a=getchar())!='\n')
	{
		if (d[a] == 0)
		{
			c[i] = a;
			i++;
			d[a] = 1;
		}
	}
	while ((a = getchar()) != '\n')
	{
		if (d[a] == 0)
		{
			c[i] = a;
			i++;
			d[a] = 1;
		}
	}
	for (int j = 0; j < i; j++)
		cout << c[j];
}