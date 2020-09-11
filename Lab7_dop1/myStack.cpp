#include <iostream>
#include "MyStack.h"
#include<fstream>
#include <string>
using namespace std;
string path="myStakc.dat";
void push(char x, Stack* myStk)   //���������� �������� � � ����	
{
	Stack* e = new Stack;    //��������� ������ ��� ������ ��������
	e->data = x;             //������ �������� x � ���� v 
	e->next = myStk->head;   //������� ������� �� ��������� ������� 
	myStk->head = e;         //����� ������� �� ������� ������
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

int myFunc(Stack* mySck)			//��� 1
{	
	int choice;
	string word;
	cout << "input word: ";
	cin >> word;
	choice = word.length();
	char* arr1 = new char(choice / 2);
	for (int i = choice / 2; i < choice; i++)
	{
		push(word[i], mySck);
	}
	for (int i = 0; i < choice / 2; i++)
	{
		push(word[i], mySck);		
	}
	
	char* arr2 = new char(choice / 2);

	return 0;
}
