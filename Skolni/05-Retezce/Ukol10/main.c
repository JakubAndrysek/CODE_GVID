#include <stdio.h>
#include <stdlib.h>

int delka(char r[]){
    int i;
    for (i=0;r[i]!='\0';i++)
    ;
    return i;
}

char smazKonec(char r[]){
    int length  = delka(r);
    char out = r[length-1];
    r[length-1] = r[length];
    return out;
}

int main()
{
    char ret[26], smazanyZnak;
    printf("Zadej slovo: ");
    scanf("%25s",ret);
    smazanyZnak=smazKonec(ret);
    printf("Snazany znak: %c | Zbytek: %s\n", smazanyZnak, ret);
    return 0;
}
