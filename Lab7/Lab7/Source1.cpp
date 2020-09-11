#include <iostream>
#include "Header.h"
#include <fstream>
using namespace std;
void push(int x, Stack* myStk)   //Добавление элемента х в стек	
{
	Stack* e = new Stack;    //выделение памяти для нового элемента
	e->data = x;             //запись элемента x в поле v 
	e->next = myStk->head;   //перенос вершины на следующий элемент 
	myStk->head = e;         //сдвиг вершины на позицию вперед
}
int pop(Stack* myStk)   //Извлечение (удаление) элемента из стека
{
	if (myStk->head == NULL)
	{
		cout << "Стек пуст!" << endl;
		return -1;               //если стек пуст - возврат -1 
	}
	else
	{
		Stack* e = myStk->head;   //е - переменная для хранения адреса элемента
		int a = myStk->head->data;   //запись числа из поля data в переменную a 
		myStk->head = myStk->head->next; //перенос вершины
		delete e;                        //удаление временной переменной
		return a;                        //возврат значения удаляемого элемента
	}
}
void show(Stack* myStk)    //Вывод стека
{
	Stack* e = myStk->head;    //объявляется указатель на вершину стека
	int a;
	if (e == NULL)
		cout << "Стек пуст!" << endl;
	while (e != NULL)
	{
		a = e->data;          //запись значения в переменную a 
		cout << a << " ";
		e = e->next;
	}
	cout << endl;
}
void task(Stack* myStk)    
{
//13
	//Stack* e = myStk->head;    //объявляется указатель на вершину стека
	//int a, count = 0, suspect;
	//if (e == NULL)
	//	cout << "Стек пуст!" << endl;

	//while (myStk->head != NULL) {
	//	e = myStk->head;
	//	suspect = e->data;
	//	e = e->next;
	//	while (e != NULL)
	//	{
	//		a = e->data;
	//		if (a == suspect) { count++; break; }
	//		e = e->next;
	//	}
	//	Stack* f = myStk->head;   //f - переменная для хранения адреса элемента
	//	myStk->head = myStk->head->next; //перенос вершины
	//	delete f;                        //удаление временной переменной
	//}
	//cout << "Количество повторяющихся элементов:" << count << endl;
//2
	Stack* e = myStk->head;    
	int a; bool k = false;
	if (e == NULL)
		cout << "Стек пуст!" << endl;
	while (e != NULL)
	{	
		Stack* m = e;
		if(k)e = e->next;

		a = e->data;          
		if (a < 0) {
			Stack* f = e;   
			m->next = e->next; 
			delete f;
			break; }
		k = true;
	}
}

void fileOut(Stack* myStk) {
	ofstream fout;
	fout.open("File.txt");
	if (!fout.is_open())
	{
		cout << "File couldn't be open" << endl;
	}
	else {
		Stack* e = myStk->head;    //объявляется указатель на вершину стека
		int a;
		if (e == NULL)
			cout << "Стек пуст!" << endl;
		int count = 1;
		fout << "TOP" << endl;
		while (e != NULL)
		{
			a = e->data;          //запись значения в переменную a 
			fout << count << ".\t" << a << endl;
			e = e->next;
			count++;
		}
		fout << "BOTTOM" << endl;
	}
	cout << "Данные записаны в файл" << endl;
	fout.close();
}
void clear(Stack* myStk) {
	if (myStk->head == NULL)
	{
		cout << "Стек пуст!" << endl;               
	}
	while (myStk->head != NULL) {
		
		Stack* f = myStk->head;   //f - переменная для хранения адреса элемента
		myStk->head = myStk->head->next; //перенос вершины
		delete f;                        //удаление временной переменной
	}
	cout << "Стек успешно очищен" << endl;
}
