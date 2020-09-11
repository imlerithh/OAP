#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Item
{
	int data;
	Item* next;
};
Item* head, * tail;

void insertToQueue(int a)  //Добавление элемента в очередь 
{
	Item* t = new Item;
	t->data = a;


	t->next = NULL;
	if (head == NULL)
		head = tail = t;
	else
	{
		t->data = a;
		tail->next = t;
		tail = t;
	}

}

void view() //Вывод элементов очереди 
{
	Item* t = head;
	if (t == NULL)
	{
		cout << "Number is empty\n";
		return;
	}
	else
		while (t != NULL)
		{
			cout << " " << t->data - 48 << " ";
			t = t->next;
		}
}
void view2() //Вывод элементов очереди 
{
	
	Item* t = head;
	ofstream file;
	file.open("file2.txt", ios::app);
	if (!file.is_open())
	{
		cout << "Ошибка открытия файла!\n" << endl;
	}
	else
	{
		if (t == NULL)
		{
			cout << "Number is empty\n";
			return;
		}
		else
			while (t != NULL)
			{
				file << t->data - 48;

				t = t->next;
			}
		file <<"\n";
	}
	
	file.close();
}
void del()
{

	while (!head == NULL)
	{
		if (head == NULL)
		{
			cout << "Ошибка очистки очереди!\n";
		}
		else
		{
			Item* p = head;
			head = head->next;
			delete p;
		}
	}
}
int main()
{
	setlocale(0, "");
	head = NULL;
	tail = NULL;
	ofstream file;
	file.open("file.txt");
	if (!file.is_open())
	{
		cout << "Ошибка открытия файла!\n" << endl;
	}
	else
	{
		file << "Алексан09дер" << endl;
		file << "Ля0казе6тт" << endl;
	}
	file.close();

	ifstream read;
	string a;
	int size;
	read.open("file.txt");
	if (!read.is_open())
	{
		cout << "Ошибка чтения!\n" << endl;
	}
	else
	{
		
		while (!read.eof())
		{
			//read >> a;
			getline(read, a);
			//cout << a;
			size = a.length();
			file.open("file2.txt", ios::app);
			if (!file.is_open())
			{
				cout << "Ошибка открытия файла!\n" << endl;
				return -1;
			}
			for (int i = 0; i < size; i++)
			{
				//read >> a;
				cout << a[i] << " ";
				if (a[i] == '0' || a[i] == '1' || a[i] == '2' || a[i] == '3' || a[i] == '4' || a[i] == '5' || a[i] == '6' || a[i] == '7' || a[i] == '8' || a[i] == '9')
				{
					insertToQueue(a[i]);
				}
				else
				{
					file << a[i];
				}

			}
			file << "|";
			file.close();
			cout << "|";
			view();
			view2();
			cout << endl;
			del();

		}
	}
	read.close();
	system("pause");
}