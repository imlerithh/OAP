// 13 
// countX (int x) – функция подсчёта числа элементов списка с заданным значением x.
#include <iostream>
using namespace std;
struct DoubleList //описание узла списка
{
	int data; //информационное поле
	DoubleList* next; //указатель на следующий элемент
	DoubleList* prev; //указатель на предыдущий элемент
};
DoubleList* head; //указатель на первый элемент списка
//**********************ДОБАВЛЕНИЕ ЭЛЕМЕНТА**********************
void AddList(int value)
{
	DoubleList* node = new DoubleList; //создание нового элемента
	node->data = value; //присвоение элементу значения
	if (head == NULL) //если список пуст
	{
		node->next = node; //установка указателя next
		node->prev = node; //установка указателя prev
		head = node; //определяется голова списка
	}
	else
	{
		DoubleList* p = head;
		p->prev->next = node;
		node->prev = p->prev;
		node->next = p;
		p->prev = node;
	}
	cout << "\nЭлемент добавлен...\n\n";
}
//***********************УДАЛЕНИЕ ЭЛЕМЕНТА***********************
int DeleteList()
{
	if (head == NULL) { cout << "\nСписок пуст\n\n"; return 0; }
	if (head == head->next)
	{
		delete head;
		head = NULL;
	}
	else
	{
		DoubleList* a = head;
		if (a == head) head = a->next;
		a->prev->next = a->next;
		a->next->prev = a->prev;
		delete a;
	}
	cout << "\nЭлемент удален...\n\n";
}
//*************************ВЫВОД СПИСКА*************************
void PrintList()
{
	if (head == NULL) cout << "\nСписок пуст\n\n";
	else
	{
		DoubleList* a = head;
		cout << "\nЭлементы списка: ";
		do
		{
			cout << a->data << " ";
			a = a->next;
		} while (a != head); cout << "\n\n";
	}
}
void task(int x) {
	int count = 0;
	if (head == NULL) cout << "\nСписок пуст\n\n";
	else
	{
		DoubleList* a = head;
		do
		{
			if (a->data == x) count++;
			a = a->next;
		} while (a != head); cout << "Количество элементво с заданным значением: " << count << "\n\n";
	}
}

//************************ГЛАВНАЯ ФУНКЦИЯ************************
int main()
{
	setlocale(LC_ALL, "Rus");
	int value, position, x;
	do
	{
		cout << "1. Добавить элемент" << endl;
	//	cout << "2. Удалить элемент" << endl;
		cout << "2. Вывести список" << endl;
		cout << "3. Задание" << endl;
		cout << "0. Выйти" << endl;
		cout << "\nНомер операции > "; cin >> x;
		switch (x)
		{
		case 1:
			cout << "Значение > "; cin >> value;
			AddList(value); break;
		//case 2:
			//DeleteList(); break;
		case 2: PrintList(); break;
		case 3: int x; cout << "Введите значение: ", cin >> x; task(x); break;
		}
	} while (x != 0);
	return 0;
}