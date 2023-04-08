#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	int klic;
} Tprvek;


void generujNeSerazeneKlice(Tprvek prvkyNeser[], int pocetPrvku) {
	for(int i = 0; i < pocetPrvku; i++) {
		prvkyNeser[i].klic = rand() % 100;
	}
}

void generujSerazeneKlice(Tprvek prvkyNeser[], int pocetPrvku) {
	prvkyNeser[0].klic = rand() % 21;
	for(int i = 1; i < pocetPrvku; i++) {
		prvkyNeser[i].klic = prvkyNeser[i-1].klic + rand() % 20;
	}
}

void vypisKlicu(Tprvek prvkyNeser[], int pocetPrvku) {
	for(int i = 0; i < pocetPrvku; i++) {
		printf("%d, ", prvkyNeser[i].klic);
	}
	printf("\n");
}

int sekvencniHledani_Neserazeno_BezZarazky(Tprvek prvkyNeser[], int pocetPrvku, int hledejKlic) {
	int i = 0;
	while(i < pocetPrvku && prvkyNeser[i].klic != hledejKlic) {
		i++;
	}
	if(i<pocetPrvku) {
		return i; // konec v poli -> nalezeno
	} else {
		return -1; // za polem -> nenalezeno
	}
}

int sekvencniHledani_Neserazeno_SeZarazkou(Tprvek prvkyNeser[], int pocetPlus1, int hledejKlic) {
	prvkyNeser[pocetPlus1-1].klic = hledejKlic; // delka je o 1 deslo - indexovano od 0
	int i = 0;
	while(prvkyNeser[i].klic != hledejKlic) {
		i++;
	}
	if(i<pocetPlus1-1) {
		return i; // konec v poli -> nalezeno
	} else {
		return -1; // na zarazce -> nenalezeno
	}
}

int sekvencniHledani_Serazeno_BezZarazky(Tprvek prvkyNeser[], int pocetPrvku, int hledejKlic) {
	int i = 0;
	while(i < pocetPrvku && prvkyNeser[i].klic < hledejKlic) {
		i++;
	}
	if(i<pocetPrvku && prvkyNeser[i].klic == hledejKlic) {
		return i; // konec v poli -> nalezeno
	} else {
		return -1; // za polem -> nenalezeno
	}
}

void algoritmusIntro(Tprvek prvkyNeser[], int pocetPrvku, char *algoritmus) {
	printf("%s\n", algoritmus);
	vypisKlicu(prvkyNeser, pocetPrvku);
}

void zpracujVysledek(Tprvek prvkyNeser[], int nalezenyIndex) {
	if(nalezenyIndex == -1) {
		printf("NeNalezeno\n");
	} else {
		printf("OkNalezeno - index : %d -> %d\n", nalezenyIndex, prvkyNeser[nalezenyIndex].klic);
	}
}

void mezera() {
	printf("\n\n");
}

int main() {
	int hledanyIndex;
	const int pocetPrvku = 10;
	Tprvek prvkyNeser[pocetPrvku+1]; // pro zarazku

	generujNeSerazeneKlice(prvkyNeser, pocetPrvku);

	// Sekvencni vyhledavani na NEserazenem poli BEZ zarazky
	algoritmusIntro(prvkyNeser, pocetPrvku, "Sekvencni vyhledavani na NEserazenem poli BEZ zarazky");
	hledanyIndex = sekvencniHledani_Neserazeno_BezZarazky(prvkyNeser, pocetPrvku, 30);
	zpracujVysledek(prvkyNeser, hledanyIndex);

	hledanyIndex = sekvencniHledani_Neserazeno_BezZarazky(prvkyNeser, pocetPrvku, 8);
	zpracujVysledek(prvkyNeser, hledanyIndex);
	mezera();


	// Sekvencni vyhledavani na NEserazenem poli SE zarazkou
	algoritmusIntro(prvkyNeser, pocetPrvku, "Sekvencni vyhledavani na NEserazenem poli SE zarazkou");
	hledanyIndex = sekvencniHledani_Neserazeno_SeZarazkou(prvkyNeser, pocetPrvku+1, 30);
	zpracujVysledek(prvkyNeser, hledanyIndex);

	hledanyIndex = sekvencniHledani_Neserazeno_SeZarazkou(prvkyNeser, pocetPrvku+1, 8);
	zpracujVysledek(prvkyNeser, hledanyIndex);
	mezera();





	Tprvek prvkySer[pocetPrvku+1]; // pro zarazku
	generujSerazeneKlice(prvkySer, pocetPrvku);

	// Sekvencni vyhledavani na Serazenem poli BEZ zarazky
	algoritmusIntro(prvkySer, pocetPrvku, "Sekvencni vyhledavani na Serazenem poli BEZ zarazky");
	hledanyIndex = sekvencniHledani_Serazeno_BezZarazky(prvkySer, pocetPrvku, 35);
	zpracujVysledek(prvkySer, hledanyIndex);

	hledanyIndex = sekvencniHledani_Serazeno_BezZarazky(prvkySer, pocetPrvku, 50);
	zpracujVysledek(prvkySer, hledanyIndex);
	mezera();


	return 0;
}