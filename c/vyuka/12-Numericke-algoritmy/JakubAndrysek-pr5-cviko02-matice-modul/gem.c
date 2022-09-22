#include "gem.h"
#include <string.h>


Tmatice* vyrobMatici(int radku, int sloupcu) {
  Tmatice* matice = malloc(sizeof(Tmatice));
  if(matice == NULL) {
    printf("E: matice nevytvorena\n");
    return NULL;
  }

  matice->prvek = malloc(radku * sizeof(float*));
  if(matice->prvek == NULL) {
      free(matice);
      printf("E: matice nevytvorena\n");
      return NULL;
  }

  for(int i = 0; i < radku; i++) {
    matice->prvek[i] = malloc(sloupcu * sizeof(float));
    if(matice->prvek[i] == NULL) {
      matice->radku = i;
      matice->sloupcu = sloupcu;
      znicMatici(matice);
      printf("E: prvky matice nevytvoreny\n");
      return NULL;
    }
  }

  matice->radku = radku;
  matice->sloupcu = sloupcu;
  return matice;
}


void znicMatici(Tmatice* matice) {
  if(matice == NULL) {
    return;
  }

  for(int r = 0; r < matice->radku; r++) {
    free(matice->prvek[r]);
  }
  free(matice->prvek);
  free(matice);
}

Tmatice* ctiM(FILE *in) {
    int radku;
    if (fscanf(in, "%d", &radku) != 1) {
        printf("E: nenacteny rozmery matice - radky\n");
        exit(EXIT_FAILURE);
    }

    int sloupcu;
    if (fscanf(in, "%d ", &sloupcu) != 1) {
        printf("E: nenacteny rozmery matice - sloupce\n");
        exit(EXIT_FAILURE);
    }

    Tmatice *m = vyrobMatici(radku, sloupcu);
    if(m == NULL) {
      printf("E: Matice nevytvorena\n");
      exit(0);
    }

    for (int r = 0; r < (m->radku); r++) {
        for (int s = 0; s < (m->sloupcu); s++) {
            if (!fscanf(in, "%f ", &m->prvek[r][s]) == 1) {
                printf("E: cteni matice r:%d s:%d\n", r, s);
                m->sloupcu = s;
                m->radku = r;
                exit(EXIT_FAILURE);
            }
        }
    }

    printf("Nactena matice %d x %d\n", m->radku, m->sloupcu);
    return m;
}

void tiskM(FILE *out, Tmatice *m) {
    for (int r = 0; r < m->radku; r++) {
        for (int s = 0; s < m->sloupcu; s++) {
            printf("%+2.2f | ", m->prvek[r][s]);
        }
        printf("\n");
    }
}

Tmatice* soucetM(Tmatice *m1, Tmatice *m2) {
    if (!(m1->radku == m2->radku && m1->sloupcu == m2->sloupcu)) {
        printf("E: matice nelze secist\n");
        exit(EXIT_FAILURE);
    }

    Tmatice* soucet = vyrobMatici(m1->radku, m2->sloupcu);

    for (int r = 0; r < m1->radku; r++) {
        for (int s = 0; s < m1->sloupcu; s++) {
            soucet->prvek[r][s] = m1->prvek[r][s] + m2->prvek[r][s];
        }
    }

    soucet->radku = m1->radku;
    soucet->sloupcu = m1->sloupcu;
    return soucet;
}

Tmatice* soucinM(Tmatice *m1, Tmatice *m2) {
    if (m1->sloupcu != m2->radku) {
        printf("E: nelze nasobit matice s rozdilnymi rozmery\n");
        return NULL;
    }

    Tmatice* soucin = vyrobMatici(m1->radku, m2->sloupcu);

    for (int r = 0; r < m1->radku; r++) {
        for (int s = 0; s < m2->sloupcu; s++) {
            soucin->prvek[r][s] = 0;
            for (int i = 0; i < m1->sloupcu; i++) {
                soucin->prvek[r][s] += m1->prvek[r][i] * m2->prvek[i][s];
            }
        }
    }

    soucin->radku = m1->radku;
    soucin->sloupcu = m2->sloupcu;
    return soucin;
}
