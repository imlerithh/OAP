//���� �� �������
/*
1)���� ����� ������ ������ �� ����� - ��������� �����
2)���������� ������ �������� �� ���������� ���� � �� ������ �����, �.�. �� ������ ���� ��������
3)����������� ������� ������ ��� ������ � ������� ��� ������ � ������ �������. ���������� ������ ����� � ������� ��������, �� ������ ���� ��� � ���� ���� � ������� ��������
4)���������� size � define ���������� ���������� ���������(�������)
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
# define str_len 16                               
# define size 3  

void enterNew();
void out();
void specialOut();
void outSO(int);

struct Train
{
	int number;
	char destination[str_len];
	int hour, minutes;
};
struct Train listOfTrains[size];
struct Train temp;
int current_size = 0; int choice;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "�������:" << endl;
	cout << "1-��� ����� ������" << endl;
	cout << "2-��� ������ ������" << endl;
	cout << "3-��� ������ ���������� � �������, ������� ���� ����� ���������� �������" << endl;
	cout << "4-��� ������" << endl;
	cin >> choice;
	do
	{
		switch (choice)
		{
		case 1:  enterNew(); break;
		case 2:  out(); break;
		case 3:  specialOut(); break;
		}
	} while (choice != 4);
	return 0;
}

void enterNew()
{
	cout << "���� ����������" << endl;
	int hour, minutes;
	for (; current_size < size;)
	{
		cout << "������ ����� ";
		cout << current_size + 1;
		cout << endl << "����� ������ " << endl;
		cin >> listOfTrains[current_size].number;
		cout << "���������� " << endl;
		cin >> listOfTrains[current_size].destination;
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
			listOfTrains[current_size].hour = hour; listOfTrains[current_size].minutes = minutes;
			break;
		}
		current_size++;
	}
	// ����������
	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
			if (strcmp(listOfTrains[i].destination, listOfTrains[j].destination) > 0)
			{
				temp = listOfTrains[i];
				listOfTrains[i] = listOfTrains[j];
				listOfTrains[j] = temp;
			}
	cout << "������ ������������� �� ��������" << endl;
	cout << "������� ������������ ���-�� �������" << endl;
	cout << "������� ��������� ������� ", cin >> choice;
}

void out()
{
	int a;
	cout << "������� ����� ��������� ������, 0 ��� ������ ���� ������� ", cin >> a;
	if (a > 0 && a <= current_size) {
		cout << "����� ������: " << a << endl;
		cout << "����� ������: " << listOfTrains[a - 1].number << endl;
		cout << "����� ����������: " << listOfTrains[a - 1].destination << endl;
		cout << "����� ����������� " << listOfTrains[a].hour << ":" << listOfTrains[a].minutes << endl;
	}
	else if (a == 0) {
		for (; a < current_size; a++) {
			cout << "����� ������: " << a + 1 << endl;
			cout << "����� ������: " << listOfTrains[a].number << endl;
			cout << "����� ����������: " << listOfTrains[a].destination << endl;
			cout << "����� ����������� " << listOfTrains[a].hour << ":" << listOfTrains[a].minutes << endl;
		}
	}
	else
		cout << "����� ������ ���" << endl;

	cout << "������� ��������� ������� ", cin >> choice;
}

void specialOut() {
	int compare_hour, compare_minutes;
	cout << "������� �����, ����� �������� ����� ����� ������ ������" << endl;
	while (true) {
		cout << "������� ��� ����������� ", cin >> compare_hour;
		if (compare_hour < 0 || compare_hour>24) {
			cout << "������ �����������, ������� �� ��� ���" << endl;
			continue;
		}
		cout << "������� ������ ����������� ", cin >> compare_minutes;
		if (compare_minutes < 0 || compare_minutes>59) {
			cout << "������ �����������, ������� �� ��� ���" << endl;
			continue;
		}
		break;
	}
	bool flag = false;
	for (int i = 0; i < size; i++) {
		if (listOfTrains[i].hour > compare_hour) { outSO(i); flag = true; }
		else if (listOfTrains[i].hour == compare_hour && listOfTrains[i].minutes > compare_minutes) { outSO(i); flag = true; }
		
	}
	if (!flag) {
		cout << "����� ������� ���" << endl;
	}
	cout << "������� ��������� ������� ", cin >> choice;
}
void outSO(int a) {
		cout << "����� ������: " << a+1 << endl;
		cout << "����� ������: " << listOfTrains[a].number << endl;
		cout << "����� ����������: " << listOfTrains[a].destination << endl;
		cout << "����� ����������� " << listOfTrains[a].hour << ":" << listOfTrains[a].minutes << endl << endl;
}