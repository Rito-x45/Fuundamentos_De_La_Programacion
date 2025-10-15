#include <stdio.h>

char contra1[8] = "0", contra2[8] = "0";

int main()
{   
    printf("Ingresa tu contraseña (Maximo 8 caracteres): \n");
    scanf("%s", &contra1[8]);
    do
    {
        printf("confirma tu contraseña: \n");
        scanf("%s", &contra2[8]);
    } while (contra1[8] != contra2[8]);

    printf("Acceso permitido\n");
    
    
}