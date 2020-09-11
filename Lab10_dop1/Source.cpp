#include<iostream>
#include<stdio.h>
#include<cmath>
//������ ����� �, �������� � ���� ��� ��������� �����, ��������� �� ����, �� ����������� ��� ������ A. ���������� ���� � ������ ������ ���� ����� �. 

#include <fstream>
#define SIZE 5

using namespace std;
int function(int A, int* arr);
int main()
{
	ofstream fout("file.txt");
	if (fout.fail())  //�������� �������� �����
	{
		cout << "\n ������ �������� �����";
		exit(1);
	}
	fout.close();
	setlocale(LC_CTYPE, "ru");
	int A, arr[SIZE];
	cout << "������� ����� �: ", cin >> A;
	cout << "������� 5 " << A << "-������� �����: " << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cin >> arr[i];
		if (arr[i] < pow(10, A - 1) || arr[i] >= pow(10,A))
		{
			cout << "�������� �� �-������� �����! ���������� ��� ���:" << endl;
			i--;
		}	
	}
	function(A, arr);
	cout << "������ �������� � ����" << endl;
	return 0;
}

int function(int A, int* arr)
{
	static int i = 0;
	if (i >= SIZE)
		return 0;
	
	ofstream fout;
	fout.open("file.txt", ios::app);
	if (fout.fail())  //�������� �������� �����
	{
		cout << "\n ������ �������� �����";
		exit(1);
	}
	bool check = true;
	char* temp = new char[A+1];
	sprintf_s(temp, A+1, "%d", arr[i]);
	for (int j = 0; j < A; j++)
	{
		if (temp[j] -'0' > A)
		{
			check = false;
			break;
		}
	}
	if (check == true)
		fout << arr[i] << " ";	
	i++;
	delete[] temp;
	fout.close();
	function(A, arr);
}