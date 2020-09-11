#include"Tree.h"


void main()
{
	setlocale(LC_ALL, "Russian");
	Tree* mainRoot = new Tree;
	int choice;

	while (1)
	{
		cout << "\n---------------------------------------\n";
		cout << "1. ���������� ���������.\n";
		cout << "2. ����� ������ � �������.\n";
		cout << "3. ��������.\n";
		cout << "4. ������(����������) ����� � �������.\n";
		cout << "5. ��������(���������) ����� � �������.\n";
		cout << "6. �������� �� ������������ ������\n";
		cout << "7. ����� ���������� ������ ������(13)\n";
		cout << "0. �����.\n";
		cout << "---------------------------------------\n";

		cout << "��� �����: "; cin >> choice; cout << endl;

		switch (choice)
		{
		case 1:
		{
			cout << "\n���������� ����� �������������� ���� �� �� ������ ������������� �����. " << endl;
			cout << "������� �������: "; cin >> choice;
			while (choice > 0)
			{
				mainRoot->AddNode(choice);
				cout << "������� �������: "; cin >> choice;
			}
			break;
		}

		case 2:
		{
			if (!mainRoot->node) cout << "� ������ ������ ���.\n";
			else mainRoot->PrintTree(mainRoot->node, 0);
			break;
		}

		case 3:
		{
			int key;
			cout << "������� ���� �������� ������� ������ �������: "; cin >> key;
			mainRoot->Delete(key);
			break;
		}

		case 4:
		{
			if (!mainRoot->node) cout << "� ������ ������ ���.\n";
			else mainRoot->DirectBypass(mainRoot->node);
			break;
		}

		case 5:
		{
			if (!mainRoot->node) cout << "� ������ ������ ���.\n";
			else mainRoot->ReverseBypass(mainRoot->node);
			break;
		}
		case 6:
		{
			mainRoot->counter = 0;
			if (!mainRoot->node) cout << "� ������ ������ ���.\n";
			else
				if (mainRoot->Balance(mainRoot->node))
					cout << "������ ��������������" << endl;
				else
					cout << "������ �� ��������������" << endl;
			break;
		}
		case 7:
		{
			mainRoot->counter = 0;
			cout << endl << "���������� ������ � ������ �����: " << mainRoot->amountOfBranches(mainRoot->node) << endl << endl;
			break;
		}
		case 0:
		{
			exit(0);
			break;
		}
		default:
		{
			cout << "������ ������ ���. �������� �����.\n";
			break;
		}

		}
	}
}


