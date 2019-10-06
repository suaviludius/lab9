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

	if ((f = fopen( "D:/text.txt", "r")) == NULL)
	{
		printf("Cannot open input file.\n");
		return 1;
	}

	int rat[N] = { 0 };
	char arr[N];
	int i = 0;
	while ((arr[i] = fgetc(f)) != EOF) 
		i++;

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
			if (ch == arr[i]) simv++; //
		}
		if (found < 2)
		{
			if (ch == '\n') printf("Simvol \\n: %2i time\n", simv); else
				if (ch == '\t') printf("Simvol \\t: %2i time\n", simv); else
					if(ch == '\b') printf("Simvol \\b: %2i time\n", simv); else
						if (ch == '\v') printf("Simvol \\v: %2i time\n", simv); else
							if (ch == '\f') printf("Simvol \\f: %2i time\n", simv); else
								printf("Simvol %2c: %2i time\n", ch, simv); //на 1 слово больше так как пробела после него нет.
			rat[t] = simv;
		}
	}
	printf("Simvol \\0:  1 time\n\n");

	for (int i = N; i > -1; i--)
	{
		char vivod = arr[i];
			if (rat[i] > 0)
			{
				for (int t = 0; t < i; t++)
				{
					if (rat[i] < rat[t])
					{
						int tt = rat[i];
						rat[i] = rat[t];
						rat[t] = tt;

						char vivod = arr[t];
						arr[t] = arr[i];
						arr[i] = vivod;
					}
				}
				if (arr[i] == '\n') printf("\\n", simv); else
					if (arr[i] == '\t') printf("\\t", simv); else
				printf("%c", arr[i]);
			}
	}
	printf("\n");

	char ch_pred = 0;
	fseek(f, 0, SEEK_SET); //Переход в начала файла.
	while (!feof(f))
	{
		ch = fgetc(f);
		if (ch_pred != ' ' || ch_pred != '\n' || ch_pred != '\t' || ch_pred != '.' || ch_pred != '!' || ch_pred != '?')
		if (ch == ' ' || ch == '\n' || ch == '\t' || ch == '.' || ch == '!' || ch == '?') slov++; //Считает точки и переход на следущую строку.
		ch_pred = ch;
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