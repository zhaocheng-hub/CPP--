#include <iostream>
#include <math.h>
using namespace std;

//��A�Ķ��η����ĵݹ麯�� ���ݹ��㷨�ͷǵݹ��㷨��  �ݹ�ʽ��֪
float Sqrt_Al(float A, float p, float e) {  //�ݹ�
	if (fabs(p*p - A) < e) {
		return p;
	}
	else {
		return Sqrt_Al(A, (p + A / p) / 2, e);
	}
}

float Sqrt_A2(float A, float p, float e) {  //�ǵݹ�
	while (fabs(p*p - A) >= e) {
		p = (p + A / p) / 2;
	}
	return p;
}

//���һ���ݹ��㷨����n����ͬ�ַ���ȫ����
void perm2(char str[], int k, int n) {
	int i, j;
	char temp;
	if (k == 0) {
		for (j = 0; j <= n - 1; j++) {
			cout << str[j];
		}
	}
	else {
		for (int i = 0; i <= k; ++i) {
			temp = str[k];   //str k �� str i ���� 
			str[k] = str[i];
			str[i] = temp;
			perm2(str, k - 1, n);
			temp = str[i];   //str k �� str i ���� 
			str[i] = str[k];
			str[k] = temp;
		}
	}
}

//�������һԪ��Ϊ���������Ա�L�������һά����A[0,n-1]�У����һ���㷨����A[n-1]Ϊ�ο�����
// �������Ϊ�������֣��󲿷�С��A[n-1]���Ҳ��ִ���A[n-1]�� A[n-1]λ����������֮�䣬
//Ҫ�����Դ��������A��  ���������򣡵�һ�ˣ�
void divide(int A[], int n) {
	int temp;
	int i = 0, j = n - 1;
	temp = A[i];  //��β����
	A[i] = A[j];
	A[j] = temp;
	temp = A[i]; //�µ��� ��temp
	/*��ʼ�㷨*/
	while (i != j) {
		while (j > i&&A[j] > temp) {  //��������ɨ��
			--j;
		}
		if (i < j) {
			A[i] = A[j];
			++i;
		} 
		while (i < j&&A[i] < temp) {  //��������ɨ��
			++i;
		}
		if (i < j) {
			A[j] = A[i];
			--j;
		}
	}
	A[i] = temp;  //�ŵ�����λ��
}