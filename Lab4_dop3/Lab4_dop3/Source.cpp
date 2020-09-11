#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <iomanip>
using namespace std;
int zapis(string path, int kol);
void vvod(int kol);
void vivod();
void del(int kol);
int out();
struct sanatorii				//создание стуктурных переменных
{
	string nazvanie;
	string mesto;

	string lechebpr;
	int kol;
	string poisk;
};
sanatorii sant[255];
sanatorii bad;
string path = "spisok.txt";
int dele = 0, kole;
void vvod(int kol) {				//ввод данных
	string mus;
	int x;
	for (int i = 0; i < kol; i++)
	{
		sant[i].nazvanie = "";
		cout << "";
		cout << "название: ";
		getline(cin, mus);
		getline(cin, sant[i].nazvanie);
		cout << endl << "место расположения: ";
		getline(cin, sant[i].mesto);
		cout << endl << "метод лечения: ";
		getline(cin, sant[i].lechebpr);

		cout << endl << "количество путёвок: ";
		cin >> sant[i].kol;
	}
	zapis(path, kol);

}
int zapis(string path, int kol) {					//запись данных в файл
	ofstream fout;
	fout.open(path);
	if (!fout.is_open()) {
		printf_s("%s", "не удалось открыть файл");
		return -1;
	}
	for (int i = 0; i < kol; i++)
	{
		fout << (sant[i].nazvanie) << "\n";
		fout << (sant[i].mesto) << "\n";
		fout << (sant[i].lechebpr) << "\n";
		fout << sant[i].kol;
		if (i != kol - 1)
			cout << "\n";
	}
	fout.close();
	return 0;
}
int out() {									//сканирование файла и запись информации в структуру
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream fin;
	int i = 0;
	fin.open(path);
	if (!fin.is_open()) {                       //open the file
		printf_s("%s", "ошибка открытия файла");
		return EXIT_FAILURE;
	}
	else {
		printf_s("%s", "файл открыт\n");
	}
	while (!fin.eof()) {

		getline(fin, sant[i].nazvanie);
		getline(fin, sant[i].mesto);
		getline(fin, sant[i].lechebpr);
		fin >> sant[i].kol;
		i++;
	}
	fin.close();
	kole = i;
}
void del() {					//удаление указанной записи
	out();
	int del;
	cout << "ВВедите номер санатория, который нужно удалить: ";
	dele++;
	cin >> del;
	for (int i = del - 1; i < kole - 1; i++) {
		sant[i].nazvanie = sant[i + 1].nazvanie;
		sant[i].mesto = sant[i + 1].mesto;
		sant[i].lechebpr = sant[i + 1].lechebpr;
		sant[i].kol = sant[i + 1].kol;
	}
	zapis(path, kole - dele);
}
void vivod() {								//вывод данных из файла
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	out();
	cout << setw(32) << "название" << setw(30) << "место" << setw(30) << "способ лечения" << setw(14) << "кол. путёвок" << endl;
	for (int i = 0; i < kole; i++)
	{
		cout << i + 1 << ".";
		cout << setw(30) << (sant[i].nazvanie);
		cout << setw(30) << (sant[i].mesto);
		cout << setw(30) << (sant[i].lechebpr);
		cout << setw(10) << (sant[i].kol);
		cout << endl;
	}
}

int perezapis(int n, int r) {						//запись объекта
	out();
	int x;
	cout << "название: ";
	getline(cin, sant[n].nazvanie);
	cout << endl << "место расположения: ";
	getline(cin, sant[n].mesto);
	cout << endl << "количество путёвок: ";
	getline(cin, sant[n].lechebpr);
	zapis(path, kole + r);
	return 0;
}
void poisk() {
	out();
	string mus;
	getline(cin, mus);
	cout << "ВВедите название санатория: ";
	getline(cin, sant[0].poisk);
	for (int i = 0; i < kole; i++) {
		if (sant[i].nazvanie == sant[0].poisk) {
			cout << setw(32) << "название" << setw(30) << "место" << setw(30) << "способ лечения" << setw(14) << "кол. путёвок" << endl;
			cout << i + 1 << ".";
			cout << setw(30) << (sant[i].nazvanie);
			cout << setw(30) << (sant[i].mesto);
			cout << setw(30) << (sant[i].lechebpr);
			cout << setw(10) << (sant[i].kol);
			cout << endl;
		}
	}

}
void poisk2() {
	out();
	string mus;
	getline(cin, mus);
	cout << "ВВедите название санатория: ";
	getline(cin, sant[0].poisk);
	for (int i = 0; i < kole; i++) {
		if (sant[i].mesto == sant[0].poisk) {
			cout << setw(32) << "название" << setw(30) << "место" << setw(30) << "способ лечения" << setw(14) << "кол. путёвок" << endl;
			cout << i + 1 << ".";
			cout << setw(30) << (sant[i].nazvanie);
			cout << setw(30) << (sant[i].mesto);
			cout << setw(30) << (sant[i].lechebpr);
			cout << setw(10) << (sant[i].kol);
			cout << endl;
		}
	}

}
void poisk3() {
	out();
	string mus;
	getline(cin, mus);
	cout << "ВВедите название санатория: ";
	getline(cin, sant[0].poisk);
	for (int i = 0; i < kole; i++) {
		if (sant[i].lechebpr == sant[0].poisk) {
			cout << setw(32) << "название" << setw(30) << "место" << setw(30) << "способ лечения" << setw(14) << "кол. путёвок" << endl;
			cout << i + 1 << ".";
			cout << setw(30) << (sant[i].nazvanie);
			cout << setw(30) << (sant[i].mesto);
			cout << setw(30) << (sant[i].lechebpr);
			cout << setw(10) << (sant[i].kol);
			cout << endl;
		}
	}

}
void main() {
	setlocale(LC_ALL, "rus");				//перевод на кирилицу
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int a, k, choice;
	do										//выбор действий
	{
		cout << endl << "Введите:" << endl;
		cout << "1-для записи" << endl;
		cout << "2-для удаления записи" << endl;
		cout << "3-для изменения записи" << endl;
		cout << "4-для вывода записи(ей)" << endl;
		cout << "5-для ввода новой записи" << endl;
		cout << "6-для поиска по названию" << endl;
		cout << "7-для поиска по месту" << endl;
		cout << "8-для поиска по лечебному профилю" << endl;
		cout << "9-для выхода" << endl;
		cout << "ваш выбор: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "введите количество санаториев: ";
			cin >> a;

			vvod(a);
			break;
		case 2:
			del();
			break;
		case 3:  int n;
			cout << "введите номер ученика: ";
			cin >> n;
			perezapis(n - 1, 0);
			break;
		case 4:  vivod();	break;
		case 5: perezapis(kole, 1); break;
		case 6: poisk(); break;
		case 7: poisk2(); break;
		case 8: poisk3(); break;
		}
	} while (choice != 9);
}