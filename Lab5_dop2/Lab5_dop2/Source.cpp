// 10-2 ���������.�������., ���� ��������, �����, ���(�, �).����������� ������� �� ���� ��������
#include <iostream>
#include <string>
using namespace std;
# define str_len 16                               
# define size 2 

void enterNew();
void out();
void del();
void find();

enum Sex {
	male,
	female
};


struct Citizen
{
	char addres[str_len];
	char name[str_len];
	Sex sex;
	int year;
};
struct Citizen listOfCitizens[size];
struct Citizen bad;
int current_size = 0; int choice;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "�������:" << endl;
	cout << "1-��� ����� ����� ������" << endl;
	cout << "2-��� ������ �������" << endl;
	cout << "3-��� �������� ������" << endl;
	cout << "4-��� ������ ������ �� ����������" << endl;
	cout << "5-��� ������" << endl;
	cin >> choice;
	do
	{
		switch (choice)
		{
		case 1:  enterNew(); break;
		case 2:  out(); break;
		case 3:  del(); break;
		case 4:  find();  break;
		}
	} while (choice != 5);
	return 0;
}

void enterNew()
{
	cout << "���� ����������" << endl;
	for (; current_size < size;)
	{
		cout << "������ ����� ";
		cout << current_size + 1;
		cout << endl << "���" << endl;
		cin >> listOfCitizens[current_size].name;
		cout << "����� " << endl;
		cin >> listOfCitizens[current_size].addres;
		cout << "��� " << endl; char ffac[str_len];
		cin >> ffac;
		if (strcmp(ffac, "male") == 0) listOfCitizens[current_size].sex = Sex::male;
		else if (strcmp(ffac, "female") == 0) listOfCitizens[current_size].sex = Sex::female;
		else cout << "������ ������� �����������" << endl;

		cout << "���� ��������" << endl;
		cin >> listOfCitizens[current_size].year;

		current_size++;
	}
	cout << "������� ������������ ���-�� �������" << endl;
	cout << "������� ��������� ������� ", cin >> choice;
}

void out()
{
	int a;
	cout << "������� ����� ��������� ������, 0 ��� ������ ���� ������� ", cin >> a;
	if (a > 0 && a <= current_size) {
		cout << "����� ������: " << a << endl;
		cout << "���: " << listOfCitizens[a-1].name << endl;
		cout << "���: (0-male, 1-female) " << listOfCitizens[a-1].sex << endl;
		cout << "�������������: " << listOfCitizens[a-1].addres << endl;
		cout << "���� ��������: " << listOfCitizens[a - 1].year << endl;
	}
	else if (a == 0) {
		for (; a < current_size; a++) {
			cout << "����� ������: " << a + 1 << endl;
			cout << "���: " << listOfCitizens[a].name << endl;
			cout << "���: (0-male, 1-female) " << listOfCitizens[a].sex << endl;
			cout << "�����: " << listOfCitizens[a].addres << endl;
			cout << "���� ��������: " << listOfCitizens[a].year << endl;
		}
	}
	else
		cout << "����� ������ ���" << endl;

	cout << "������� ��������� ������� ", cin >> choice;
}

void del()
{
	int d;
	cout << "\n����� ������, ������� ���� �������, 0 ��� �������� ���� �������" << endl;  cin >> d;
	if (d != 0)
	{
		for (int de1 = (d - 1); de1 < current_size; de1++)
			listOfCitizens[de1] = listOfCitizens[de1 + 1];
		current_size = current_size - 1;
	}
	if (d == 0)
		for (int i = 0; i < size; i++) {
			listOfCitizens[i] = bad;
			current_size = 0;
		}
	cout << "������� ��������� ������� ", cin >> choice;
}

void find()
{
	int yearr; bool m = true;
	cout << "������� ��� ��������: ", cin >> yearr;
	for (int i = 0; i < size; i++) {
		if (yearr==listOfCitizens[i].year) {
			cout << "���������� � �������� � ���� ��������������" << endl;
			cout << "���: " << listOfCitizens[i].name << endl;
			cout << "�����: " << listOfCitizens[i].addres << endl;
			cout << "���: (0-male, 1-female) " << listOfCitizens[i].sex << endl;
			m = false;
		}
	}
	if (m) cout << "��� �������� � ���� ��������������" << endl;

	cout << "������� ��������� ������� ", cin >> choice;
}