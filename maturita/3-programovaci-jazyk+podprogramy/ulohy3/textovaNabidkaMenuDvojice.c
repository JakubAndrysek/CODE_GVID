#include <stdio.h>

// Definujeme strukturu pro dvojici (znak, řetězec)
struct Pair {
  char ch;
  char str[100];
};

// Funkce, která vytiskne textovou nabídku a načte volbu od uživatele
char menu(struct Pair pairs[], int n) {
  printf("Vyberte možnost:\n");
  for (int i = 0; i < n; i++) {
    printf("%c - %s\n", pairs[i].ch, pairs[i].str);
  }
  printf("Zadejte volbu: ");

  // Načteme volbu od uživatele
  char ch = getchar();

  // Přečteme zbytek řádku
  while (getchar() != '\n')
    ;

  // Podle zvolené volby vrátíme odpovídající znak
  for (int i = 0; i < n; i++) {
    if (pairs[i].ch == ch) {
      return ch;
    }
  }
  return 'X';
}

int main() {
  // Vytvoříme pole dvojic (znak, řetězec)
  struct Pair pairs[4] = {
      {'A', "Volba A"},
      {'B', "Volba B"},
      {'K', "Konec"},
      {'X', "Neznámá volba"},
  };

  // Komunikujeme s uživatelem dokud nezvolí ukončení programu
  char ch;
  do {
    ch = menu(pairs, 4);
    switch (ch) {
    case 'A':
      printf("Zvolil jste volbu A\n");
      break;
    case 'B':
      printf("Zvolil jste volbu B\n");
      break;
    case 'K':
      printf("Ukončuji program\n");
      break;
    case 'X':
      printf("Neznámá volba\n");
      break;
    }
  } while (ch != 'K');

  return 0;
}