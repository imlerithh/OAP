#include <iostream>
#include "Header.h"
#include <fstream>
using namespace std;
void push(int x, Stack* myStk)   //���������� �������� � � ����	
{
	Stack* e = new Stack;    //��������� ������ ��� ������ ��������
	e->data = x;             //������ �������� x � ���� v 
	e->next = myStk->head;   //������� ������� �� ��������� ������� 
	myStk->head = e;         //����� ������� �� ������� ������
}
int pop(Stack* myStk)   //���������� (��������) �������� �� �����
{
	if (myStk->head == NULL)
	{
		cout << "���� ����!" << endl;
		return -1;               //���� ���� ���� - ������� -1 
	}
	else
	{
		Stack* e = myStk->head;   //� - ���������� ��� �������� ������ ��������
		int a = myStk->head->data;   //������ ����� �� ���� data � ���������� a 
		myStk->head = myStk->head->next; //������� �������
		delete e;                        //�������� ��������� ����������
		return a;                        //������� �������� ���������� ��������
	}
}
void show(Stack* myStk)    //����� �����
{
	Stack* e = myStk->head;    //����������� ��������� �� ������� �����
	int a;
	if (e == NULL)
		cout << "���� ����!" << endl;
	while (e != NULL)
	{
		a = e->data;          //������ �������� � ���������� a 
		cout << a << " ";
		e = e->next;
	}
	cout << endl;
}
void task(Stack* myStk)    
{
//13
	//Stack* e = myStk->head;    //����������� ��������� �� ������� �����
	//int a, count = 0, suspect;
	//if (e == NULL)
	//	cout << "���� ����!" << endl;

	//while (myStk->head != NULL) {
	//	e = myStk->head;
	//	suspect = e->data;
	//	e = e->next;
	//	while (e != NULL)
	//	{
	//		a = e->data;
	//		if (a == suspect) { count++; break; }
	//		e = e->next;
	//	}
	//	Stack* f = myStk->head;   //f - ���������� ��� �������� ������ ��������
	//	myStk->head = myStk->head->next; //������� �������
	//	delete f;                        //�������� ��������� ����������
	//}
	//cout << "���������� ������������� ���������:" << count << endl;
//2
	Stack* e = myStk->head;    
	int a; bool k = false;
	if (e == NULL)
		cout << "���� ����!" << endl;
	while (e != NULL)
	{	
		Stack* m = e;
		if(k)e = e->next;

		a = e->data;          
		if (a < 0) {
			Stack* f = e;   
			m->next = e->next; 
			delete f;
			break; }
		k = true;
	}
}

void fileOut(Stack* myStk) {
	ofstream fout;
	fout.open("File.txt");
	if (!fout.is_open())
	{
		cout << "File couldn't be open" << endl;
	}
	else {
		Stack* e = myStk->head;    //����������� ��������� �� ������� �����
		int a;
		if (e == NULL)
			cout << "���� ����!" << endl;
		int count = 1;
		fout << "TOP" << endl;
		while (e != NULL)
		{
			a = e->data;          //������ �������� � ���������� a 
			fout << count << ".\t" << a << endl;
			e = e->next;
			count++;
		}
		fout << "BOTTOM" << endl;
	}
	cout << "������ �������� � ����" << endl;
	fout.close();
}
void clear(Stack* myStk) {
	if (myStk->head == NULL)
	{
		cout << "���� ����!" << endl;               
	}
	while (myStk->head != NULL) {
		
		Stack* f = myStk->head;   //f - ���������� ��� �������� ������ ��������
		myStk->head = myStk->head->next; //������� �������
		delete f;                        //�������� ��������� ����������
	}
	cout << "���� ������� ������" << endl;
}
