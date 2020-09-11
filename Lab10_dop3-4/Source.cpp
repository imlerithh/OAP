//dop3
//ƒано n различных натуральных чисел (n = 5). Ќапечатать все перестановки этих чисел.
//dop4
//ѕо заданному числу n определить символ, который стоит на n-ом месте последовательности, получившейс€ после шага c номером 26.

#include <algorithm>
#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

void dop3_4(int* arr, int n, int counter, int* temp)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << endl;
	if (counter == 26)
		*temp = arr[n - 1];
	if (next_permutation(arr, arr + n))
		dop3_4(arr, n, ++counter,temp);
}

int main() 
{
	setlocale(LC_ALL, "");
	int n=6, counter = 0, temp;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		*(arr + i) = i + 1;
	}
	dop3_4(arr, n, counter,&temp);
	cout << endl;
	cout << "ѕоследний элемент строки 26: " << temp << endl;
	delete[] arr;
	return 0;
}