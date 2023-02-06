#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sluc(FILE *f1, FILE *f2, FILE *fSeraz) {
  bool notEmpty = true;

  int ch1 = fgetc(f1);
  int ch2 = fgetc(f2);

  while (notEmpty) {

    if (ch1 == EOF && ch2 == EOF) {
      printf("Error reading OR end of file\n");
      notEmpty = false;
      return;
    }

    if (ch1 == EOF || ch2 == EOF) {
      printf("Read one of them\n");
      if (ch1 != EOF) {
        fputc(ch1, fSeraz);
      } else {
        fputc(ch2, fSeraz);
      }
      notEmpty = false;
      return;
    }

    if (ch1 < ch2) {
      fputc(ch1, fSeraz);
      ch1 = fgetc(f1);
    } else {
      fputc(ch2, fSeraz);
      ch2 = fgetc(f2);
    }
  }
}

void testSerazeni(FILE *fSeraz) {
  rewind(fSeraz);
  int ch1 = fgetc(fSeraz);
  int ch2 = fgetc(fSeraz);
  while (ch1 != EOF && ch2 != EOF) {
    printf("%c", ch1);
    if (ch2 >= ch1) {
      ch1 = ch2;
      ch2 = fgetc(fSeraz);
    } else {
      printf("\nNeni serazeno\n");
      return;
    }
  }
  printf("\nJe serazeno\n");
}

int main() {
  FILE *f1 = fopen("in1.txt", "r");
  FILE *f2 = fopen("in2.txt", "r");
  FILE *fSeraz = fopen("out1+2.txt", "w+");

  if (f1 == NULL || f2 == NULL || fSeraz == NULL) {
    printf("Error opening\n");
    return 1;
  }

  sluc(f1, f2, fSeraz);

  testSerazeni(fSeraz);

  fclose(fSeraz);
  fclose(f1);
  fclose(f2);

  return 0;
}