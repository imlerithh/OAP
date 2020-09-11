#pragma once

#pragma once
#include <string>
#include <vector>

template<typename T>
class List {
public:
	List() :
		head(nullptr),
		size(0),
		last(nullptr) {}

	~List() {
		
	}

	int get_size() const {
		return this->size;
	}

	void push_back(T data) {
		if (this->head == nullptr) {
			this->head = new Node<T>(data);
			this->size++;
		}
		else {
			Node<T>* current = this->head;

			if (current->_pNext == nullptr) {
				current->_pNext = new Node<T>(data, this->head, current);
				this->head->_pPrev = current->_pNext;
				this->size++;
				return;
			}

			for (unsigned int i = 0; i < this->size - 1; i++) {
				current = current->_pNext;
			}

			current->_pNext = new Node<T>(data, this->head, current);
			current = current->_pNext;
			this->head->_pPrev = current;
			this->size++;
		}
	}

	void deleteIndexRepeat(int deleteIndex) {
		Node<T>* printElement = this->head;
		Node<T>* current = this->head;
		Node<T>* deleteElement;
		Node<T>* NextElement;
		Node<T>* PrevElement;

		while (this->size) {

			printElement = this->head;

			for (unsigned int i = 0; i < this->size; i++) {
				std::cout << printElement->_data << " ";
				printElement = printElement->_pNext;
			}
			std::cout << std::endl;

			if (this->size == 1) {
				delete this->head;
				this->head = nullptr;
				return;
			}

			for (int i = 0; i < deleteIndex - 1; ++i) {
				current = current->_pNext;
			}

			if (this->size == 2) {
				deleteElement = current;
				current = current->_pNext;
				this->head = current;
				current->_pNext = nullptr;
				current->_pPrev = nullptr;
				delete deleteElement;
				this->size--;
				continue;
			}

			deleteElement = current;
			current = current->_pNext;
			NextElement = deleteElement->_pNext;
			PrevElement = deleteElement->_pPrev;
			if (deleteElement == this->head)
				this->head = current;
			PrevElement->_pNext = NextElement;
			NextElement->_pPrev = PrevElement;
			this->size--;
			delete deleteElement;
		}
	}

	T& operator[](const int index) const{
		if (index >= this->size || index < 0) throw std::exception("Несоответсвие индекса!");

		Node<T>* current = this->head;

		for (unsigned int i = 0; i < index; i++) {
			current = current->_pNext;
		}

		return current->_data;
	}

private:
	template<typename T>
	class Node {
		friend class Univer;
	public:
		Node<T>* _pNext;
		Node<T>* _pPrev;
		T        _data;

		Node(T _data = T(), Node<T>* _pNext = nullptr, Node<T>* _pPrev = nullptr) :
			_data(_data),
			_pNext(_pNext),
			_pPrev(_pPrev) {}
	};

	Node<T>* head;
	Node<T>* last;
	int      size;
};