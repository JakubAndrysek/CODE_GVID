#include <stdio.h>


void vypisMatici(int mat[][20],int n, int m){
int i,j;
  printf("\n");
  for (i=0; i<n; i++){
    for (j=0; j<m; j++){
        printf("%3d",mat[i][j]);
    }
    printf("\n");
  }
}
void vyplnCisla(int mat[][20],int n, int m){
  for(int y = 0; y<n; y++)
  {
    for(int x = 0; x<m; x++)
    {
      mat[y][x] = 1+x+(y*m);
    }
  }
}

int main(void) {
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

  vyplnCisla(matice,n,m);
  vypisMatici(matice,n,m);

  return 0;
}
