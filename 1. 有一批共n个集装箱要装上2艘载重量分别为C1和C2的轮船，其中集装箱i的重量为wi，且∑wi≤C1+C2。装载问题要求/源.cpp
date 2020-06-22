#include<iostream>
#include<algorithm>
#define MAX 100
using namespace std;
int n;                    //物品总个数
int c1, c2;               //两个轮船的载重
int w[MAX];             //物品重量数组
int x[MAX];            //物品的选择情况 0不选 1选 
int cw = 0;           //当前的装载量
int bestw = 0;       //最优装载
void backpack(int t) {
	if (t>n) {
		if (cw>bestw) {
			bestw = cw;
		}
	}
	else {
		for (int j = 0; j <= 1; j++) {     //枚举物体t所有可能的装载情况
			x[t] = j;
			if (cw + w[t] * x[t] <= c1) {    //约束条件
				cw += w[t] * x[t];
				backpack(t + 1);
				cw -= w[t] * x[t];
			}
		}
	}
}
int main() {
	cin >> c1 >> c2 >> n;    //轮船c1,c2最大载重量以及集装箱数量
	int k = 1;
	int sum = 0;    //集装箱总重量
	for (int i = 1; i <= n; i++) {
		cin >> w[k];
		sum += w[k];
		k++;
	}
	backpack(1);
	if (sum - bestw <= c2) {     //集装箱剩余重量与c2轮船载重量比较
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}