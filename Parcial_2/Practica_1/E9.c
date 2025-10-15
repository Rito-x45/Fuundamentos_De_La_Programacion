#include <stdio.h>

int kwh = 1;

int main()
{
    while (kwh < 0)
    {
        printf("\nIngresa la Cantidad de Kwh consumidos:");
        scanf("%d", &kwh);
        if(kwh < 100)
            printf("Bajo consumo");
        else if(kwh >=100 && kwh < 300)
            printf("Consumo normal");        
        else 
            printf("Alto consumo");
    }
}