#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rozdel(int nTice, FILE *fIn, FILE *fOut1, FILE *fOut2) {
  if (nTice <= 0)
    return;

  int ch;
  int count = 0;
  while ((ch = fgetc(fIn)) != EOF) {
    if (count < nTice) {
      fputc(ch, fOut1);
    } else {
      fputc(ch, fOut2);
    }
    count++;
		if(count  == 2*nTice) {
			count = 0;
		}
  }
}

int main() {
  FILE *fIn = fopen("fIn.txt", "r");
  FILE *fOut1 = fopen("fOut1.txt", "w");
  FILE *fOut2 = fopen("fOut2.txt", "w");

  if (fIn == NULL || fOut1 == NULL || fOut2 == NULL) {
    printf("Error opening\n");
    return 1;
  }

  const int nTice = 2;
  rozdel(nTice, fIn, fOut1, fOut2);

  return 0;
}