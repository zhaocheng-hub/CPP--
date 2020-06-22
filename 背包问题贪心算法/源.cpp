#include<iostream>
#include<algorithm>
using namespace std;
struct Node {
	int no; //���
	double weight;//����
	double value;//��ֵ
	double weighted; //Ȩ��
};
bool cmp(Node a, Node b) {
	if (a.weighted != b.weighted)
		return a.weighted > b.weighted;
	else if (a.weight != b.weight)
		return a.weight < b.weight;
	else
		return a.no < b.no;
}
int main()
{
	int n;//��Ʒ����
	Node a[1001];
	cout << "��������Ʒ����:";
	cin >> n;
	cout << "������������Ʒ�������ͼ�ֵ:";
	for (int i = 1; i <= n; i++)
	{
		a[i].no = i;
		cin >> a[i].weight >> a[i].value;
		a[i].weighted = a[i].value / a[i].weight;
	}
	double sum=0,weight_sum;
	cout << "�����뱳������";
	cin >> weight_sum;
	sort(a + 1, a + n + 1, cmp);
	cout << "���\t" << "����\t" << "��ֵ\t" << "Ȩ��\t" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout<<a[i].no<<"\t";
		cout<< a[i].weight << "\t";
		cout<< a[i].value<<"\t";
		cout << a[i].weighted << endl;
	}
	int i = 1;

	while (weight_sum > 0&&i<=n)
	{
		if (weight_sum < a[i].weight)
			i++;
		else
		{
			weight_sum -= a[i].weight;
			sum += a[i].value;
			i++;
		}
	}
	cout <<"������װ��ֵΪ"<<sum<<"����Ʒ";
}