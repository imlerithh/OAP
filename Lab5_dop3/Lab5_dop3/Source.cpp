//10-1
//�����������.������������, �������, ����������� ���������, �������.����� ����������� �� ���������� �������(> ��������� ��������).
//����� ��������� ����������� � ������� ������������.
#include <iostream>
#include <string>
using namespace std;
# define str_len 16                               
# define size 2 

void enterNew();
void out();
void find();

enum Form
{
	democracy, tirany
};

struct Country
{
	float population;
	char capital[str_len];
	char name[str_len];
	int square;
	Form form;
};
struct Country listOfCountrys[size];
struct Country bad;
int current_size = 0; int choice;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "�������:" << endl;
	cout << "1-��� ����� ����� ������" << endl;
	cout << "2-��� ������ �������" << endl;
	cout << "3-��� ������ ������ �� ����������" << endl;
	cout << "4-��� ������" << endl;
	cin >> choice;
	do
	{
		switch (choice)
		{
		case 1:  enterNew(); break;
		case 2:  out(); break;
		case 3:  find();  break;
		}
	} while (choice != 4);
	return 0;
}

void enterNew()
{
	cout << "���� ����������" << endl;
	for (; current_size < size;)
	{
		cout << "������ ����� ";
		cout << current_size + 1;
		cout << endl << "�������� ������ " << endl;
		cin >> listOfCountrys[current_size].name;
		cout << "������� " << endl;
		cin >> listOfCountrys[current_size].capital;
		cout << "������� " << endl;
		cin >> listOfCountrys[current_size].square;
		cout << "��������� " << endl;
		cin >> listOfCountrys[current_size].population;
		cout << "����� ��������� " << endl; char ffac[str_len];
		cin >> ffac;
		if (strcmp(ffac, "democracy") == 0) listOfCountrys[current_size].form = Form::democracy;
		else if (strcmp(ffac, "tirany") == 0) listOfCountrys[current_size].form = Form::tirany;
		else cout << "������ ������� �����������" << endl;

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
		cout << "�������� ������: " << listOfCountrys[a - 1].name << endl;
		cout << "�������: " << listOfCountrys[a - 1].capital << endl;
		cout << "�������: " << listOfCountrys[a - 1].square << endl;
		cout << "���������: " << listOfCountrys[a - 1].population << " mln" << endl;
	}
	else if (a == 0) {
		for (; a < current_size; a++) {
			cout << "����� ������: " << a + 1 << endl;
			cout << "�������� ������: " << listOfCountrys[a].name << endl;
			cout << "�������: " << listOfCountrys[a].capital << endl;
			cout << "�������: " << listOfCountrys[a].square << endl;
			cout << "���������: " << listOfCountrys[a].population << " mln" << endl;
		}
	}
	else
		cout << "����� ������ ���" << endl;

	cout << "������� ��������� ������� ", cin >> choice;
}

void find()
{
	float squaree; bool m = true;
	cout << "������� ������� ������: ", cin >> squaree;
	for (int i = 0; i < size; i++) {
		if (squaree < listOfCountrys[i].square) {
			cout << "���������� � ������ c ������� ��������" << endl;
			cout << "�������� ������: " << listOfCountrys[i].name << endl;
			cout << "�������: " << listOfCountrys[i].capital << endl;
			cout << "���������: " << listOfCountrys[i].population << endl;
			m = false;
		}
	}
	if (m) cout << "��� ����� � ����� ���������" << endl;

	cout << "������� ��������� ������� ", cin >> choice;
}
