#include <iostream>
#include "MyStack.h"
#include<fstream>
#include <string>
using namespace std;
string path="myStakc.txt";
void push(int x, int i, Stack* myStk)   //���������� �������� � � ����	
{
	Stack* e = new Stack;    //��������� ������ ��� ������ ��������
	e->data = x;             //������ �������� x � ���� v 
	e->num = i;
	e->next = myStk->head;   //������� ������� �� ��������� ������� 
	myStk->head = e;         //����� ������� �� ������� ������
}

int fromFile(Stack* myStk)          //���������� �� �����
{	
	int buf;
	ifstream fin;
	Stack* e = myStk->head;
	
	fin.open(path);
	if (!fin.is_open()) {
		printf_s("%s", "�� ������� ������� ����");
		return -1;
	}
	int i = 0;
	while (!fin.eof())
	{
		string buf;
		int num=0;
		getline(fin, buf);
		num = buf.length();
		push(num, i, myStk);
		i++;
	}
	fin.close();
	return 0;
	
}

int myFunct(Stack* myStk)
{
	Stack* e = myStk->head;    //����������� ��������� �� ������� �����

	if (e == NULL) 
	{
		cout << "���� ����!" << endl;
		return 0;
	}
	int raz = e->data;
	int number = e->num;
	while (e != NULL)
	{
		if (raz > (e->data))
		{
			number = e->num;
			raz = e->data;
		}
		e = e->next;
	}
	cout << "\n����� ����� �������� ������: " << number + 1<<"\n������ ����� �������� ������: "<<raz ;

	cout << endl;
	return 0;
}


void show(Stack* myStk)    //����� �����
{
	Stack* e = myStk->head;    //����������� ��������� �� ������� �����
	
	if (e == NULL)
		cout << "���� ����!" << endl;
	while (e != NULL)
	{
								         
		cout << e->data << " ";
		e = e->next;
	}
	cout << endl;
}
