#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int spocitejSlovaNaRadku(char radek[]) {
	int slova = 0;
	int index = 0;
	while(radek[index] != '\0') {
		if(radek[index] != ' ' && radek[index] != '.' && index == 0) {
			slova++;
		}
		if(radek[index] == ' ') {
			slova++;
		}
		index++;
	}
	return slova;
}


void zpracujRadky(FILE* file) {
	char line[201];
	while(fscanf(file, "%200[^\t\n]\n", line) == 1) {
		int slova = spocitejSlovaNaRadku(line);
		printf("%d\n", slova);
	}
}






int main() {w
	FILE *file = fopen("testInput.txt", "r");
	if(file == NULL) {
		printf("Error opening\n");
		return EXIT_FAILURE;
	}

	zpracujRadky(file);


	return 0;
}