#include <stdio.h>

void vedlejsiDiagonala1(char mat[][20],int n){
  int i,j;
   for (i=0; i<n; i++)
    for (j=0; j<n; j++)
      if (n-j>i)
        mat[i][j]='&';
      else
        mat[i][j]='#';
}

void vedlejsiDiagonala2(char mat[][20],int n)
{
    for(int y = 0; y < n; y++)
    {
        for(int x = 0; x < n; x++)
        {
            if(x+y == n-1)
            {
                mat[y][x] = '*';
            }
            else
            {
                mat[y][x] = '-';
            }
        }
    }
}

void vypisMatici(char mat[][20],int n){
 int i,j;
  for (i=0; i<n; i++){
    for (j=0; j<n; j++)
      printf("%2c",mat[i][j]);
    printf("\n");
  }
}

int main(void) {
  int n=0, m=0;
  char matice[20][20];
  do{
    printf("Zadej rozmer ctvercove matice (<21): ");
    scanf("%d",&n);
  } while(n<1 || n>20);

  vedlejsiDiagonala1(matice,n);
  vypisMatici(matice,n);
  vedlejsiDiagonala2(matice,n);
  vypisMatici(matice,n);

  return 0;
}
