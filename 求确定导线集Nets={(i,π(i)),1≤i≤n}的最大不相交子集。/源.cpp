#include <stdio.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

void circut(int a[], int set[][11], int n);
void back_track(int i, int j, int set[][11]);

int main()
{
	int a[] = { 0,8,7,4,2,5,1,9,3,10,6 };
	int set[11][11];

	circut(a, set, 10);

	printf("max set: %d \n", set[10][10]);
	back_track(10, 10, set);
	printf("\n");

	return 0;
}

void circut(int a[], int set[][11], int n)
{
	int i, j;

	for (i = 0; i < n; i++)
	{
		set[i][0] = 0;
		set[0][i] = 0;
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (a[i] != j)
				set[i][j] = MAX(set[i - 1][j], set[i][j - 1]);
			else
				set[i][j] = set[i - 1][j - 1] + 1;
		}
	}
}

void back_track(int i, int j, int set[][11])
{
	if (i == 0)
		return;
	if (set[i][j] == set[i - 1][j])
		back_track(i - 1, j, set);
	else if (set[i][j] == set[i][j - 1])
		back_track(i, j - 1, set);
	else
	{
		back_track(i - 1, j - 1, set);
		printf("(%d,%d) ", i, j);
	}
}