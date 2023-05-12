#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

enum {
	NOT_FOUND = 0,
	OK = 1,
};

int myStrLen(const char str[], int maxlen) {
	for (int i = 0; i < maxlen; i++) {
		if(str[i] == '\0') {
			return i;
		}
	}
	return -1;
}

int najdiPrvniVyskyt(char pole[], int velikost, int cislo) {
	for (int i = 0; i < velikost; i++) {
		int hled = pole[i];
		if (hled == cislo) {
			return i;
		}
	}
	return NOT_FOUND;
}

int najdiPosledniVyskyt(char pole[], int velikost, int cislo) {
	for(int i = velikost - 1; i >= 0; i--) {
		if (pole[i] == cislo) {
			return i;
		}
	}
	return NOT_FOUND;
}

int nactiPoleZnaku(FILE* f, char str[]) {
	// if(fscanf(f, "%50s", str) == 1) {
	if(fscanf(f, "%100[^\t\n]", str) == 1) { // pro nacteni mezer
		// return strlen(str);
		return myStrLen(str, 100);
	}
	return NOT_FOUND;
}



void hledej(char *str, int len) {
	int prvni = najdiPrvniVyskyt(str, len, '9');
	printf("Prvni vyskyt '9' na pozici %d\n", prvni);

	int posledni = najdiPosledniVyskyt(str, len, '9');
	printf("Posledni vyskyt '9' na pozici %d\n", posledni);
}

////////////////////////////////////////////////////////////////

void nahradCislo(char pole[], int velikost, char co, char cim) {
	for (int i = 0; i < velikost; i++) {
		int hled = pole[i];
		if (hled == co) {
			pole[i] = cim;
		}
	}
}


void skryjCislo(char pole[], int velikost) {
	nahradCislo(pole, velikost, '9', '#');
}


void swap(char *a, char *b) {
	char pom = *a;
	*a = *b;
	*b = pom;
}

void otocPoleCyklem(char pole[], int velikost) {
	for(int i = 0; i < velikost/2; i++) {
		swap(&pole[i], &pole[velikost - i - 1]);
		// swap(&pole[i], &pole[velikost - i - 1]);
	}
}


void otocPoleRekurzi(char pole[], int velikost, int start) {
    if (start >= velikost/2) {
        return;
    }
    int end = velikost - start - 1;
    swap(&pole[start], &pole[end]);
    otocPoleRekurzi(pole, velikost, start + 1);
}

void otoc(char pole[], int velikost) {
	otocPoleCyklem(pole, velikost);
	otocPoleRekurzi(pole, velikost, 0);
}

int main() {

	FILE* f = fopen("testFile.txt", "r");
	if(f == NULL) {
		printf("Error opening\n");
		return EXIT_FAILURE;
	}

	char str[101];
	int delka = nactiPoleZnaku(f, str);
	if(delka == NOT_FOUND) {
		printf("Nenacteno - nulova delka\n");
		return EXIT_FAILURE;
	}

	printf("%s -> %d znaku\n", str, delka);

	hledej(str, delka);

	printf("Skryvam cislo '9' pomoci '#'\n");
	skryjCislo(str, delka);
	printf("%s -> %d znaku\n", str, delka);

	printf("Otacim pole tam a zpet - bude zase spravne\n");
	otoc(str, delka);
	printf("%s -> %d znaku\n", str, delka);

	return 0;
}