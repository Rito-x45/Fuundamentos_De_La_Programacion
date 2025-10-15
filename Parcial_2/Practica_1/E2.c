#include <stdio.h>

int ahorro = 10, dia = 1;

int main()
{
    while (ahorro <= 100)
    {
        printf("Dia %d, tengo ahorrado %d\n", dia, ahorro);
        dia++;
        ahorro += 10;
    }
    
}