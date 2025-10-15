#include <stdio.h>

int edad = 1, menores = 0, mayores = 0;

int main()
{
    while (edad != 0)
    {
        printf("\nIngresa la edad (0 para terminar):");
        scanf("%d", &edad);
        if(edad < 18)
            menores++;
        else
            mayores++;
    }
    printf("\nHay %d menores y %d mayores\n", menores, mayores);
}