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
		cout << "������� ���� ������ ������? " << endl;
		cin >> countOfWords;
		if (countOfWords > this->size)
			cout << "���������� ���� ��������� ������ �������! ���������� ��� ���." << endl;

	} while (countOfWords > this->size);
		cout << endl;

	cout << "������� ������: ", cin >> str;
	
	if (this->currentSize < this->size)
	{
		while (counter != countOfWords)
		{

			Node* newElem = new Node;
			Node* temp;
			newElem->str = str;
			cout << "������� �����: ", cin >> newElem->word;
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
		cout << "���-������� ���������." << endl;

}
//--------------------------------------------------------------------
void HashTable::PrintTable()
{
	Node* temp;

	cout << "\n-----------------------------------------------------------------------------------------------------------\n";
	for (int i = 0; i < this->size; i++)
	{
		temp = this->table[i].next;

		cout << " ������� �" << i << ":\n";
		if (!this->table[i].next)
		{
			cout << "�����\n\n";
			continue;
		}

		while (temp)
		{
			cout << "|�����: " << temp->word << "\t\t���������� � ������: " << temp->numberOfWords <<"\t\t������: "<< temp->str <<"|\n";
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
	cout << "������� �����, ������� ������ �����: ", cin >> tempWord;
	Node* temp;
	int i = 0;
	temp = this->table[i].next;
	for (i; i < this->size; i++)
	{
		while (temp)
		{
			if (temp->word == tempWord)
			{
				cout << "����� ������������ � �������" << endl;
				cout << "|�����: " << temp->word << "\t\t���������� � ������: " << temp->numberOfWords << "\t\t������: " << temp->str << "|\n";
				flag = true;
				break;
			}
			temp = temp->next;
		}

		temp = this->table[i].next;
	}

	if (!flag)
		cout << "����� �� �������" << endl;

}
//--------------------------------------------------------------------
void HashTable::FillPercent()
{
	cout << "\n�� ������ ������ ������� ��������� �� " << int(float(this->currentSize) / float(this->size) * 100) << "%.\n";
}
//--------------------------------------------------------------------