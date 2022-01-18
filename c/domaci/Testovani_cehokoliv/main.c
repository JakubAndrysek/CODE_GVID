#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>




int delka(char r[]){
int i;
for (i=0;r[i]!='\0';i++)
;
return i;
}

char toLowChar(char *text[])
{
  int length = delka(text);
  printf("fDelka: %d", length);

  return text;
}

int main()
{
    char text[11] = "AhOj";
    char nove[11];
    //puts(toLowChar(text));
    int length = delka(text);
    printf("Delka: %d\n", length);
    /*
    for(int i = 0; i<length; i++)
    {

    //text[i] = tolower(text[i]);
      printf("*%c*\n", tolower(text[i]));
    }
    */
    nove = toLowChar(text);


    return 0;
}
