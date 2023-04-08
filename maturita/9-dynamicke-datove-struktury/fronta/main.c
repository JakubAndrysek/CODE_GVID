#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _tprvek Tprvek;

struct _tprvek {
	int data;
	Tprvek *next;
};

typedef struct {
	Tprvek *first;
	int length;
} Thead;



Thead* frontaVytvor() {
	Thead* fronta = malloc(sizeof(Thead));
	if(fronta != NULL) {
		fronta->first = NULL;
		fronta->length = 0;
		return fronta;
	}
	return NULL;
}

bool frontaPridej(Thead* fronta, int data) {
	Tprvek* new = malloc(sizeof(Tprvek));

	if(new == NULL) {
		printf("ERROR: fronta pridej failed\n");
		return false;
	}
	new->data = data;
	new->next = NULL;
	fronta->length++;

	if(fronta->first != NULL) {
		new->next = fronta->first;
	}
	fronta->first = new;
	return true;
}

void frontaTiskni(Thead *fronta) {
	Tprvek *posledni = fronta->first;

	while(posledni != NULL) {
		printf("%d\n", posledni->data);
		posledni = posledni->next;
	}
}

void frontaZrus(Thead *fronta) {
	while(fronta->first != NULL) {
		Tprvek *mazu = fronta->first;
		fronta->first = fronta->first->next;
		free(mazu);
	}
	free(fronta);
}

int frontaOdeber(Thead *fronta) {
	int frontaData = fronta->first->data;
	fronta->length--;
	Tprvek* druhy = fronta->first->next;
	free(fronta->first);
	fronta->first = druhy;
	return frontaData;
}

int frontaNahled(Thead *fronta) {
	return fronta->first->data;
}



int main() {
	Thead* fronta = frontaVytvor();

	frontaPridej(fronta, 1);
	frontaPridej(fronta, 2);
	frontaPridej(fronta, 3);

	frontaTiskni(fronta);

	int odebiram = frontaOdeber(fronta);
	printf("odebrano %d\n", odebiram);

	frontaTiskni(fronta);

	frontaZrus(fronta);

	return 0;
}