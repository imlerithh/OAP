// Вокзал. Номер поезда, пункт назначения, время прибытия, время отправления.Выбор по пункту назначения.
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
	cout << "Введите:" << endl;
	cout << "1-для ввода новой записи" << endl;
	cout << "2-для вывода записей" << endl;
	cout << "3-для удаления записи" << endl;
	cout << "4-для поиска записи по назначению" << endl;
	cout << "5-для записи в файл" << endl;
	cout << "6-для выхода" << endl;
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
	cout << "Ввод информации" << endl;
	int hour, minutes;
	for (;current_size < size;)
	{
		cout << "Запись номер ";
		cout << current_size + 1;
		cout << endl << "Номер поезда " << endl;
		cin >> listOfTrains[current_size].number;
		cout << "Назначение " << endl;
		cin >> listOfTrains[current_size].destination;
		while (true) {
			cout << "Введите час прибытия ", cin >> hour;
			if (hour < 0 || hour>24) {
				cout << "Данные неккоректны, введите их еще раз" << endl;
				continue;
			}
			cout << "Введите минуту прибытия ", cin >> minutes;
			if (minutes < 0 || minutes>59) {
				cout << "Данные неккоректны, введите их еще раз" << endl;
				continue;
			}
			listOfTrains[current_size].arrivalTime = to_string(hour) + ":" + to_string(minutes);
			break;
		}
		while (true) {
			cout << "Введите час отправления ", cin >> hour;
			if (hour < 0 || hour>24) {
				cout << "Данные неккоректны, введите их еще раз" << endl;
				continue;
			}
			cout << "Введите минуту отправления ", cin >> minutes;
			if (minutes < 0 || minutes>59) {
				cout << "Данные неккоректны, введите их еще раз" << endl;
				continue;
			}
			listOfTrains[current_size].departureTime = to_string(hour) + ":" + to_string(minutes);
			break;
		}

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
		cout << "Номер поезда: " << listOfTrains[a-1].number << endl;
		cout << "Пункт назначения: " << listOfTrains[a-1].destination << endl;
		cout << "Время прибытия: " << listOfTrains[a-1].arrivalTime << endl;
		cout << "Время отправления " << listOfTrains[a-1].departureTime << endl << endl;
	}
	else if (a == 0) {
		for (; a < current_size; a++) {
			cout << "Номер записи: " << a + 1 << endl;
			cout << "Номер поезда: " << listOfTrains[a].number << endl;
			cout << "Пункт назначения: " << listOfTrains[a].destination << endl;
			cout << "Время прибытия: " << listOfTrains[a].arrivalTime << endl;
			cout << "Время отправления " << listOfTrains[a].departureTime << endl;
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
			listOfTrains[de1] = listOfTrains[de1 + 1];
		current_size = current_size - 1;
	}
	if (d == 0)
		for (int i = 0; i < size; i++) {
			listOfTrains[i] = bad;
			current_size = 0;
		}
	cout << "Введите следующую команду ", cin >> choice;
}

void find()
{
	char dest[str_len]; bool m = true;
	cout << "Введите пункт назначения: ", cin >> dest;
	for (int i = 0; i < size; i++) {
		if (strcmp(dest, listOfTrains[i].destination) == 0) {
			cout << "Информация о поезде, который идет в эту точку " << endl;
			cout << "Номер поезда: " << listOfTrains[i].number << endl;
			cout << "Время прибытия: " << listOfTrains[i].arrivalTime << endl;
			cout << "Время отправления: " << listOfTrains[i].departureTime << endl;
			m = false;
		}
	}
	if (m) cout << "Нет совпадающих поездов" << endl;

	cout << "Введите следующую команду ", cin >> choice;
}

void fileOut() {
	ofstream fout;
	fout.open("File.txt");
	if (!fout.is_open())
	{
		cout << "File couldn't be open" << endl;
	}
	else {
		cout << "Начинаю работу с файлом" << endl;
		cout << "Записываю информацию о всех поездах в файл" << endl;
		for (int i = 0; i < current_size; i++) {
			fout << "Номер записи: " << i+1 << endl;
			fout << "Номер поезда: " << listOfTrains[i].number << endl;
			fout << "Пункт назначения: " << listOfTrains[i].destination << endl;
			fout << "Время прибытия: " << listOfTrains[i].arrivalTime << endl;
			fout << "Время отправления " << listOfTrains[i].departureTime << endl << endl;
		}
		cout << "Данные записаны в файл" << endl;
	}
	fout.close();

	cout << "Введите следующую команду ", cin >> choice;
}