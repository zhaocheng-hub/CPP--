#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
#define LEN 100

int isMatch(char a, char b) {
	if ((a == 'A' && b == 'U') || (a == 'U'&&b == 'A'))
		return 1;
	if ((a == 'C' && b == 'G') || (a == 'G' && b == 'C'))
		return 1;
	return 0;
}
int RNA_2(char B[LEN], int n) {
	int i, j, k, t;
	int max;
	int C[10][10] = { 0 };
	
	for (k = 5; k <= n - 1; k++) {
		for (int i = 1; i <= n - k; i++) {
			j = i + k;
			max =C[i][j-1] ;
			for (t = i; t <= j - 4; t++) {
				if (isMatch(B[t-1],B[j-1])&& max < C[i][t - 1] + 1 + C[t + 1][j - 1])
					max = C[i][t - 1] + 1 + C[t + 1][j - 1];
			}
			C[i][j] = max;
			printf("c[%d][%d]=%d--", i, j, C[i][j]);
		}
		cout << endl;
	}
	return C[1][n];
}
int main() {
	char B[LEN];
	cin >> B;
	cout<<RNA_2(B, 9)<<endl;
}