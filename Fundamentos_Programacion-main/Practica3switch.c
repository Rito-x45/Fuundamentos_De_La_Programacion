#include <stdio.h>

int opcion = 0;

int main()
{
    printf("Bienvenido");
    printf("1 Pasta \n2 Pizza \n3 Sopa \n4 Cafe \n5 Salir del menu\n");
    printf("Seleccciona solo el numero: ");
    scanf("%d", &opcion);

    switch (opcion)
    {
        case 1:
            printf("\n Haz elegido la Pasta\n Disfrutala =)");
            break;

        case 2:
            printf("\n Haz elegido la Pizza\n Disfrutala =)");
            break;
        
        case 3:
            printf("\n Haz elegido la Sopa\n Disfrutala =)");
            break;

        case 4:
            printf("\n Haz elegido la Cafe\n Disfrutala =)");
            break;

        case 5:
            //nada print("salir del menu");
            break;

        default:
            printf("Opcion invalida");
            break;
    }

    return 27;
}