#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

char menuBasic() {
  printf("\n\nVyberte možnost:\n");
  printf("A - Volba A\n");
  printf("B - Volba B\n");
  printf("K - Konec\n");
  printf("Zadejte volbu: ");

  char znak = getchar();

  while (getchar() != '\n');

  switch (znak) {
  case 'K':
    return 'K';
  case 'A':
    return 'A';
  case 'B':
    return 'B';
  default:
    return 'X';
  }
}

void testmenu() {
  char ch;
  do {
    ch = menuBasic();
	printf(">>>>");

    switch (ch) {
    case 'K':
      printf("Koncim");
      break;
    case 'A':
      printf("Volba A");
	  break;
    case 'B':
      printf("Volba B");
	  break;
    case 'X':
      printf("Neznama volba");
	  break;
    }
	printf("<<<<<\n");

  } while (ch != 'K');
}

int main() {

  testmenu();
  return 0;
}