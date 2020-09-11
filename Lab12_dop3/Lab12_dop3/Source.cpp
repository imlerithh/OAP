#include <iostream>
#include <string>

#define BLACK 0
#define RED 1

using namespace std;

struct Tree //��������� �������� ������
{
	int key;
	bool color;
	Tree* left;
	Tree* right;
	Tree* parent;

}*head;
int add_k = 0;
void create(int); //�������� ������
void add(int); //���������� ��������� � ������
void output(); //����� ������
void check_1(Tree*);
void check_2(Tree*);
void check_3(Tree*);
void check_4(Tree*);
void check_5(Tree*);
void rotate_right(Tree*);
void rotate_left(Tree*);
Tree* Dad(Tree*);
Tree* uncle(Tree*);

int main()
{
	setlocale(LC_CTYPE, "ru");
	int choice;
	int number;
	while (true)
	{
		cout << endl;
		cout << "-----����-----" << endl;
		cout << "1. ������� ������ " << endl;
		cout << "2. ��������� ������� " << endl;
		cout << "3. ������� ������ �� ����� " << endl;
		cout << "4. ����� " << endl;
		cout << "------------------" << endl;
		cout << "��� �����: ", cin >> choice;
		cout << endl;
		switch (choice)
		{

		case 1:
			cout << "������� ���� �����: ", cin >> number;
			create(number);
			break;

		case 2:
			while (true)
			{
				cout << "���� ������ ����� - ������� ������������� ����� " << endl;
				cout << "������� �������: ", cin >> number;
				if (number < 0)
					break;
				add(number);
			}
			break;
		case 3:
			output();
			break;
		case 4:
			cout << "Goodbye :)" << endl;
			exit(0);
			break;
		default:
			cout << "������ ������ � ���� ���! ���������� ��� ��� " << endl;
			break;
		}
	}
	Tree* iu = head;
	return 0;
}

void create(int data) //�������� ������ (������ ������� �����)
{
	add_k++;
	head = new Tree;
	head->key = data;

	head->left = new Tree; //����� ���� ������
	head->left->key = NULL;
	head->left->left = NULL;
	head->left->right = NULL;
	head->left->color = BLACK;

	head->right = new Tree; //������ ���� ������ 
	head->right->key = NULL;
	head->right->left = NULL;
	head->right->right = NULL;
	head->right->color = BLACK;

	head->color = 0; //

	head->parent = NULL;
}
void add(int data) // ���������� ��������� 
{
	add_k++;
	Tree* temp = head;
	Tree* buff = NULL;
	while (temp->key != NULL) //���������� ��� � ��������� ������
	{
		buff = temp;
		if (data > buff->key)
		{
			temp = temp->right;
		}
		else
		{
			temp = temp->left;
		}
	}

	temp->key = data;

	temp->left = new Tree;  //����� ������ ����
	temp->left->key = NULL;
	temp->left->left = NULL;
	temp->left->right = NULL;
	temp->left->color = BLACK;

	temp->right = new Tree;//������ ������ ����
	temp->right->key = NULL;
	temp->right->left = NULL;
	temp->right->right = NULL;
	temp->right->color = BLACK;

	temp->color = RED; // ���� �������

	temp->parent = buff;

	if (data < buff->key) // �������� �� ����� ����� �������� 
	{
		buff->left = temp;
	}
	else
	{
		buff->right = temp;
	}
	check_1(temp);
}
Tree* Dad(Tree* n) //�������� �� ������������� ��������� 2 ������ 
{
	if ((n != NULL) && (n->parent != NULL))
		return n->parent->parent;
	else
		return NULL;
}
Tree* uncle(Tree* n)
{
	Tree* g = Dad(n);
	if (g == NULL)
		return NULL;
	if (n->parent == g->left) //�������� �� 
		return g->right;
	else
		return g->left;
}
void check_1(Tree* n) // ���� ��� ������ ������� (head) �� ���� ������ 
{
	if (n->parent == NULL)
		n->color = BLACK;
	else
		check_2(n);
}
void check_2(Tree* n)  //�������� �������� �� ����
{
	if (n->parent->color == BLACK) //���� ������ ������������ � ��������� ��� ������� 
		return;
	else
		check_3(n);
}
void check_3(Tree* n) //�������� �� ��������� ����� �� ������� �� ����� 
{
	Tree* u = uncle(n), * g;
	if ((u != NULL) && (u->color == RED)) {

		n->parent->color = BLACK;
		u->color = BLACK;
		g = Dad(n);
		g->color = RED;
		check_1(g);
	}
	else {
		check_4(n);
	}
}
void check_4(Tree* n)
{
	Tree* g = Dad(n);

	if ((n == n->parent->right) && (n->parent == g->left)) {
		rotate_left(n->parent);
		n = n->left;
	}
	else if ((n == n->parent->left) && (n->parent == g->right)) {
		rotate_right(n->parent);
		n = n->right;
	}
	check_5(n);
}
void check_5(Tree* n)
{
	Tree* g = Dad(n);

	n->parent->color = BLACK;
	g->color = RED;
	if ((n == n->parent->left) && (n->parent == g->left)) {
		rotate_right(g);
	}
	else {
		rotate_left(g);
	}
}
void rotate_left(Tree* n)
{
	Tree* pivot = n->right;
	pivot->parent = n->parent;
	if (n->parent != NULL) {
		if (n->parent->left == n)
			n->parent->left = pivot;
		else
			n->parent->right = pivot;
	}

	n->right = pivot->left;
	if (pivot->left != NULL)
		pivot->left->parent = n;

	n->parent = pivot;
	pivot->left = n;
}

void rotate_right(Tree* n)
{
	Tree* pivot = n->left;

	pivot->parent = n->parent; /* ��� ����, ��������, pivot ���������� ������ ������ */
	if (n->parent != NULL) {
		if (n->parent->left == n)
			n->parent->left = pivot;
		else
			n->parent->right = pivot;
	}

	n->left = pivot->right;
	if (pivot->right != NULL)
		pivot->right->parent = n;

	n->parent = pivot;
	pivot->right = n;
}

char get_color(bool x)
{
	if (x)
		return 'r';
	else
		return 'b';
}

void print_Tree(Tree* temp, int level) //����� ������
{
	if (temp)
	{
		print_Tree(temp->left, level + 1);
		for (int i = 0; i < level; i++) cout << "   ";
		cout << temp->key << get_color(temp->color) << endl;
		print_Tree(temp->right, level + 1);
	}
}
void output() // ����� ������
{
	Tree* temp = new Tree;
	temp = head;
	while (temp->parent != NULL) //���� head
		temp = temp->parent;
	print_Tree(temp, 0);
}
//void output(Tree* temp, int level) // ����� ������
//{ 
//	if (temp)
//	{
//		output(temp->right, level + 1);
//		for (int i = 0; i < level; i++)
//			cout << "   ";
//		cout << temp->key << get_color(temp->color) << endl;
//		output(temp->left, level + 1);
//	}
//}