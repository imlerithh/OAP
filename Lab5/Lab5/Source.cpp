//��������. ���, ���� �����������, �������������, ���������. ����� �� �������������. 
//���� ����������� ����������� � ������� �������� ����, ��������� � ������� ������������.

//#include <iostream>
//#include <string>
//using namespace std;
//# define str_len 16                               
//# define size 2 
//
//void enterNew();
//void out();
//void del();
//void find();
//
//enum Faculty {
//	IT,
//	HTIT,
//	TOV 
//};
//
//struct date {
//	int day : 5;
//	int month : 4;
//	int year : 15;
//};
//
//struct Student
//{
//	char speciality[str_len];
//	char name[str_len];
//	Faculty fac;
//	date date;
//};
//struct Student listOfStudents[size];
//struct Student bad;
//int current_size = 0; int choice;
//int main()
//{
//	setlocale(LC_CTYPE, "Russian");
//	cout << "�������:" << endl;
//	cout << "1-��� ����� ����� ������" << endl;
//	cout << "2-��� ������ �������" << endl;
//	cout << "3-��� �������� ������" << endl;
//	cout << "4-��� ������ ������ �� ����������" << endl;
//	cout << "5-��� ������" << endl;
//	cin >> choice;
//	do
//	{
//		switch (choice)
//		{
//		case 1:  enterNew(); break;
//		case 2:  out(); break;
//		case 3:  del(); break;
//		case 4:  find();  break;
//		}
//	} while (choice != 5);
//	return 0;
//}
//
//void enterNew()
//{
//	cout << "���� ����������" << endl;
//	for (; current_size < size;)
//	{
//		cout << "������ ����� ";
//		cout << current_size + 1;
//		cout << endl << "��� �������� " << endl;
//		cin >> listOfStudents[current_size].name;
//		cout << "������������� " << endl;
//		cin >> listOfStudents[current_size].speciality;
//		cout << "��������� " << endl; char ffac[str_len];
//		cin >> ffac;
//		if (strcmp(ffac, "IT") == 0) listOfStudents[current_size].fac = Faculty::IT;
//		else if (strcmp(ffac, "HTIT") == 0) listOfStudents[current_size].fac = Faculty::HTIT;
//		else if (strcmp(ffac, "TOV") == 0) listOfStudents[current_size].fac = Faculty::TOV;
//		else cout << "������ ������� �����������" << endl;
//
//		cout << "���� �����������" << endl;
//		int input_date;
//		cout << "����" << endl;
//			cout << "����(�� 1 �� 31)" << endl;
//		cin >> input_date;
//		if (input_date > 0 && input_date < 32)
//			listOfStudents[current_size].date.day = input_date;
//		else
//		{
//			cout << "������������ ���� ����"  << endl;
//			exit(0);
//		}
//
//		cout << "�����" << endl;
//		cout << "�����(�� 1 �� 12)" << endl;
//		cin >> input_date;
//		if (input_date > 0 && input_date < 13)
//			listOfStudents[current_size].date.month = input_date;
//		else
//		{
//			cout << "������������ ���� ����" << endl;
//			exit(0);
//		}
//
//			cout << "���" << endl;
//		cout << "���(�� 2020)" << endl;
//		cin >> input_date;
//		if (input_date > 0 && input_date < 2021)
//			listOfStudents[current_size].date.year = input_date;
//		else
//		{
//			cout << "������������ ���� ����" << endl;
//			exit(0);
//		}
//		current_size++;
//	}
//	cout << "������� ������������ ���-�� �������" << endl;
//	cout << "������� ��������� ������� ", cin >> choice;
//}
//
//void out()
//{
//	int a;
//	cout << "������� ����� ��������� ������, 0 ��� ������ ���� ������� ", cin >> a;
//	if (a > 0 && a <= current_size) {
//		cout << "����� ������: " << a << endl;
//		cout << "���: " << listOfStudents[a-1].name << endl;
//		cout << "���������: (0-��, 1-����, 2-���) " << listOfStudents[a-1].fac << endl;
//		cout << "�������������: " << listOfStudents[a-1].speciality << endl;
//		cout << "���� �����������: " << listOfStudents[a-1].date.day << '.' << listOfStudents[a-1].date.month << "." << listOfStudents[a-1].date.year << endl;
//	}
//	else if (a == 0) {
//		for (; a < current_size; a++) {
//			cout << "����� ������: " << a + 1 << endl;
//			cout << "���: " << listOfStudents[a].name << endl;
//			cout << "���������: (0-��, 1-����, 2-���) " << listOfStudents[a].fac << endl;
//			cout << "�������������: " << listOfStudents[a].speciality << endl;
//			cout << "���� �����������: " << listOfStudents[a].date.day << '.' << listOfStudents[a].date.month << "." << listOfStudents[a].date.year << endl;
//		}
//	}
//	else
//		cout << "����� ������ ���" << endl;
//
//	cout << "������� ��������� ������� ", cin >> choice;
//}
//
//void del()
//{
//	int d;
//	cout << "\n����� ������, ������� ���� �������, 0 ��� �������� ���� �������" << endl;  cin >> d;
//	if (d != 0)
//	{
//		for (int de1 = (d - 1); de1 < current_size; de1++)
//			listOfStudents[de1] = listOfStudents[de1 + 1];
//		current_size = current_size - 1;
//	}
//	if (d == 0)
//		for (int i = 0; i < size; i++) {
//			listOfStudents[i] = bad;
//			current_size = 0;
//		}
//	cout << "������� ��������� ������� ", cin >> choice;
//}
//
//void find()
//{
//	char specc[str_len]; bool m = true;
//	cout << "������� �������������: ", cin >> specc;
//	for (int i = 0; i < size; i++) {
//		if (strcmp(specc, listOfStudents[i].speciality) == 0) {
//			cout << "���������� � �������� � ���� ��������������" << endl;
//			cout << "���: " << listOfStudents[i].name << endl;
//			cout << "���������: (0-��, 1-����, 2-���) " << listOfStudents[i].fac << endl;
//			cout << "���� �����������: " << listOfStudents[i].date.day << '.' << listOfStudents[i].date.month << "." << listOfStudents[i].date.year << endl;
//			m = false;
//		}
//	}
//	if (m) cout << "��� �������� � ���� ��������������" << endl;
//
//	cout << "������� ��������� ������� ", cin >> choice;
//}


