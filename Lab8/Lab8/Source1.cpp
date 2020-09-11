#include <iostream>
#include "Header.h"
#include <fstream>

using namespace std;
void push(int x, Queue* myStk)   //Добавление элемента х в стек	
{
	if (myStk->head == NULL) {
		Queue* e = new Queue;    //выделение памяти для нового элемента
		e->data = x;             //запись элемента x в поле v 
		myStk->head = e;         //сдвиг вершины на позицию вперед
		myStk->tail = e;
	}
	Queue* e = new Queue;    //выделение памяти для нового элемента
	e->data = x;             //запись элемента x в поле v 
	myStk->tail->next = e;
	myStk->tail = e;
	myStk->tail->next = NULL;
}
int pop(Queue* myStk)   //Извлечение (удаление) элемента из стека
{
	if (myStk->head == NULL)
	{
		cout << "Очередь пуст!" << endl;
		return -1;               //если стек пуст - возврат -1 
	}
	else
	{
		Queue* e = myStk->head;			 //е - переменная для хранения адреса элемента
		int a = myStk->head->data;       //запись числа из поля data в переменную a 
		myStk->head = myStk->head->next; //перенос вершины
		delete e;                        //удаление временной переменной
		return a;                        //возврат значения удаляемого элемента
	}
}
void show(Queue* myStk)    //Вывод стека
{
	Queue* e = myStk->head;    //объявляется указатель на вершину стека
	int a, count=0;
	if (e == NULL)
		cout << "Очередь пуста!" << endl;
	while (e != NULL)
	{
		a = e->data;          //запись значения в переменную a 
		cout << a << " ";
		e = e->next;
		count++;
	}
	cout << endl << "Количество элементов: "<< count << endl;
}
void task(Queue* myStk)
{
	Queue* e = myStk->head;    //объявляется указатель на вершину стека
	int a, max = e->data, min= e->data;
	if (e == NULL)
		cout << "Очередь пуста!" << endl;
	while (e != NULL)
	{
		a = e->data;          //запись значения в переменную a 
		if (a < min) min = a;
		if (a > max) max = a;
		e = e->next;
	}
	cout << "Минимальный элемент очереди: " << min << endl;
	cout << "Максимальный элемент очереди: " << max << endl;

}
void clear(Queue* myStk) {
	if (myStk->head == NULL)
	{
		cout << "Очередь пуста!" << endl;
	}
	while (myStk->head != NULL) {

		Queue* f = myStk->head;   //f - переменная для хранения адреса элемента
		myStk->head = myStk->head->next; //перенос вершины
		delete f;                        //удаление временной переменной
	}
	cout << "Очередь успешно очищена" << endl;
}