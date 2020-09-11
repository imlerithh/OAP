//10-1
//Государство.Наименование, столица, численность населения, площадь.Выбор государства по занимаемой площади(> заданного значения).
//Форму правления реализовать с помощью перечисления.
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
		cout << "Площадь " << endl;
		cin >> listOfCountrys[current_size].square;
		cout << "Население " << endl;
		cin >> listOfCountrys[current_size].population;
		cout << "Форма правления " << endl; char ffac[str_len];
		cin >> ffac;
		if (strcmp(ffac, "democracy") == 0) listOfCountrys[current_size].form = Form::democracy;
		else if (strcmp(ffac, "tirany") == 0) listOfCountrys[current_size].form = Form::tirany;
		else cout << "Данные введены неккоректно" << endl;

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
		cout << "Площадь: " << listOfCountrys[a - 1].square << endl;
		cout << "Население: " << listOfCountrys[a - 1].population << " mln" << endl;
	}
	else if (a == 0) {
		for (; a < current_size; a++) {
			cout << "Номер записи: " << a + 1 << endl;
			cout << "Название страны: " << listOfCountrys[a].name << endl;
			cout << "Столица: " << listOfCountrys[a].capital << endl;
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
	float squaree; bool m = true;
	cout << "Введите площадь страны: ", cin >> squaree;
	for (int i = 0; i < size; i++) {
		if (squaree < listOfCountrys[i].square) {
			cout << "Информация о стране c большей площадью" << endl;
			cout << "Название страны: " << listOfCountrys[i].name << endl;
			cout << "Столица: " << listOfCountrys[i].capital << endl;
			cout << "Население: " << listOfCountrys[i].population << endl;
			m = false;
		}
	}
	if (m) cout << "Нет стран с таким названием" << endl;

	cout << "Введите следующую команду ", cin >> choice;
}
