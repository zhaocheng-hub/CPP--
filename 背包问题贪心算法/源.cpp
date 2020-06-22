#include<iostream>
#include<algorithm>
using namespace std;
struct Node {
	int no; //编号
	double weight;//重量
	double value;//价值
	double weighted; //权重
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
	int n;//物品总数
	Node a[1001];
	cout << "请输入物品总数:";
	cin >> n;
	cout << "请依次输入物品的重量和价值:";
	for (int i = 1; i <= n; i++)
	{
		a[i].no = i;
		cin >> a[i].weight >> a[i].value;
		a[i].weighted = a[i].value / a[i].weight;
	}
	double sum=0,weight_sum;
	cout << "请输入背包容量";
	cin >> weight_sum;
	sort(a + 1, a + n + 1, cmp);
	cout << "编号\t" << "重量\t" << "价值\t" << "权重\t" << endl;
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
	cout <<"最多可以装价值为"<<sum<<"的物品";
}