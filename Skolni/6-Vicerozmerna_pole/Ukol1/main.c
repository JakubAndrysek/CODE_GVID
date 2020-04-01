#include <stdio.h>

//funkce, která najde největší číslo v matici. Princip je stejný jako u jednorozměrného pole.
int max(int mat[][20],int n, int m)
{
    int max = mat[0][0];
    for(int y = 0; y < n; y++)
    {
        for(int x = 0; x < m; x++)
        {
            if(mat[y][x] > max)
            {
                max = mat[y][x];
            }
        }
    }
    return max;
}

//funkce na doplnění, která vrací aritmetický průměr čísel v matici
float prumer(int mat[][20],int n, int m)
{
    float prumer = 0.0;

    for(int y = 0; y < n; y++)
    {
        for(int x = 0; x < m; x++)
        {
            prumer += mat[y][x];
        }
    }
    return prumer/(n*m);
}

void nactiMatici(int mat[][20], int n, int m)
{
    for(int y = 0; y < n; y++)
    {
        printf("Zadej sloupec cislo %d\n", y);
        for(int x = 0; x < m; x++)
        {
            scanf("%d", &mat[y][x]);
        }
    }
}

void vypisMatici(int mat[][20], int n, int m)
{
    printf("Vypis matice\n");
    for(int y = 0; y < n; y++)
    {
        for(int x = 0; x < m; x++)
        {
            printf("%d", mat[y][x]);
        }
        printf("\n");
    }
}

// funkce pro načtení a výpis si napište sami

int main(void)
{
    int n=0, m=0;
    int matice[20][20];//definice matice
    do{
        printf("Zadej pocet radku matice (<21): ");
        scanf("%d",&n);
    } while(n<1 || n>20);

    do{
        printf("Zadej pocet sloupcu matice (<21): ");
        scanf("%d",&m);
    } while(m<1 || m>20);

    nactiMatici(matice,n,m);
    vypisMatici(matice,n,m);
    printf("Nejvetsi cislo v matici je %d\n",max(matice,n,m));
    printf("Aritmeticky prumer cisel v matici je %.2f",prumer(matice,n,m));

    return 0;
}
