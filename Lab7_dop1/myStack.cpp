#include <iostream>
#include "MyStack.h"
#include<fstream>
#include <string>
using namespace std;
string path="myStakc.dat";
void push(char x, Stack* myStk)   //Добавление элемента х в стек	
{
	Stack* e = new Stack;    //выделение памяти для нового элемента
	e->data = x;             //запись элемента x в поле v 
	e->next = myStk->head;   //перенос вершины на следующий элемент 
	myStk->head = e;         //сдвиг вершины на позицию вперед
}

void show(Stack* myStk)    //Вывод стека
{
	Stack* e = myStk->head;    //объявляется указатель на вершину стека
	
	if (e == NULL)
		cout << "Стек пуст!" << endl;
	while (e != NULL)
	{
								         
		cout << e->data << " ";
		e = e->next;
	}
	cout << endl;
}

int myFunc(Stack* mySck)			//доп 1
{	
	int choice;
	string word;
	cout << "input word: ";
	cin >> word;
	choice = word.length();
	char* arr1 = new char(choice / 2);
	for (int i = choice / 2; i < choice; i++)
	{
		push(word[i], mySck);
	}
	for (int i = 0; i < choice / 2; i++)
	{
		push(word[i], mySck);		
	}
	
	char* arr2 = new char(choice / 2);

	return 0;
}
