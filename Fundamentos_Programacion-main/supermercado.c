#include <stdio.h>
#define DESCUENTO 0.20
#define IVA 0.16

float gasto = 0, gastocdes = 0, cuentat = 0;

int main(void)
{
    printf("ingrese la cantidad de dineo que gasto: \n");
    scanf("%f", &gasto);

    if(gasto > 1000)
    {
        gastocdes = (gasto * DESCUENTO);
        cuentat = (((gasto - gastocdes) * IVA) + gasto);

        printf("Tu total a pagar es de: %.2f \n", cuentat);
    }
    if(gasto <= 1000)
    {
        cuentat = ((gasto * IVA) + gasto);
        printf("Tu total a pagar es de: %.2f \n", cuentat);
    }

    return 27;
}
