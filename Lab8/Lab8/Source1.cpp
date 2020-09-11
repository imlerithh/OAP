#include <iostream>
#include "Header.h"
#include <fstream>

using namespace std;
void push(int x, Queue* myStk)   //���������� �������� � � ����	
{
	if (myStk->head == NULL) {
		Queue* e = new Queue;    //��������� ������ ��� ������ ��������
		e->data = x;             //������ �������� x � ���� v 
		myStk->head = e;         //����� ������� �� ������� ������
		myStk->tail = e;
	}
	Queue* e = new Queue;    //��������� ������ ��� ������ ��������
	e->data = x;             //������ �������� x � ���� v 
	myStk->tail->next = e;
	myStk->tail = e;
	myStk->tail->next = NULL;
}
int pop(Queue* myStk)   //���������� (��������) �������� �� �����
{
	if (myStk->head == NULL)
	{
		cout << "������� ����!" << endl;
		return -1;               //���� ���� ���� - ������� -1 
	}
	else
	{
		Queue* e = myStk->head;			 //� - ���������� ��� �������� ������ ��������
		int a = myStk->head->data;       //������ ����� �� ���� data � ���������� a 
		myStk->head = myStk->head->next; //������� �������
		delete e;                        //�������� ��������� ����������
		return a;                        //������� �������� ���������� ��������
	}
}
void show(Queue* myStk)    //����� �����
{
	Queue* e = myStk->head;    //����������� ��������� �� ������� �����
	int a, count=0;
	if (e == NULL)
		cout << "������� �����!" << endl;
	while (e != NULL)
	{
		a = e->data;          //������ �������� � ���������� a 
		cout << a << " ";
		e = e->next;
		count++;
	}
	cout << endl << "���������� ���������: "<< count << endl;
}
void task(Queue* myStk)
{
	Queue* e = myStk->head;    //����������� ��������� �� ������� �����
	int a, max = e->data, min= e->data;
	if (e == NULL)
		cout << "������� �����!" << endl;
	while (e != NULL)
	{
		a = e->data;          //������ �������� � ���������� a 
		if (a < min) min = a;
		if (a > max) max = a;
		e = e->next;
	}
	cout << "����������� ������� �������: " << min << endl;
	cout << "������������ ������� �������: " << max << endl;

}
void clear(Queue* myStk) {
	if (myStk->head == NULL)
	{
		cout << "������� �����!" << endl;
	}
	while (myStk->head != NULL) {

		Queue* f = myStk->head;   //f - ���������� ��� �������� ������ ��������
		myStk->head = myStk->head->next; //������� �������
		delete f;                        //�������� ��������� ����������
	}
	cout << "������� ������� �������" << endl;
}