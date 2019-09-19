#include <stdio.h>
#include <stdlib.h>

void From10(int input, int to){
    int output[100];
    int i=0, p=0;

    printf("Dvojkova:%d->Desitkova:",input);
    //Zbutek po deleni 2; celociselne deleni 2
    while(input!=0)
    {
        output[p] = input % to;
        input = input / to;
        //printf("C: %d|%d \n",input,output);
        p++;
    }
    //Vypis binarniho cisla
    for(i=p-1;i>=0;i--){
        printf("%d",output[i]);
    }

}


int main()
{
    int in, to;
    scanf("%d%d", &in, &to);

    From10(in,to);
    printf("\n\n");


    return 0;
}
