#include <stdio.h>


void vypisMatici(int mat[][20],int n, int m){
int i,j,soucet = 0;
  printf("\n");
  for (i=0; i<n; i++)
  {
    for (j=0; j<m; j++)
    {
      printf("%3d",mat[i][j]);
      soucet += mat[i][j];
    }
    printf(" -> %2d",soucet);
    soucet = 0;
    printf("\n");
  }
}
void nactiMatici(int mat[][20],int n, int m){
int i,j;
  for (i=0; i<n; i++)
    for (j=0; j<m; j++)
        scanf("%d",&mat[i][j]);
}

int main(void) {
  int n=0, m=0;
  int matice[20][20];//definice matice
  do{
    printf("Zadej pocet radku matice (<21): ");
    scanf("%d",&n);
  } while(n<1 || n>20);

  do{
    printf("Zadej pocet sloupcu matice (<21): "); //Abych mohl pridat 1 sloupec
    scanf("%d",&m);
  } while(m<1 || m>20);

  nactiMatici(matice,n,m);
  vypisMatici(matice,n,m);

  return 0;
}
