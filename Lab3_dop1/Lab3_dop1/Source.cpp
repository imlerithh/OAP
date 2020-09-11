//var 12
//1. ����������� �� ����� FILE1 � ���� FILE2 ��� ������, � ������� ���� �����, ����������� � ������ ������.���������� ���������� ��������� ���� � ��������� ������  
//����� FILE2.
//2. ������ � ���������� ������ ��������, ��������� �� ����, ����, �������, �����, ������ + , � ���� - ���� �� � ����.��������� �� ����� ������ � ��������� 
//� ������� ���������� �������.

#include <iostream>
#include<fstream>
using namespace std;

//������� 1

int Task1()
{

	char str[50];
	char firstWord[8];
	char strTemp[15] = { " " };

	ifstream fileIn("FileA.txt");
	ofstream fileOut("Result.txt");
	if (!fileIn.is_open())
	{
		cout << "������ �������� �����" << endl;
		return EXIT_FAILURE;
	}

	if (!fileOut.is_open())
	{
		cout << "������ �������� �����" << endl;
		return EXIT_FAILURE;
	}

	fileIn >> firstWord;
	cout << "������ ����� �� �����: " << firstWord << endl;
	while (!fileIn.eof())
	{
		fileIn.getline(str, 50);
		for (int i = 0, j = 0; i < strlen(str); i++)
		{
			if (str[i] != ' ')
			{
				strTemp[j] = str[i];
				j++;

			}
			else
			{
				if (strcmp(strTemp, firstWord) == 0)
				{
					for (int k = 0; k < strlen(str); k++)
					{
						fileOut << str[k];
					}

				}
				else
					j = 0;
			}
		}
	}

	int counterConstants = 0;
	char constants[20] = { 'B','C','D','F','G','H','J','K','L','M','N','P','Q','R','S','T','V','W','X','Z' };
	for (int i = 0; i < strlen(str); i++)
	{
		str[i] = toupper(str[i]);
		for (int j = 0; j < strlen(constants); j++)
		{
			if (str[i] == constants[j])
			{
				counterConstants++;

			}
		}

	}
	cout << "���������� ��������� � ��������� ������ ����� " << counterConstants << endl;
	cout << "������ �������� � ����" << endl;

	return 0;
}



	//������� 2


int Inputfile(char* str,int& temp)
{
	ofstream Infile("Input.txt");
	if (!Infile.is_open())
	{
		cout << "������ �������� �����!" << endl;
		return EXIT_FAILURE;
	}
	for (int i = 0; i < temp; i++)
	{
		Infile << *(str + i);
	}
	
	cout << "������ �������� � ����" << endl;
	Infile.close();

	return 0;

}

int OutputFile(char* outstr)
{
	ifstream Outfile("Input.txt");

	if (!Outfile.is_open())
	{
		cout << "������ �������� �����!" << endl;
		return EXIT_FAILURE;
	}

	Outfile.getline(outstr,100);
	cout << "������ �������� �� �����" << endl;

	int counterVirgle = 0;
	for (int i = 0; i < strlen(outstr); i++)
	{
		if (*(outstr + i) == ',')
			counterVirgle++;
	}

	cout << "���������� ������� � ������ ����� " << counterVirgle << endl;
	Outfile.close();
}

int Task2()
{
	cout << "������� ������: " << endl;
	char* str = new char[100];
	gets_s(str, 100);
	cout << "��������� ������: ";
	puts(str);
	int temp = strlen(str);
	Inputfile(str,temp);

	char* outstr = new char[100];

	OutputFile(outstr);


	
	delete[] outstr;
	delete[] str;
	return 0;
}




int main()
{
	setlocale(LC_CTYPE, "ru");
	
//	Task1();
	Task2();
	
	return 0;
}