#include <conio.h>
#include <stdio.h>
#include <string.h>
#define N 80

//количество букв, слов и предложений в тексте

int main()
{
	FILE* f;
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
			printf("%d\n",ch);
			if (ch == '\n') printf("Simvol \\n: %2i time\n", simv); else
				if (ch == '\t') printf("Simvol \\t: %2i time\n", simv); else
					if (ch == -1) printf("Simvol \\0: %2i time\n", simv); else
								printf("Simvol %2c: %2i time\n", ch, simv); //на 1 слово больше так как пробела после него нет.
			rat[t] = simv;
		}
	}

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
				if (arr[i] == '\n') printf("\\n"); else
					if (arr[i] == '\t') printf("\\t"); else
						if (arr[i] == -1) printf("\\0"); else
				printf("%c", arr[i]);
			}
	}
	printf("\n");
	fclose(f);
	return 0;
}

}
