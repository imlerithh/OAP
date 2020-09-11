#include "Hash.h"

//--------------------------------------------------------------------
int HashTable::HashFunction(string str)
{
	int key = 0;
	for (int i = 0; i < str.length(); i++)
		key += int(str[i]);
	unsigned int key2 = 5 * ((6180339 * key) - int((0.6180339887499 * key)));
	int a = (key * key + key2) % this->size;
	return a;
}
//--------------------------------------------------------------------
void HashTable::Insert()
{
	if (this->currentSize < this->size)
	{
		ifstream f("file.txt");
		if (!(f.is_open()))
		{
			cout << "Ошибка открытия файла" << endl;
			return;
		}
		while (!f.eof())
		{
			Node* newElem = new Node;
			Node* temp;
			getline(f, newElem->str);
			int position = HashFunction(newElem->str);
			temp = this->table[position].next;

			if (!temp)
			{
				this->table[position].next = newElem;
				this->table[position].next->prev = &this->table[position];
				this->currentSize++;
			}
			else
				while (true)
				{
					if (!temp->next)
					{
						temp->next = newElem;
						temp->next->prev = temp;
						this->currentSize++;
						break;
					}
					else
						temp = temp->next;
				}
		}
		f.close();

	}
	else
		cout << "Хэш-таблица заполнена." << endl;
	
}
//--------------------------------------------------------------------
void HashTable::PrintTable()
{
	Node* temp;

	cout << "\n-----------------------------------------------------------------------------------------------------------\n";
	for (int i = 0; i < this->size; i++)
	{
		temp = this->table[i].next;

		cout << " Цепочка №" << i << ":\n";
		if (!this->table[i].next)
		{
			cout << "пусто\n\n";
			continue;
		}

		while (temp)
		{
			cout << "\t\tСлово: " << temp->str << "|\n";
			temp = temp->next;
		}
		cout << endl;

	}
	cout << "\n-----------------------------------------------------------------------------------------------------------\n";
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
void HashTable::SearchNodes()
{
	string searchNode;

	cout << "Введите слово: "; cin >> searchNode;
	int i = HashFunction(searchNode);
	if (!this->table[i].next)
	{
		cout << "Слово не обнаружено.\n";
		return;
	}

	cout << "Все найденные числа:\n";
	cout << " Цепочка №" << i << ":\n";

	Node* temp = this->table[i].next;

	while (temp)
	{
		cout << "\t\tСлово: " << temp->str << "|\n";
		temp = temp->next;
	}
	cout << endl;

}
void HashTable::DeleteNode()
{
	string delElemStr;
	Node* temp;
	char tempWord;
	bool flag = false;
	cout << "Введите букву, которую хотите удалить: ", cin >> tempWord;
	int i = 0;
	temp = this->table[i].next;
	for (i; i < this->size; i++)
	{
		while (temp)
		{
			if (temp->str[0] == tempWord)
			{
				this->table[i - 1].next = temp->next;
				this->table[i - 1].prev = nullptr;
				delete temp;
				this->currentSize--;
				flag = true;
				break;
			}
			temp = temp->next;
		}

		temp = this->table[i].next;
	}

	if (!flag)
		cout << "Слово не найдена" << endl;
}
//--------------------------------------------------------------------
void HashTable::FillPercent()
{
	cout << "\nНа данный момент таблица заполнена на " << int(float(this->currentSize) / float(this->size) * 100) << "%.\n";
}
//--------------------------------------------------------------------