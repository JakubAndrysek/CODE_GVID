#include <stdio.h>

int main() {
  // Deklarace proměnných pro vstupní čísla a výsledek
  int num1 = 0b10101010;
  int num2 = 0b01010101;
  int result = 0;

  // Projdeme bity od nejméně významného po nejvýznamnější
  for (int i = 0; i < 8; i++) {
    // Sčítáme bity pomocí bitového XOR
    result ^= ((num1 >> i) & 1) ^ ((num2 >> i) & 1);

    // Nastavíme přenášení pomocí bitového OR a AND
    result |= (((num1 >> i) & 1) & ((num2 >> i) & 1)) << (i + 1);
  }

  // Vytiskneme výsledek
  printf("%d\n", result);

  return 0;
}