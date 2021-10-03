#include <stdio.h>
#include <stdlib.h>

void BMI(FILE* vstup, FILE* vystup, int big, FILE* vystupObez)
{
    char jmeno[21];
    int vyska;
    float hmotnost;

    while(fscanf(vstup, "%s %d %f", jmeno, &vyska, &hmotnost) == 3)
    {
			float bmiVypo = hmotnost/((vyska/100.0)*(vyska/100.0));

			printf("%s ma BMI %.2f\n", jmeno, bmiVypo);
			fprintf(vystup, "%s ma BMI %.2f\n", jmeno, bmiVypo);

			if(bmiVypo > big)
			{
				fprintf(vystupObez, "%s je obezni ma BMI %.2f\n", jmeno, bmiVypo);
			}

    }
}


void BMIbonus(FILE* vstup, FILE* vystup, int big, FILE* vystupObez)
{
    char jmeno[20];
    int vyska;
    float hmotnost;

    while(fscanf(vstup, "%20[a-zA-Z] ,%d ,%f ", jmeno, &vyska, &hmotnost) == 3)
    {
			float bmiVypo = hmotnost/((vyska/100.0)*(vyska/100.0));

			printf("%s %d %.2f\n", jmeno, vyska, hmotnost);
			printf("%s ma BMI %.2f\n", jmeno, bmiVypo);
			fprintf(vystup, "%s ma BMI %.2f\n", jmeno, bmiVypo);

			if(bmiVypo > big)
			{
				fprintf(vystupObez, "%s je obezni ma BMI %.2f\n", jmeno, bmiVypo);
			}
    }
}


int main(int argc, char *argv[])  // pro parametry prikazoveho radku
{
  FILE* vstup = fopen("Vstup.txt", "r");
  FILE* bonus = fopen("Bonus.txt", "r");
  FILE* vystup = fopen("Vystup.txt", "w");
  FILE* vystupObez = fopen("VystupObez.txt", "w");

  if(vstup == NULL)
  {
    printf("Chyba otevreni");
    return 1;
  }

  if(vystup == NULL)
  {
    printf("Chyba otevreni");
    return 1;
  }

  if(vystupObez == NULL)
  {
    printf("Chyba otevreni");
    return 1;
  }

  //BMI(vstup, vystup, 30, vystupObez);
  BMIbonus(bonus, vystup, 30, vystupObez);


  fclose(vstup);
  fclose(bonus);
  fclose(vystup);
  fclose(vystupObez);

  return 0;
}
