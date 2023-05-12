#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MAX_UZIVATELU 10

typedef struct {
	int ID;
	char jmeno[10];
} Tuzivatel;

typedef struct {
	Tuzivatel uzivatele[MAX_UZIVATELU];
	int pocetUzivatelu;
} Tuzivatele;

////////////////////////////////

typedef struct {
	int ID_uzivatele;
	char email[21];
} Temail;

typedef struct {
	Temail emaily[MAX_UZIVATELU];
	int pocetEmailu;
} Temaily;

typedef struct {
	Tuzivatele uzivatele;
	Temaily emaily;
} Tosoy;

int nactiUzivatele(FILE *f_uzivatele, Tuzivatel uzivatele[]) {
	// skip the first line
	char temp[51];
	fscanf(f_uzivatele, "#%50[^\n]", temp);
	int index = 0;
	while(fscanf(f_uzivatele, "%d, %20s\n", &uzivatele[index].ID, uzivatele[index].jmeno) == 2) {
		index++;
	}
	return index;
}

int nactiEmaily(FILE *f_emaily, Temail emaily[]) {
	// skip the first line
	char temp[51];
	fscanf(f_emaily, "#%50[^\n]", temp);
	int index = 0;
	while(fscanf(f_emaily, "%d, %20s\n", &emaily[index].ID_uzivatele, emaily[index].email) == 2) {
		index++;
	}
	return index;
}

char* vratEmailIdUzivatele(Temaily emaily, int ID_uzivatele) {
	for(int emailIndex = 0; emailIndex < emaily.pocetEmailu; emailIndex++) {
		if(ID_uzivatele == emaily.emaily[emailIndex].ID_uzivatele) {
			return emaily.emaily[emailIndex].email;
		}
	}
	return NULL;
}

void vypisUzivatele(Tosoy osoby) {
	for(int uzivatelIndex=0; uzivatelIndex < osoby.uzivatele.pocetUzivatelu; uzivatelIndex++) {
		Tuzivatel uzivatel = osoby.uzivatele.uzivatele[uzivatelIndex];
		char *mail = vratEmailIdUzivatele(osoby.emaily, uzivatel.ID);
		printf("Uzivatel ID: '%d', jmeno: '%s', mail: %s\n", uzivatel.ID, uzivatel.jmeno, mail);
	}
}


int main() {
	FILE *f_uzivatele = fopen("uzivatele.txt", "r");
	if(f_uzivatele == NULL) {
		printf("Error opening\n");
		return EXIT_FAILURE;
	}

	FILE *f_emaily = fopen("emaily.txt", "r");
	if(f_emaily == NULL) {
		printf("Error opening\n");
		return EXIT_FAILURE;
	}

	Tosoy osoby;
	osoby.uzivatele.pocetUzivatelu = nactiUzivatele(f_uzivatele, osoby.uzivatele.uzivatele);
	printf("Pocet uzivatelu: %d\n", osoby.uzivatele.pocetUzivatelu);

	osoby.emaily.pocetEmailu = nactiEmaily(f_emaily, osoby.emaily.emaily);
	printf("Pocet emailu: %d\n", osoby.emaily.pocetEmailu);

	vypisUzivatele(osoby);


	return 0;
}