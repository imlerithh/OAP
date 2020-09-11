#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <functional>
#include <fstream>
#include "Queue.h"
#include "Queue_prior.h"
using namespace std;

char number[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };

// Function prototype
void wrapper_function(function<void()>);
void My_task();
void Dop_one();
void Dop_two();
void Dop_three();

int main(int argc, char* argv) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	/*wrapper_function(My_task);*/
	wrapper_function(Dop_one);
	/*wrapper_function(Dop_two);*/
	/*wrapper_function(Dop_three);*/

	return EXIT_SUCCESS;
}

// Обертка для функций
void wrapper_function(function<void()> f) {
	cout << "---------------------------------------------" << endl;
	f();
	cout << "---------------------------------------------" << endl;
	system("pause");
}

void My_task() {
	Queue<char>* q = new Queue<char>;
	char simbol;

	while (true)
	{
		cout << "Введите символ: ";
		cin >> simbol;
		if (simbol == 'q') break;
		if (q->get_size() != 5) {
			q->push(simbol);
		}
		else {
			q->push(simbol);
			q->pop();
		}

		cout << "Элементы: ";
		q->print();
	}

	delete q;
}

void Dop_one() {
	Queue_prior<int>* q = new Queue_prior<int>;
	int temp;

	while (true) {
		cout << "Введите число (0 - выход): ";
		cin >> temp;
		if (temp == 0) return;
		q->push(temp);

		cout << "Вывод элементов: ";
		q->print();
	}
}

void Dop_two() {
	Queue<double>* q = new Queue<double>;
	double size, temp;
	cout << "Сколько чисел вы хотите ввести: ";
	cin >> size;
	for (unsigned int i = 0; i < size; i++)
	{
		cin >> temp;
		q->push(temp);
	}

	for (int i = 0; i < q->get_size() - 1; i++) {
		for (int j = 0; j < q->get_size() - i - 1; j++) {
			if ((*q)[j] < (*q)[j + 1]) {
				// меняем элементы местами
				temp = (*q)[j];
				(*q)[j] = (*q)[j + 1];
				(*q)[j + 1] = temp;
			}
		}
	}

	q->print();

	delete q;
}

void Dop_three() {
	ifstream file_one;
	ofstream file_two;
	string temp1, temp2 = "";
	Queue<char>* q = new Queue<char>;

	file_one.open("file1.txt");
	file_two.open("file2.txt");

	if (!file_one.is_open() || !file_two.is_open()) {
		cout << "Ошибка открытия файла!" << endl;
		return;
	}

	function<bool(char)> func = [](char simbol)->bool {
		for (unsigned int i = 0; i < 10; i++) {
			if (simbol == number[i]) return true;
		}
		return false;
	};

	while (!file_one.eof()) {
		getline(file_one, temp1);
		for (unsigned int i = 0; i < temp1.length(); i++) {
			if (func(temp1[i])) q->push(temp1[i]);
			else temp2 += temp1[i];
		}

		for (unsigned int i = 0; i < q->get_size(); i++) {
			temp2 += q->pop();
		}
		temp2 += '\n';

		file_two << temp2;
		temp2 = "";
		q->clear();
	}

	delete q;
}