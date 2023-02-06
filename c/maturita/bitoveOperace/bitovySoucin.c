#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define BITS 16

void binarniSoucin(char a[], char b[]) {
  char result[BITS+1] = {0};

  for (int i = 0; i < BITS; i++) {
    result[i] = (a[i] == '1' && b[i] == '1') ? '1' : '0';
  }

  printf("Vysledek: %s\n", result);
}

void bitovyPosun(char a[], int posun) {
	
}

int main() {
  char num1[17] = "0101010101010101";
  char num2[17] = "1010101010101010";

  binarniSoucin(num1, num2);

  return 0;
}