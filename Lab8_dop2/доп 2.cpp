#include<iostream>
using namespace std;
struct Item
{
	float data;
	Item* next;
};
Item* head, * tail;

bool isNull(void)    //Проверка на пустоту
{
	return (head == NULL);
}
void deletFirst()   //Извлечение элемента из начала
{
	if (isNull())
		cout << "Очередь пуста" << endl;
	else
	{
		Item* p = head;
		head = head->next;
		delete p;
	}
}
void getFromHead()  //Получение элемента из начала
{
	if (isNull())
		cout << "Очередь пуста" << endl;
	else
		cout << "Начало = " << head->data << endl;
}
void insertToQueue(float x)  //Добавление элемента в очередь 
{
	Item* p = new Item;      //новый указатель 
	p->data = x;
	p->next = NULL;
	Item* v = new Item;      //указатель для нового числа
	if (isNull())
		head = tail = p;
	else
	{

		tail->next = p;
		tail = p;

	}
		
	
}
void printQueue()             //Вывод очереди
{
	Item* p = new Item;
	if (isNull())
		cout << "Очередь пуста" << endl;
	else
	{
		cout << "Очередь = ";
		p = head;
		while (!isNull())
		{
			if (p != NULL)
			{
				cout << p->data << " "; cout << "->";
				p = p->next;
			}
			else
			{
				cout << "NULL" << endl;
				return;
			}
		}
	}
}

void clrQueue()           //Очистка очереди
{
	while (!isNull()) deletFirst();
}
int sdvig() {
	Item* p = new Item;
	float buf;
	if (isNull())
		cout << "Очередь пуста" << endl;
	else
	{
		cout << "Очередь = ";
		p = head;
		buf = p->data;
		while (!isNull())
		{
			if (p != NULL)
			{
				cout << p->data << " "; cout << "->";
				if ((p->data) > buf)
					buf = p->data;
				p = p->next;
				
			}
			else
			{
				break;
			}
		}
	}
	p = head;
	while (buf != p->data)
	{
		p = head;
		if (buf == p->data)
			break;
		if (p != NULL)
		{
			if (buf != p->data) 
			{
				deletFirst();
				printQueue();
			}
			else
			{
				break;
				return 0;
			}
		}
	}
}


int main()
{
	setlocale(LC_CTYPE, "Russian");
	int i = 1, choice = 1; head = NULL;  tail = NULL;
	float z;
	while (choice != 0)
	{
		cout << "1 - добавить элемент" << endl;
		cout << "2 - получить элемент с начала" << endl;
		cout << "3 - извлечь элемент с начала" << endl;
		cout << "4 - вывести элементы" << endl;
		cout << "5 - очистить очередь" << endl;
		cout << "6 - сдвиг\n";
		cout << "0 - выход" << endl;
		cout << "Выберите действие  ";  cin >> choice;
		switch (choice)
		{
		case 1: cout << "Введите элемент:  "; cin >> z;
			insertToQueue(z); printQueue();  break;
		case 2: getFromHead(); break;
		case 3: deletFirst();  break;
		case 4: printQueue();  break;
		case 5: clrQueue();    break;
		case 6: sdvig();	break;
		default: cout << "такого пункта в меню нет!";
			break;
		}
	}
	return 0;
}
