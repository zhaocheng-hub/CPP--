#include <iostream>
#include <cstdio>

using namespace std;

int n, m; //������Ⱦ����
int a = 1, b = 1; 
int cou = 0; //Ϳɫ�ɹ�������
int graph[21][21] = { 0 }; //����ڽӾ���
int color[21] = { 0 }; // ���Ϳɫ�������

bool ok(int c) {  //�жϵ�c�Ƿ����Ϳɫ
	for (int k = 1; k <= n; k++) {  
		if (graph[c][k] && color[c] == color[k]) { //c��k��ͨ��c��k��Ϳɫ��ͬ�򷵻�ʧ��
			return false;
		}
	}
	return true;
}

void backtrack(int cur) {  //��cur���㿪ʼͿɫ
	if (cur>n) {   //���Ѿ�Ϳɫ���n�����Ȼ�ɹ� ����Ϳɫ���
		for (int i = 1; i <= n; i++) {
			printf("%d ", color[i]);
		}
		cou++;
		printf("\n");
	}
	else {
		for (int i = 1; i <= m; i++) { //��ʼ����Ϳɫ
			color[cur] = i; 
			if (ok(cur)) {  //�ж����ɹ��������һ��Ϳɫ
				backtrack(cur + 1);
			}
			color[cur] = 0;
		}
	}
}

int main()
{
	scanf_s("%d %d", &n, &m);  //�����������Ϳ���Ϳ����ɫ������
	while (scanf_s("%d %d", &a, &b) != EOF && a != 0 && b != 0) { //��������ĳ������ͨ�ĵ�
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	backtrack(1);  //�ӵ�һ���㿪ʼͿɫ�����ε���
	if (cou != 0)
		cout << "Ϳɫ�ɹ�";
	else
		cout << "Ϳɫʧ��";
	return 0;
}