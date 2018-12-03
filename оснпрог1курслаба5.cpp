#include "pch.h" 
#include <conio.h> //Для работы функции getch(); 
#include <stdio.h> // ввод-вывод 
#include <stdlib.h> //Для памяти 
#include <conio.h> 
#include <string.h> 
#include <windows.h> 
#include <locale.h>

char* InputWord()//функция для ввода строки 
{
	int n = 2;
	char* strn = new char[n];
	strn[0] = '1';
	strn[1] = '\0';
	char inp;
	while ((inp = getchar()) != '\n')
	{
		char* buf = new char[n];
		for (int i = 0; i < n - 1; i++)
		{
			buf[i] = strn[i];
		}
		buf[n - 1] = '\0';
		buf[n - 2] = inp;
		n++;
		delete[] strn;
		strn = buf;
	}
	return strn;
}
int countVowels(char* a)//функция для подсчета гласных 
{
	int m = 0;
	char glas[] = "аАоОиИеЕёЁэЭыЫуУюЮяЯ"; //строка со всеми гласными буквами 
	for (int i = 0; i < strlen(a); i++)
	{
		for (int j = 0; j < strlen(glas); j++)
		{
			if (a[i] == glas[j])
			{
				m++;
			}
		}
	}
	return m;
}
int countA(char* a)//функция для подсчета букв А и а 
{
	int n = 0;

	for (int i = 0; i < strlen(a); i++)
	{
		if (a[i] == 'а' || a[i] == 'А')
		{
			n++;
		}

	}
	return n;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);//setlocale(LC_ALL, "Rus"); 
	int menu = 0;
	char* ch = NULL;
	int kolglas = 0;
	int kolA = 0;
	bool ext = false;
	int obrabotka = 0;
	char check = '\0';
	while (ext != true)
	{
		printf("1. Ввод строки\n");
		printf("2. Обработка данных\n");
		printf("3. Вывести результат\n");
		printf("---------------------\n");
		printf("4. Выход \n");
		while (scanf_s("%d%c", &menu, &check, 1) != 2 || check != '\n' || menu < 0 || menu > 4)
		{
			printf("Ошибка!");
			while (getchar() != '\n');
			printf("Введите число от 1 до 4: ");
		}
		if (menu == 1)
		{
			printf("Введите строку:");
			ch = InputWord();
		}
		else if (menu == 2)
		{
			if (ch == NULL)
			{
				printf("Строка не введена\n");
			}
			else
			{
				kolglas = countVowels(ch);
				kolA = countA(ch);
				printf("Успешно подсчитано\n");
				obrabotka++;
			}

		}
		else if (menu == 3)
		{
			if (obrabotka == 0)
			{
				printf("Данные не обработаны\n");
			}
			else
			{
				printf("Количество гласных в строке = %d\n", kolglas);
				printf("Количество букв а или А в строке = %d\n", kolA);
			}

		}
		else if (menu == 4)
		{
			ext = true;
			delete[] ch;
		}
	}
	return 0;
}
