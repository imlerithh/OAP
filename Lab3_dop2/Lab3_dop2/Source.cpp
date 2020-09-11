//var 8
//1. Скопировать из файла FILE1 в файл FILE2 все строки, кроме той строки, в которой больше всего гласных букв.Напечатать номер этой строки.
//2. Ввести с клавиатуры строку символов, состоящую из букв, цифр, запятых, точек, знаков +, и записать ее в файл.Прочитать из файла данные 
//и вывести подстроку, которая соответствует записи вещественного числа с фиксированной точкой.

#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

//1
//void main()
//
//{
//	setlocale(LC_ALL, "rus");
//	fstream f1, f2;
//	string stroka;
//	int gl = 0,i=0,gl2=0,j=0;
//	int M[10],max=0,el=0,num=0;
//	f1.open("FILE1.txt", fstream::in);
//	f2.open("FILE2.txt", fstream::out);
//	while (!f1.eof())
//	{
//		gl = 0;
//		getline(f1, stroka);
//		for (i=0; stroka[i] != '.'; i++)
//		{
//
//			if (stroka[i] == 'у' || stroka[i] == 'е'|| stroka[i] == 'ы'|| stroka[i] == 'а'|| stroka[i] == 'о'|| stroka[i] == 'э'|| stroka[i] == 'я'|| stroka[i] == 'и'|| stroka[i] == 'ю')
//			{
//				gl++;
//			}
//		}
//		M[j] = gl;
//		el++;
//		if (M[j] > M[j - 1]) {
//			max = M[j];
//			num = el;
//		}
//			j++;
//	}
//	f1.close(); f2.close();
//	f1.open("FILE1.txt", fstream::in);
//	f2.open("FILE2.txt", fstream::out);
//	i = 0;
//	while (!f1.eof())
//	{
//		getline(f1, stroka);
//			if (M[i] != max)
//				f2 << stroka << "\n";
//			i++;
//	}
//	f2 << num << '\n';
//	f1.close(); f2.close();
//}

// 2
void main()
{
	setlocale(LC_ALL, "rus");
	fstream f3;
	string stroka;
	f3.open("FILE3.txt", fstream::out);
	cin >> stroka;
	f3 << stroka << '\n';
	f3.close();
	f3.open("FILE3.txt", fstream::in);
	int i = 0, toch = 0, j = 0;
	char M[4] = " ";
	while (!f3.eof())
	{
		getline(f3, stroka);
		while (stroka[i] != '\n')
		{
			if (stroka[i] >= '0' && stroka[i] <= '9' && stroka[i - 1] == '.' && stroka[i - 2] >= '0' && stroka[i - 2] <= '9')
			{
				M[j] = stroka[i - 2];
				j++;
				M[j] = stroka[i - 1];
				j++;
				M[j] = stroka[i];
				cout << "<<< " << M << " >>>" << '\n';
				break;
			}
			i++;
		}
		break;
	}
	f3.close();
}