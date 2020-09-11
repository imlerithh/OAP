#include <iostream>
#include "Header.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int choice;
	Stack* myStk = new Stack; //выделение памяти для стека
	myStk->head = NULL;       //инициализация первого элемента	
	
	for (;;)
	{
		cout << "Выберите команду:" << endl;
		cout << "1 - Добавление элемента в стек" << endl;
		cout << "2 - Извлечение элемента из стека" << endl;
		cout << "3 - Вывод стека" << endl;
		cout << "4 - Задание" << endl;
		cout << "5 - Работа с файлом" << endl;
		cout << "6 - Очистка стека" << endl;
		cout << "7 - Выход" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Введите элемент: " << endl;
			cin >> choice;
			push(choice, myStk);
			break;
		case 2: choice = pop(myStk);
			if (choice != -1)
				cout << "Извлеченный элемент: " << choice << endl;
			break;
		case 3: cout << "Весь стек: " << endl;
			show(myStk);
			break;
		case 4: cout << "Задание: " << endl;
			task(myStk); break;
		case 5: cout << "Запись в файл: " << endl;
			fileOut(myStk); break;
		case 6: cout << "Начало очитски стека" << endl;
			clear(myStk); break;
		case 7: return 0;
			break;
		}
	}
	return 0;
}
