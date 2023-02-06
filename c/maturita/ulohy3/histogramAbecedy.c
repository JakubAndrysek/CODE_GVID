#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void histogramAbecedy(int x[], int size, FILE *file) {
  char c;
  while ((c = fgetc(file)) != EOF) {
    x[c - 'a']++;
  }
}

void testHistogramAbecedy() {
  FILE *file = fopen("testHistogram.txt", "r");
  // FILE* file  = stdin;

  if (file == NULL) {
    printf("Error file\n");
    exit(-1);
  }

  const int size = 26;
  int abeceda[size];

  for (int i = 0; i < size; i++) {
    abeceda[i] = 0;
  }

  histogramAbecedy(abeceda, size, file);

  for (int i = 0; i < size; i++) {
    printf("Znak %c je zastoupen %d\n", 'a' + i, abeceda[i]);
  }
}

int main() {
  testHistogramAbecedy();
  return 0;
}