#include "Hash.h"

//--------------------------------------------------------------------
int HashTable::HashFunction(int hashKey)
{
	double m = 5;
	double A = (sqrt(m) - 1) / 2;
	double z = A * hashKey;
	z -= (int)z;

	return (int)(this->size * z);
}
//--------------------------------------------------------------------
void HashTable::Insert()
{
	int countOfWords = 0;
	int counter = 0;
	string str;
	do
	{
		cout << "Сколько букв хотите ввести? " << endl;
		cin >> countOfWords;
		if (countOfWords > this->size)
			cout << "Количество букв превышает размер таблицы! Попробуйте еще раз." << endl;

	} while (countOfWords > this->size);
		cout << endl;

	cout << "Введите строку: ", cin >> str;
	
	if (this->currentSize < this->size)
	{
		while (counter != countOfWords)
		{

			Node* newElem = new Node;
			Node* temp;
			newElem->str = str;
			cout << "Введите букву: ", cin >> newElem->word;
			for (int i = 0; i < str.length(); i++)
			{
				if (str[i] == newElem->word)
					newElem->numberOfWords++;
			}
			int position = HashFunction(newElem->numberOfWords);
			temp = this->table[position].next;

			if (!temp)
			{
				this->table[position].next = newElem;
				this->table[position].next->prev = &this->table[position];
				this->currentSize++;
				counter++;
			}
			else 
				while (true)
				{
					if (!temp->next)
					{
						temp->next = newElem;
						temp->next->prev = temp;

						this->currentSize++;
						counter++;
						break;
					}
					else
						temp = temp->next;
				}
		}
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
			cout << "|Буква: " << temp->word << "\t\tКоличество в строке: " << temp->numberOfWords <<"\t\tСтрока: "<< temp->str <<"|\n";
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
	char tempWord;
	bool flag=false;
	cout << "Введите букву, которую хотите найти: ", cin >> tempWord;
	Node* temp;
	int i = 0;
	temp = this->table[i].next;
	for (i; i < this->size; i++)
	{
		while (temp)
		{
			if (temp->word == tempWord)
			{
				cout << "Буква присутствует в таблице" << endl;
				cout << "|Буква: " << temp->word << "\t\tКоличество в строке: " << temp->numberOfWords << "\t\tСтрока: " << temp->str << "|\n";
				flag = true;
				break;
			}
			temp = temp->next;
		}

		temp = this->table[i].next;
	}

	if (!flag)
		cout << "Буква не найдена" << endl;

}
//--------------------------------------------------------------------
void HashTable::FillPercent()
{
	cout << "\nНа данный момент таблица заполнена на " << int(float(this->currentSize) / float(this->size) * 100) << "%.\n";
}
//--------------------------------------------------------------------