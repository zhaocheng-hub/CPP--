#include <cstdlib>
#include <iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
#define N 105 
int dp[N + 1][N + 1];  //����ֵ
char str1[N], str2[N];
int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}
int LCSL(int len1, int len2)  //����LCS�ĳ���
{
	int i, j;
	int len = max(len1, len2); 
	for (i = 0; i <= len; i++)  //Ҳ���Էֿ���ֵ
	{
		dp[i][0] = 0;
		dp[0][i] = 0;
	}
	for (i = 1; i <= len1; i++)
		for (j = 1; j <= len2; j++)
		{
			if (str1[i - 1] == str2[j - 1]) //�����i���ַ��͵�j���ַ���ͬ
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else   //�����ͬ
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	return dp[len1][len2];  //�������½�Ԫ�ص�ֵ
}
void LCS(int i, int j) //����LCS
{
	if (i == -1 || j == -1) return;
	if (str1[i] == str2[j])
	{
		LCS(i - 1, j - 1);
		printf("%c ", str1[i]);
	}
	else if (dp[i - 1][j]>dp[i][j - 1])
		LCS(i - 1, j);
	else
		LCS(i, j - 1);
}
int main()
{
	while (cin >> str1 >> str2)
	{
		int len1 = strlen(str1);
		int len2 = strlen(str2);
		cout << LCSL(len1, len2) << endl;
		LCS(len1, len2);
	}
	return 0;
}