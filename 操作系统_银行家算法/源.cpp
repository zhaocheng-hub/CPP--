#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct Available {
	string name;  //��Դ����
	int number;   //��Դʣ������
};
int fun1(bool Finish[],int n)
{
	for (int i = 0; i < n; i++)
	{
		if (Finish[i] == 0)
			return 0;
	}
	return 1;
}
//vector <Available> a; // ʣ����Դ����
int **Allocation;
int **Need;
int b;
int m,n;//mΪ��ǰ��Դ��, nΪ��ǰ��������
string c;
Available d;
int fun2(vector <Available> &a) {  //����ʣ����Դ
	std::cout << "����������ʣ����Դ�����ƺ�����:" << endl;
	while (std::cin >> c >> b)
	{
		d.name = c;
		d.number = b;
		a.push_back(d);
	}
	std::cin.clear(); //���EOF
	std::cin.sync(); //�����
	m = a.size();
	return 0;
}

//int m= a.size();  //mΪ��ǰ��Դ��
//vector<vector <int > > Max(m);

int fun3(vector<vector <int > > &Max) {  //�������������Ҫ����Դ��
	int i = 0, j = 0;
	std::cout << "���������1������������Ҫ����Դ��:" << endl;
	while (std::cin >> b)
	{
		for (int j = 0; j < m; j++)
		{
			Max[j].push_back(b);
			if (j != m - 1)
				std::cin >> b;
		}
		j = 0;
		i++;
		std::cout << "���������" << i + 1 << "����������Ҫ����Դ��:" << endl;
	}
	std::cin.clear(); //���EOF
	std::cin.sync(); //�����
	n = Max[0].size();
	return 0;
}

//int n = Max[0].size();//nΪ��ǰ��������
//int **Allocation = new int*[n];
//int **Need = new int*[n];
int fun4(vector<vector <int > > &Max) {  //�����ѷ�����Դ��
	Allocation = new int*[n];
	Need = new int*[n];
	for (int i = 0; i < n; i++)
	{
		std::cout << "�����������" << i + 1 << "�������ѷ������Դ��:" << endl;
		Allocation[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			std::cin >> b;
			Allocation[i][j] = b;
		}
	}
	for (int i = 0; i < n; i++)
	{
		Need[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			Need[i][j] = Max[j][i] - Allocation[i][j];
		}
	}
	return 0;
}

int fun5(vector <Available> a, vector<vector <int > > Max) {//�鿴������
	std::cout << "Availavle:" << endl;
	for (unsigned int i = 0; i < a.size(); i++)
	{
		std::cout << a[i].name << " " << a[i].number << endl;
	}
	std::cout << "Max" << "  ";
	for (int i = 0; i < m; i++)
	{
		std::cout << a[i].name << "  ";
	}
	std::cout << endl;
	for (unsigned int i = 0; i < Max[0].size(); i++)  //Max[j][i]Ϊ��i��������Ҫ�ĵ�j����Դ������
	{
		std::cout << i << "  ";
		for (int j = 0; j < m; j++)
		{
			std::cout << Max[j][i] << " ";
		}
		std::cout << endl;
	}
	std::cout << "Allocation" << "  ";
	for (int i = 0; i < m; i++)
	{
		std::cout << a[i].name << "  ";
	}
	std::cout << endl;
	for (int i = 0; i < n; i++)
	{
		std::cout << i << "  ";
		for (int j = 0; j < m; j++)
		{
			std::cout << Allocation[i][j] << " ";
		}
		std::cout << endl;
	}
	std::cout << "Need" << "  ";
	for (int i = 0; i < m; i++)
	{
		std::cout << a[i].name << "  ";
	}
	std::cout << endl;
	for (int i = 0; i < n; i++)
	{
		std::cout << i << "  ";
		for (int j = 0; j < m; j++)
		{
			std::cout << Need[i][j] << " ";
		}
		std::cout << endl;
	}
	return 0;
}
	
int fun6(vector <Available> a, vector<vector <int > > Max){			//���м��㷨
	int *Request = new int[m];
	int k;
	bool  flase_1 = 1, flase_2 = 1;//�������м��㷨����i��ȷ
	cout << "������i:";
	cin >> k;
	cout << "����������Pi��Ҫ����Դ:";
	for (int j = 0; j < m; j++)
		cin >> Request[j];
	for (int j = 0; j < m; j++) //����һ
	{
		if (Request[j] > Need[k][j])
			flase_1 = 0;
	}
	for (int j = 0; j < m; j++)   //�����
	{
		if (Request[j] > a[j].number)
			flase_2 = 0;
	}
	if (flase_1==1&&flase_2==1) {
		for (int j = 0; j < m; j++)
		{
			a[j].number -= Request[j];
			Allocation[k][j] += Request[j];
			Need[k][j] -= Request[j];
		}
	} else {
		if (flase_1 == 0)
			cout << "����һ������";
		else if (flase_2 == 0)
			cout << "�����������";
		cout << "��������������"<<endl;
		fun6(a, Max);
		return 0;
	}
	//��ȫ���㷨
	bool *Finish = new bool[n];
	int *Work = new int[m];
	for (int i = 0; i < n; i++)
	{
		Finish[i] = 0;
	}
	for (int i = 0; i < m; i++)
	{
		Work[i] = a[i].number;
	}
	bool flase_4 = 1;
	while (fun1(Finish, n)==0&&flase_4)//�жϺ��� ���ȫΪ1�� ����1 ���򷵻�0
	{
		flase_4 = 0;  //���ѭ����һ����Դû�з����κθı䣬��ʧ��
		for (int i = 0; i < n; i++)
		{
			bool flase_3 = 1;
			if (Finish[i] == false)
			{
				for (int j = 0; j < m&&flase_3; j++)
				{
					if (Need[i][j] > Work[j])
						flase_3 = 0;
				}
				if (flase_3 == 1)
				{
					for (int j = 0; j < m; j++)
					{
						Work[j] += Allocation[i][j];
						Finish[i] = true;
						flase_4 = 1; //��Դ�Ѿ������ı���Լ�����һ��ѭ��
					}
					cout << "����" << i << "�Ѿ����ͷ�" << endl;
				}
			}
		}
	}
	if (flase_4 == 1)
		cout << "�ɹ�" << endl;
	else 
		cout << "ʧ��" << endl;
	cout << "ʣ����Դ������Ϊ:";
	for (int i = 0; i < m; i++)
		cout << Work[i] << " ";
	cout << endl;
	for (int j = 0; j < m; j++) //��Դ����
	{
		a[j].number += Request[j];
		Allocation[k][j] -= Request[j];
		Need[k][j] += Request[j];
	}
	fun5(a, Max);
	fun6(a, Max);
	return 0;
}
int main()
{
	vector <Available> a; // ʣ����Դ����
	fun2(a);
	vector<vector <int > > Max(m);
	fun3(Max);
	fun4(Max);
	fun5(a, Max);//�鿴���
	fun6(a, Max);
}