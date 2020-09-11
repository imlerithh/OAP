#pragma once
struct Queue
{
	int data;             //информационный элемент
	Queue* head;		 //вершина стека 
	Queue* tail;
	Queue* next;		 //указатель на следующий элемент
};

void show(Queue* myStk);         //прототип
int pop(Queue* myStk);           //прототип
void push(int x, Queue* myStk);  //прототип
void task(Queue* myStk);
void fileOut(Queue* myStk);
void clear(Queue* myStk);
