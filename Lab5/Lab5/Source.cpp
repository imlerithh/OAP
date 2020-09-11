//Студенты. Имя, дата поступления, специальность, факультет. Выбор по специальности. 
//Дату поступления реализовать с помощью битового поля, факультет с помощью перечисления.

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
//	cout << "Введите:" << endl;
//	cout << "1-для ввода новой записи" << endl;
//	cout << "2-для вывода записей" << endl;
//	cout << "3-для удаления записи" << endl;
//	cout << "4-для поиска записи по назначению" << endl;
//	cout << "5-для выхода" << endl;
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
//	cout << "Ввод информации" << endl;
//	for (; current_size < size;)
//	{
//		cout << "Запись номер ";
//		cout << current_size + 1;
//		cout << endl << "Имя студента " << endl;
//		cin >> listOfStudents[current_size].name;
//		cout << "Специальность " << endl;
//		cin >> listOfStudents[current_size].speciality;
//		cout << "Факультет " << endl; char ffac[str_len];
//		cin >> ffac;
//		if (strcmp(ffac, "IT") == 0) listOfStudents[current_size].fac = Faculty::IT;
//		else if (strcmp(ffac, "HTIT") == 0) listOfStudents[current_size].fac = Faculty::HTIT;
//		else if (strcmp(ffac, "TOV") == 0) listOfStudents[current_size].fac = Faculty::TOV;
//		else cout << "Данные введены неккоректно" << endl;
//
//		cout << "Дата поступления" << endl;
//		int input_date;
//		cout << "День" << endl;
//			cout << "День(от 1 до 31)" << endl;
//		cin >> input_date;
//		if (input_date > 0 && input_date < 32)
//			listOfStudents[current_size].date.day = input_date;
//		else
//		{
//			cout << "Некорректный ввод даты"  << endl;
//			exit(0);
//		}
//
//		cout << "Месяц" << endl;
//		cout << "Месяц(от 1 до 12)" << endl;
//		cin >> input_date;
//		if (input_date > 0 && input_date < 13)
//			listOfStudents[current_size].date.month = input_date;
//		else
//		{
//			cout << "Некорректный ввод даты" << endl;
//			exit(0);
//		}
//
//			cout << "Год" << endl;
//		cout << "Год(до 2020)" << endl;
//		cin >> input_date;
//		if (input_date > 0 && input_date < 2021)
//			listOfStudents[current_size].date.year = input_date;
//		else
//		{
//			cout << "Некорректный ввод даты" << endl;
//			exit(0);
//		}
//		current_size++;
//	}
//	cout << "Введено максимальное кол-во записей" << endl;
//	cout << "Введите следующую команду ", cin >> choice;
//}
//
//void out()
//{
//	int a;
//	cout << "Введите номер выводимой записи, 0 для вывода всех записей ", cin >> a;
//	if (a > 0 && a <= current_size) {
//		cout << "Номер записи: " << a << endl;
//		cout << "Имя: " << listOfStudents[a-1].name << endl;
//		cout << "Факультет: (0-ИТ, 1-ХТИТ, 2-ТОВ) " << listOfStudents[a-1].fac << endl;
//		cout << "Специальность: " << listOfStudents[a-1].speciality << endl;
//		cout << "Дата поступления: " << listOfStudents[a-1].date.day << '.' << listOfStudents[a-1].date.month << "." << listOfStudents[a-1].date.year << endl;
//	}
//	else if (a == 0) {
//		for (; a < current_size; a++) {
//			cout << "Номер записи: " << a + 1 << endl;
//			cout << "Имя: " << listOfStudents[a].name << endl;
//			cout << "Факультет: (0-ИТ, 1-ХТИТ, 2-ТОВ) " << listOfStudents[a].fac << endl;
//			cout << "Специальность: " << listOfStudents[a].speciality << endl;
//			cout << "Дата поступления: " << listOfStudents[a].date.day << '.' << listOfStudents[a].date.month << "." << listOfStudents[a].date.year << endl;
//		}
//	}
//	else
//		cout << "Такой записи нет" << endl;
//
//	cout << "Введите следующую команду ", cin >> choice;
//}
//
//void del()
//{
//	int d;
//	cout << "\nНомер записи, которую надо удалить, 0 для удаления всех записей" << endl;  cin >> d;
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
//	cout << "Введите следующую команду ", cin >> choice;
//}
//
//void find()
//{
//	char specc[str_len]; bool m = true;
//	cout << "Введите специальность: ", cin >> specc;
//	for (int i = 0; i < size; i++) {
//		if (strcmp(specc, listOfStudents[i].speciality) == 0) {
//			cout << "Информация о студенте с этой специальностью" << endl;
//			cout << "Имя: " << listOfStudents[i].name << endl;
//			cout << "Факультет: (0-ИТ, 1-ХТИТ, 2-ТОВ) " << listOfStudents[i].fac << endl;
//			cout << "Дата поступления: " << listOfStudents[i].date.day << '.' << listOfStudents[i].date.month << "." << listOfStudents[i].date.year << endl;
//			m = false;
//		}
//	}
//	if (m) cout << "Нет студента с этой специальностью" << endl;
//
//	cout << "Введите следующую команду ", cin >> choice;
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
	cout << "Введите:" << endl;
	cout << "1-для ввода новой записи" << endl;
	cout << "2-для вывода записей" << endl;
	cout << "3-для поиска записи по назначению" << endl;
	cout << "4-для выхода" << endl;
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
	cout << "Ввод информации" << endl;
	for (; current_size < size;)
	{
		cout << "Запись номер ";
		cout << current_size + 1;
		cout << endl << "Название страны " << endl;
		cin >> listOfCountrys[current_size].name;
		cout << "Столица " << endl;
		cin >> listOfCountrys[current_size].capital;
		cout << "Президент " << endl;
		cin >> listOfCountrys[current_size].president;
		cout << "Площадь " << endl;
		cin >> u.square;
		listOfCountrys[current_size].square = u.square;
		cout << "Население " << endl;
		cin >> u.population;
		listOfCountrys[current_size].population = u.population;

		current_size++;
	}
	cout << "Введено максимальное кол-во записей" << endl;
	cout << "Введите следующую команду ", cin >> choice;
}

