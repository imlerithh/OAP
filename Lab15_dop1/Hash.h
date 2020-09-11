#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
struct Node
{
	int numberOfWords;
	char word;
	string str;
	Node* next;
	Node* prev;

	Node()
	{
		this->numberOfWords = 0;
		this->word = '\0';
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
	int HashFunction(int hashKey);
	void PrintTable();
	void SearchNodes();
	void FillPercent();
};

