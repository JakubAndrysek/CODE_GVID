#include <stdio.h>
#include <stdlib.h>

int delka(char r[]){
int i;
for (i=0;r[i]!='\0';i++)
;
return i;
}

char smaz_i_ty_znak(char r[],int i){

    //tady smažte i-tý znak z řetězce ret
    //nezapomeňte, že první znak má index 0
    //pokud i-tý znak neexistuje, vraťte '\0'
    int length = delka(r);
    if(i<0 || i > length)
    {
        return '0';
    }
    char out = r[i];
    for(int x = i; x < length; x++)
    {
        r[x] = r[x+1];
    }

    return out;
}

int main()
{
    char ret[26], smazanyZnak;
    printf("Zadej slovo: ");
    scanf("%25s",ret);
    smazanyZnak = smaz_i_ty_znak(ret, 5); //smazano seste pismeno, protoze pocitame od nuly!!!
    printf("Smazany znak je %c\na z řetězce zbývá %s ", smazanyZnak, ret);

    return 0;
}