#include <iostream>
#include <string>
using namespace std;
# define str_len 16                               
# define size 2 

void enterNew();
void out();
void find();

union fCountry
{
	float population;
	int square;
}u;

struct Country
{
	float population;
	char capital[str_len];
	char name[str_len];
	char president[str_len];
	int square;
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
		cout << "��������� " << endl;
		cin >> listOfCountrys[current_size].president;
		cout << "������� " << endl;
		cin >> u.square;
		listOfCountrys[current_size].square = u.square;
		cout << "��������� " << endl;
		cin >> u.population;
		listOfCountrys[current_size].population = u.population;

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
		cout << "���������: " << listOfCountrys[a - 1].president << endl;
		cout << "�������: " << listOfCountrys[a - 1].square << endl;
		cout << "���������: " << listOfCountrys[a - 1].population << " mln" << endl;
	}
	else if (a == 0) {
		for (; a < current_size; a++) {
			cout << "����� ������: " << a + 1 << endl;
			cout << "�������� ������: " << listOfCountrys[a].name << endl;
			cout << "�������: " << listOfCountrys[a].capital << endl;
			cout << "���������: " << listOfCountrys[a].president << endl;
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
	char namee[str_len]; bool m = true;
	cout << "������� �������� ������: ", cin >> namee;
	for (int i = 0; i < size; i++) {
		if (strcmp(namee, listOfCountrys[i].name) == 0) {
			cout << "���������� � ������ � ���� ���������" << endl;
			cout << "�������� ������: " << listOfCountrys[i].name << endl;
			cout << "�������: " << listOfCountrys[i].capital << endl;
			cout << "���������: " << listOfCountrys[i].president << endl;
			cout << "�������: " << listOfCountrys[i].square << endl;
			cout << "���������: " << listOfCountrys[i].population << endl;
			m = false;
		}
	}
	if (m) cout << "��� ����� � ����� ���������" << endl;

	cout << "������� ��������� ������� ", cin >> choice;
}