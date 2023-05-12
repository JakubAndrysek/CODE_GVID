#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

enum {
	PREFIX,
	ARROW,
	SUFFIX,
} Egrma;


bool isCharInString(const char c, const char string[]) {
	for(int iter = 0; string[iter] != '\0'; iter++) {
		if(c == string[iter]) {
			return true;
		}
	}
	return false;
}
/**
 * @brief Kontrola regularni grmamtiky
 * Pravidla tvaru A → a, A → aB | A → a, A → Ba (Ale nelze obo je zaroven A → aB | Ba)
 *	– a ∈ Σ je terminální symbol
 *	– A, B ∈ N jsou nonterminály

 * @param terminaly
 * @param nonTerminaly
 * @param retezec
 * @return true
 * @return false
 */
bool overPodleGramatikyTypu3(const char terminaly[], const char nonTerminaly[], const char retezec[]) {
	int state = PREFIX;
	for(int retPoz = 0; retezec[retPoz] != '\0'; retPoz++) {
		char c = retezec[retPoz];
		char cNext = retezec[retPoz+1];

		switch (state) {
		case PREFIX:
			if(c == '-') {
				state = ARROW;
				continue;
			}
			if(!isCharInString(c, nonTerminaly)) {
				printf("\nChyba Prefix: %c\n\n", c);
				return false;
			}

			// printf("%c", c);
			break;

		case SUFFIX:
			if(isCharInString(c, terminaly)) {
				if(retezec[retPoz+1] == '\0') {
					return true; // a
				} else if (isCharInString(cNext, nonTerminaly)) {
					return true; // aS | aA | aB | aC
				} else {
					printf("Error SUFFIX: %c (aa | aX)\n\n", c);
					return false; // aa | aX
				}
			} else if (isCharInString(c, nonTerminaly)) {
				if (isCharInString(cNext, terminaly)) {
					return true; // Sa | Aa | Ba | Ca
				} else {
					printf("Error SUFFIX: %c (AA | AD)\n\n", c);
					return false; // AA | AD
				}
			} else {
				printf("Error SUFFIX: %c (unhandled character)\n", c);
				return false;
			}

			// printf("%c", c);
			break;

		case ARROW:
			if(c == '>') {
				state = SUFFIX;
			} else {
				printf("Chyba Arrow: %c\n\n", c);
				return 	 false;
			}
			break;
		}
	}
	return true;
}


/**
 * @brief Kontrola Bezkontextove gramatiky
 * Pravidla tvaru A → α
 *	– α ∈ (N ∪ Σ)* cokoliv (z Abecedy nebo nonterminalu)
 * 	– A ∈ N je nonterminál
 *
 * @param terminaly
 * @param nonTerminaly
 * @param retezec
 * @return true
 * @return false
 */
bool overPodleGramatikyTypu2(const char terminaly[], const char nonTerminaly[], const char retezec[]) {
	int state = PREFIX;
	for(int retPoz = 0; retezec[retPoz] != '\0'; retPoz++) {
		char c = retezec[retPoz];
		char cNext = retezec[retPoz+1];

		switch (state) {
		case PREFIX:
			if(c == '-') {
				state = ARROW;
				continue;
			}
			if(!isCharInString(c, nonTerminaly)) {
				printf("\nChyba Prefix: %c\n\n", c);
				return false;
			}

			// printf("%c", c);
			break;

		case SUFFIX:
			if(isCharInString(c, terminaly) || isCharInString(c, nonTerminaly)) {
				return true;
			} else {
				printf("CHyba Suffix: %c\n\n", c);
				return false;
			}

			// printf("%c", c);
			break;

		case ARROW:
			if(c == '>') {
				state = SUFFIX;
			} else {
				printf("Chyba Arrow: %c\n\n", c);
				return 	 false;
			}
			break;
		}
	}
	return true;
}


int main() {

	const char terminaly[] = "a";
	const char nonTerminaly[] = "SABC";
	const char retezec[100];
	bool gJeTyp3;
	bool gJeTyp2;

	strcpy(retezec, "A->Sa");
	gJeTyp3 = overPodleGramatikyTypu3(terminaly, nonTerminaly, retezec);
	printf("Retezec: '%s' je gramatiky typu 3: %d\n", retezec, gJeTyp3);

	strcpy(retezec, "A->aB");
	gJeTyp3 = overPodleGramatikyTypu3(terminaly, nonTerminaly, retezec);
	printf("Retezec: '%s' je gramatiky typu 3: %d\n", retezec, gJeTyp3);

	strcpy(retezec, "A->SB");
	gJeTyp3 = overPodleGramatikyTypu3(terminaly, nonTerminaly, retezec);
	printf("Retezec: '%s' je gramatiky typu 3: %d\n", retezec, gJeTyp3);



	////////////////////////////////////////
	// Gramatik  typu 2 - Kontextova
	strcpy(retezec, "A->a");
	gJeTyp2 = overPodleGramatikyTypu2(terminaly, nonTerminaly, retezec);
	printf("Retezec: '%s' je gramatiky typu 2: %d\n", retezec, gJeTyp2);

	strcpy(retezec, "A->S");
	gJeTyp2 = overPodleGramatikyTypu2(terminaly, nonTerminaly, retezec);
	printf("Retezec: '%s' je gramatiky typu 2: %d\n", retezec, gJeTyp2);

	strcpy(retezec, "A->Sa");
	gJeTyp2 = overPodleGramatikyTypu2(terminaly, nonTerminaly, retezec);
	printf("Retezec: '%s' je gramatiky typu 2: %d\n", retezec, gJeTyp2);



	return 0;
}