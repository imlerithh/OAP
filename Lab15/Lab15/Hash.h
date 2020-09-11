#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
struct Node
{
	int groupNumber;
	string surname;
	Node* next;
	Node* prev;

	Node()
	{
		this->groupNumber = -1;
		this->surname = "";
		this->next = this->prev = NULL;
	}
};


struct HashTable
{
	int currentSize;
	int size;
	Node* table;

	HashTable(int size)
	{
		this->size = size;
		this->currentSize = 0;
		this->table = new Node[size];
	}

	void Insert();
	int HashFunction(string, int);
	void PrintTable();
	void DeleteNode();
	void SearchNodes();
	void FillPercent();
};