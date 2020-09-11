//12
//�������� ������. �.�.�, ���� ��������, �����, �������, ����� ������ ��� �����, ���������. ����� �� �������.
#include <iostream>  
#include <fstream>
#define STR_LEN 15                               
#define SIZE 2 
using namespace std;

//��������� �������
void enter_new();
void del();
void out();
char check_char(char* pointer);
int check_int(int);

enum Sex
{
	male = 1, female, it
};

//���������� ���������
struct Date
{
	int day : 6;
	int month : 5;
	int year : 12;
};

struct Notepad
{
	Sex sex;
	char name[STR_LEN];
	char surname[STR_LEN];
	int  telnumber;
	Date birthdays;
	char WorkOrStudy[STR_LEN];
	char post[STR_LEN];

};
struct Notepad list_of_humans[SIZE];
struct Notepad rubbish;
int current_size = 0; int choice;

//����
int main()
{

	setlocale(LC_CTYPE, "Russian");
	do
	{
		cout << "�������:" << endl;
		cout << "1-��� ����� ����������" << endl;
		cout << "2-��� �������� ����������" << endl;
		cout << "3-��� ������ ����������" << endl;
		cout << "4-��� ������ �� ���������" << endl;
		cout << "��� �����: ", cin >> choice;
		//��������
		check_int(choice);

		switch (choice)
		{
		case 1: enter_new();  break;
		case 2: del();	break;
		case 3:	out();	break;
		case 4: cout << "�� ������ �������!" << endl; exit(0); break;
		default: cout << "������ ������ ���� ���!" << endl;  break;
		}

	} while (choice == choice);
}

//���� ����������
void enter_new()
{
	int input_date;
	char current_sex[STR_LEN];
	cout << "\n���� ����� ����������" << endl;
	if (current_size < SIZE)
	{
		cout << "����� ������: ";
		cout << current_size + 1;
		cout << "\n��� ��� (male, female, it):" << endl;
		cin >> current_sex;
		if (strcmp(current_sex, "male") == 0)
		{
			list_of_humans[current_size].sex = Sex::male;
		}
		else if (strcmp(current_sex, "female") == 0)
		{
			list_of_humans[current_size].sex = Sex::female;
		}
		else if (strcmp(current_sex, "it") == 0)
		{
			list_of_humans[current_size].sex = Sex::it;
		}
		else
		{
			cout << "����������� ������ ��� " << endl;
			exit(0);
		}

		cout << "�������:" << endl;
		cin >> list_of_humans[current_size].surname;
		//��������
		check_char(list_of_humans[current_size].surname);

		cout << "���: " << endl;
		cin >> list_of_humans[current_size].name;
		//��������
		check_char(list_of_humans[current_size].name);

		cout << "�������:" << endl;
		cin >> list_of_humans[current_size].telnumber;
		//��������
		check_int(list_of_humans[current_size].telnumber);

		cout << "���� ��������: " << endl;

		// ����
		cout << "\n���� (�� 1 �� 31): " << endl;
		cin >> input_date;
		if (input_date > 0 && input_date < 32)
			list_of_humans[current_size].birthdays.day = input_date;
		else
		{
			cout << "������������ ���� ���� " << endl;
			exit(0);
		}

		// �����
		cout << "����� (�� 1 �� 12): " << endl;
		cin >> input_date;
		if (input_date > 0 && input_date < 13)
			list_of_humans[current_size].birthdays.month = input_date;
		else
		{
			cout << "������������ ���� ���� " << endl;
			exit(0);
		}

		// ���
		cout << "��� (�� �������� ���� (�� 2020))" << endl;
		cin >> input_date;
		if (input_date > 0 && input_date < 2021)
			list_of_humans[current_size].birthdays.year = input_date;
		else
		{
			cout << "������������ ���� ���� " << endl;
			exit(0);
		}
		cout << "����� ������ ��� �����: " << endl;
		cin >> list_of_humans[current_size].WorkOrStudy;
		//��������
		check_char(list_of_humans[current_size].WorkOrStudy);

		cout << "���������: " << endl;
		cin >> list_of_humans[current_size].post;
		//��������
		check_char(list_of_humans[current_size].post);

		current_size++;
	}
	else
		cout << "������� ������������ ���-�� ����������";

	cout << "�������� ��������: " << endl;
}

//�������� ����������
void del()
{
	char del_info[STR_LEN];
	cout << "\n������� ������� �������, ���������� � ������� ���� ������� (��� �������� ���� ���������� ������� all): " << endl;
	cin >> del_info;
	if (strcmp(del_info, "all") != 0)
	{
		for (int i = 0; i < current_size; i++)
		{
			if (strcmp(del_info, list_of_humans[i].surname) == 0)
			{
				for (int j = i; j < current_size; j++)
				{
					list_of_humans[j] = list_of_humans[j + 1];
					current_size = current_size - 1;
				}
				cout << "���������� ������� �������" << endl;
				break;
			}


		}
	}
	if (strcmp(del_info, "all") == 0)
		for (int i = 0; i < SIZE; i++)
			list_of_humans[i] = rubbish;
	cout << "��� ������?" << endl;

}

//����� ���������� �� �������
void out()
{
	int ch;
	char output_info[STR_LEN];
	cout << "�������: " << endl;
	cout << "1-����� ���������� �� ����� ��������" << endl;
	cout << "2-����� ���������� ��� ����" << endl;
	cout << "��� �����: ", cin >> ch;
	switch (ch)
	{
	case 1:

		cout << "\n������� �������" << endl;
		cin >> output_info;
		//��������
		check_char(output_info);

		//�����
		for (int i = 0; i < current_size; i++)
		{
			if (strcmp(output_info, list_of_humans[i].surname) == 0)
			{
				cout << "\n���: " << list_of_humans[i].sex << endl;
				cout << "�������: " << list_of_humans[i].surname << endl;
				cout << "���: " << list_of_humans[i].name << endl;
				cout << "�������: " << list_of_humans[i].telnumber << endl;
				cout << "���� ��������: " << list_of_humans[i].birthdays.day << "." << list_of_humans[i].birthdays.month << "." << list_of_humans[i].birthdays.year << endl;
				cout << "����� ������ ��� �����: " << list_of_humans[i].WorkOrStudy << endl;
				cout << "���������: " << list_of_humans[i].post << endl;
			}
		}
		break;

	case 2:

		//�����
		for (int i = 0; i < current_size; i++)
		{

			cout << "\n���: " << list_of_humans[i].sex << endl;
			cout << "�������: " << list_of_humans[i].surname << endl;
			cout << "���: " << list_of_humans[i].name << endl;
			cout << "�������: " << list_of_humans[i].telnumber << endl;
			cout << "���� ��������: " << list_of_humans[i].birthdays.day << "." << list_of_humans[i].birthdays.month << "." << list_of_humans[i].birthdays.year << endl;
			cout << "����� ������ ��� �����: " << list_of_humans[i].WorkOrStudy << endl;
			cout << "���������: " << list_of_humans[i].post << endl;

		}
		break;

	default:
		cout << "������ ������ � ���� ��� " << endl;
		break;
	}

	cout << "��� ������?" << endl;

}

char check_char(char* pointer)
{
	for (int i = 0; i < strlen(pointer); i++)
	{
		if (*(pointer + i) < 65 || (*(pointer + i) > 90 && *(pointer + i) < 97) || *(pointer + i) > 122)
		{
			cout << "\n������������ ����" << endl;
			exit(0);
		}
	}


}

int check_int(int check)
{
	if (!cin)
	{
		cout << "������������ ����" << endl;
		exit(0);
	}
}