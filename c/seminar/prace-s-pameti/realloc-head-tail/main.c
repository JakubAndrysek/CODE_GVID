/*
 * Projekt:
 * Autor:
 * Datum:
 */

//#include "gvid.h"       // par drobnosti pro zjednoduseni prace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // pro praci s textovymi retezci
// #include <stdbool.h> // pro praci s typem bool a konstantami true a false
// #include <ctype.h>   // isalpha, isspace, islower, isupper, ...
// #include <math.h>    // funkce z matematicke knihovny
// #include <float.h>   // konstanty pro racionalni typy DBL_MAX, DBL_DIG, ...
// #include <limits.h>  // konstanty pro celociselne typy INT_MAX, INT_MIN, ...
// #include <time.h>    // funkce time a dalsi pro praci s casem
#include "queue.h"

//fronta jako pole
//pole ukazatelu na radky
//kruhova indexace
void showHelp() {
    printf(
            "Vytvoř program headtail, který podle zadaných parametrů vypíše zadaný počet prvních nebo posledních řádků standardního vstupu.\n"
            "\n"
            "headtail(.exe) [-h] (head | tail) pocet\n"
            "-h -- nepovinný parametr - vytiskne nápovědu\n"
            "head nebo tail -- volitelný (jeden nebo druhý) parametr\n"
            "pocet -- počet řádků, které se budou tisknout\n"
            "\n"
            "Pozor! Čteš ze standardního vstupu, takže dopředu nevíš, jak dlouhé budou vstupní řádky, ani kolik jich bude.\n"
            "\n"
            "Odevzdávej soubor ukol3-PrijmeniJmeno.zip bez adresářů bin a obj.\n");
}


void head(FILE* in, int count) {
    char c;
    while ((c = fgetc(in)) != EOF) {
        if (c == '\n') {
            count--;
            if(count <=0) {
                return;
            }
        }
        printf("%c", c);
    }
}

void tail(FILE* in, int count) {
    Tqueue* queue = createQueue(count);

    char item;
    int size = 0;
    int capacity = 0;
    while ((item = getchar())!= EOF) {
        switch (item) {
            case '\n':
                addItem(queue, '\0', &size, &capacity); // end string
                startNewLine(queue);
                capacity = 0;
                size = 0;
                break;
            default:
                addItem(queue, item, &size, &capacity);
                break;
        }
    }
//    loadQueue(queue, stdin);
    printf("Result:\n");

    printQueue(queue);

    deleteQueue(queue);
}

int argToInt(char text[]) {
    char *ptr;
    long ret = strtol(text, &ptr, 10);
    if(*ptr != '\0') {
        printf("E: neprevedeno '%s' na cislo\n", text);
        exit(EXIT_FAILURE);
    }
    return ret;
}

void processArguments(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0) {
            showHelp();
            return;
        }
    }

    if(argc<3) {
        printf("E: malo argumentu");
        return;
    }

    FILE* file = fopen(argv[3], "r");

    if (strcmp(argv[1], "head") == 0) {
        head(file, argToInt(argv[2]));
    } else if (strcmp(argv[1], "tail") == 0) {
        tail(file, argToInt(argv[2]));
    }
}

int main(int argc, char *argv[])  // pro parametry prikazoveho radku
{
    processArguments(argc, argv);
    return 0;
}
