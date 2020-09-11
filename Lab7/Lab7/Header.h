#pragma once
struct Stack
{
	int data;             //информационный элемент
	Stack* head;		 //вершина стека 
	Stack* next;		 //указатель на следующий элемент
};

void show(Stack* myStk);         //прототип
int pop(Stack* myStk);           //прототип
void push(int x, Stack* myStk);  //прототип
void task(Stack* myStk);
void fileOut(Stack* myStk);
void clear(Stack* myStk);