#include <stdio.h>

void diagonala1(char mat[][20],int n){
  int i,j;
  for (i=0; i<n; i++)
  {
    for (j=0; j<n; j++)
    {
      if (j>i)
          mat[i][j]='&';
      else
          mat[i][j]='#';
    }
  }

}

void diagonala2(char mat[][20],int n)
{
  int i,j;
  for (i=0; i<n; i++)
  {
    for (j=0; j<n; j++)
    {
      if (j>i)
          mat[i][j]='+';
      else
          mat[i][j]='-';
      if(j==i)
       mat[i][j] = 'o';
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

diagonala1(matice,n);
vypisMatici(matice,n);
diagonala2(matice,n);
vypisMatici(matice,n);

return 0;
}
