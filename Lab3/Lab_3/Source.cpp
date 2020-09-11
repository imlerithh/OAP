//1. Скопировать из файла FILE1 в файл FILE2 все строки, в которых более 2 слов.Определить номер слова, в котором больше всего гласных букв.
//2. Ввести с клавиатуры строку символов, состоящую из цифр и скобок, и записать ее в файл.Прочитать из файла данные, посчитать и вывести 
//количество скобок различного вида.

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void task1() {
	ifstream fin;
	ofstream fout;
	fin.open("File1.txt");
	fout.open("File2.txt");
	int indexes[10];
	if (!fin.is_open())
	{
		cout << "File couldn't be open" << endl;
	}
	else {
		cout << "Start working with file" << endl;
		char ch;
		char alphabet[] = { 'A','a','E','e','I','i','O','o','U','u','Y','y' };
		int LineIndex = 1, i = 0, CountOfVowels = 0, WordIndex = 1, maxVowels, maxVowelsIndex;
		bool sameLine = false;
		while (fin.get(ch)) {
			for (int l = 0; l < sizeof(alphabet) / sizeof(alphabet[0]); l++) {
				if (alphabet[l] == ch) {
					CountOfVowels++;
					break;
				}
			}
			if (ch == ' ') {
				if (!sameLine) {
					indexes[i] = LineIndex;
					i++;
				}

				if (WordIndex != 1) {
					if (CountOfVowels > maxVowels) {
						maxVowels = CountOfVowels;
						maxVowelsIndex = WordIndex;
					}
				}
				if (WordIndex == 1) {
					maxVowels = CountOfVowels;
					maxVowelsIndex = 1;
				}
				CountOfVowels = 0;
				WordIndex++;
				sameLine = true;
			}
			if (ch == '\n') {
				LineIndex++;

				if (WordIndex != 1) {
					if (CountOfVowels > maxVowels) {
						maxVowels = CountOfVowels;
						maxVowelsIndex = WordIndex;
					}
				}
				if (WordIndex == 1) {
					maxVowels = CountOfVowels;
					maxVowelsIndex = 1;
				}
				CountOfVowels = 0;
				WordIndex++;
				sameLine = false;
			}
		}
		cout << "Index of the word with biggest amount of vowels - " << maxVowelsIndex << endl;
	}
	fin.close();
	ifstream finn;
	finn.open("File1.txt");
		string str;		
		if (!fout.is_open())
		{
			cout << "File couldn't be open" << endl;
		}
		else if (!fout.is_open())
			cout << "File couldn't be open" << endl;
		else {	int line = 1;
			while (!finn.eof()) {
				str = "";
				getline(finn, str);
				for (int i = 0; i < sizeof(indexes) / sizeof(indexes[0]); i++) {
						if (line == indexes[i]) {
							fout << str << "\n";
							break;
						}
				}
				line++;
			}
			cout << "Data succesfully recorded to the File2";
		}
	finn.close();
	fout.close();
}
void task2() {
	ifstream fin;
	ofstream fout;
	char brackets[] = { '{','}','[',']','(',')' };
	fout.open("FileA.txt");
	string str;
	cout << "Enter the string ", cin >> str;
	if (!fout.is_open())
	{
		cout << "File couldn't be open" << endl;
	}
	else {
		fout << str;
	}
	fout.close();
	fin.open("FileA.txt");
	if (!fin.is_open())
	{
		cout << "File couldn't be open" << endl;
	}
	else {
		char ch;
		int bracketsCount = 0;
		while (fin.get(ch)) {
			for (int i = 0; i < 6; i++) {
				if (brackets[i] == ch) bracketsCount++;
			}
		}
		cout << "Amount of brackets - " << bracketsCount << endl;
	}
	fin.close();
}
int main() {
	int number;
	cout << "Hi, enter the number of the task: ", cin >> number;
	switch (number) {
	case 1: task1();
	case 2: task2();
	default: cout << "There is no task with this number";
	}
	return 0;
}