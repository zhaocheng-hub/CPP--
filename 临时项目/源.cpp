#include <stdio.h> 
#include <math.h> 
#include<iostream>
#include<string.h>
using namespace std;
union test{
	int i;
	char c;
	double a;
}test;
struct node {
	char c;
};
int  main()
{
	union test a;
	struct node b;
	cout << sizeof(a) << endl;
	cout << sizeof(b) << endl;
}