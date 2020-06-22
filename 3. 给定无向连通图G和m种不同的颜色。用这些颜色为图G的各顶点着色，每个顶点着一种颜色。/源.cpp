#include <iostream>
#include <cstdio>

using namespace std;

int n, m; //点数和染料数
int a = 1, b = 1; 
int cou = 0; //涂色成功的种类
int graph[21][21] = { 0 }; //点的邻接矩阵
int color[21] = { 0 }; // 点的涂色情况数组

bool ok(int c) {  //判断点c是否可以涂色
	for (int k = 1; k <= n; k++) {  
		if (graph[c][k] && color[c] == color[k]) { //c与k连通且c与k的涂色相同则返回失败
			return false;
		}
	}
	return true;
}

void backtrack(int cur) {  //第cur个点开始涂色
	if (cur>n) {   //若已经涂色完第n个点必然成功 输入涂色情况
		for (int i = 1; i <= n; i++) {
			printf("%d ", color[i]);
		}
		cou++;
		printf("\n");
	}
	else {
		for (int i = 1; i <= m; i++) { //开始尝试涂色
			color[cur] = i; 
			if (ok(cur)) {  //判断若成功则进入下一个涂色
				backtrack(cur + 1);
			}
			color[cur] = 0;
		}
	}
}

int main()
{
	scanf_s("%d %d", &n, &m);  //输入点的数量和可用涂料颜色的数量
	while (scanf_s("%d %d", &a, &b) != EOF && a != 0 && b != 0) { //依次输入某两个连通的点
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	backtrack(1);  //从第一个点开始涂色，依次递增
	if (cou != 0)
		cout << "涂色成功";
	else
		cout << "涂色失败";
	return 0;
}