#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
using namespace std;
struct Node
{
	string str;
	Node* next;
	Node* prev;

	Node()
	{
		this->str = "";
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
	int HashFunction(string str);
	void PrintTable();
	void SearchNodes();
	void FillPercent();
	void DeleteNode();
};


