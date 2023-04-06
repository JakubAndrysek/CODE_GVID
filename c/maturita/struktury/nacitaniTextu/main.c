#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
	char jmeno[MAX];
	char skola[MAX];
	int cisloPopisne;
	int pocetHodnot;
} Tsettings;


void loadSettingsPtr(FILE* f, Tsettings *settings) {
	if(fscanf(f, "Jmeno: %10s\n", settings->jmeno) != 1) {
		printf("Read Jmeno ERROR\n");
	}

	if(fscanf(f, "Skola: %10s\n", settings->skola) != 1) {
		printf("Read Skola ERROR\n");
	}
	if(fscanf(f, "CP: %d\n", &settings->cisloPopisne) != 1) {
		printf("Read CP ERROR\n");
	}
	settings->pocetHodnot = 3;
}

Tsettings loadSettingsRet(FILE* f) {
	Tsettings settings;
	if(fscanf(f, "Jmeno: %10s\n", settings.jmeno) != 1) {
		printf("Read Jmeno ERROR\n");
	}

	if(fscanf(f, "Skola: %10s\n", settings.skola) != 1) {
		printf("Read Skola ERROR\n");
	}
	if(fscanf(f, "CP: %d\n", &settings.cisloPopisne) != 1) {
		printf("Read CP ERROR\n");
	}
	settings.pocetHodnot = 3;
	return settings;
}

void printSettings(Tsettings settings) {
	printf("Jmeno: %s\n", settings.jmeno);
	printf("Skola: %s\n", settings.skola);
	printf("CP: %d\n", settings.cisloPopisne);
}


int main() {


	FILE* f = fopen("settings.txt", "r");
	if(f == NULL) {
		printf("ERROR read file\n");
		return EXIT_FAILURE;
	}

	Tsettings settings;

	settings = loadSettingsRet(f);

	printSettings(settings);

	// load trought pointer
	rewind(f); // reset file read pointer
	Tsettings settingsPtr;
	loadSettingsPtr(f, &settingsPtr);
	printSettings(settings);



	return 0;
}