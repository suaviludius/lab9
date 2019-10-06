#include <conio.h>
#include <stdio.h>
#include <string.h>
#define N 180

//количество букв, слов и предложений в тексте

int main()
{
	FILE* f;
	int simv = 0; //Счетчик колличества одинаковых символов 
	char arr[N]; // Массив символов файла
	int rat[N] = { 0 }; // Массив колличества повторений символов
	int k = 0; //количество символов в файле
	
	if ((f = fopen( "D:/text.txt", "r")) == NULL) //Открытие файла для чтения
	{
		printf("Cannot open input file.\n");
		return 1;
	}

	while ((arr[k] = fgetc(f)) != EOF) //Заносим символы файла в массив
		k++;

	printf("Statistics by text file: \n"); //"Статистика по текстовому файлу"
	for (int t = 0; t < k+1; t++, simv = 0) //Просмотр символов массива символов
	{
		char ch = arr[t]; //символ для сравнения
		for (int i = 0; i < t+1; i++)// Элементы до символа
		{
			if (ch == arr[i])
			{
				simv++;
			}
		}
		if (simv > 1) continue;
		for (int i = t+1; i < k; i++) // Элементы после символа
		{
			if (ch == arr[i]) simv++; 
		}
		if (ch == '\n') printf("Symbol  \\n: %3i time\n", simv); else // Новая строка
			if (ch == '\t') printf("Symbol  \\t: %3i time\n", simv); else // Табуляция
				if (ch == -1) printf("Symbol EOF: %3i time\n", simv); else //Символ конца файла
					printf("Symbol %3c: %3i time\n", ch, simv); // Символ и его количество
		rat[t] = simv; //Запоминаем колличество символов, встретившихся впервые, с номером их расположения в arr[]
	}
	printf("\nCharacter output by frequency: \n"); //"Вывод символов по частоте"
	for (int i = k; i > -1; i--)
	{
			if (rat[i] > 0)
			{
				for (int t = 0; t < i; t++)
				{
					if (rat[i] < rat[t])
					{
						int rat_swap = rat[i]; //своп
						rat[i] = rat[t];
						rat[t] = rat_swap;

						char arr_swap= arr[t]; //пинг
						arr[t] = arr[i];
						arr[i] = arr_swap;
					}
				}
				if (arr[i] == '\n') printf("\\n"); else
					if (arr[i] == '\t') printf("\\t"); else
						if (arr[i] == -1) printf("EOF"); else
				printf("%c", arr[i]);
			}
	}
	printf("\n");
	fclose(f);
	return 0;
}
