#pragma once
#include <iostream>
#include <fstream>
using namespace std;
const unsigned int NAME_SIZE = 30;

struct Person
{
	char name[NAME_SIZE];
	int age;
	Person* next;
	Person* prev;
};
void insert(Person* e, Person** phead, Person** plast); //���������� � ����� ������
Person* setElement();
void outputList(Person** phead, Person** plast);      //����� ������ �� �����
void find(char name[NAME_SIZE], Person** phead);    // ����� ����� � ������
void delet(char name[NAME_SIZE], Person** phead, Person** plast);  // �������� �����
void writeToFile(Person** phead);       //������ � ����
void readFromFile(Person** phead, Person** plast);          //���������� �� �����
void deleteList(Person** phead, Person** plast);
void countList(Person** phead, Person** plast);