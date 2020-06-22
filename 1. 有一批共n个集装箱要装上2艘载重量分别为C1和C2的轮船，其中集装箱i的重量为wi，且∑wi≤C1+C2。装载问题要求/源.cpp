#include<iostream>
#include<algorithm>
#define MAX 100
using namespace std;
int n;                    //��Ʒ�ܸ���
int c1, c2;               //�����ִ�������
int w[MAX];             //��Ʒ��������
int x[MAX];            //��Ʒ��ѡ����� 0��ѡ 1ѡ 
int cw = 0;           //��ǰ��װ����
int bestw = 0;       //����װ��
void backpack(int t) {
	if (t>n) {
		if (cw>bestw) {
			bestw = cw;
		}
	}
	else {
		for (int j = 0; j <= 1; j++) {     //ö������t���п��ܵ�װ�����
			x[t] = j;
			if (cw + w[t] * x[t] <= c1) {    //Լ������
				cw += w[t] * x[t];
				backpack(t + 1);
				cw -= w[t] * x[t];
			}
		}
	}
}
int main() {
	cin >> c1 >> c2 >> n;    //�ִ�c1,c2����������Լ���װ������
	int k = 1;
	int sum = 0;    //��װ��������
	for (int i = 1; i <= n; i++) {
		cin >> w[k];
		sum += w[k];
		k++;
	}
	backpack(1);
	if (sum - bestw <= c2) {     //��װ��ʣ��������c2�ִ��������Ƚ�
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}