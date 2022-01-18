#include <stdio.h>
#include <stdlib.h>

int elementCount(char arr[])
{
    int i = 0;
    for(; arr[i] != '\0'; i++)
    {
        ;
    }
    return i;
}

void addLast(char arr[], char var)
{
    char count = elementCount(arr);
    arr[count+1] = arr[count];
    arr[count] = var;
}

void vytvor_ab(int n, char ret[]){
    for(int i = 'a'; i!='c'; i++)
    {
        for(int x = 0; x < n; x++)
        {
            addLast(ret, i);
        }
    }
}
int main()
{
char ret[201]=""; //inicializace řetězce na prázdný řetězec
int n;
do {
printf("Zadej cele kladne cislo < 100: ");
scanf("%d",&n);
}while (n<=0 || n>100);

vytvor_ab(n, ret);
puts(ret);
return 0;
}
