// 13 
// countX (int x) � ������� �������� ����� ��������� ������ � �������� ��������� x.
#include <iostream>
using namespace std;
struct DoubleList //�������� ���� ������
{
	int data; //�������������� ����
	DoubleList* next; //��������� �� ��������� �������
	DoubleList* prev; //��������� �� ���������� �������
};
DoubleList* head; //��������� �� ������ ������� ������
//**********************���������� ��������**********************
void AddList(int value)
{
	DoubleList* node = new DoubleList; //�������� ������ ��������
	node->data = value; //���������� �������� ��������
	if (head == NULL) //���� ������ ����
	{
		node->next = node; //��������� ��������� next
		node->prev = node; //��������� ��������� prev
		head = node; //������������ ������ ������
	}
	else
	{
		DoubleList* p = head;
		p->prev->next = node;
		node->prev = p->prev;
		node->next = p;
		p->prev = node;
	}
	cout << "\n������� ��������...\n\n";
}
//***********************�������� ��������***********************
int DeleteList()
{
	if (head == NULL) { cout << "\n������ ����\n\n"; return 0; }
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
	cout << "\n������� ������...\n\n";
}
//*************************����� ������*************************
void PrintList()
{
	if (head == NULL) cout << "\n������ ����\n\n";
	else
	{
		DoubleList* a = head;
		cout << "\n�������� ������: ";
		do
		{
			cout << a->data << " ";
			a = a->next;
		} while (a != head); cout << "\n\n";
	}
}
void task(int x) {
	int count = 0;
	if (head == NULL) cout << "\n������ ����\n\n";
	else
	{
		DoubleList* a = head;
		do
		{
			if (a->data == x) count++;
			a = a->next;
		} while (a != head); cout << "���������� ��������� � �������� ���������: " << count << "\n\n";
	}
}

//************************������� �������************************
int main()
{
	setlocale(LC_ALL, "Rus");
	int value, position, x;
	do
	{
		cout << "1. �������� �������" << endl;
	//	cout << "2. ������� �������" << endl;
		cout << "2. ������� ������" << endl;
		cout << "3. �������" << endl;
		cout << "0. �����" << endl;
		cout << "\n����� �������� > "; cin >> x;
		switch (x)
		{
		case 1:
			cout << "�������� > "; cin >> value;
			AddList(value); break;
		//case 2:
			//DeleteList(); break;
		case 2: PrintList(); break;
		case 3: int x; cout << "������� ��������: ", cin >> x; task(x); break;
		}
	} while (x != 0);
	return 0;
}