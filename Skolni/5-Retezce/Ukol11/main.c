#include <stdio.h>
#include <stdlib.h>

int delka(char r[]){
int i;
for (i=0;r[i]!='\0';i++)
;
return i;
}

char smazZacatek(char r[]){
    char out = r[0];
    int length = delka(r);
    for(int x = 1; x<= length; x++)
    {
        r[x-1] = r[x];
    }
    return out;
}

int main()
{
    char ret[26], smazanyZnak;
    printf("Zadej slovo: ");
    scanf("%25s",ret);
    smazanyZnak=smazZacatek(ret);
    printf("Snazany znak: %c | Zbytek: %s\n", smazanyZnak, ret);
    return 0;
}
