#include "gem.h"
#include <string.h>
#include <math.h>

int cisloChyby;

const char* CHYBOVE_HLASENI[] = {
    [EOK] = "Vse je v por",
    [EROZMER] = "Chybny rozmer matice",
    [ECTENI] = "Chyba cteni matice",
    [EPAMET] = "Chyba pameti - malloc",
    [ENEZNAMA] = "Neznama chyba",
};

const char* chyboveHlaseni(int kod) {
    if(kod < 0 || kod > ENEZNAMA) {
        kod = ENEZNAMA;
    }
    return CHYBOVE_HLASENI[kod];
}

const char* RESENI_ROVNICE[] = {
    [EJEDNO] = "Soustava je regularni - jedno reseni",
    [ENEKONECNO] = "Rovnice ma nekonecno reseni",
    [EZADNE] = "Rovnice nema reseni",
    [ECHYBARESENI] = "Chyba reseni",
};

const char* reseniRovnice(int kodReseni) {
    if(kodReseni < 0 || kodReseni > EZADNE) {
        kodReseni = ECHYBARESENI;
    }
    return RESENI_ROVNICE[kodReseni];
}

Tmatice* vyrobMatici(int radku, int sloupcu) {
  Tmatice* matice = malloc(sizeof(Tmatice));
  if(matice == NULL) {
    cisloChyby = EPAMET;
    return NULL;
  }

  matice->prvek = malloc(radku * sizeof(float*));
  if(matice->prvek == NULL) {
      free(matice);
      cisloChyby = EPAMET;
      return NULL;
  }

  for(int i = 0; i < radku; i++) {
    matice->prvek[i] = malloc(sloupcu * sizeof(float));
    if(matice->prvek[i] == NULL) {
      matice->radku = i;
      matice->sloupcu = sloupcu;
      znicMatici(matice);
      cisloChyby = EPAMET;
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
        cisloChyby = ECTENI;
        return NULL;
    }

    int sloupcu;
    if (fscanf(in, "%d ", &sloupcu) != 1) {
        cisloChyby = ECTENI;
        return NULL;
    }

    if(!(radku > 2 && radku + 1 == sloupcu)) {
        cisloChyby = EROZMER;
        return NULL;
    }

    Tmatice *m = vyrobMatici(radku, sloupcu);
    if(m == NULL) {
      cisloChyby = EPAMET;
      return NULL;
    }

    for (int r = 0; r < (m->radku); r++) {
        for (int s = 0; s < (m->sloupcu); s++) {
            if (!fscanf(in, "%f ", &m->prvek[r][s]) == 1) {
                printf("E: cteni matice r:%d s:%d\n", r, s);
                m->sloupcu = s;
                m->radku = r;
                cisloChyby = ECTENI;
                return NULL;
            }
        }
    }

    printf("Nactena matice %d x %d\n", m->radku, m->sloupcu);
    return m;
}

void tiskM(FILE *out, Tmatice *m) {
    for (int r = 0; r < m->radku; r++) {
        for (int s = 0; s < m->sloupcu; s++) {
            printf("%+3.2f | ", m->prvek[r][s]);
        }
        printf("\n");
    }
}


void vymenRadky(Tmatice* matice, int a, int b) {
    float* pom = matice->prvek[a];
    matice->prvek[a] = matice->prvek[b];
    matice->prvek[b] = pom;
}

int maxAbsPivot(Tmatice *matice, int d) {
    int max = d;
    for(int r = 1; r < matice->radku; r++) {
        if(fabs(matice->prvek[r][d]) > matice->prvek[max][d]) {
            max = r;
        }
    }
    return max;
}

void radkoveUpravy(Tmatice* matice, int r) {
    for(int k = r+1; k <= matice->radku-1; k++) {
        float c = matice->prvek[k][r] / matice->prvek[r][r];
        matice->prvek[k][r] = 0.0f;
        for(int s = r+1; s <= matice->radku; s++) {
            matice->prvek[k][s] = c*matice->prvek[r][s] - matice->prvek[k][s];
//            printf("rad set [%d][%d]\n", k, s);
//            tiskM(stdout, matice);
        }
    }
}

bool jeHorni(Tmatice* matice) {
    for(int r = 0; r < matice->radku; r++) {
        for(int s = 0; s < matice->sloupcu-1; s++) {
            if(s>=r) { // nad diagonalou + diagonala
//                printf("%+3.2f | ", matice->prvek[r][s]);
                if(fabs(matice->prvek[r][s]) == 0) {
                    return EXIT_FAILURE;
                }
            } else {
//                printf(" x   | ");
                if(fabs(matice->prvek[r][s]) != 0) {
                    return EXIT_FAILURE;
                }
            }
        }
//        printf("\n");
    }
    return EXIT_SUCCESS;
}

int testResitelnosti(Tmatice* matice) {
    int n = matice->radku-1;
    if(matice->prvek[n][n] != 0) {
        return EJEDNO;
    } else if (matice->prvek[n][n+1] == 0) {
        return ENEKONECNO;
    } else if (matice->prvek[n][n+1] == 0) {
        return EZADNE;
    } else {
        return ECHYBARESENI;
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
