#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nacteneCislo() {
  int znak;
  int vysledneCislo = 0;
  while ((znak = getc(stdin)) != '\n') {
    // printf("%d\n", znak);
    if (znak >= '0' && znak <= '9') {
      vysledneCislo *= 10;             // Zvysime rad
      int prevedeneCislo = znak - '0'; // Prevedeme znak na cislo
      vysledneCislo += prevedeneCislo; // pricteme prevedene cislo
    } else {
		break;
	}
  }
  return vysledneCislo;
}

void test() {
	int a = 5;
	for(int i = 0; i < 5; i++, a++) {
		printf("%d [%d]\n", i, a);
	}
}

int main() {

//   int vysledneCislo = nacteneCislo();
//   printf("Vysledne cislo: %d\n", vysledneCislo);
	test();

  return 0;
}