#include <stdio.h>

void vyplnSloupce(int mat[][20],int n, int m)
{
    int i,j;
    for (i=0; i<n; i++)
    {
        for (j=0; j<m; j++)
        {
            mat[i][j]=j+1;
        }
    }

}

//doplňte tuto funkci tak, aby na prvním řádku byly jedničky, na druhém dvojky, ...
void vyplnRadky(int mat[][20],int n, int m)
{
    for(int y = 0; y < n; y++)
    {
        for(int x = 0; x < m; x++)
        {
            mat[y][x] = y+1;
        }
    }

}

// BOONUS :-)
void vyplnSikmo(int mat[][20],int n, int m)
{
    for(int y = 0; y < n; y++)
    {
        for(int x = 0; x < m; x++)
        {
            mat[y][x] = y+x+1;
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

int main(void) {
int n=0, m=0;
int matice[20][20];
do{
printf("Zadej pocet radku matice (<21): ");
scanf("%d",&n);
} while(n<1 || n>20);

do{
printf("Zadej pocet sloupcu matice (<21): ");
scanf("%d",&m);
} while(m<1 || m>20);

vyplnSloupce(matice,n,m);
vypisMatici(matice,n,m);
vyplnRadky(matice,n,m);
vypisMatici(matice,n,m);
vyplnSikmo(matice,n,m); //BONUS :-)
vypisMatici(matice,n,m);

return 0;
}
