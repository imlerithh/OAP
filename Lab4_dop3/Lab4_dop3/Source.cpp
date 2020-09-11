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
struct sanatorii				//�������� ���������� ����������
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
void vvod(int kol) {				//���� ������
	string mus;
	int x;
	for (int i = 0; i < kol; i++)
	{
		sant[i].nazvanie = "";
		cout << "";
		cout << "��������: ";
		getline(cin, mus);
		getline(cin, sant[i].nazvanie);
		cout << endl << "����� ������������: ";
		getline(cin, sant[i].mesto);
		cout << endl << "����� �������: ";
		getline(cin, sant[i].lechebpr);

		cout << endl << "���������� ������: ";
		cin >> sant[i].kol;
	}
	zapis(path, kol);

}
int zapis(string path, int kol) {					//������ ������ � ����
	ofstream fout;
	fout.open(path);
	if (!fout.is_open()) {
		printf_s("%s", "�� ������� ������� ����");
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
int out() {									//������������ ����� � ������ ���������� � ���������
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream fin;
	int i = 0;
	fin.open(path);
	if (!fin.is_open()) {                       //open the file
		printf_s("%s", "������ �������� �����");
		return EXIT_FAILURE;
	}
	else {
		printf_s("%s", "���� ������\n");
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
void del() {					//�������� ��������� ������
	out();
	int del;
	cout << "������� ����� ���������, ������� ����� �������: ";
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
void vivod() {								//����� ������ �� �����
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	out();
	cout << setw(32) << "��������" << setw(30) << "�����" << setw(30) << "������ �������" << setw(14) << "���. ������" << endl;
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

int perezapis(int n, int r) {						//������ �������
	out();
	int x;
	cout << "��������: ";
	getline(cin, sant[n].nazvanie);
	cout << endl << "����� ������������: ";
	getline(cin, sant[n].mesto);
	cout << endl << "���������� ������: ";
	getline(cin, sant[n].lechebpr);
	zapis(path, kole + r);
	return 0;
}
void poisk() {
	out();
	string mus;
	getline(cin, mus);
	cout << "������� �������� ���������: ";
	getline(cin, sant[0].poisk);
	for (int i = 0; i < kole; i++) {
		if (sant[i].nazvanie == sant[0].poisk) {
			cout << setw(32) << "��������" << setw(30) << "�����" << setw(30) << "������ �������" << setw(14) << "���. ������" << endl;
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
	cout << "������� �������� ���������: ";
	getline(cin, sant[0].poisk);
	for (int i = 0; i < kole; i++) {
		if (sant[i].mesto == sant[0].poisk) {
			cout << setw(32) << "��������" << setw(30) << "�����" << setw(30) << "������ �������" << setw(14) << "���. ������" << endl;
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
	cout << "������� �������� ���������: ";
	getline(cin, sant[0].poisk);
	for (int i = 0; i < kole; i++) {
		if (sant[i].lechebpr == sant[0].poisk) {
			cout << setw(32) << "��������" << setw(30) << "�����" << setw(30) << "������ �������" << setw(14) << "���. ������" << endl;
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
	setlocale(LC_ALL, "rus");				//������� �� ��������
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int a, k, choice;
	do										//����� ��������
	{
		cout << endl << "�������:" << endl;
		cout << "1-��� ������" << endl;
		cout << "2-��� �������� ������" << endl;
		cout << "3-��� ��������� ������" << endl;
		cout << "4-��� ������ ������(��)" << endl;
		cout << "5-��� ����� ����� ������" << endl;
		cout << "6-��� ������ �� ��������" << endl;
		cout << "7-��� ������ �� �����" << endl;
		cout << "8-��� ������ �� ��������� �������" << endl;
		cout << "9-��� ������" << endl;
		cout << "��� �����: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "������� ���������� ����������: ";
			cin >> a;

			vvod(a);
			break;
		case 2:
			del();
			break;
		case 3:  int n;
			cout << "������� ����� �������: ";
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