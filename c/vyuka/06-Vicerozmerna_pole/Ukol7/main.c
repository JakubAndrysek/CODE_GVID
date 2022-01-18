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
void nactiMatici(int mat[][20],int n, int m){
int i,j;
  for (i=0; i<n; i++)
    for (j=0; j<m; j++)
        scanf("%d",&mat[i][j]);
}
int vymenSloupcu(int mat[][20],int n, int m,int s1, int s2){
  //vymena  sloupce s1 se sloupcem s2
  if ((s1<1 || s1>m) || (s2<1 || s2>m)){
      printf("Aspon jeden sloupec neexistuje.\n") ;
      return 0;
  }

  s1--;
  s2--;

  int vymena[20];
  for(int y = 0; y<m; y++)
  {
    vymena[y] = mat[y][s1];
    //printf("%d, ",vymena[y]);
    mat[y][s1] = mat[y][s2];
    mat[y][s2] = vymena[y];
  }


  return 1;
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

  nactiMatici(matice,n,m);
  vypisMatici(matice,n,m);
  if (vymenSloupcu(matice,n,m,1,n+3))
    printf("Vymenily se sloupce %d s %d.\n",1,n+3);
  else
    printf("Sloupce %d a %d se nevymenily.\n", 1, n+3);
  vypisMatici(matice,n,m);

  if (vymenSloupcu(matice,n,m,1,2))
    printf("Vymenily se sloupce %d. s %d.\n",1,2);
  else
    printf("Sloupce %d a %d se nevymenily.\n", 1, 2);

  vypisMatici(matice,n,m);

  return 0;
}
