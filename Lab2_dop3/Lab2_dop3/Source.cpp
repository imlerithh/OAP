//var15
//1. ��� ���� ������������ �����, ���������� �������� ���������� ������� �� �������, ������ ��������� ������� ����� �������� �������� 
//���������� �������� �������.������� ����� ���� ��� �� ���������, ���������� k - �� ������ �������� �������.
//2. ������� ��������� ���� F1 �� �����, ��� �� 8 �����, � �������� � ���� ����������.����������� �� ����� F1 � ���� F2 ������, 
//������� � k �� k + 3.


// 1
//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//#define ROW 3
//#define COLUMN 3
//#define SIZE 5
//using namespace std;
////   ������� 1
//
//// �������� ������� � ������ �� � ���� "Matrix.txt"
//float CreateF()
//{
//	errno_t err;
//	float matrix[ROW][COLUMN];
//	FILE* fp;
//	err = fopen_s(&fp, "Matrix.txt", "w");
//	if (err != 0)
//	{
//		perror("���������� ������� ����\n");
//		return EXIT_FAILURE;
//	}
//	for (int i = 0; i < ROW; i++)
//	{
//		for (int j = 0; j < COLUMN; j++)
//		{
//			*(*(matrix + i) + j) = 1 + rand() % 100;
//			fprintf(fp, "%f\t", *(*(matrix + i) + j));
//
//		}
//		fprintf(fp, "\n");
//	}
//	printf("%s", "������� �������� � ���� 'Matrix.txt'\n");
//	fclose(fp);
//
//}
//
////������ ������� �� ����� "Matrix.txt" � ���� "Result.txt"
//float RecordF()
//{
//	errno_t errM;
//	errno_t errR;
//	float arr[ROW][COLUMN];
//	int k = 0;
//	FILE* fr;
//	FILE* fm;
//
//	printf("%s", "������� ����� ������: ");
//	scanf_s("%d", &k);
//	if (k >= ROW || k < 0)
//	{
//		printf("����� ������ �� ����������");
//		exit(1);
//	}
//
//	errM = fopen_s(&fm, "Matrix.txt", "r");
//	if (errM != 0)
//	{
//		perror("���������� ������� ����\n");
//		return EXIT_FAILURE;
//	}
//
//	errR = fopen_s(&fr, "Result.txt", "w");
//	if (errR != 0)
//	{
//		perror("���������� ������� ����\n");
//		return EXIT_FAILURE;
//	}
//
//	for (int i = 0; i < ROW; i++)
//	{
//		for (int j = 0; j < COLUMN; j++)
//			fscanf_s(fm, "%f", &arr[j][i]);
//
//	}
//
//	printf("%s", "�������� ������� � ����� 'Matrix.txt'\n");
//	fclose(fm);
//
//	for (int i = 0; i < COLUMN; i++)
//	{
//		fprintf(fr, "%f\t", arr[i][k]);
//	}
//
//	printf("%s", "������ �������� � ���� 'Result.txt'");
//	fclose(fr);
//}
//int main() {
//	setlocale(LC_CTYPE, "Russian");
//	CreateF();
//	RecordF();
//}


//2
#include <iostream>
#include <stdio.h>
int main()
{
 using namespace std;
 setlocale(LC_ALL, "");
 FILE* f, * f2; char str1[20];
 int lng, i, k;
 cout << "������� ����� ������, � �������� ����� ������ ���������:";
 cin >> k;
 fopen_s(&f, "f1.txt", "r");
 fopen_s(&f2, "f2.txt", "w");
 for (i = 0; i < k; i++)
 {
 fgets(str1, sizeof(str1), f);
 }
 for (i = 0; i < 4; i++)
 {
 fgets(str1, sizeof(str1), f);
 fputs(str1, f2);
 }
 fclose(f);
 fclose(f2);
}
