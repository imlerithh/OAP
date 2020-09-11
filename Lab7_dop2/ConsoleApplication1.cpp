#include"Header.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	int choice;
	Stack* myStk = new Stack; //выделение памяти для стека
	myStk->head = NULL;       //инициализация первого элемента	
	fromFile(myStk);
	show(myStk);
	myFunct(myStk);
	return 0;

}