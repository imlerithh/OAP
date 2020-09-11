// Создать очередь для массива целых (положительных и отрицательных) чисел и функции для ввода, вывода и удаления элементов очереди.
// Найти минимальный и максимальный элемент очереди. 
// Вывести все элементы очереди и посчитать их количество. 
#include <iostream>
#include "Header.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int choice;
	Queue* myQueue = new Queue; //выделение памяти для стека
	myQueue->head = NULL;       //инициализация первого элемента	
	myQueue->tail = NULL;

	for (;;)
	{
		cout << "Выберите команду:" << endl;
		cout << "1 - Добавление элемента в очередь" << endl;
		cout << "2 - Извлечение элемента из очереди" << endl;
		cout << "3 - Вывод очереди" << endl;
		cout << "4 - Задание" << endl;
		cout << "5 - Очистка очереди" << endl;
		cout << "6 - Выход" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Введите элемент: " << endl;
			cin >> choice;
			push(choice, myQueue);
			break;
		case 2: choice = pop(myQueue);
			if (choice != -1)
				cout << "Извлеченный элемент: " << choice << endl;
			break;
		case 3: cout << "Весь стек: " << endl;
			show(myQueue);
			break;
		case 4: cout << "Задание: " << endl;
			task(myQueue); break; 
		case 5: cout << "Начало очитски стека" << endl;
			clear(myQueue); break;
		case 6: return 0;
			break;
		}
	}
	return 0;
}