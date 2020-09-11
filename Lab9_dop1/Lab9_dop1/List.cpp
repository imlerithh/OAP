#include "List.h"
#include<iostream>
void insert(Person* e, Person** phead, Person** plast) //���������� � ����� ������
{
	Person* p = *plast;
	if (*plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
}

Person* setElement()      // �������� �������� � ���� ��� �������� � ���������� 
{
	Person* temp = new  Person();
	if (!temp)
	{
		cerr << "������ ��������� ������ ������";
		return NULL;
	}
	cout << "������� ���: ";
	cin.getline(temp->name, NAME_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	cout << "������� �������: ";
	cin >> temp->age;
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

void outputList(Person** phead, Person** plast)      //����� ������ �� �����
{
	Person* t = *phead;
	if (t == NULL)
	{
		cout << "������ ����" << endl;
		return;
	}
	while (t)
	{
		cout << "���: " << t->name << " " << "�������: " << t->age << endl;
		t = t->next;
	}
	cout << endl;
}

void find(char name[NAME_SIZE], Person** phead)    // ����� ����� � ������
{
	Person* t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name)) break;
		t = t->next;
	}
	if (!t)
		cerr << "��� �� �������" << endl;
	else
		cout << t->name << ' ' << t->age << endl;
}

void delet(char name[NAME_SIZE], Person** phead, Person** plast) // �������� �����
{
	struct Person* t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name))  break;
		t = t->next;
	}

	if (!t)
		cerr << "��� �� �������" << endl;
	else
	{
		if (*phead == t)
		{
			*phead = t->next;
			if (*phead)
				(*phead)->prev = NULL;
			else
				*plast = NULL;
		}
		else
		{
			t->prev->next = t->next;
			if (t != *plast)
				t->next->prev = t->prev;
			else
				*plast = t->prev;
		}
		delete t;
		cout << "������� ������" << endl;
	}
}

void writeToFile(Person** phead)       //������ � ����
{
	struct Person* t = *phead;
	FILE* fp;
	errno_t err = fopen_s(&fp, "mlist", "wb");
	if (err)
	{
		cerr << "���� �� �����������" << endl;
		exit(1);
	}
	cout << "���������� � ����" << endl;
	while (t)
	{
		fwrite(t, sizeof(struct Person), 1, fp);
		t = t->next;
	}
	fclose(fp);
}

void readFromFile(Person** phead, Person** plast)          //���������� �� �����
{
	struct Person* t;
	FILE* fp;
	errno_t err = fopen_s(&fp, "mlist", "rb");
	if (err)
	{
		cerr << "���� �� �����������" << endl;
		exit(1);
	}
	while (*phead)
	{
		*plast = (*phead)->next;
		delete* phead;
		*phead = *plast;
	}
	*phead = *plast = NULL;
	cout << "�������� �� �����" << endl;
	while (!feof(fp))
	{
		t = new Person();
		if (!t)
		{
			cerr << "������ ��������� ������" << endl;
			return;
		}
		if (1 != fread(t, sizeof(struct Person), 1, fp)) break;
		insert(t, phead, plast);
	}
	fclose(fp);
}

void deleteList(Person** phead, Person** plast) // �������� ������
{
	struct Person* t = *phead;
	if (*phead == NULL)
	{
		cout << "������ ����" << endl;
		return;
	}

	while (*phead != NULL)
	{
		*phead = t->next;
		t = t->next;
		if (*phead)
			(*phead)->prev = NULL;
		else
			*plast = NULL;

	}
	delete t;
	cout << "������� ������" << endl;
}
void countList(Person** phead, Person** plast)
{
	int counter = 0;
	struct Person* t = *phead;
	if (*phead == NULL)
	{
		cout << "������ ����" << endl;
		return;
	}
	while (t != NULL)
	{
		t = t->next;
		counter++;
	}
	cout << "���������� ��������� � ������: " << counter << endl;
}