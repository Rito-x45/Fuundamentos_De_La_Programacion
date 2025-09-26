#include <stdio.h>

void menu(char decicion)
{
    if(decicion == 's')
    {
        printf("Bienvenido\n"); 
        printf("1 Pasta \n2 Pizza \n3 Sopa \n4 Cafe \n5 Salir del menu\n");
    }
        
    else 
        printf("ps ctm"); 
}

int main()
{
    char decicon; 

    printf("Desea ver el menu (s/n): ");
    scanf(" %c", &decicon);

    menu(decicon);
    
    return 0; 
}
