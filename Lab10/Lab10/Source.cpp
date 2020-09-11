//13
// Разработать программу, реализующую рекурсивную функцию подсчета количества всех положительных делителей натурального числа n.

//15
// Разработать программу, реализующую рекурсивный алгоритм вычисления значений S(x) для любых целых не отрицательных значений x.

#include <iostream>
using namespace std;

int fun13(int n, int x) {
	int temp = 0;
	if (x == 0) return 0;
	if (n % x == 0) temp = 1;

	return fun13(n, x - 1) + temp;
}

int fun15(int x) {
	if (x > 100) return x + 10;
	else return fun15(fun15(x+4));
}

int main() {
	setlocale(LC_ALL, "rus");
//13
//	cout << fun13(99, 99) << endl;
//15
	cout << fun15(110) << endl;

	system("pause");
	return 0;
}
 
