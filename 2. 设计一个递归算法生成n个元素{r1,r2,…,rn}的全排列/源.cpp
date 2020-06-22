#include<iostream>
#include<string>
using namespace std;
void swap(char *a, char *b)
{
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
//ȫ���к���
void fullPermutation(char *str, int begin, int n)
{
	//�ݹ鵽���һ���ַ�ʱ�����ǰ���з�ʽ������
	if (begin == n - 1)
	{
		for (int j = 0; j<n; j++)
		{
			cout << str[j];
		}
		cout << endl;
		return;
	}
	else
	{
		//�Ժ�����ַ�����ȫ����
		for (int i = begin; i<n; i++)
		{
			//�����ַ�����ÿ���ַ�����������ǰ��һ��
			swap(&str[begin], &str[i]);
			//�����ַ��������ַ�������ȫ���м���
			fullPermutation(str, begin + 1, n);
			//��������
			swap(&str[begin], &str[i]);
		}
		return;
	}
}
int main()
{
	int n; //n:�ַ�����
	cout << "�����ַ�����:";
	cin >> n;
	char *str = new char[n]; //�ַ�����
	cout << "�����ַ���:" << endl;
	for (int i = 0; i<n; i++)
		cin >> str[i];
	cout << "ȫ�������£�" << endl;
	fullPermutation(str, 0, n);
	delete[n]str;
	system("pause");
	return 0;
}