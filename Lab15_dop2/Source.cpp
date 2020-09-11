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
			cout << "������ �������� �����" << endl;
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
			cout << "\t\t�����: " << temp->str << "|\n";
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

	cout << "������� �����: "; cin >> searchNode;
	int i = HashFunction(searchNode);
	if (!this->table[i].next)
	{
		cout << "����� �� ����������.\n";
		return;
	}

	cout << "��� ��������� �����:\n";
	cout << " ������� �" << i << ":\n";

	Node* temp = this->table[i].next;

	while (temp)
	{
		cout << "\t\t�����: " << temp->str << "|\n";
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
	cout << "������� �����, ������� ������ �������: ", cin >> tempWord;
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
		cout << "����� �� �������" << endl;
}
//--------------------------------------------------------------------
void HashTable::FillPercent()
{
	cout << "\n�� ������ ������ ������� ��������� �� " << int(float(this->currentSize) / float(this->size) * 100) << "%.\n";
}
//--------------------------------------------------------------------