//12
//Записная книжка. Ф.И.О, дата рождения, адрес, телефон, место работы или учебы, должность. Поиск по фамилии.
#include <iostream>  
#include <fstream>
#define STR_LEN 15                               
#define SIZE 2 
using namespace std;

//Прототипы функций
void enter_new();
void del();
void out();
char check_char(char* pointer);
int check_int(int);

enum Sex
{
	male = 1, female, it
};

//Объявление структуры
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

//Меню
int main()
{

	setlocale(LC_CTYPE, "Russian");
	do
	{
		cout << "Введите:" << endl;
		cout << "1-для ввода информации" << endl;
		cout << "2-для удаления информации" << endl;
		cout << "3-для вывода информации" << endl;
		cout << "4-для выхода из программы" << endl;
		cout << "Ваш выбор: ", cin >> choice;
		//Проверка
		check_int(choice);

		switch (choice)
		{
		case 1: enter_new();  break;
		case 2: del();	break;
		case 3:	out();	break;
		case 4: cout << "До скорых встречь!" << endl; exit(0); break;
		default: cout << "Такого пункта меню нет!" << endl;  break;
		}

	} while (choice == choice);
}

//Ввод информации
void enter_new()
{
	int input_date;
	char current_sex[STR_LEN];
	cout << "\nВвод новой информации" << endl;
	if (current_size < SIZE)
	{
		cout << "Номер строки: ";
		cout << current_size + 1;
		cout << "\nВаш пол (male, female, it):" << endl;
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
			cout << "Некорректно введен пол " << endl;
			exit(0);
		}

		cout << "Фамилия:" << endl;
		cin >> list_of_humans[current_size].surname;
		//Проверка
		check_char(list_of_humans[current_size].surname);

		cout << "Имя: " << endl;
		cin >> list_of_humans[current_size].name;
		//Проверка
		check_char(list_of_humans[current_size].name);

		cout << "Телефон:" << endl;
		cin >> list_of_humans[current_size].telnumber;
		//Проверка
		check_int(list_of_humans[current_size].telnumber);

		cout << "Дата рождения: " << endl;

		// День
		cout << "\nДень (от 1 до 31): " << endl;
		cin >> input_date;
		if (input_date > 0 && input_date < 32)
			list_of_humans[current_size].birthdays.day = input_date;
		else
		{
			cout << "Некорректный ввод даты " << endl;
			exit(0);
		}

		// Месяц
		cout << "Месяц (от 1 до 12): " << endl;
		cin >> input_date;
		if (input_date > 0 && input_date < 13)
			list_of_humans[current_size].birthdays.month = input_date;
		else
		{
			cout << "Некорректный ввод даты " << endl;
			exit(0);
		}

		// Год
		cout << "Год (до текущего года (до 2020))" << endl;
		cin >> input_date;
		if (input_date > 0 && input_date < 2021)
			list_of_humans[current_size].birthdays.year = input_date;
		else
		{
			cout << "Некорректный ввод даты " << endl;
			exit(0);
		}
		cout << "Место работы или учебы: " << endl;
		cin >> list_of_humans[current_size].WorkOrStudy;
		//Проверка
		check_char(list_of_humans[current_size].WorkOrStudy);

		cout << "Должность: " << endl;
		cin >> list_of_humans[current_size].post;
		//Проверка
		check_char(list_of_humans[current_size].post);

		current_size++;
	}
	else
		cout << "Введено максимальное кол-во информации";

	cout << "Выберите действие: " << endl;
}

//Удаление информации
void del()
{
	char del_info[STR_LEN];
	cout << "\nВведите фамилию человек, информацию о котором надо удалить (для удаления всей информации введите all): " << endl;
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
				cout << "Информация успешно удалена" << endl;
				break;
			}


		}
	}
	if (strcmp(del_info, "all") == 0)
		for (int i = 0; i < SIZE; i++)
			list_of_humans[i] = rubbish;
	cout << "Что дальше?" << endl;

}

//Вывод информации на консоль
void out()
{
	int ch;
	char output_info[STR_LEN];
	cout << "Введите: " << endl;
	cout << "1-Вывод информации об одном человеке" << endl;
	cout << "2-Вывод информации обо всех" << endl;
	cout << "Ваш выбор: ", cin >> ch;
	switch (ch)
	{
	case 1:

		cout << "\nВведите фамилию" << endl;
		cin >> output_info;
		//Проверка
		check_char(output_info);

		//Вывод
		for (int i = 0; i < current_size; i++)
		{
			if (strcmp(output_info, list_of_humans[i].surname) == 0)
			{
				cout << "\nПол: " << list_of_humans[i].sex << endl;
				cout << "Фамилия: " << list_of_humans[i].surname << endl;
				cout << "Имя: " << list_of_humans[i].name << endl;
				cout << "Телефон: " << list_of_humans[i].telnumber << endl;
				cout << "Дата рождения: " << list_of_humans[i].birthdays.day << "." << list_of_humans[i].birthdays.month << "." << list_of_humans[i].birthdays.year << endl;
				cout << "Место работы или учебы: " << list_of_humans[i].WorkOrStudy << endl;
				cout << "Должность: " << list_of_humans[i].post << endl;
			}
		}
		break;

	case 2:

		//Вывод
		for (int i = 0; i < current_size; i++)
		{

			cout << "\nПол: " << list_of_humans[i].sex << endl;
			cout << "Фамилия: " << list_of_humans[i].surname << endl;
			cout << "Имя: " << list_of_humans[i].name << endl;
			cout << "Телефон: " << list_of_humans[i].telnumber << endl;
			cout << "Дата рождения: " << list_of_humans[i].birthdays.day << "." << list_of_humans[i].birthdays.month << "." << list_of_humans[i].birthdays.year << endl;
			cout << "Место работы или учебы: " << list_of_humans[i].WorkOrStudy << endl;
			cout << "Должность: " << list_of_humans[i].post << endl;

		}
		break;

	default:
		cout << "Такого пункта в меню нет " << endl;
		break;
	}

	cout << "Что дальше?" << endl;

}

char check_char(char* pointer)
{
	for (int i = 0; i < strlen(pointer); i++)
	{
		if (*(pointer + i) < 65 || (*(pointer + i) > 90 && *(pointer + i) < 97) || *(pointer + i) > 122)
		{
			cout << "\nНекорректный ввод" << endl;
			exit(0);
		}
	}


}

int check_int(int check)
{
	if (!cin)
	{
		cout << "Некорректный ввод" << endl;
		exit(0);
	}
}