/*
 * Projekt:
 * Autor:
 * Datum:
 */

#include "gvid.h"       // par drobnosti pro zjednoduseni prace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // pro praci s textovymi retezci
 #include <stdbool.h> // pro praci s typem bool a konstantami true a false
// #include <ctype.h>   // isalpha, isspace, islower, isupper, ...
// #include <math.h>    // funkce z matematicke knihovny
// #include <float.h>   // konstanty pro racionalni typy DBL_MAX, DBL_DIG, ...
// #include <limits.h>  // konstanty pro celociselne typy INT_MAX, INT_MIN, ...
// #include <time.h>    // funkce time a dalsi pro praci s casem

typedef struct{
	int pocit;
	bool prvni;
	int skok;
} prepinac;


int clear()
{
	FILE* pom1 = fopen("pom1.txt", "w");

	if(pom1 == NULL)
	{
		printf("Soubor nelze otevrit");
		return 1;
	}

	fprintf(pom1,"");
	fclose(pom1);

	FILE* pom2 = fopen("pom2.txt", "w");

	if(pom2 == NULL)
	{
		printf("Soubor nelze otevrit");
		return 1;
	}

	fprintf(pom2,"");
	fclose(pom2);

	printf("Pomocne soubory jsou prazdne\n");
}


int zaklad(FILE* vstup)
{
	bool prvni = true;

	char znak = ' ';
	while(fscanf(vstup, " %c", &znak)==1)
	{
		printf("%c", znak);

		char soubor[20];
		if(prvni)
		{
			strcpy(soubor, "pom1.txt");
		}
		else
		{
			strcpy(soubor, "pom2.txt");
		}

		FILE* pom = fopen(soubor, "a");

		if(pom == NULL)
		{
			printf("Soubor nelze otevrit");
			return 1;
		}

		fprintf(pom,"%c", znak);

		prvni = !prvni;

	}
}


int bonus(FILE* vstup, int skok)
{
	prepinac prep;
	prep.skok = skok;
	prep.pocit = 0;
	prep.prvni = true;
	int count = 0;

	char znak;
	while(fscanf(vstup, " %c", &znak)==1)
	{
		printf("%c", znak);
//
		char soubor[20];

		if(prep.pocit>prep.skok-1)
		{
			prep.prvni = !prep.prvni;
			prep.pocit = 0;
			count++;
		}

		if(prep.prvni)
		{
			strcpy(soubor, "pom1.txt");
		}
		else
		{
			strcpy(soubor, "pom2.txt");
		}

		FILE* pom = fopen(soubor, "a+");

		if(pom == NULL)
		{
			printf("Soubor nelze otevrit");
			return 1;
		}

		fprintf(pom,"%c", znak);
		fclose(pom);

		prep.pocit++;

	}
	printf("\n\nPocet casti: %d\n", count+1);
}


int main(void)
{
	FILE* vstup = fopen("vstup.txt", "r");

	if(vstup == NULL)
	{
		printf("Soubor nelze otevrit");
		return 1;
	}


	if(!clear())
	{
		fclose(vstup);
		return 1;
	}


	if(!zaklad(vstup))
	{
		fclose(vstup);
		return 1;
	}

	if(!bonus(vstup, 20))
	{
		fclose(vstup);
		return 1;
	}


	fclose(vstup);

	printf("\n\nDokonceno");

	return 0;
}
