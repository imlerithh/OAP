#include <iostream>  
#include <fstream>
#define LENGTH 15
#define QUALITY 30
#define EXAM 5
using namespace std;

//��������� �������
void enter_student();
void compare();
void output();
char check_char(char* pointer);
int check_int(int);

//���������� ���������
struct Students
{
	char surname[LENGTH];
	char firstname[LENGTH];
	int exams=EXAM;
	int marks[EXAM];
};
struct Students results[QUALITY];
struct Students the_best_students[QUALITY];
int current_quality = 0;
int current_best=0;

int main()
{
	setlocale(LC_CTYPE, "ru");
	int choice;
	enter_student();
	compare();

	cout << "������� ���������� ���������? (��������: 1 - ��, 2 - ���)" << endl;
	cin >> choice;
	//��������
	check_int(choice);
	if (choice == 1)
		output();
	else
		cout << "Goodbye!" << endl;

	getchar();
	return 0;
}


//���� ����������
void enter_student()
{
	int extend;
	
		if (current_quality < QUALITY)
		{
			cout << "������� ������� ��������:" << endl;
			cin >> results[current_quality].surname;
			//��������
			check_char(results[current_quality].surname);

			cout << "������� ��� ��������:" << endl;
			cin >> results[current_quality].firstname;
			//��������
			check_char(results[current_quality].firstname);

			cout << "������� ������ �� ��������(�� 5-� ������� �������):" << endl;
			for (int i = 0; i < results[current_quality].exams; i++)
			{
				cout << "������ �� " << i + 1 << "-� �������" << endl;
				cin >> results[current_quality].marks[i];
				//��������
				check_int(results[current_quality].marks[i]);
			}
		}
		else
			cout << "������������ ���������� ���������." << endl;
		
		cout << "������ �������" << endl;
		current_quality++;
		for (;;)
		{
			cout << "\n������ �������� ��� ������ ��������?(�������: 1 - ��, 2 - ���)" << endl;
			cin >> extend;
			if (extend == 2)
				break;
			else if (extend == 1)
			{
				enter_student();
				break;
			}
			else
			{
				cout << "������ �������� ���" << endl;
				exit(0);
			}
		}

}

//��������� �����������
void compare()
{
	int counter = 0;
	for (int i = 0; i < current_quality; i++)
	{
		for (int j = 0; j < results[i].exams; j++)
		{
			if (results[i].marks[j] >= 4)
			{
				counter++;
			}

			if (counter == results[i].exams)
			{
				the_best_students[current_best] = results[i];
				current_best++;
			}
		}
		counter = 0;
	}
	float result_compare = ((float)current_best / (float)current_quality) * 100;
	cout << "��������� ����� ���������, ������� �������� �� 4 � 5, � ������ ����� ���������: " << result_compare << "%" << endl;

}

//����� ���������� �� �������
void output()
{
	int ch;
	cout <<"\n�������: " << endl;
	cout << "1-����� ���� ���������" << endl;
	cout << "2-����� ������ ���������" << endl;
	cout << "��� �����: ", cin >> ch;
	switch (ch)
	{
	case 1:

		for (int i = 0; i < current_quality; i++)
		{
			cout << "�������: " << results[i].surname << endl;
			cout << "���: " << results[i].firstname << endl;
			cout << "���������� ���������: " << results[i].exams << endl;
			for (int j = 0; j < results[i].exams; j++)
			{
				cout << "������ �� " << j + 1 << "-� �������: " << results[i].marks[j] <<endl;		
			}
		}
		cout << endl;
		break;

	case 2:

		for (int i = 0; i < current_best; i++)
		{
			cout << "�������: " << the_best_students[i].surname << endl;
			cout << "���: " << the_best_students[i].firstname << endl;
			cout << "���������� ���������: " << the_best_students[i].exams << endl;
			for (int j = 0; j < the_best_students[i].exams; j++)
			{
				cout << "������ �� " << j + 1 << "-� �������: " << the_best_students[i].marks[j] <<endl;		
			}
		}
		cout << endl;
		break;

	default:
		cout << "������ ������ ��� " << endl;
		break;
	}
	cout << "\n�� ������ �������" << endl;
}


//������� � ����������

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
	if (!cin || check>5)
	{
		cout << "������������ ����" << endl;
		exit(0);
	}
}


