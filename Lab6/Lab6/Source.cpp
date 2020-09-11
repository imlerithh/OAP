//Создать список, содержащий элементы целого типа. Найти сумму отрицательных двухзначных элементов или выдать сообщение, что таких элементов нет. 
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct list {
	int number;
	list* next;
};


void enterNew(list*& p);
void out(list* p);
void task(list*& p);
void fileOut(list*& p);


int choice;

int main() {
	setlocale(LC_CTYPE, "Russian");
	list* first = nullptr;
	cout << "Введите:" << endl;
	cout << "1-для ввода новой записи" << endl;
	cout << "2-для вывода записей" << endl;
	cout << "3-для выполнения задания " << endl;
	cout << "4-для записи в файл" << endl;
	cout << "5-для выхода" << endl;
	cin >> choice;
	do
	{
		switch (choice)
		{
		case 1:  enterNew(first); break;
		case 2:  out(first); break;
		case 3:  task(first); break;
		case 4:  fileOut(first); break;
		}
	} while (choice != 5);
	return 0;
}

void enterNew(list*& p) {
	cout << "Ввод информации" << endl;
	cout << "Введите число "; int value;
	cin >> value;

	
		list* newP = new list;
		if (newP != NULL)     //есть ли место?  
		{
			newP->number = value;
			newP->next = p;
			p = newP;
		}
		else
			cout << "Операция добавления не выполнена" << endl;

		cout << "Введите следующую команду ", cin >> choice;
}

void out(list* p) {
	cout << "Вывод информации" << endl;
	if (p == NULL)
		cout << "Список пуст" << endl;
	else
	{
		cout << "Список:" << endl;
		while (p != NULL)
		{
			cout << "\t-->\t" << p->number;
			p = p->next;
		}
		cout << "\t-->NULL" << endl;
	}
	cout << "Введите следующую команду ", cin >> choice;
}

void task(list*& p) {
	cout << "Задание" << endl;
	int sum = 0;
	if (p == NULL)
		cout << "Список пуст" << endl;
	else
	{
		cout << "Список:" << endl;
		while (p != NULL)
		{
		//	if (p->number > 0)
		//if (p->number>9 && p->number < 100)
		if (p->number < 0 && p->number % 5 == 0)
		//	if (p->number<-9 && p->number > -100)
				sum += p->number;
			p = p->next;
		}

		cout << "sum\t" << sum << endl;
	}
	cout << "Введите следующую команду ", cin >> choice;

}


void fileOut(list*& p) {
	list* temp = p;
	list buf;
	ofstream frm("A.dat");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	while (temp)
	{
		buf = *temp;
		frm.write((char*)&buf, sizeof(list));
		temp = temp->next;
	}
	frm.close();
	cout << "Список записан в файл A.dat\n";

	cout << "Введите следующую команду ", cin >> choice;
}