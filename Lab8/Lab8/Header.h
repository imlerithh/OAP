#pragma once
struct Queue
{
	int data;             //�������������� �������
	Queue* head;		 //������� ����� 
	Queue* tail;
	Queue* next;		 //��������� �� ��������� �������
};

void show(Queue* myStk);         //��������
int pop(Queue* myStk);           //��������
void push(int x, Queue* myStk);  //��������
void task(Queue* myStk);
void fileOut(Queue* myStk);
void clear(Queue* myStk);
