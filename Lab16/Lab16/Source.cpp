#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

//вставкой по убыванию
void insertSort(int* A, int size)
{
	int t, i, j;
	for (i = 1; i < size; i++)
	{
		t = A[i];
		for (j = i - 1; j >= 0 && A[j] < t; j--)
			A[j + 1] = A[j];
		A[j + 1] = t;
	}
}

//выбором по возрастанию
void selectSort(int A[], int size)
{
	int k, i, j;
	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1, k = i; j < size; j++)
			if (A[j] < A[k])
				k = j;
		int c = A[k];
		A[k] = A[i];
		A[i] = c;
	}
}

//пузырьком по убыванию
void bubbleSortDes(int a[], int n)
{
	int i, j, t;
	for (i = 1; i < n; i++)
		for (j = n - 1; j >= i; j--)
			if (a[j - 1] < a[j])
			{
				t = a[j - 1];
				a[j - 1] = a[j];
				a[j] = t;
			}
}
//пузырьком по Возрастанию
void bubbleSortAsc(int a[], int n)
{
	int i, j, t;
	for (i = 1; i < n; i++)
		for (j = n - 1; j >= i; j--)
			if (a[j - 1] > a[j])
			{
				t = a[j - 1];
				a[j - 1] = a[j];
				a[j] = t;
			}
}
//Хоара по убыванию
int getHoarBorder(int A[], int sm, int em)
{
	int i = sm - 1, j = em + 1;
	int brd = A[sm];
	int buf;
	while (i < j)
	{
		while (A[--j] < brd);
		while (A[++i] > brd);
		if (i < j)
		{
			buf = A[j];
			A[j] = A[i];
			A[i] = buf;
		};
	}
	return j;
}
int* sortHoar(int A[], int sm, int em)
{
	if (sm < em)
	{
		int hb = getHoarBorder(A, sm, em);
		sortHoar(A, sm, hb);
		sortHoar(A, hb + 1, em);
	}
	return A;
};
//ВАРИАНТЫ
void fun1(int A[], int aSize) {
	int bSize = (aSize + 1) / 2;
	int* B = new int[bSize];
	int aInd = 0;
	for (int i = 0; i < bSize; aInd += 2, i++) {
		B[i] = A[aInd];
	}

	cout << "Initial B array:\n";
	for (int i = 0; i < bSize; i++) {
		cout << B[i] << " ";
	}
	cout << endl;
//bubble sort
	/*bubbleSortDes(B, bSize);

	cout << "B array after bubble sort:\n";
	for (int i = 0; i < bSize; i++) {
	cout << B[i] << " ";
	}
	cout << endl;*/
//insert sort
	insertSort(B, bSize);

	cout << "B array after insert sort:\n";
	for (int i = 0; i < bSize; i++) {
		cout << B[i] << " ";
	}
	cout << endl;
}
void fun12(int A[], int aSize) {
	int bSize = (aSize + 1) / 2;
	int* B = new int[bSize];
	int aInd = 0;
	for (int i = 0; i < bSize; aInd += 2,i++) {
		B[i] = A[aInd];
	}

	cout << "Initial B array:\n";
	for (int i = 0; i < bSize; i++) {
		cout << B[i] << " ";
	}
	cout << endl;
//bubble sort
	/*bubbleSortAsc(B, bSize);

	cout << "B array after bubble sort:\n";
	for (int i = 0; i < bSize; i++) {
		cout << B[i] << " ";
	}
	cout << endl;*/
//select sort
	selectSort(B, bSize);

	cout << "B array after select sort:\n";
	for (int i = 0; i < bSize; i++) {
		cout << B[i] << " ";
	}
	cout << endl;
}


void fun3(int A[], int aSize) {
	int max = A[0], iMax = 0;
	for (int i = 1; i < aSize; i++) {
		if (A[i] > max) { max = A[i]; iMax = i; }
	}
	cout << "Max element in A array: " << max << "; Its index: " << iMax << endl;

	int bSize = (aSize - 1 - iMax) / 2;
	int* B = new int[bSize];
	for (int i = 0; iMax < aSize; iMax++) {
		if (iMax % 2 != 0) { B[i] = A[iMax]; i++; }
	}

	cout << "Initial B array:\n";
	for (int i = 0; i < bSize; i++) {
		cout << B[i] << " ";
	}
	cout << endl;
	//bubble sort
	bubbleSortDes(B, bSize);

	cout << "B array after bubble sort:\n";
	for (int i = 0; i < bSize; i++) {
		cout << B[i] << " ";
	}
	cout << endl;
	//Hoar sort
		/*B = sortHoar(B, 0, bSize - 1);

		cout << "B array after Hoar sort:\n";
		for (int i = 0; i < bSize; i++) {
			cout << B[i] << " ";
		}*/
}
void fun13(int A[], int aSize) {
	int max = A[0], iMax = 0;
	for (int i = 1; i < aSize; i++) {
		if (A[i] > max) { max = A[i]; iMax = i; }
	}
	cout << "Max element in A array: " << max << "; Its index: " << iMax << endl;
	
	int bSize = (aSize - 1 - iMax) / 2;
	int* B = new int[50];
	for (int i = 0; iMax < aSize; iMax++) {
		if (iMax % 2 == 0) { B[i] = A[iMax]; i++; }
	}

	cout << "Initial B array:\n";
	for (int i = 0; i < bSize; i++) {
		cout << B[i] << " ";
	}
	cout << endl;
//bubble sort
	/*bubbleSortDes(B, bSize);

	cout << "B array after bubble sort:\n";
	for (int i = 0; i < bSize; i++) {
		cout << B[i] << " ";
	}
	cout << endl;*/
//Hoar sort
	B = sortHoar(B, 0, bSize - 1);

	cout << "B array after Hoar sort:\n";
	for (int i = 0; i < bSize; i++) {
		cout << B[i] << " ";
	}
}
int main() {
	int const aSize = 20;
	srand(time(NULL));
	int A[50];

	int choice;
	while (true) {
		cout << "\n";
		cout << "A array:\n";
		for (int i = 0; i < aSize; i++) {
			A[i] = rand() % 30 + 1;
			cout << A[i] << " ";
		}
		cout << "\n\n";

		cout << "Enter the choice:\n";
		cout << "1 - 13 variant\n";
		cout << "2 - 3 variant\n";
		cout << "3 - 12 variant\n";
		cout << "4 - 1 variant\n";
		cout << "0 - exit\n";
		cin >> choice;
		switch (choice) {
		case 1: fun13(A, aSize); break;
		case 2: fun3(A, aSize);  break;
		case 3: fun12(A, aSize); break;
		case 4: fun1(A, aSize);  break;
		case 0: exit(0);
		default: cout << "Wrong option"; break;
		}
	}
}