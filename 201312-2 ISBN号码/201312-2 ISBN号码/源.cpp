#include<iostream>
#include<stdio.h>
using namespace std;
int main() {
	int a, b, c;
	int sum;
	char d, t;
	scanf_s("%d-%d-%d-%c", &a, &b, &c, &d,1);
	sum = a + b / 100 * 2 + b / 10 % 10 * 3 + b % 10 * 4 + c / 10000 * 5 + c / 1000 % 10 * 6 + c / 100 % 10 * 7 + c / 10 % 10 * 8 + c % 10 * 9;
	sum = sum % 11;
	if (sum == 10)
		t = 'X';
	else
		t = sum + '0';
	if (t == d)
		cout << "Right";
	else
		cout << a << "-" << b << "-" << c << "-" << t;
}