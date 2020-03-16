/*
 * Projekt: Corona 1
 * Autor: Jakub Andrysek
 * Datum: 2020-3-16
 */

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

void addFirst(char arr[], char var)
{
    int count = elementCount(arr);
    for(int i = count+1; i>0; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[0] = var;
}

void printByElement(char arr[])
{
    int count = elementCount(arr);
    for( int i = 0; i<count; i++)
    {
        printf("[%d] -> %c\n",  i,arr[i] );
    }
}

int from10to2(int num, char arr[], int length)
{
    while(num > 0)
    {
        if(elementCount(arr)+1 <= length)
        {
            if(num%2 == 0)
            {
                addFirst(arr, '0');
            }
            else
            {
                addFirst(arr, '1');
            }
            num =  num / 2;
        }
        else
        {
            return 0;
        }


    }
    return 1;
}

void convertFrom10to2()
{
    int dec;
    int length = 100;
    char bin[101] = "";
    printf("Convert from decimal to binar\nEnter decimal number: ");
    scanf("%d", &dec);
    printf("Convert decimal number %d to binar -> ", dec);

    int status = from10to2(dec, bin, length);
    if(status)
    {
        puts(bin);
    }
    else
    {
        printf("Error - length\n");
    }

    printf("\n");
}

int from2to10(char arr[])
{
    int num = 2;
    int count = elementCount(arr);
    int dec = arr[0] - '0';
    for(int i = 1; i<count; i++)
    {
        dec = dec * num + (arr[i] - '0');
    }
    return dec;
}

void convertFrom2to10()
{
    int dec;
    char bin[101] = "";
    printf("Convert from binar to decimal\nEnter binar string: ");
    scanf("%100s", bin);
    printf("Convert binar string %s to decimal-> ", bin);
    printf("%d\n\n", from2to10(bin));
}

void cesar(char arr[], int jump)
{
    int count = elementCount(arr);
    for(int i = 0; i < count; i++)
    {
        if(arr[i]+jump>'z' && arr[i]>='a' && arr[i] <= 'z')
        {
            printf("%c", arr[i]+jump-('z' - 'a'+1));
        }
        else if(arr[i]+jump>'Z' && arr[i] >= 'A' && arr[i] <='Z')
        {
            printf("%c", arr[i]+jump-('Z' - 'A'+1));
        }
        else
        {
            printf("%c", arr[i]+jump);
        }
    }
    printf("\n\n");
}

void cesarUse()
{
    char array[101];
    printf("Cesar\nEnter the word: ");
    scanf("%100s", array);
    cesar(array, 3);
}

void cesarKey(char arr[], char key)
{
    int jump = key - 'a';
    cesar(arr,jump);
}

void cesarKeyUse()
{
    char array[101];
    char key;
    printf("Cesar with key\nEnter the word: ");
    scanf("%100s", array);
    printf("Enter the key: ");
    scanf(" %c", &key);
    cesarKey(array, key);
}

void intro()
{
    printf("Jakub Andrysek - 3.G - 16. 3. 2020\n\n");
}

int main()
{
    intro();
    convertFrom10to2();
    convertFrom2to10();
    cesarUse();
    cesarKeyUse();
    return 0;
}
