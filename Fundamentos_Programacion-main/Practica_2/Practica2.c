#include <stdio.h>
#define PI 3.1415926

int id = 0;
float r = 0, area = 0, perimetro = 0, circunferencia = 0;
char u = 'a';

int main(void)
{
    printf("Ingresa el radio del circulo: ");
    scanf("%f", &r);

    printf("Quiere el resultado en centimetros o metros?\nSi lo desea en cm ingrese c, si lo desea en metros m: ");
    scanf(" %c", &u);

    printf("ID de proyecto: %d\n", ++id);
    printf("Tu radio es: %f %c\n", r, u);

    area = PI * r * r;
    perimetro = PI * (r * 2);
    circunferencia = PI * (r * 2);

    printf("El area de tu circulo es: %f %c\n", area, u);
    printf("El perimetro de tu circulo es: %f %c\n", perimetro, u);
    printf("La circunferencia es: %f %c\n", circunferencia, u);
    return 0;
}