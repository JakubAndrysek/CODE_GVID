#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

char cisloNaChar(int cislo) {
	if(cislo >= 0 && cislo < 10) {
		return cislo + '0';
	} else if(cislo >= 10 && cislo <= 'Z' - 'A' + 10) {
		return cislo + 'A' - 10;
	} else {
		return '?';
	}
}

void rozklad(int num, int soustava) {
	printf("Prevod z 10 do %d soustavy\n", soustava);
	printf("Prevadim %d na ", num);

	int pole[100]; // tohle neni idealni
	int counter = 0;
	// while loop to iterate through each digit
	while(num >= 1) {
		// calculate remainder
		int rozlozeno = num % soustava;
		// print the remainder
		// printf("%d", rozlozeno); // po vypsani je cislo v opacnem poradi
		pole[counter] = rozlozeno;
		counter++;
		// calculate quotient
		num = num / soustava;
	}

	// otocene poradi
	// counter-- tam musi byt protoze na konci zvysim pocitadlo counter++
	for(counter--; counter >= 0; counter--) {
		printf("%c", cisloNaChar(pole[counter]));
	}
	printf("\n\n");
}



int main() {

	int cislo = 172;
	// prevede cislo cislo z desitkove do 2
	rozklad(cislo, 2);

	// prevede cislo cislo z desitkove do 4
	rozklad(cislo, 4);

	// prevede cislo cislo z desitkove do 10
	rozklad(cislo, 10);

	// prevede cislo cislo z desitkove do 16
	rozklad(cislo, 16);
	return 0;
}