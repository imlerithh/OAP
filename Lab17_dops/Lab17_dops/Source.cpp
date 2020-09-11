#include<iostream>
#include<ctime>
using namespace std;

void FillArray(int * arr, int size) {
	srand(time(NULL));
	cout << "Array:\n";
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 50 + 1;
		cout << arr[i] << " ";
	}
	cout << endl;
}

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


void dop2(){
	int n;
	cout << "Enter the size of the array: ", cin >> n;
	int* A = new int[n];
	FillArray(A, n);
	int max = A[0], min = A[0], maxI = 0, minI = 0;
	for (int i = 1; i < n; i++) {
		if (A[i] <= min) { min = A[i]; minI = i; } 
		if (A[i] >= max) { max = A[i]; maxI = i; }
	}
	cout << "Max element of the array: " << max << "; Its index: " << maxI << endl;
	cout << "Min element of the array: " << min << "; Its index: " << minI << endl;
	delete[] A;
}

void dop3() {
	int n = 10;
	int* A = new int[n];
	FillArray(A, n);
	selectSort(A, 4);
	insertSort(A + 6, 4);
	cout << "Array after sort:\n";
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
	delete[] A;
}

void dop4() {
	int n = 15;
	int* A = new int[n];
	srand(time(NULL));
	cout << "Array:\n";
	for (int i = 0; i < n; i++) {
		A[i] = rand() % 11 - 5;
		cout << A[i] << " ";
	}
	cout << endl;
	selectSort(A, n);
//deleting duplicate elements
	for (int i = 0; i < n; i++) {
		if (A[i] == A[i + 1]) {
			for (int j = i, count = 0; count < n - i; j++, count++)
				A[j] = A[j + 1];
			n--;
			i--;
		}
	}
	cout << "Array after sort and deleting the same elements:\n";
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
	delete[] A;
}

int main() {
	int choice;
	while (true) {
		cout << "1 - Dop number 2\n";
		cout << "2 - Dop number 3\n";
		cout << "3 - Dop number 4\n";
		cout << "0 - exit\n";
		cout << "Enter the choice: ", cin >> choice;
		switch (choice) {
		case 1:	cout << "--------------------" << endl; dop2(); cout << "--------------------" << endl; break;
		case 2:	cout << "--------------------" << endl; dop3(); cout << "--------------------" << endl; break;
		case 3:	cout << "--------------------" << endl; dop4(); cout << "--------------------" << endl; break;
		case 0:	exit (0); break;
		default: cout << "You entered the wrong number\n"; break;
		}
	}




	return 0;
}