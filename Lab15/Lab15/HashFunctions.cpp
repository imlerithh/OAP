#include "Hash.h"

//--------------------------------------------------------------------
int HashTable::HashFunction(string hashString, int hashKey)
{
	return ((hashString.size() ^ hashKey) % this->size);
}
//--------------------------------------------------------------------
void HashTable::Insert()
{
	if (this->currentSize < this->size)
	{
		Node* newElem = new Node;
		Node* temp;

		cout << "\n������� ����� ������: ";	cin >> newElem->groupNumber;
		cout << "������� �������: ";		cin >> newElem->surname; cout << endl;

		int position = HashFunction(newElem->surname, newElem->groupNumber);
		temp = this->table[position].next;

		if (!temp)
		{
			this->table[position].next = newElem;
			this->table[position].next->prev = &this->table[position];
			this->currentSize++;
			return;
		}

		while (true)
		{
			if (!temp->next)
			{
				temp->next = newElem;
				temp->next->prev = temp;

				this->currentSize++;
				return;
			}
			else
				temp = temp->next;
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
			cout << "|�������: " << temp->surname << "\t\t����� ������: " << temp->groupNumber << "|\n";
			temp = temp->next;
		}
		cout << endl;

	}
	cout << "\n-----------------------------------------------------------------------------------------------------------\n";
}
//--------------------------------------------------------------------
void HashTable::DeleteNode()
{
	int delElemKey; string delElemStr; Node* temp;
	cout << "\n����� ������: ";	cin >> delElemKey;
	cout << "������� ������� "; cin >> delElemStr;
	cout << endl;
	int position = HashFunction(delElemStr, delElemKey);
	if (!this->table[position].next)
	{
		cout << "����� � ����� ������� ���.\n";
		return;
	}

	temp = this->table[position].next;

	while (temp->surname != delElemStr)
	{

		if (!temp)
		{
			cout << "��������� � ����� �������� ���.\n";
			return;
		}
		temp = temp->next;
	}

	if (temp == this->table[position].next)
	{
		this->table[position].next = temp->next;
		this->table[position].prev = nullptr;
		if (this->table[position].next)
			this->table[position].next->prev = &this->table[position];
		delete temp;
		this->currentSize--;
		cout << "���������� � �������� �������.\n";
		return;
	}

	if (temp->next = nullptr)
	{
		temp->prev->next = nullptr;
		delete temp;
		this->currentSize--;
		cout << "���������� � �������� �������.\n";
		return;
	}

	temp->next->prev = temp->prev;
	temp->prev->next = temp->next;
	delete temp;
	this->currentSize--;

	cout << "���������� � �������� �������.\n";

}
//--------------------------------------------------------------------
void HashTable::SearchNodes()
{
	int searchNodeKey;
	string searchString;
	cout << "������� ����� ������: "; cin >> searchNodeKey;
	cout << "������� �������: "; cin >> searchString; cout << endl;

	int i = HashFunction(searchString, searchNodeKey);
	if (!this->table[i].next)
	{
		cout << "��������� �� ����������.\n";
		return;
	}

	cout << "��� ��������� ��������:\n";
	cout << " ������� �" << i << ":\n";

	Node* temp = this->table[i].next;

	while (temp)
	{
		cout << "|�������: " << temp->surname << "\t\t����� ������: " << temp->groupNumber << "|\n";
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