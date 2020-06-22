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
	printf("������Ҫ����Ľ���id�ʹ�С��");
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
	printf("������Ҫ���յĽ��̺ţ�\n");
	scanf("%d", &pid);
	if (first == NULL)
		printf("�ɻ��յĽ�����Ϊ0\n");
	else {
		while (first != NULL)
		{
			if (first->log == pid)
			{
				second->link = first->link;
				printf("�ѻ���\n");
				break;
			}
			second = first;
			first = first->link;
		}
	}
	if (first == NULL)
		printf("�޸ý���\n");
	else {
		while (start != NULL)
		{
			if (start->stress == first->stress + first->strength)
			{
				start->stress = first->stress;
				start->strength = start->strength + first->strength;  //�Ϻϲ�
				flag = 1;
			}
			if (start->stress + start->strength == first->stress)
			{
				start->strength = start->strength + first->strength;  //�ºϲ�
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
	printf("��������\n��ʼ��ַ\t��������\t��־\n");
	while (first != NULL)
	{
		printf("%d\t\t%d\t\t%d\t\t\n", first->stress, first->strength, first->log);
		first = first->link;
	}
	first = ready;
	printf("�ѷ�������\n��ʼ��ַ\t��������\t��־\n");
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
		printf("ѡ������(0-�˳���1-�������棻2-�������棻3-��ʾ����)\nѡ�����0-3����");
		scanf("%d", &choice);
		switch (choice) {
		case 0: break;
		case 1: distribute(); break;
		case 2: recover(); break;
		case 3: display(); break;
		default:printf("������Ч�ַ�\n"); break;
		}
		system("pause");
	}
	return 0;
}