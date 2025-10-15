#include <stdio.h>

int precio = 0, suma = 0, opcion = 0;

int main()
{
    do
    {
        printf("\nEscoge una opcion del Menu: \n1.Hamburguesa $50\n2.Refresco $20\n3.Papas $25\n4.Salir\nElija una opcion: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
            case 1:
                printf("\nEscogio Hamburgesa\n");
                precio = 50;
                break;
            case 2:
                printf("\nEscogio Refresco\n");
                precio = 20;
                break;
            case 3:
                printf("\nEscogio Papas\n");
                precio = 25;
                break;
            case 4:
                printf("\nSalio del menu\n");
                break;
            
            default:
            printf("\nOpcion invalida\n");
                break;
        }
        suma = precio + suma;
    } while (opcion != 4);

    printf("La cuenta final es de: %d \n", suma); 
}