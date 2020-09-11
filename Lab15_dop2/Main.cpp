#include "Hash.h"


void main()
{
	setlocale(LC_ALL, "Russian");
	int size;
	cout << "������� ������ ���-�������: "; cin >> size; cout << endl;

	HashTable* HT_1 = new HashTable(size);


	int choice = -1;
	while (choice)
	{
		cout << "\n------------------------------";
		cout << "\n���� ��� ������ � ���-��������" << endl;
		cout << "1 - ���������� ��������" << endl;
		cout << "2 - ����� ���-�������" << endl;
		cout << "3 - ����� ��������(-��)" << endl;
		cout << "4 - ������� ����������" << endl;
		cout << "5 - ������� �� ������ �����" << endl;
		cout << "0 - �����" << endl;
		cout << "------------------------------\n\n";
		cout << "��� �����: "; cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:
		{
			HT_1->Insert();
			break;
		}
		case 2:
		{
			HT_1->PrintTable();
			break;
		}
		case 3:
		{
			HT_1->SearchNodes();
			break;
		}
		case 4:
		{
			HT_1->FillPercent();
			break;
		}
		case 5:
		{
			HT_1->DeleteNode();
			break;
		}
		case 0:
		{
			exit(0);
		}
		default:
		{
			cout << "\n������ ������ �� ����������. �������� �����.\n";
			break;
		}
		}

	}
}
