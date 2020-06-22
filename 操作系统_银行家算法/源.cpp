#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct Available {
	string name;  //资源名称
	int number;   //资源剩余数量
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
//vector <Available> a; // 剩余资源数组
int **Allocation;
int **Need;
int b;
int m,n;//m为当前资源量, n为当前进程数量
string c;
Available d;
int fun2(vector <Available> &a) {  //创建剩余资源
	std::cout << "请依次输入剩余资源的名称和数量:" << endl;
	while (std::cin >> c >> b)
	{
		d.name = c;
		d.number = b;
		a.push_back(d);
	}
	std::cin.clear(); //清除EOF
	std::cin.sync(); //清空流
	m = a.size();
	return 0;
}

//int m= a.size();  //m为当前资源量
//vector<vector <int > > Max(m);

int fun3(vector<vector <int > > &Max) {  //创建多个进程需要的资源数
	int i = 0, j = 0;
	std::cout << "请您输入第1个进程依次需要的资源数:" << endl;
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
		std::cout << "请您输入第" << i + 1 << "个进程所需要的资源数:" << endl;
	}
	std::cin.clear(); //清除EOF
	std::cin.sync(); //清空流
	n = Max[0].size();
	return 0;
}

//int n = Max[0].size();//n为当前进程数量
//int **Allocation = new int*[n];
//int **Need = new int*[n];
int fun4(vector<vector <int > > &Max) {  //创建已分配资源数
	Allocation = new int*[n];
	Need = new int*[n];
	for (int i = 0; i < n; i++)
	{
		std::cout << "请依次输入第" << i + 1 << "个进程已分配的资源数:" << endl;
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

int fun5(vector <Available> a, vector<vector <int > > Max) {//查看输出结果
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
	for (unsigned int i = 0; i < Max[0].size(); i++)  //Max[j][i]为第i个进程需要的第j个资源的数量
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
	
int fun6(vector <Available> a, vector<vector <int > > Max){			//银行家算法
	int *Request = new int[m];
	int k;
	bool  flase_1 = 1, flase_2 = 1;//假设银行家算法步骤i正确
	cout << "请输入i:";
	cin >> k;
	cout << "请依次输入Pi需要的资源:";
	for (int j = 0; j < m; j++)
		cin >> Request[j];
	for (int j = 0; j < m; j++) //步骤一
	{
		if (Request[j] > Need[k][j])
			flase_1 = 0;
	}
	for (int j = 0; j < m; j++)   //步骤二
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
			cout << "步骤一不符合";
		else if (flase_2 == 0)
			cout << "步骤二不符合";
		cout << "请重新输入数据"<<endl;
		fun6(a, Max);
		return 0;
	}
	//安全性算法
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
	while (fun1(Finish, n)==0&&flase_4)//判断函数 如果全为1则 返回1 否则返回0
	{
		flase_4 = 0;  //如果循环过一次资源没有发生任何改变，则失败
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
						flase_4 = 1; //资源已经发生改变可以继续下一次循环
					}
					cout << "进程" << i << "已经被释放" << endl;
				}
			}
		}
	}
	if (flase_4 == 1)
		cout << "成功" << endl;
	else 
		cout << "失败" << endl;
	cout << "剩余资源数依次为:";
	for (int i = 0; i < m; i++)
		cout << Work[i] << " ";
	cout << endl;
	for (int j = 0; j < m; j++) //资源还回
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
	vector <Available> a; // 剩余资源数组
	fun2(a);
	vector<vector <int > > Max(m);
	fun3(Max);
	fun4(Max);
	fun5(a, Max);//查看结果
	fun6(a, Max);
}