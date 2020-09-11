// ������. ����� ������, ����� ����������, ����� ��������, ����� �����������.����� �� ������ ����������.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
# define str_len 16                               
# define size 2 

void enterNew();
void out();
void del();
void find();
void fileOut();

struct Train
{
	int number;
	char destination[str_len];
	string arrivalTime;
	string departureTime;
};
struct Train listOfTrains[size];
struct Train bad;
int current_size = 0; int choice;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "�������:" << endl;
	cout << "1-��� ����� ����� ������" << endl;
	cout << "2-��� ������ �������" << endl;
	cout << "3-��� �������� ������" << endl;
	cout << "4-��� ������ ������ �� ����������" << endl;
	cout << "5-��� ������ � ����" << endl;
	cout << "6-��� ������" << endl;
	cin >> choice;
	do
	{
		switch (choice)
		{
		case 1:  enterNew(); break;
		case 2:  out(); break;
		case 3:  del(); break;
		case 4:  find();  break;
		case 5:  fileOut(); break;
		}
	} while (choice != 6);
	return 0;
}

void enterNew()
{
	cout << "���� ����������" << endl;
	int hour, minutes;
	for (;current_size < size;)
	{
		cout << "������ ����� ";
		cout << current_size + 1;
		cout << endl << "����� ������ " << endl;
		cin >> listOfTrains[current_size].number;
		cout << "���������� " << endl;
		cin >> listOfTrains[current_size].destination;
		while (true) {
			cout << "������� ��� �������� ", cin >> hour;
			if (hour < 0 || hour>24) {
				cout << "������ �����������, ������� �� ��� ���" << endl;
				continue;
			}
			cout << "������� ������ �������� ", cin >> minutes;
			if (minutes < 0 || minutes>59) {
				cout << "������ �����������, ������� �� ��� ���" << endl;
				continue;
			}
			listOfTrains[current_size].arrivalTime = to_string(hour) + ":" + to_string(minutes);
			break;
		}
		while (true) {
			cout << "������� ��� ����������� ", cin >> hour;
			if (hour < 0 || hour>24) {
				cout << "������ �����������, ������� �� ��� ���" << endl;
				continue;
			}
			cout << "������� ������ ����������� ", cin >> minutes;
			if (minutes < 0 || minutes>59) {
				cout << "������ �����������, ������� �� ��� ���" << endl;
				continue;
			}
			listOfTrains[current_size].departureTime = to_string(hour) + ":" + to_string(minutes);
			break;
		}

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
		cout << "����� ������: " << listOfTrains[a-1].number << endl;
		cout << "����� ����������: " << listOfTrains[a-1].destination << endl;
		cout << "����� ��������: " << listOfTrains[a-1].arrivalTime << endl;
		cout << "����� ����������� " << listOfTrains[a-1].departureTime << endl << endl;
	}
	else if (a == 0) {
		for (; a < current_size; a++) {
			cout << "����� ������: " << a + 1 << endl;
			cout << "����� ������: " << listOfTrains[a].number << endl;
			cout << "����� ����������: " << listOfTrains[a].destination << endl;
			cout << "����� ��������: " << listOfTrains[a].arrivalTime << endl;
			cout << "����� ����������� " << listOfTrains[a].departureTime << endl;
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
			listOfTrains[de1] = listOfTrains[de1 + 1];
		current_size = current_size - 1;
	}
	if (d == 0)
		for (int i = 0; i < size; i++) {
			listOfTrains[i] = bad;
			current_size = 0;
		}
	cout << "������� ��������� ������� ", cin >> choice;
}

void find()
{
	char dest[str_len]; bool m = true;
	cout << "������� ����� ����������: ", cin >> dest;
	for (int i = 0; i < size; i++) {
		if (strcmp(dest, listOfTrains[i].destination) == 0) {
			cout << "���������� � ������, ������� ���� � ��� ����� " << endl;
			cout << "����� ������: " << listOfTrains[i].number << endl;
			cout << "����� ��������: " << listOfTrains[i].arrivalTime << endl;
			cout << "����� �����������: " << listOfTrains[i].departureTime << endl;
			m = false;
		}
	}
	if (m) cout << "��� ����������� �������" << endl;

	cout << "������� ��������� ������� ", cin >> choice;
}

void fileOut() {
	ofstream fout;
	fout.open("File.txt");
	if (!fout.is_open())
	{
		cout << "File couldn't be open" << endl;
	}
	else {
		cout << "������� ������ � ������" << endl;
		cout << "��������� ���������� � ���� ������� � ����" << endl;
		for (int i = 0; i < current_size; i++) {
			fout << "����� ������: " << i+1 << endl;
			fout << "����� ������: " << listOfTrains[i].number << endl;
			fout << "����� ����������: " << listOfTrains[i].destination << endl;
			fout << "����� ��������: " << listOfTrains[i].arrivalTime << endl;
			fout << "����� ����������� " << listOfTrains[i].departureTime << endl << endl;
		}
		cout << "������ �������� � ����" << endl;
	}
	fout.close();

	cout << "������� ��������� ������� ", cin >> choice;
}