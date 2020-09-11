#pragma once
#include <string>
#include <vector>
#include <iostream>
void split(const std::string& str, std::vector<std::string>& tokens, const std::string& delimiters) {
	std::string::size_type lastPos = str.find_first_not_of(delimiters, 0);
	std::string::size_type pos = str.find_first_of(delimiters, lastPos);

	while (std::string::npos != pos || std::string::npos != lastPos) {
		tokens.push_back(str.substr(lastPos, pos - lastPos));
		lastPos = str.find_first_not_of(delimiters, pos);
		pos = str.find_first_of(delimiters, lastPos);
	}
}
using namespace std;
template<typename T>
class Queue {
public:
	Queue() {
		head = nullptr;
		size = 0;
	}

	~Queue() {
		while (this->size) {
			this->pop();
		}
	}

	int get_size() const {
		return this->size;
	}

	void push(T data) {
		if (this->head == nullptr) {
			this->head = new Node<T>(data);
			this->size++;
		}
		else {
			Node<T>* current = this->head;
			while (current->pNext != nullptr) {
				current = current->pNext;
			}

			current->pNext = new Node<T>(data);
			this->size++;
		}
	}

	T pop() {
		if (this->head == nullptr) return NULL;
		T temp;
		Node<T>* current = this->head;
		temp = current->data;
		this->head = this->head->pNext;
		this->size--;

		delete current;
		return temp;
	}

	void insert(T data, const int index) {
		if (index >= this->size + 1 || index < 0) throw std::exception("Несоответсвие индекса!");

		if (this->size == 0) {
			this->head = new Node<T>(data);
			this->size++;
		}
		else if (index == 0) {
			this->head = new Node<T>(data, this->head);
			this->size++;
		}
		else {
			Node<T>* previous = this->head;
			for (unsigned int i = 0; i < index - 1; i++)
			{
				previous = previous->pNext;
			}

			Node<T>* newNode = new Node<T>(data, previous->pNext);

			previous->pNext = newNode;
			this->size++;
		}
	}

	void delete_for_index(const int index) {
		if (index >= this->size || index < 0) throw std::exception("Несоответсвие индекса!");

		if (index == 0) {
			this->pop_front();
		}
		else if (index == this->size - 1) {
			this->pop_back();
		}
		else {
			Node<T>* previous = this->head;
			for (unsigned int i = 0; i < index - 1; i++) {
				previous = previous->pNext;
			}

			Node<T>* toDelete = previous->pNext;
			previous->pNext = previous->pNext->pNext;

			delete toDelete;
			this->size--;
		}

	}

	void print() {
		for (unsigned int i = 0; i < this->size; i++) {
			cout << (*this)[i] << " ";
		}
		cout << endl;
	}

	void clear() {
		while (this->size) {
			this->pop();
		}
		this->head = nullptr;
	}

	T& operator[](const int index) {
		if (index >= this->size || index < 0) throw std::exception("Несоответсвие индекса!");

		Node<T>* current = this->head;

		for (unsigned int i = 0; i < index; i++) {
			current = current->pNext;
		}

		return current->data;
	}

private:
	template<typename T>
	class Node {
	public:
		Node<T>* pNext;
		T data;

		Node(T data, Node<T>* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};

	Node<T>* head;
	int size;
};
