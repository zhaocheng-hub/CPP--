#include<iostream>
using namespace std;
int fun(int n, char A, char B, char C)//��A�ϵ��ƶ���B��CΪ��ת��
{
	if (n > 0)
	{
		fun(n - 1, A, C, B);//�Ƚ�n-1����A�ƶ���C����
		cout << "�����Ϊ" << n << "������" << A << "�ƶ���" << B << "����ȥ" << endl;
		fun(n - 1, C, B, A);//�ٽ�n-1����C�ƶ���B����
	}
	return 0;
}
int main()
{
	int n;
	char A, B, C;
	cin >> n >> A >> B >> C;
	fun(n, A, B, C);
}