void out()
{
	int a;
	cout << "Введите номер выводимой записи, 0 для вывода всех записей ", cin >> a;
	if (a > 0 && a <= current_size) {
		cout << "Номер записи: " << a << endl;
		cout << "Название страны: " << listOfCountrys[a - 1].name << endl;
		cout << "Столица: " << listOfCountrys[a - 1].capital << endl;
		cout << "Президент: " << listOfCountrys[a - 1].president << endl;
		cout << "Площадь: " << listOfCountrys[a - 1].square << endl;
		cout << "Население: " << listOfCountrys[a - 1].population << " mln" << endl;
	}
	else if (a == 0) {
		for (; a < current_size; a++) {
			cout << "Номер записи: " << a + 1 << endl;
			cout << "Название страны: " << listOfCountrys[a].name << endl;
			cout << "Столица: " << listOfCountrys[a].capital << endl;
			cout << "Президент: " << listOfCountrys[a].president << endl;
			cout << "Площадь: " << listOfCountrys[a].square << endl;
			cout << "Население: " << listOfCountrys[a].population << " mln" << endl;
		}
	}
	else
		cout << "Такой записи нет" << endl;

	cout << "Введите следующую команду ", cin >> choice;
}

void find()
{
	char namee[str_len]; bool m = true;
	cout << "Введите название страны: ", cin >> namee;
	for (int i = 0; i < size; i++) {
		if (strcmp(namee, listOfCountrys[i].name) == 0) {
			cout << "Информация о стране с этим названием" << endl;
			cout << "Название страны: " << listOfCountrys[i].name << endl;
			cout << "Столица: " << listOfCountrys[i].capital << endl;
			cout << "Президент: " << listOfCountrys[i].president << endl;
			cout << "Площадь: " << listOfCountrys[i].square << endl;
			cout << "Население: " << listOfCountrys[i].population << endl;
			m = false;
		}
	}
	if (m) cout << "Нет стран с таким названием" << endl;

	cout << "Введите следующую команду ", cin >> choice;
}