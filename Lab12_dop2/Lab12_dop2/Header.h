#pragma once
#include<iostream>
#include <iomanip>
using namespace std;

template<typename T1>
class MyTree
{
public:
	MyTree();
	~MyTree();


private:
	template<typename T1>
	class Node
	{
	public:
		Node* pright;
		Node* pleft;
		T1 key;
		Node(T1 key = T1(), Node* pright = nullptr, Node* pleft = nullptr)
		{
			this->key = key;
			this->pright = pright;
			this->pleft = pleft;
		}
	};
	int Size;
	Node<T1>* head;
	Node<T1>* temp;
public:
	void out_tree(MyTree<T1>::Node<T1>* head = nullptr, int k = 0, int n = 40);		//out tree
	void push_back(T1 key, MyTree<T1>::Node<T1>* head = nullptr);		//input element
	void pop(MyTree<T1>::Node<T1>* head = nullptr);						//clear tree
};

template<typename T1>
MyTree<T1>::MyTree()
{
	Size = 0;
	head = nullptr;
}
template<typename T1>
MyTree<T1>::~MyTree()
{
	pop();
}

template<typename T1>
inline void MyTree<T1>::push_back(T1 key, MyTree<T1>::Node<T1>* head)
{
	Node<T1>* curent = head;
	if (this->head == nullptr)
	{
		this->head = head = new Node<T1>(key);
		Size++;
	}
	else
	{
		if (head == nullptr)			push_back(key, this->head);

		if (curent == nullptr)
			return;
		else if (curent->key == key)
		{

			curent->key = key;
		}
		else if (curent->pleft == nullptr)
		{
			curent->pleft = new Node<T1>(key);
			Size++;
		}
		else if (curent->pright == nullptr)
		{
			curent->pright = new Node<T1>(key);
			Size++;
		}

		else if (curent->pleft != nullptr)		push_back(key, curent->pright);

		else if (curent->pright != nullptr)		push_back(key, curent->pright);

	}

	return;
}

template<typename T1>
inline void MyTree<T1>::pop(MyTree<T1>::Node<T1>* head)
{
	Node<T1>* temp;
	Node<T1>* current = head;
	if (current == nullptr)
	{
		if (this->head == nullptr)
		{
			printf("Записей нет!");
			this->Size = 0;
			return;
		}
		else if (this->head != nullptr)
		{
			current = this->head;
			pop(current);
		}
	}
	else if (current != nullptr)
	{
		if (current->pleft != nullptr)
		{
			pop(current->pleft);
		}
		if (current->pright != nullptr)
		{
			pop(current->pright);
		}
		delete current;
		return;
	}
	this->Size = 0;
	this->head = nullptr;
}

template<typename T1>
inline void MyTree<T1>::out_tree(MyTree<T1>::Node<T1>* head, int k, int n)
{
	Node<T1>* current = head;

	if (current == nullptr)
	{
		if (this->head == nullptr)
		{
			printf("Дерево пустое");
			return;
		}
		else if (this->head != nullptr)
		{
			current = this->head;
			out_tree(current);
		}
	}
	else if (current != nullptr)
	{
		if (current)
		{

			cout << setw(70) << setw(n + k) << current->key << endl;
			if (current->pleft != nullptr)
			{
				out_tree(current->pleft, k - 1, (n - 12));
			}
			if (current->pright != nullptr)
			{
				out_tree(current->pright, k + 1, (n + 13));
			}
		}
	}
}