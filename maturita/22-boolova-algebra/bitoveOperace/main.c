#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef void (*eventFunction)(const char cisA[], const char cisB[], char res[]);

void testBitOperaci(const char cisA[], const char cisB[], eventFunction function) {
	printf("InA: %s\n", cisA);
	printf("InB: %s\n", cisB);

	char result[9];
	function(cisA, cisB, result);
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


int main() {
	char cisloA[] = "00000101"; // 4
	char cisloB[] = "00001001"; // 4



	// bitovySoucinAnd(cisloA, cisloB, result);
	// print8bit(result);

	testBitOperaci(cisloA, cisloB, bitovySoucinAnd);
	
	testBitOperaci(cisloA, cisloB, bitovySoucetOr);

	return 0;
}