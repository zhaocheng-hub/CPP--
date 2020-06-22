#include<iostream>
using namespace std;
void quicksort(int*a, int start, int end);
int main()
{
	int i;
	void quicksort(int a[], int start, int end);
	int s[] = {38,31,42,18,30,50,90,69,57,79 };
	quicksort(s, 0, 9);
	for (i = 0; i < 10; i++)
		printf("%4d", s[i]);
	return 0;
}
void quicksort(int*a, int start, int end)
{
	int i, j, k, t;
	k = a[start];
	i = start; j = end;
	while (i < j) {
		while (a[j] >= k && i < j)
			j--;
		a[i] = a[j];
		a[j] = k;
		while (a[i] <= k && i < j)
			i++;
		a[j] = a[i];
		a[i] = k;
	}
	for (t = 0; t < 10; t++)
		printf("%4d", a[t]);
	printf("\n");
	a[i] = k;
	if (i - 1 > start) quicksort(a, start, i - 1);
	if (i + 1 < end) quicksort(a, i + 1, end);
}