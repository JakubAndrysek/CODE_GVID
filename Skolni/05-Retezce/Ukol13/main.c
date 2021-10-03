#include <stdio.h>
#include <stdlib.h>
int delka(char r[]){
int i;
for (i=0;r[i]!='\0';i++)
;
return i;
}

char smaz_i_ty_znak(char r[],int i){
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

void smaz_znaky(char r[], char c){
    int length = delka(r);
    for(int i = length-1; i >= 0; i --)
    {
        if(r[i] == 'e')
        {
            smaz_i_ty_znak(r, i);
        }
    }
}

int main()
{
    char ret[26], smazanyZnak;
    printf("Zadej slovo: ");
    scanf("%25s",ret);
    smaz_znaky(ret,'e');
    printf("Promazany retezec: %s",ret);
    return 0;
}
