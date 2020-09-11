//гайд по заданию
/*
1)Если номер поезда ввести не число - программе пизда
2)Назначение должно состоять из английских букв и из одного слова, т.е. не должно быть пробелов
3)Назаначение следует писать или только в верхнем или только в нижнем реистре. Допускатся первая буква в верхнем регистре, но только если она у всех слов в верхнем регистре
4)переменная size в define определяет количество элементов(поездов)
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
	cout << "Введите:" << endl;
	cout << "1-для ввода данных" << endl;
	cout << "2-для вывода данных" << endl;
	cout << "3-для вывода информации о поездах, которые идут после указанного времени" << endl;
	cout << "4-для выхода" << endl;
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
	cout << "Ввод информации" << endl;
	int hour, minutes;
	for (; current_size < size;)
	{
		cout << "Запись номер ";
		cout << current_size + 1;
		cout << endl << "Номер поезда " << endl;
		cin >> listOfTrains[current_size].number;
		cout << "Назначение " << endl;
		cin >> listOfTrains[current_size].destination;
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
			listOfTrains[current_size].hour = hour; listOfTrains[current_size].minutes = minutes;
			break;
		}
		current_size++;
	}
	// сортировка
	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
			if (strcmp(listOfTrains[i].destination, listOfTrains[j].destination) > 0)
			{
				temp = listOfTrains[i];
				listOfTrains[i] = listOfTrains[j];
				listOfTrains[j] = temp;
			}
	cout << "Записи отсортированы по алфавиту" << endl;
	cout << "Введено максимальное кол-во записей" << endl;
	cout << "Введите следующую команду ", cin >> choice;
}

void out()
{
	int a;
	cout << "Введите номер выводимой записи, 0 для вывода всех записей ", cin >> a;
	if (a > 0 && a <= current_size) {
		cout << "Номер записи: " << a << endl;
		cout << "Номер поезда: " << listOfTrains[a - 1].number << endl;
		cout << "Пункт назначения: " << listOfTrains[a - 1].destination << endl;
		cout << "Время отправления " << listOfTrains[a].hour << ":" << listOfTrains[a].minutes << endl;
	}
	else if (a == 0) {
		for (; a < current_size; a++) {
			cout << "Номер записи: " << a + 1 << endl;
			cout << "Номер поезда: " << listOfTrains[a].number << endl;
			cout << "Пункт назначения: " << listOfTrains[a].destination << endl;
			cout << "Время отправления " << listOfTrains[a].hour << ":" << listOfTrains[a].minutes << endl;
		}
	}
	else
		cout << "Такой записи нет" << endl;

	cout << "Введите следующую команду ", cin >> choice;
}

void specialOut() {
	int compare_hour, compare_minutes;
	cout << "Введите время, после которого нужно найти идущие поезда" << endl;
	while (true) {
		cout << "Введите час отправления ", cin >> compare_hour;
		if (compare_hour < 0 || compare_hour>24) {
			cout << "Данные неккоректны, введите их еще раз" << endl;
			continue;
		}
		cout << "Введите минуту отправления ", cin >> compare_minutes;
		if (compare_minutes < 0 || compare_minutes>59) {
			cout << "Данные неккоректны, введите их еще раз" << endl;
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
		cout << "Таких поездов нет" << endl;
	}
	cout << "Введите следующую команду ", cin >> choice;
}
void outSO(int a) {
		cout << "Номер записи: " << a+1 << endl;
		cout << "Номер поезда: " << listOfTrains[a].number << endl;
		cout << "Пункт назначения: " << listOfTrains[a].destination << endl;
		cout << "Время отправления " << listOfTrains[a].hour << ":" << listOfTrains[a].minutes << endl << endl;
}