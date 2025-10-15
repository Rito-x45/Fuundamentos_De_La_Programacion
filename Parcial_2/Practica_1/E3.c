#include <stdio.h>

int num = 1, suma = 0;

int main()
{
    do
    {
        printf("Ingrsa un numero(si pones 0 la suma termina): ");
        scanf("%d", &num);
        suma = num + suma;
    } while (num != 0);

    printf("La suma final es de: %d \n", suma);
    
    
}