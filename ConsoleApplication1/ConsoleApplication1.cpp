#include <conio.h>
#include <stdio.h>
#include <string.h>
#define N 80

//количество букв, слов и предложений в тексте

int main(int argc, char* argv[])
{
	FILE* f;
	char buk[87] = "qwetryuiopasdfghjklzxcbvnmйцукенгшщзхъфывапрлоджэячсмитьбю";
	char pre[4] = "!?.";
	int pred, slov, bukv, simv;
	pred = slov = bukv = simv = 0;
	int pos = 0;
	char ch;
	int length = 0;

	if ((f = fopen( "D:/text.txt", "r")) == NULL)
	{
		printf("Cannot open input file.\n");
		return 1;
	}

	char arr[N];
	while (fgets(arr, N, f) != '\0')
	{
		printf("%s\n", arr);
		for (int t = 0; t < N; t++)
		{
			simv = 0;
			char ch = arr[t];
			int found = 0;
			pos++;
			for (int i = 0; i < pos; i++)
			{
				if (ch == arr[i])
				{
					found++; simv++;
				}
			}
			for (int i = pos; i < N; i++)
			{
				if (ch == arr[i]) simv++; //Считает точки и переход на следущую строку
			}
			if (found < 2)
				printf("Simvol %c: %i time\n", ch, simv); //на 1 слово больше так как пробела после него нет.
		}
	}

	while (!feof(f))
	{
		ch = fgetc(f);
		if (ch == ' ' || ch == '\n' || ch == '\t') slov++; //Считает точки и переход на следущую строку.
	} //Табуляцию тоже считаем.
	fseek(f, 0, SEEK_SET); //Переход в начала файла.
	printf("Slov : %i\n", slov + 1); //на 1 слово больше так как пробела после него нет.

	while (!feof(f))
	{
		ch = fgetc(f);
		for (int i = 0; i < 87; i++)
			if (ch == buk[i]) bukv++;;
	}
	fseek(f, 0, SEEK_SET);
	printf("Bukv : %i", bukv);
	
	while (!feof(f))
	{
		ch = fgetc(f);
		for (int i = 0; i < 3; i++)
			if (ch == pre[i])
			{
				pred++;
				break;
			}
	}
	fseek(f, 0, SEEK_SET);
	printf("\nPredlozheniy : %i\n", pred);
	fclose(f);
	return 0;
}