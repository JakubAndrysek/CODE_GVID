#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>



bool testujZavorky(const char vstup[]) {
	int pocitadlo = 0;
	for(int znak = 0; vstup[znak] != '\0'; znak++) {
		printf("%c", vstup[znak]);
		if(vstup[znak] == '[') {
			pocitadlo++;
		} else if(vstup[znak] == ']') {
			pocitadlo--;
		}
	}

	if(!(pocitadlo == 0)) {
		return false;
	}

	return true;
}


int main() {

	char testovanyVstpOK[] =  "[a]b[ ] [c[]d]";
	char testovanyVstpErr[] = "a[b]c]d[e[f]g]";


	bool jeSpravne;
	jeSpravne = testujZavorky(testovanyVstpOK);
	printf(" -> zavorky jsou spravne: %d\n", jeSpravne);

	jeSpravne = testujZavorky(testovanyVstpErr);
	printf(" -> zavorky jsou spravne: %d\n", jeSpravne);

	return 0;
}