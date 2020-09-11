#include "Header.h"

using namespace std;

int main(void)
{
	setlocale(LC_ALL, "");

	MyTree<int> tree;
	tree.push_back(10);			
	tree.push_back(22);
	tree.push_back(11);
	tree.push_back(20);
	tree.push_back(32);
	tree.push_back(13);
	tree.push_back(21);
	tree.push_back(33);
	std::cout << endl;
	setlocale(LC_CTYPE, "Rus");
	char s[80];  int c;
	while (true)
	{
		std::cout << endl;
		std::cout << "1. Ввод элемента" << endl;
		std::cout << "2. Вывод на экран" << endl;
		std::cout << "3. Удаление списка" << endl;
		std::cout << "0. Выход" << endl;
		std::cout << endl;
		do
		{
			std::cout << "Ваш выбор: ";
			cin >> c;
		} while (c < 0 || c > 3);

		switch (c)
		{
		case 1:
		{
			int key;
			std::cout << endl << "key = ";
			std::cin >> key;
			tree.push_back(key);
			break;
		case 2:	tree.out_tree();
			break;
		case 3:
			tree.pop();
			break;
		case 0: exit(0); break;
		default: exit(1);
			break;
		}
		}
	}
	tree.pop();
	return 0;
}