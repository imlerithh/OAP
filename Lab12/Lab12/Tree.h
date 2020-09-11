#pragma once

#include <iostream>
using namespace std;

struct  Node
{
	int key;
	int count;
	Node* left;
	Node* right;
};

struct Tree
{
	Node* node = nullptr;
	int counter;
	void AddNode(int k);
	void PrintTree(Node* temp, int l);
	void Delete(int k);
	bool Balance(Node* temp);
	void DirectBypass(Node* temp);
	void ReverseBypass(Node* temp);
	int amountOfBranches(Node* temp);
};