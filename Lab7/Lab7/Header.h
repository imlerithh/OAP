#pragma once
struct Stack
{
	int data;             //�������������� �������
	Stack* head;		 //������� ����� 
	Stack* next;		 //��������� �� ��������� �������
};

void show(Stack* myStk);         //��������
int pop(Stack* myStk);           //��������
void push(int x, Stack* myStk);  //��������
void task(Stack* myStk);
void fileOut(Stack* myStk);
void clear(Stack* myStk);