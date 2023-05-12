#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int overZnakyVRetezciPodleJazyka(const char jazyk[], char testujiRetezec[]) {
	for(int pozRet = 0; testujiRetezec[pozRet] != '\0'; pozRet++) {
		printf("Kontroluji: %c\n", testujiRetezec[pozRet]);
		bool jeSoucastiJazyka = false;
		for(int pozJaz = 0; jazyk[pozJaz] != '\0'; pozJaz++) {
			if(testujiRetezec[pozRet] == jazyk[pozJaz]) {
				jeSoucastiJazyka = true;
			}
		}
		if(!jeSoucastiJazyka) {
			printf(" -> ERR: znak '%c' nepatri do jazyka\n\n", testujiRetezec[pozRet]);
			return pozRet;
		}
	}
	printf("OK\n\n");
}


int main() {

	const char jazyk[] = "0123"; // 4 soustava
	const char testovanyRetezec[] = "02512";

	overZnakyVRetezciPodleJazyka(jazyk, testovanyRetezec);

	overZnakyVRetezciPodleJazyka("01", "01110101101010");

	overZnakyVRetezciPodleJazyka("abc", "back");
	return 0;
}