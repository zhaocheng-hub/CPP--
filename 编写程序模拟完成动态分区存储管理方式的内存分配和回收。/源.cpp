#include<cstdio>  
#include<iostream>  
using namespace std;

struct part
{
	int stress;
	long int  strength;
	int log;
	struct part *link;
	part(void) {};
	part(int a, long int b, int c) { stress = a; strength = b; log = c; link = NULL; }
}*ready = NULL, *pnew;

part one = part(11240, 101400, 1);
part *wait = &one;

void distribute()
{
	int pid, pst;
	printf("输入想要分配的进程id和大小：");
	scanf("%d %ld", &pid, &pst);
	part *first, *second;
	first = wait->link;
	second = NULL;
	while (first != NULL)
	{
		if (first->strength >= pst)
			break;
		first = first->link;
	}
	if (first == NULL)
		first = wait;
	pnew = new part();
	pnew->stress = first->stress + first->strength - pst;
	pnew->strength = pst;
	pnew->log = pid;
	pnew->link = NULL;
	first->strength = first->strength - pst;
	first = ready;
	if (ready == NULL)
	{
		ready = pnew;
	}
	else {

		while (first->stress > pnew->stress)
		{
			second = first;
			first = first->link;
			if (first == NULL)
			{
				second->link = pnew;
				pnew->link = NULL;
				break;
			}
		}
		if (first != NULL)
		{
			second->link = pnew;
			pnew->link = first;
		}

	}
	first = second = wait;
	while (first != NULL)
	{
		if (first->strength == 0)
		{
			second->link = first->link;
		}
		second = first;
		first = first->link;
	}
}

void recover()
{
	int pid = 0;
	int flag = 0;
	part * start = wait;
	part * first = ready;
	part * second = first;
	printf("输入想要回收的进程号：\n");
	scanf("%d", &pid);
	if (first == NULL)
		printf("可回收的进程数为0\n");
	else {
		while (first != NULL)
		{
			if (first->log == pid)
			{
				second->link = first->link;
				printf("已回收\n");
				break;
			}
			second = first;
			first = first->link;
		}
	}
	if (first == NULL)
		printf("无该进程\n");
	else {
		while (start != NULL)
		{
			if (start->stress == first->stress + first->strength)
			{
				start->stress = first->stress;
				start->strength = start->strength + first->strength;  //上合并
				flag = 1;
			}
			if (start->stress + start->strength == first->stress)
			{
				start->strength = start->strength + first->strength;  //下合并
				flag = 2;
			}
			second = start;
			start = start->link;
		}
		if (flag == 0)
		{
			second->link = first;
			first->link = NULL;
			first->log = 1;
		}

	}

}
void display()
{
	part *first = wait;
	printf("空闲区表\n起始地址\t分区长度\t标志\n");
	while (first != NULL)
	{
		printf("%d\t\t%d\t\t%d\t\t\n", first->stress, first->strength, first->log);
		first = first->link;
	}
	first = ready;
	printf("已分配区表\n起始地址\t分区长度\t标志\n");
	while (first != NULL)
	{
		printf("%d\t\t%d\t\t%d\t\t\n", first->stress, first->strength, first->log);
		first = first->link;
	}
	printf("\n");
}

int main()
{
	int choice = 1;
	while (choice != 0) {
		printf("选择功能项(0-退出，1-分配主存；2-回收主存；3-显示主存)\n选择功能项（0-3）：");
		scanf("%d", &choice);
		switch (choice) {
		case 0: break;
		case 1: distribute(); break;
		case 2: recover(); break;
		case 3: display(); break;
		default:printf("输入有效字符\n"); break;
		}
		system("pause");
	}
	return 0;
}