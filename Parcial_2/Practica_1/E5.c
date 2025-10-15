#include <stdio.h>

int vel = 0;

int main()
{
    printf("Ingresa tu velocidad: ");
    scanf("%d", &vel);
    
    while (vel > 120)
    {
        printf("\n\t\tExecso de velocidad\nIngresa una nueva velocidad:");
        scanf("%d", &vel);
    }

    printf("\nVelocidad acpetable\n");
    
}