#include <iostream>
#include <string>

#define BLACK 0
#define RED 1

using namespace std;

struct Tree //структура элемента дерева
{
	int key;
	bool color;
	Tree* left;
	Tree* right;
	Tree* parent;

}*head;
int add_k = 0;
void create(int); //Создание дерева
void add(int); //Добавление элементов в дерево
void output(); //Вывод дерева
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
		cout << "-----Меню-----" << endl;
		cout << "1. Создать дерево " << endl;
		cout << "2. Добавиить элемент " << endl;
		cout << "3. Вывести дерево на экран " << endl;
		cout << "4. Выход " << endl;
		cout << "------------------" << endl;
		cout << "Ваш выбор: ", cin >> choice;
		cout << endl;
		switch (choice)
		{

		case 1:
			cout << "Введите ключ корня: ", cin >> number;
			create(number);
			break;

		case 2:
			while (true)
			{
				cout << "Если хотите выйти - введите отрицательное число " << endl;
				cout << "Введите элемент: ", cin >> number;
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
			cout << "Такого пункта в меню нет! Попробуйте еще раз " << endl;
			break;
		}
	}
	Tree* iu = head;
	return 0;
}

void create(int data) //Создание дерева (корень черного цвета)
{
	add_k++;
	head = new Tree;
	head->key = data;

	head->left = new Tree; //Левый лист черный
	head->left->key = NULL;
	head->left->left = NULL;
	head->left->right = NULL;
	head->left->color = BLACK;

	head->right = new Tree; //Правый лист черный 
	head->right->key = NULL;
	head->right->left = NULL;
	head->right->right = NULL;
	head->right->color = BLACK;

	head->color = 0; //

	head->parent = NULL;
}
void add(int data) // Добавление элементов 
{
	add_k++;
	Tree* temp = head;
	Tree* buff = NULL;
	while (temp->key != NULL) //Добавление как в бинароном делеве
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

	temp->left = new Tree;  //Левый черный лист
	temp->left->key = NULL;
	temp->left->left = NULL;
	temp->left->right = NULL;
	temp->left->color = BLACK;

	temp->right = new Tree;//Правый черный лист
	temp->right->key = NULL;
	temp->right->left = NULL;
	temp->right->right = NULL;
	temp->right->color = BLACK;

	temp->color = RED; // Цвет вершины

	temp->parent = buff;

	if (data < buff->key) // Проверка на какую ветку добавить 
	{
		buff->left = temp;
	}
	else
	{
		buff->right = temp;
	}
	check_1(temp);
}
Tree* Dad(Tree* n) //Проверка на существование элементов 2 колена 
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
	if (n->parent == g->left) //Проверка на 
		return g->right;
	else
		return g->left;
}
void check_1(Tree* n) // Если это первый элемент (head) то цвет черный 
{
	if (n->parent == NULL)
		n->color = BLACK;
	else
		check_2(n);
}
void check_2(Tree* n)  //Проверка родителя на цвет
{
	if (n->parent->color == BLACK) //если черный возвращаемся и оставляем его красным 
		return;
	else
		check_3(n);
}
void check_3(Tree* n) //Проверка на колчество шагов от вершины до листа 
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

	pivot->parent = n->parent; /* при этом, возможно, pivot становится корнем дерева */
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

void print_Tree(Tree* temp, int level) //вывод дерева
{
	if (temp)
	{
		print_Tree(temp->left, level + 1);
		for (int i = 0; i < level; i++) cout << "   ";
		cout << temp->key << get_color(temp->color) << endl;
		print_Tree(temp->right, level + 1);
	}
}
void output() // Вывод дерева
{
	Tree* temp = new Tree;
	temp = head;
	while (temp->parent != NULL) //Ищем head
		temp = temp->parent;
	print_Tree(temp, 0);
}
//void output(Tree* temp, int level) // Вывод дерева
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