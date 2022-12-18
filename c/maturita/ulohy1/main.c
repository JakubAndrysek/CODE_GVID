#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	int pocetVrcholu;
	int delkaStrany;
} nUhelnik;


nUhelnik nUhelnikNastav(nUhelnik uhelnik, int pocetVrcholu, int delkaStrany) {
	uhelnik.delkaStrany = delkaStrany;
	uhelnik.pocetVrcholu = pocetVrcholu;
	return uhelnik;
}

void nUhelnikNastavOdkazem(nUhelnik *uhelnik, int pocetVrcholu, int delkaStrany) {
	uhelnik->pocetVrcholu = pocetVrcholu;
	uhelnik->delkaStrany = delkaStrany;
}

nUhelnik* nUhelnikVytvor(int pocetVrcholu, int delkaStrany) {
	nUhelnik *uhelnik = malloc(sizeof(nUhelnik));
	if(uhelnik == NULL) {
		printf("Nepodarilo se vytvorit nUhelnik\n");
		exit(EXIT_FAILURE);
	}
	uhelnik->pocetVrcholu = pocetVrcholu;
	uhelnik->delkaStrany = delkaStrany;
	return uhelnik;
}

void nUhelnikZrus(nUhelnik *uhelnik) {
	free(uhelnik);
}

void nUhelnikTisknikMalloc(nUhelnik *uhelnik) {
	printf("nUhelnik: vrcholu: %d delka strany: %d\n", uhelnik->pocetVrcholu, uhelnik->delkaStrany);
}

void nUhelnikTisknik(nUhelnik uhelnik) {
	printf("nUhelnik: vrcholu: %d delka strany: %d\n", uhelnik.pocetVrcholu, uhelnik.delkaStrany);
}

float nUhelnikObvod(nUhelnik uhelnik) {
	return uhelnik.delkaStrany * uhelnik.pocetVrcholu;
}

float nUhelnikPolomer(nUhelnik uhelnik) {
	return (uhelnik.delkaStrany / (2 * sin(180 / uhelnik.pocetVrcholu))) / 2;
}


void testZakladni() {
	nUhelnik ctyrUhelnik;
	ctyrUhelnik = nUhelnikNastav(ctyrUhelnik, 4, 10);
	nUhelnikTisknik(ctyrUhelnik);
	printf("Obvod: %f\n", nUhelnikObvod(ctyrUhelnik));
	printf("Polomer: %f\n", nUhelnikPolomer(ctyrUhelnik));
}

void testOdkazem() {
	nUhelnik ctyrUhelnik;
	nUhelnikNastavOdkazem(&ctyrUhelnik, 4, 10);
	nUhelnikTisknik(ctyrUhelnik);
	printf("Obvod: %f\n", nUhelnikObvod(ctyrUhelnik));
	printf("Polomer: %f\n", nUhelnikPolomer(ctyrUhelnik));
}

void testMalloc() {
	nUhelnik *uhelnik = nUhelnikVytvor(4, 10);
	nUhelnikTisknikMalloc(uhelnik);
	nUhelnikZrus(uhelnik);
}

int main() {
	testZakladni();

	testOdkazem();

	testMalloc();
}