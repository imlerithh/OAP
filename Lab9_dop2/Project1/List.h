#pragma once
#include <string>
#include <vector>

struct Date {
	int date;
	int month;
	int year;
};

struct Student {
	std::string lastName;
	std::string firstName;
	std::string otch;
	Date date;
	int course;
	int group;
	int mark[5];
};

template<typename T>
class List {
public:
	List(): 
		head(nullptr), 
		size(0),
		last(nullptr) {}

	~List() {
		while (this->size) {
			this->pop_front();
		}
	}

	int get_size() const {
		return this->size;
	}

	void push_back(T _data) {
		if (this->head == nullptr) {
			this->head = new Node<T>(_data);
			this->size++;
		}
		else {
			Node<T>* current = this->head;
			Node<T>* _pPrev    = this->head;

			if (current->_pNext != nullptr) {
				current = current->_pNext;
			}
			while (current->_pNext != nullptr) {
				current = current->_pNext;
				_pPrev    = _pPrev->_pNext;
			}

			current->_pNext = new Node<T>(_data);

			
			if (current != this->head) _pPrev = _pPrev->_pNext;
			current = current->_pNext;
			current->_pPrev = _pPrev;

			this->last = current->_pNext;
			this->size++;
		}
	}

	void pop_back() {
		if (this->head == nullptr) return;

		Node<T>* current = this->head;
		
		while (current->_pNext != nullptr) {
			current = current->_pNext;
		}

		delete current;
		current = nullptr;
		this->size--;
	}

	void pop_front() {
		if (this->head == nullptr) return;

		Node<T>* current = this->head;
		this->head       = this->head->_pNext;

		if (this->size != 1) this->head->_pPrev = nullptr;

		delete current;
		this->size--;
	}

	void insert(T _data, const int index) {
		if (index >= this->size + 1 || index < 0) throw std::exception("Несоответсвие индекса!");

		if (this->size == 0) {
			this->head = new Node<T>(_data);
			this->size++;
		}
		else if (index == 0) {
			this->head                 = new Node<T>(_data, this->head);
			this->head->_pNext->_pPrev = this->head;
			this->size++;
		}
		else {
			Node<T>* _pPrevious = this->head;
			for (unsigned int i = 0; i < index - 1; i++) {
				_pPrevious = _pPrevious->_pNext;
			}

			Node<T>* newNode = new Node<T>(_data, _pPrevious->_pNext, _pPrevious);

			_pPrevious->_pNext->_pPrev = newNode;
			_pPrevious->_pNext         = newNode;

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
			Node<T>* _pPrevious = this->head;
			for (unsigned int i = 0; i < index - 1; i++) {
				_pPrevious = _pPrevious->_pNext;
			}

			Node<T>* toDelete                = _pPrevious->_pNext;
			_pPrevious->_pNext                 = _pPrevious->_pNext->_pNext;
			_pPrevious->_pNext->_pNext->_pPrev = _pPrevious;

			delete toDelete;
			this->size--;
		}

	}

	T& operator[](const int index) {
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

		Node(T _data = T(), Node<T>* _pNext = nullptr, Node<T>* _pPrev = nullptr): 
			_data(_data), 
			_pNext(_pNext), 
			_pPrev(_pPrev) {}
	};

	Node<T>* head;
	Node<T>* last;
	int      size;
};

template<>
class List<Student> {
friend class Univer;
public:
	List() :
		head(nullptr),
		size(0) {}

	~List() {
		while (this->size) {
			this->pop_front();
		}
	}

	int get_size() const {
		return this->size;
	}

	void push_back(Student _data) {
		if (this->head == nullptr) {
			this->head = new Node<Student>(_data);
			this->size++;
		}
		else {
			Node<Student>* current = this->head;
			Node<Student>* _pPrev = this->head;

			if (current->_pNext != nullptr) {
				current = current->_pNext;
			}
			while (current->_pNext != nullptr) {
				current = current->_pNext;
				_pPrev = _pPrev->_pNext;
			}

			current->_pNext = new Node<Student>(_data);


			if (current != this->head) _pPrev = _pPrev->_pNext;
			current = current->_pNext;
			current->_pPrev = _pPrev;

			this->size++;
		}
	}

