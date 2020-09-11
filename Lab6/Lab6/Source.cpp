//������� ������, ���������� �������� ������ ����. ����� ����� ������������� ����������� ��������� ��� ������ ���������, ��� ����� ��������� ���. 
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct list {
	int number;
	list* next;
};


void enterNew(list*& p);
void out(list* p);
void task(list*& p);
void fileOut(list*& p);


int choice;

int main() {
	setlocale(LC_CTYPE, "Russian");
	list* first = nullptr;
	cout << "�������:" << endl;
	cout << "1-��� ����� ����� ������" << endl;
	cout << "2-��� ������ �������" << endl;
	cout << "3-��� ���������� ������� " << endl;
	cout << "4-��� ������ � ����" << endl;
	cout << "5-��� ������" << endl;
	cin >> choice;
	do
	{
		switch (choice)
		{
		case 1:  enterNew(first); break;
		case 2:  out(first); break;
		case 3:  task(first); break;
		case 4:  fileOut(first); break;
		}
	} while (choice != 5);
	return 0;
}

void enterNew(list*& p) {
	cout << "���� ����������" << endl;
	cout << "������� ����� "; int value;
	cin >> value;

	
		list* newP = new list;
		if (newP != NULL)     //���� �� �����?  
		{
			newP->number = value;
			newP->next = p;
			p = newP;
		}
		else
			cout << "�������� ���������� �� ���������" << endl;

		cout << "������� ��������� ������� ", cin >> choice;
}

void out(list* p) {
	cout << "����� ����������" << endl;
	if (p == NULL)
		cout << "������ ����" << endl;
	else
	{
		cout << "������:" << endl;
		while (p != NULL)
		{
			cout << "\t-->\t" << p->number;
			p = p->next;
		}
		cout << "\t-->NULL" << endl;
	}
	cout << "������� ��������� ������� ", cin >> choice;
}

void task(list*& p) {
	cout << "�������" << endl;
	int sum = 0;
	if (p == NULL)
		cout << "������ ����" << endl;
	else
	{
		cout << "������:" << endl;
		while (p != NULL)
		{
		//	if (p->number > 0)
		//if (p->number>9 && p->number < 100)
		if (p->number < 0 && p->number % 5 == 0)
		//	if (p->number<-9 && p->number > -100)
				sum += p->number;
			p = p->next;
		}

		cout << "sum\t" << sum << endl;
	}
	cout << "������� ��������� ������� ", cin >> choice;

}


void fileOut(list*& p) {
	list* temp = p;
	list buf;
	ofstream frm("A.dat");
	if (frm.fail())
	{
		cout << "\n ������ �������� �����";
		exit(1);
	}
	while (temp)
	{
		buf = *temp;
		frm.write((char*)&buf, sizeof(list));
		temp = temp->next;
	}
	frm.close();
	cout << "������ ������� � ���� A.dat\n";

	cout << "������� ��������� ������� ", cin >> choice;
}