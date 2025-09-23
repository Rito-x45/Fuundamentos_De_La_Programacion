#include <stdio.h>

int edad = 0;

int main(void){
    printf("ingrese su edad por favor: ");
    scanf("%d", &edad);

    if (edad >= 18)
        printf("medicamento aprovado para ser vendido\n");
    
    if (edad < 18)
        printf("Aun no tienes edad para comprar el medicamento\n");

    return 27;
}


