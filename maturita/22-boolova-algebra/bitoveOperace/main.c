#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef void (*eventFunction2arg)(const char cisA[], const char cisB[], char res[]);
typedef void (*eventFunction1argMove)(const char cisA[], char res[], int posun);

void testBitOperaci(const char cisA[], const char cisB[], eventFunction2arg function) {
	printf("InA: %s\n", cisA);
	printf("InB: %s\n", cisB);

	char result[9];
	function(cisA, cisB, result);
	printf("Res: %s\n\n", result);

}

void testBitMove(const char cisA[], int posun, eventFunction1argMove function) {
	printf("pos: %d\n", posun);
	printf("InA: %s\n", cisA);

	char result[9];
	function(cisA, result, posun);
	printf("Res: %s\n\n", result);

}

void bitovySoucinAnd(const char cisA[], const char cisB[], char res[]) {
	for(int iter = 0; cisA[iter] != '\0'; iter++) {
		if(cisA[iter] == '1' || cisB[iter] == '1') {
			res[iter] = '1';
		} else {
			res[iter] = '0';
		}
	}
}

void bitovySoucetOr(const char cisA[], const char cisB[], char res[]) {
	for(int iter = 0; cisA[iter] != '\0'; iter++) {
		if(cisA[iter] == '1' && cisB[iter] == '1') {
			res[iter] = '1';
		} else {
			res[iter] = '0';
		}
	}
}

/**
 * @brief Bitovy XOR function
 * 0 0 -> 0
 * 0 1 -> 1
 * 1 0 -> 1
 * 1 1 -> 0
 * @param cisA
 * @param cisB
 * @param res
 */
void bitovySoucetXOr(const char cisA[], const char cisB[], char res[]) {
	for(int iter = 0; cisA[iter] != '\0'; iter++) {
		if(cisA[iter] != cisB[iter]) {
			res[iter] = '1';
		} else {
			res[iter] = '0';
		}
	}
}

/**
 * @brief Bitovy posun
 * nejdriv si vysledne mistastavim na 0 (vsechny prvky)
 * jdu po prvcich a vypocitam posunuty index, pokud neexistuje toto misto v rozsahu -> zahazuji, jinak zapisu
 *
 * @param cisA
 * @param res
 * @param posun
 */
void bitovyPosun(const char cisA[], char res[], int posun) {
	const int len = strlen(cisA);
	for(int i = 0; i < len; i++) { // prvne vse nastavim na 0 (jde udelat lepe)
		res[i] = '0';
	}

	for(int i = 0; i < len; i++) {
		int posunIndex = i + posun;
		if(posunIndex > 0 && posunIndex < len) {
			res[posunIndex] = cisA[i];
		}
	}
}

/**
 * @brief Bitova rotece
 * Jedu po znacich a vkladam je na posunute misto POSUN.
 * Pomoci modula si index premapuji na spravny rozsah
 * @param cisA
 * @param res
 * @param posun
 */
void bitovaRotece(const char cisA[], char res[], int posun) {
	const int len = strlen(cisA);
	for(int i = 0; i < len; i++) {
		res[(i+posun)%len] = cisA[i];
	}
}

void aritmetickySoucetBitove(const char cisA[], const char cisB[], char res[]) {
	const int len = strlen(cisA);
	bool prenasimBit = false;
	for(int i = len-1; i >= 0; i--) { // prvne vse nastavim na 0 (jde udelat lepe)
		if((prenasimBit || cisA[i] == '1') && cisB[i] == '1') { // pokud je 1 A 1 -> 0 + zbytek 1
			res[i] = '0';
			prenasimBit = true;
		} else if((prenasimBit || cisA[i] == '1') || cisB[i] == '1') { // pokud je 0 A 1 | 1 A 0 -> 1 + zbytek 0
			res[i] = '1';
			prenasimBit = false;
		} else { // jinak 0 A 0 + zbytek 0
			res[i] = '0';
			prenasimBit = false;
		}

	}
}


int main() {
	char cisloA[] = "10000101"; // 133
	char cisloB[] = "01001001"; // 73



	// bitovySoucinAnd(cisloA, cisloB, result);
	// print8bit(result);

	printf("Bitovy And\n");
	testBitOperaci(cisloA, cisloB, bitovySoucinAnd);

	printf("Bitovy Or\n");
	testBitOperaci(cisloA, cisloB, bitovySoucetOr);

	printf("Bitovy XoR\n");
	testBitOperaci(cisloA, cisloB, bitovySoucetXOr);

	printf("Bitovy posun\n");
	testBitMove(cisloA, -3, bitovyPosun);

	printf("Bitovay rotace\n");
	testBitMove(cisloA, 1, bitovaRotece);
	testBitMove(cisloA, -1, bitovaRotece);
	testBitMove(cisloA, 6, bitovaRotece);

	printf("Aritmeticky soucet bitove\n");
	// https://slideplayer.cz/slide/3340124/11/images/6/Součet+dvojkových+čísel.jpg
	testBitOperaci(cisloA, cisloB, aritmetickySoucetBitove); // prevedeny vysledek je 206
	return 0;
}