#include <stdio.h>

int cali = 0;

int main()
{
    do
    {
        printf("Ingrsa la calificacion(si pones -1 termina): ");
        scanf("%d", &cali);
        if (cali >= 0 && cali < 6)
            printf("Reprobado\n");
        else if(cali >= 6 && cali <= 8)
            printf("Regular\n");
        else if(cali >= 9)
            printf("Execxelente\n");
        //else
            //printf("calificacion invalida\n");
    } while (cali !=-1);      
}