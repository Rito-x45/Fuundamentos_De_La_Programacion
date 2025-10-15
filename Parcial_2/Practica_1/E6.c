#include <stdio.h>

int preciop = 1, suma = 0;

int main()
{
    do
    {
        printf("Ingrsa los precios de los productos que deseas(si pones 0 la suma termina): ");
        scanf("%d", &preciop);
        suma = preciop + suma;
    } while (preciop != 0);
    
    printf("La suma final es de: %d \n", suma);   
}