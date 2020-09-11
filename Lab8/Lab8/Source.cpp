// ������� ������� ��� ������� ����� (������������� � �������������) ����� � ������� ��� �����, ������ � �������� ��������� �������.
// ����� ����������� � ������������ ������� �������. 
// ������� ��� �������� ������� � ��������� �� ����������. 
#include <iostream>
#include "Header.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int choice;
	Queue* myQueue = new Queue; //��������� ������ ��� �����
	myQueue->head = NULL;       //������������� ������� ��������	
	myQueue->tail = NULL;

	for (;;)
	{
		cout << "�������� �������:" << endl;
		cout << "1 - ���������� �������� � �������" << endl;
		cout << "2 - ���������� �������� �� �������" << endl;
		cout << "3 - ����� �������" << endl;
		cout << "4 - �������" << endl;
		cout << "5 - ������� �������" << endl;
		cout << "6 - �����" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "������� �������: " << endl;
			cin >> choice;
			push(choice, myQueue);
			break;
		case 2: choice = pop(myQueue);
			if (choice != -1)
				cout << "����������� �������: " << choice << endl;
			break;
		case 3: cout << "���� ����: " << endl;
			show(myQueue);
			break;
		case 4: cout << "�������: " << endl;
			task(myQueue); break; 
		case 5: cout << "������ ������� �����" << endl;
			clear(myQueue); break;
		case 6: return 0;
			break;
		}
	}
	return 0;
}