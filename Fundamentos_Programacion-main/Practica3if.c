#include <stdio.h>

int opcion = 0;

int main()
{
    printf("Bienvenido");
    printf("1 Pasta \n2 Pizza \n3 Sopa \n4 Cafe \n5 Salir del menu\n");
    printf("Seleccciona solo el numero: ");
    scanf("%d", &opcion);

    if(opcion == 1)
        printf("\n Haz elegido la Pasta\n Disfrutala =)");

    else if (opcion == 2)
       printf("\n Haz elegido la Pizza\n Disfrutala =)");
    
    else if (opcion == 3)
       printf("\n Haz elegido la Sopa\n Disfrutala =)");

    else if (opcion == 4)
       printf("\n Haz elegido la Cafe\n Disfrutala =)");
    
    else if (opcion == 5);
       //nada
    
    else
        printf("Opcion invalida");
    
    return 27;
}