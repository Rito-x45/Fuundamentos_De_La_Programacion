#include <stdio.h>
#define PI 3.1415926

int id = 0;
float r = 0;
char u = 'a';
float perimetro = 0;
float area = 0;
float circunferencia = 0;

int main(void)
{
    printf("ingresa el radio del circulo: ");
    scanf("%f", r);
    printf("Quiere el resultado en centimetros o metros?: \n si lo desea en cm ingrese c, si lo desea en metros m:");
    scanf("%c", u);

    printf("id de proyecto %d", ++id);

    printf("Tu radio es: %f", r);

    area = PI * r * r;
    printf("El area de tu circulo es: %f %s ", area, u);

    perimetro = PI * (r * 2);
    printf("El perimetro de tu circulo es: %f %s", perimetro, u);

    circunferencia = PI * (r * 2);
    printf("La circunferencia es: %f %s", circunferencia, u);   

    return 27;
}