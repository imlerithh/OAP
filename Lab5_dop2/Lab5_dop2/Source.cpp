// 10-2 Горожанин.Фамилия., дата рождения, адрес, пол(м, ж).Реализовать выборку по году рождения
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
	cout << "Введите:" << endl;
	cout << "1-для ввода новой записи" << endl;
	cout << "2-для вывода записей" << endl;
	cout << "3-для удаления записи" << endl;
	cout << "4-для поиска записи по назначению" << endl;
	cout << "5-для выхода" << endl;
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
	cout << "Ввод информации" << endl;
	for (; current_size < size;)
	{
		cout << "Запись номер ";
		cout << current_size + 1;
		cout << endl << "Имя" << endl;
		cin >> listOfCitizens[current_size].name;
		cout << "Адрес " << endl;
		cin >> listOfCitizens[current_size].addres;
		cout << "Пол " << endl; char ffac[str_len];
		cin >> ffac;
		if (strcmp(ffac, "male") == 0) listOfCitizens[current_size].sex = Sex::male;
		else if (strcmp(ffac, "female") == 0) listOfCitizens[current_size].sex = Sex::female;
		else cout << "Данные введены неккоректно" << endl;

		cout << "Дата рождения" << endl;
		cin >> listOfCitizens[current_size].year;

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
		cout << "Имя: " << listOfCitizens[a-1].name << endl;
		cout << "Пол: (0-male, 1-female) " << listOfCitizens[a-1].sex << endl;
		cout << "Специальность: " << listOfCitizens[a-1].addres << endl;
		cout << "Дата рождения: " << listOfCitizens[a - 1].year << endl;
	}
	else if (a == 0) {
		for (; a < current_size; a++) {
			cout << "Номер записи: " << a + 1 << endl;
			cout << "Имя: " << listOfCitizens[a].name << endl;
			cout << "Пол: (0-male, 1-female) " << listOfCitizens[a].sex << endl;
			cout << "Адрес: " << listOfCitizens[a].addres << endl;
			cout << "Дата рождения: " << listOfCitizens[a].year << endl;
		}
	}
	else
		cout << "Такой записи нет" << endl;

	cout << "Введите следующую команду ", cin >> choice;
}

void del()
{
	int d;
	cout << "\nНомер записи, которую надо удалить, 0 для удаления всех записей" << endl;  cin >> d;
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
	cout << "Введите следующую команду ", cin >> choice;
}

void find()
{
	int yearr; bool m = true;
	cout << "Введите год рождения: ", cin >> yearr;
	for (int i = 0; i < size; i++) {
		if (yearr==listOfCitizens[i].year) {
			cout << "Информация о студенте с этой специальностью" << endl;
			cout << "Имя: " << listOfCitizens[i].name << endl;
			cout << "Адрес: " << listOfCitizens[i].addres << endl;
			cout << "Пол: (0-male, 1-female) " << listOfCitizens[i].sex << endl;
			m = false;
		}
	}
	if (m) cout << "Нет студента с этой специальностью" << endl;

	cout << "Введите следующую команду ", cin >> choice;
}