#include <iostream>
#include "List.h"
using namespace std;

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "rus");
	int count, deleteIndex;

	cout << "������� ���������� ���������: ";
	cin >> count;
	cout << "����� ������� ������� ������ ���: ";
	cin >> deleteIndex;

	List<int> list;

	for (int i = 0; i < count; i++) {
		list.push_back(i + 1);
	}

	list.deleteIndexRepeat(deleteIndex);

	return EXIT_SUCCESS;
}