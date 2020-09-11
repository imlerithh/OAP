//var 4
//1. Скопировать из файла FILE1 в файл FILE2 все строки, которые не содержат цифры.Подсчитать ко - личество строк, которые начинаются на букву «А» в файле FILE2.
//2. Ввести с клавиатуры строку символов, состоящую из цифр и слов, разделенных пробелами, и запи - сать ее в файл.
// Прочитать из файла данные, подсчитать количество символов в самом длинном слове и вывести его.


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
//		cout << "Ошибка FILE1-1" << endl;
//	}
//
//	fout.open("FILE1-2.txt");
//
//	if (!fout.is_open())
//	{
//		cout << " 1Ошибка FILE1-2" << endl;
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
//		cout << "Ошибка FILE1-2" << endl;
//	}
//	int kolvo = 0;
//	string str1;
//	while (!fin1.eof())
//	{
//		fin1 >> str1;
//		if (str1[0] == 'a')
//			kolvo++;
//	}
//	cout << " количество строк, которые начинаются на букву «А» в файле " <<kolvo<< endl;
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
			cout << "Ошибка" << endl;
		}
		string str;
		cout << "Введите строку состоящую из групп цифр и слов 6 слов" << endl;
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
			cout << "Ошибка" << endl;
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
		cout << "самое длинное слово " << max << endl;
		fin.close();
}