	void pop_back() {
		if (this->head == nullptr) return;

		Node<Student>* current = this->head;

		while (current->_pNext != nullptr) {
			current = current->_pNext;
		}

		delete current;
		current = nullptr;
		this->size--;
	}

	void pop_front() {
		if (this->head == nullptr) return;

		Node<Student>* current = this->head;
		this->head = this->head->_pNext;

		if (this->size != 1) this->head->_pPrev = nullptr;

		delete current;
		this->size--;
	}

	void insert(Student _data, const int index) {
		if (index >= this->size + 1 || index < 0) throw std::exception("Несоответсвие индекса!");

		if (this->size == 0) {
			this->head = new Node<Student>(_data);
			this->size++;
		}
		else if (index == 0) {
			this->head = new Node<Student>(_data, this->head);
			this->head->_pNext->_pPrev = this->head;
			this->size++;
		}
		else {
			Node<Student>* _pPrevious = this->head;
			for (unsigned int i = 0; i < index - 1; i++) {
				_pPrevious = _pPrevious->_pNext;
			}

			Node<Student>* newNode = new Node<Student>(_data, _pPrevious->_pNext, _pPrevious);

			_pPrevious->_pNext->_pPrev = newNode;
			_pPrevious->_pNext = newNode;

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
			Node<Student>* _pPrevious = this->head;
			for (unsigned int i = 0; i < index - 1; i++) {
				_pPrevious = _pPrevious->_pNext;
			}

			Node<Student>* toDelete = _pPrevious->_pNext;
			_pPrevious->_pNext = _pPrevious->_pNext->_pNext;
			_pPrevious->_pNext->_pNext->_pPrev = _pPrevious;

			delete toDelete;
			this->size--;
		}

	}

	void sort() {
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if ((*this)[j].lastName[0] > (*this)[j + 1].lastName[0]) {
					Node<Student>* currentOne = this->head;
					Node<Student>* currentTwo = this->head;

					for (int i = 0; i < j; i++) {
						currentOne = currentOne->_pNext;
					}

					for (int i = 0; i < j + 1; i++) {
						currentTwo = currentTwo->_pNext;
					}

					Node<Student>* tempOneNext = currentOne->_pNext;
					Node<Student>* tempOnePrev = currentOne->_pPrev;
					Node<Student>* tempTwoNext = currentTwo->_pNext;
					Node<Student>* tempTwoPrev = currentTwo->_pPrev;
					
					if (currentOne == this->head) {
						this->head = currentTwo;
						currentTwo->_pNext = currentOne;
						currentOne->_pNext = tempTwoNext;
						tempTwoNext->_pPrev = currentOne;
						currentOne->_pPrev = currentTwo;
						currentTwo->_pPrev = nullptr;
					}
					else if (currentTwo->_pNext == nullptr) {
						tempOnePrev->_pNext = currentTwo;
						currentTwo->_pNext = currentOne;
						currentOne->_pNext = nullptr;
						currentOne->_pPrev = currentTwo;
						currentTwo->_pPrev = tempOnePrev;
					}
					else {
						tempOnePrev->_pNext = currentTwo;
						currentTwo->_pNext = currentOne;
						currentOne->_pNext = tempTwoNext;
						tempTwoNext->_pPrev = currentOne;
						currentOne->_pPrev = currentTwo;
						currentTwo->_pPrev = tempOnePrev;
					}
				}
			}
		}
	}

	Student& operator[](int index) {
		if (index >= this->size || index < 0) throw std::exception("Несоответсвие индекса!");

		Node<Student>* current = this->head;

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

	Node<Student>* head;
	int            size;
};