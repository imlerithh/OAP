#include <ctime>             
#include <stdlib.h>
#include <iostream>
using namespace std;

int getHoarBorder(int A[], int sm, int em)
{
	int i = sm - 1, j = em + 1;
	int brd = A[sm];
	int buf;
	while (i < j)
	{
		while (A[--j] > brd);
		while (A[++i] < brd);
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

void sortBubble(int a[], int n)
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

int main()
{
	setlocale(LC_CTYPE, "Russian");
	const int N = 50000;
	int k[N], f[N];
	clock_t  t1, t2;
	srand(time(NULL));

	for (int i = 0; i < N; i++) {
		int rmin = 0;
		int rmax = 100000;
		f[i]  = (int)(((double)rand() / (double)RAND_MAX) * (rmax - rmin) + rmin);
	}
	for (int n = 10000; n <= N; n += 10000)
	{
		cout << "Array size = " << n << endl << endl;
		cout << "Bubble sort:\t";
		memcpy(k, f, n * sizeof(int));
		t1 = clock();
		sortBubble(k, n);
		t2 = clock();
		cout << t2 - t1 << " tacts of time" << endl;
		cout << "Select sort:\t";
		memcpy(k, f, n * sizeof(int));
		t1 = clock();
		selectSort(k, n);
		t2 = clock();
		cout << t2 - t1 << " tacts of time" << endl;
		cout << "Hoar sort:\t";
		memcpy(k, f, n * sizeof(int));
		t1 = clock();
		sortHoar(k, 0, n-1);
		t2 = clock();
		cout << t2 - t1 << " tacts of time" << endl << endl;
	}
	return 0;
}
