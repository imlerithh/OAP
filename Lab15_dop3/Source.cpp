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
			f >> newElem->key;
			

			int position = HashFunction(newElem->key);
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
			cout << "\t\t�����: " << temp->key << "|\n";
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
	int searchNodeKey;
	
	cout << "������� �����: "; cin >> searchNodeKey;
	int i = HashFunction(searchNodeKey);
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
		cout << "\t\t�����: " << temp->key << "|\n";
		temp = temp->next;
	}
	cout << endl;

}
//--------------------------------------------------------------------
void HashTable::FillPercent()
{
	cout << "\n�� ������ ������ ������� ��������� �� " << int(float(this->currentSize) / float(this->size) * 100) << "%.\n";
}
//--------------------------------------------------------------------