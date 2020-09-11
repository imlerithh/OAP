#include"Tree.h"


void main()
{
	setlocale(LC_ALL, "Russian");
	Tree* mainRoot = new Tree;
	int choice;

	while (1)
	{
		cout << "\n---------------------------------------\n";
		cout << "1. Добавление элементов.\n";
		cout << "2. Вывод дерева в консоль.\n";
		cout << "3. Удаление.\n";
		cout << "4. Прямой(нисходящий) обход с выводом.\n";
		cout << "5. Обратный(смешанный) обход с выводом.\n";
		cout << "6. Проверка на балансировку дерева\n";
		cout << "7. Вывод количества вершин дерева(13)\n";
		cout << "0. Выход.\n";
		cout << "---------------------------------------\n";

		cout << "Ваш выбор: "; cin >> choice; cout << endl;

		switch (choice)
		{
		case 1:
		{
			cout << "\nДобавление будет осуществляться пока вы не введёте отрицательное число. " << endl;
			cout << "Введите элемент: "; cin >> choice;
			while (choice > 0)
			{
				mainRoot->AddNode(choice);
				cout << "Введите элемент: "; cin >> choice;
			}
			break;
		}

		case 2:
		{
			if (!mainRoot->node) cout << "В дереве ничего нет.\n";
			else mainRoot->PrintTree(mainRoot->node, 0);
			break;
		}

		case 3:
		{
			int key;
			cout << "Введите ключ элемента который хотите удалить: "; cin >> key;
			mainRoot->Delete(key);
			break;
		}

		case 4:
		{
			if (!mainRoot->node) cout << "В дереве ничего нет.\n";
			else mainRoot->DirectBypass(mainRoot->node);
			break;
		}

		case 5:
		{
			if (!mainRoot->node) cout << "В дереве ничего нет.\n";
			else mainRoot->ReverseBypass(mainRoot->node);
			break;
		}
		case 6:
		{
			mainRoot->counter = 0;
			if (!mainRoot->node) cout << "В дереве ничего нет.\n";
			else
				if (mainRoot->Balance(mainRoot->node))
					cout << "Дерево сбалансировано" << endl;
				else
					cout << "Дерево не сбалансировано" << endl;
			break;
		}
		case 7:
		{
			mainRoot->counter = 0;
			cout << endl << "Количество вершин в дереве равно: " << mainRoot->amountOfBranches(mainRoot->node) << endl << endl;
			break;
		}
		case 0:
		{
			exit(0);
			break;
		}
		default:
		{
			cout << "Такого пункта нет. Выберете снова.\n";
			break;
		}

		}
	}
}


