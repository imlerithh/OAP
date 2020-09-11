#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
template<typename T>
class Queue_prior {
public:
	Queue_prior() {
		head = nullptr;
		size = 0;
	}

	~Queue_prior() {
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
			Node<T>* prev = nullptr;

			if (current->data < data) {
				Node<T>* newNode = new Node<T>(data, this->head);
				this->head = newNode;
				this->size++;
				return;
			}
			else if (current->data == data) {
				Node<T>* newNode = new Node<T>(data, this->head);
				this->head = newNode;
				this->size++;
				return;
			}
			else {
				prev = current;
				current = current->pNext;
			}

			while (current->pNext != nullptr) {
				if (current->data < data) {
					Node<T>* newNode = new Node<T>(data, current);
					prev->pNext = newNode;
					this->size++;
					return;
				}
				else if (current->data > data) {
					prev = current;
					current = current->pNext;
				}
				else if (current->data == data) {
					Node<T>* newNode = new Node<T>(data, current);
					prev->pNext = newNode;
					this->size++;
					return;
				}
				else {
					current->pNext = new Node<T>(data);
					this->size++;
					return;
				}
			}

			if (current->data < data) {
				Node<T>* newNode = new Node<T>(data, current);
				prev->pNext = newNode;
				this->size++;
			}
			else if (current->data == data) {
				Node<T>* newNode = new Node<T>(data, current);
				prev->pNext = newNode;
				this->size++;
			}
			else {
				current->pNext = new Node<T>(data);
				this->size++;
			}
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