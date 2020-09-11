#include <iostream>
#include "Header.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int choice;
	Stack* myStk = new Stack; //��������� ������ ��� �����
	myStk->head = NULL;       //������������� ������� ��������	
	
	for (;;)
	{
		cout << "�������� �������:" << endl;
		cout << "1 - ���������� �������� � ����" << endl;
		cout << "2 - ���������� �������� �� �����" << endl;
		cout << "3 - ����� �����" << endl;
		cout << "4 - �������" << endl;
		cout << "5 - ������ � ������" << endl;
		cout << "6 - ������� �����" << endl;
		cout << "7 - �����" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "������� �������: " << endl;
			cin >> choice;
			push(choice, myStk);
			break;
		case 2: choice = pop(myStk);
			if (choice != -1)
				cout << "����������� �������: " << choice << endl;
			break;
		case 3: cout << "���� ����: " << endl;
			show(myStk);
			break;
		case 4: cout << "�������: " << endl;
			task(myStk); break;
		case 5: cout << "������ � ����: " << endl;
			fileOut(myStk); break;
		case 6: cout << "������ ������� �����" << endl;
			clear(myStk); break;
		case 7: return 0;
			break;
		}
	}
	return 0;
}
