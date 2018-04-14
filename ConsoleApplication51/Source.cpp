#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <stdint.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#define printName(name) printf("hello, %s\n", name)
#define len 250

using namespace std;

unsigned short int q;

void main()

{
	setlocale(LC_ALL, "Russian");
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);
	int bckr, t;
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));


	srand(time(NULL));

	unsigned short int nz;

	do
	{
		cout << "Введите номер задания: ";
		cin >> nz;

		cin.get();

		switch (nz)
		{
		case 1:
		{

		}break;

		case 2:
		{
			cout << "Имеется текстовый файл. Переписать его строки в обратном порядке " << endl
				<< "(справа налево) в другой файл. Порядок строк во втором файле должен: " << endl
				<< "a.совпадать с порядком строк в заданном файле;" << endl
				<< "b.быть обратным по отношению к порядку строк в заданном файле.\n\n";
			char*str = "Since 1066 there have been forty \nmonarchs in England, thirty-five kings, \nfive queens and seven dynasties. \nOnly fourteen monarchs have stayed on the \nthrone for more than twenty-five years, \none of them is Queen Elizabeth II.\n";
			FILE *fp = NULL;
			FILE *A = NULL;
			FILE *B = NULL;
			if ((fp = fopen("case2.txt", "w")) == NULL)
			{
				printf("error\n");
				exit(1);
			}
			else
			{
				printf("в файл case2 будет записан след текст:\n%s\n", str);
				fprintf(fp, "%s", str);
			}
			fclose(fp);

			if ((fp = fopen("case2.txt", "r")) == NULL || (A = fopen("case2A.txt", "w")) == NULL ||
				(B = fopen("case2B.txt", "w")) == NULL)
			{
				printf("error\n");
				exit(1);
			}
			else
			{
				int count = 0;
				while (!feof(fp))
				{
					getc(fp);
					count++;
				}
				rewind(fp);

				int b = 0;
				char c[400];

				for (int i = 0; i < count; i++)
				{
					fscanf(fp, "%c", &c[i]);
					if (c[i] == '\n')
					{
						int d = b;
						for (int j = i - 2; j >= d; j--)
						{
							fprintf(A, "%c", c[j]);
							b++;
						}
						if (d == 0)
							fprintf(A, "\n");
					}
				}
				rewind(fp);
				int j = 0;
				printf("файл подзадания A записан\n");
				for (int i = count-2; i >= 0; i--)
				{
					fscanf(fp, "%c", &c[i]);
				}
				for (int j = 0; j < count-1; j++)
				{
					fprintf(B, "%c", c[j]);
				}
				printf("файл подзадания B записан\n");
			}
			fclose(fp);
			fclose(A);
			fclose(B);
		}break;

		}
		SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
		cout << "Хотите продолжить 1/0?";
		cin >> q;


		switch (q)
		{
		case 1:
			system("cls");
			break;
		default:
			cout << "ошибка" << endl;
		}
	} while (nz > 0);


}

