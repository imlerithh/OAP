
//1. Даны два файла вещественных чисел с именами fA и fB, содержащие элементы прямоугольных матриц M1 и M2 по строкам, 
// причем начальный элемент каждого файла содержит количество столбцов соответствующей матрицы.Создать файл той же структуры с именем fC,
//содержащий сумму M1 + M2.
//2. Компоненты файла f –  целые двухзначные(отличные от нуля) числа, причем 10 положительных чисел, 10 отрицательных, и т.д.
//Получить файл g, в котором записаны сначала 5 положительных чисел, затем 5 отрицательных и т.д.


//1
#include <stdio.h>
#include <iostream>


int main() {
	setlocale(LC_CTYPE, "rus");
	FILE* filea, * fileb, * filec;
	fopen_s(&filea, "fA.txt", "r");
	fopen_s(&fileb, "fB.txt", "r");
	fopen_s(&filec, "fC.txt", "w");

	if (filea != 0 && fileb != 0)
		printf("Файлы успешно открыты\n");
	else return 1;

	char fa[50], fb[50];
	fgets(fa, 50, filea);
	int amount_1 = (int)fa[0] - 48;

	fgets(fb, 50, fileb);
	int amount_2 = (int)fb[0] - 48;

	double A[10][10];
	double B[10][10];
	double C[10][10];


	int massIndexArows = 0, massIndexAcols = 0;
	int massIndexBrows = 0, massIndexBcols = 0;

	int i = 2;
	char numA[50];
	int numAcounter = 0;
	char numB[50];
	int numBcounter = 0;
	int j = 2;
	for (int k = 0; k < (amount_1 >= amount_2 ? amount_1 : amount_2); k++)
	{
		while (fa[i] != '\n') {
			if (fa[i] != ' ' && fa[i] != '\n') {
				while (fa[i] != ' ' && fa[i] != '\n')
				{
					numA[numAcounter] = fa[i];
					numAcounter++;
					i++;
				}
				numA[i] = 'f';
				A[massIndexArows][massIndexAcols] = atof(numA);
				massIndexAcols++;
			}
			else {
				i++;
			}
			numAcounter = 0;
			for (int g = 0; g < 5; g++)
			{
				numA[g] = 0;
			}

		}

		while (fb[j] != '\n') {
			if (fb[j] != ' ' && fb[j] != '\n') {
				while (fb[j] != ' ' && fb[j] != '\n')
				{
					numB[numBcounter] = fb[j];
					numBcounter++;
					j++;
				}
				numB[j] = 'f';

				B[massIndexBrows][massIndexBcols] = atof(numB);
				massIndexBcols++;
			}
			else {
				j++;
			}
			numBcounter = 0;
			for (int g = 0; g < 5; g++)
			{
				numB[g] = 0;
			}
		}
		fgets(fa, 50, filea);
		fgets(fb, 50, fileb);
		i = 0;
		j = 0;
		massIndexAcols = 0;
		massIndexBcols = 0;
		massIndexArows++;
		massIndexBrows++;
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			fprintf(filec, "%f ", A[i][j] + B[i][j]);
		}
		fprintf(filec, "\n");

	}

	fclose(filea);
	fclose(fileb);
	fclose(filec);
	return 0;
}

/*
//2
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>


int main() {
	setlocale(LC_CTYPE, "rus");
	FILE* f, * g;
	fopen_s(&f, "f.txt", "r");
	fopen_s(&g, "g.txt", "w");

	if (f != 0 && g != 0)
		printf("Файл успешно открыт\n");
	else return 1;

	char fa[70];
	fgets(fa, 70, f);

	char strnums[3];
	int intnums[20];
	int i = -1;
	int strnumsindex = 0;
	int intnumsindex = 0;
	while (fa[i] != '\0')
	{
		i++;
		for (; fa[i] != ' ' && fa[i] != '\0'; i++) {
			strnums[strnumsindex] = fa[i];
			strnumsindex++;
		}
		intnums[intnumsindex] = atof(strnums);
		intnumsindex++;
		for (int j = 2; j > 0; j--)
			strnums[j] = '\0';
		strnumsindex = 0;
	}

	int OutputCounter = 1;
	while (OutputCounter <= 20) {
		for (int i = 0; i < 20; i++)
		{
			if ((OutputCounter <= 5 || (OutputCounter > 10 && OutputCounter <= 15)) && intnums[i] > 0 && intnums[i] != 100)
			{
				fprintf(g, "%d ", intnums[i]);
				intnums[i] = 100;
				break;
			}
			else if (((OutputCounter > 5 && OutputCounter <= 10) || (OutputCounter > 15)) && intnums[i] < 0 && intnums[i] != 100)
			{
				fprintf(g, "%d ", intnums[i]);
				intnums[i] = 100;
				break;
			}
		}
		OutputCounter++;
	}



	fclose(f);
	return 0;
}
*/