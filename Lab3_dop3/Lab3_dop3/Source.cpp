//var 4
//1. ����������� �� ����� FILE1 � ���� FILE2 ��� ������, ������� �� �������� �����.���������� �� - �������� �����, ������� ���������� �� ����� ��� � ����� FILE2.
//2. ������ � ���������� ������ ��������, ��������� �� ���� � ����, ����������� ���������, � ���� - ���� �� � ����.
// ��������� �� ����� ������, ���������� ���������� �������� � ����� ������� ����� � ������� ���.


//#include <iostream>
//#include <fstream>
//#include <string>
//
//
//int main()
//{
//	using namespace std;
//	setlocale(LC_ALL, "ru");
//	ofstream fout;
//	ifstream fin;
//	fin.open("FILE1-1.txt");
//
//	if (!fin.is_open())
//	{
//		cout << "������ FILE1-1" << endl;
//	}
//
//	fout.open("FILE1-2.txt");
//
//	if (!fout.is_open())
//	{
//		cout << " 1������ FILE1-2" << endl;
//	}
//
//	char ch;
//	char ch1[50];
//	while (!fin.eof())
//		{
//			int a = 0;
//			fin.getline(ch1, 50);
//
//			for (int i = 0; i < strlen(ch1); i++)
//			{
//				if (ch1[i] == '1' || ch1[i] == '2' || ch1[i] == '3' ||
//					ch1[i] == '4' || ch1[i] == '5' || ch1[i] == '6' ||
//					ch1[i] == '7' || ch1[i] == '8' || ch1[i] == '9' ||
//					ch1[i] == '0')
//				{
//					a++;
//				}
//			}
//			if (a == 0)
//			{
//				fout << ch1 << endl;
//			}
//		}
//
//	fin.close();
//	fout.close();
//
//	ifstream fin1;
//	fin1.open("FILE1-2.txt");
//
//	if (!fin1.is_open())
//	{
//		cout << "������ FILE1-2" << endl;
//	}
//	int kolvo = 0;
//	string str1;
//	while (!fin1.eof())
//	{
//		fin1 >> str1;
//		if (str1[0] == 'a')
//			kolvo++;
//	}
//	cout << " ���������� �����, ������� ���������� �� ����� ��� � ����� " <<kolvo<< endl;
//
//	fin1.close();
//}




#include <iostream>
#include <fstream>
#include <string>


int main()
{
	using namespace std;
	setlocale(LC_ALL, "ru");

	ofstream fout;
		fout.open("t1.txt");
	
		if (!fout.is_open())
		{
			cout << "������" << endl;
		}
		string str;
		cout << "������� ������ ��������� �� ����� ���� � ���� 6 ����" << endl;
		for (int i = 0; i <= 5; i++)
		{
			cin >> str;
			fout << str<<" ";
			
		}
	
		fout.close();

		ifstream fin;
		fin.open("t1.txt");

		if (!fin.is_open())
		{
			cout << "������" << endl;
		}
		char str1[50];
		int test = 0;
		int max = 0;
		while (!fin.eof())
		{
			
			fin >> str1;
			test=strlen(str1);
			if (max < test)
			{
				max = test;
			}
		}
		cout << "����� ������� ����� " << max << endl;
		fin.close();
}