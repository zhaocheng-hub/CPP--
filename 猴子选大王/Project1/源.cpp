#include<iostream>
#include<stdio.h>
using namespace std;
typedef struct Node{
	int data;     // 编号
	int point;    // 前一只猴子的编号
	int next;     // 后一只猴子的编号
}node,*LinkList;
int main() {
	int  n, m;   //n只猴子，每隔m个淘汰一个；
	cin >> n >> m;
	 LinkList a = new Node[n];  
	for (int i = 1; i <= n; i++) {
		a[i].point = i - 1;
		a[i].data = i;
		a[i].next = i+1;
	}
	//修正头和尾
	a[1].point = n;    
	a[n].next = 1;
	int t = 0, i = 1;  //用于计数
	while (n != 1) {
		t++;             //报数
		if (t==m) {      //当报数到m的时候淘汰编号为i的猴子
			t = 0;       //重置报数
			n--;         //剩余猴子-1；
			int p = a[i].point;    //p为编号为i的猴子前面的猴子的编号
			int q = a[i].next;     //q为编号为i的猴子后面的猴子的编号
			a[p].next = q;         //编号为p的猴子的后一只猴子改为编号q的猴子;
			a[q].point = p;        //编号为q的猴子的前一只猴子改为编号p的猴子；
			cout << "淘汰编号为" << i << "的猴子" << endl;
		}
	    i = a[i].next;  //i换为编号为i猴子的后一只猴子
	}
	cout <<"编号为"<< i <<"的猴子是大王"<< endl;
	delete[] a;
	return 0;
}