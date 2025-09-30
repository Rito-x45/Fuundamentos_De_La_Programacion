#include <stdio.h>
#include <ctype.h>

#define TC_USD 18.50
#define TC_EUR 20.00
#define DESC_EST 0.10
#define DESC_TERC 0.15

int opcion = 0, hora_ent = 0, min = 0;
float monedamxn = 0.0, convercionf = 0.0, estatura = 0.0, peso = 0.0, imc = 0.0, precio = 0.0, preciof = 0.0, ahorro = 0.0, distancia = 0.0, velp = 0.0, temp_h = 0.0;
char convercion = 'a', categoriac = 'a';

int main()
{
    printf("Selecciona una opcion del Menu\n1) Conversor de divisas(MXN->USD/EUR)\n2)Calculadora de IMC\n3)Descuento en Tienda\n4)Tiempo de Viaje\n5)Salir");
    printf("Solo pon el digito (Ej. 5): ");
    scanf("%d", &opcion);

    switch (opcion)
    {
        case 1:
            printf("Ingresa la cantidad de pesos que deseas convertir: ");
            scanf("%f", &monedamxn);
            printf("A que lo deas convertir?\nusd preiona 'D'/'d'\n eur preciona 'E'/'e'\n elige: ");
            scanf(" %c", &convercion);
            convercion = tolower(convercion);
            if(monedamxn >= 0) 
            {
                switch (convercion)
                {
                    case 'd':
                        convercionf = monedamxn/TC_USD;
                        printf("Tus pesos a dolares son: %.2f", convercionf);
                        break;

                    case 'e':
                        convercionf = monedamxn/TC_EUR;
                        printf("Tus pesos a dolares son: %.2f", convercionf);
                        break;
                    
                    default:
                        printf("Error\nNo selecciono una opcion valida");
                        break;
                }
            } 
            else 
                printf("Error\nLa cantidad debe ser mayor o igual a 0");
        break;
        
        case 2: 
            printf("Ingresa tu peso en Kg: ");
            scanf("%f", &peso);
            printf("Ingresa tu estatura en metros: ");
            scanf("%f", &estatura);

            if(peso > 0 && estatura > 0)
            {
                imc = peso/(estatura*estatura);
                printf("Tu Indice de masa corporal (IMC) es : %.2f \n Tienes: ", imc);

                if (imc < 18.5)
                    printf("Bajo Peso");

                else if (imc >= 18.5 && imc <= 24.9)
                    printf("Peso Normal");
                else if (imc >= 25 && imc <= 29.9)
                    printf("SObrepeso");
                else 
                    printf("Obesidad");
            }
            else
                printf("Eroro\nTu peso y estatura deben ser mayores a 0");
        break;

        case 3:
            printf("Ingresa el precio del producto: ");
            scanf("%f", &precio);
            printf("Ingresa que tipo de cliente eres: \n'e' para estudiante\n't' pata tercera edad\n'n' para ninguno\nTipo de Cliente: ");
            scanf(" %c", &categoriac);
            categoriac = tolower(categoriac);
            if(precio >= 0)
            {
                switch (categoriac)
                {
                case 'e':
                    ahorro = precio * DESC_EST;
                    preciof = precio - ahorro;
                    printf("Tu precio final es: %.2f\nAhorraste %.2f", preciof, ahorro);
                    break;
                
                case 't':
                    ahorro = precio * DESC_TERC;
                    preciof = precio - ahorro;
                    printf("Tu precio final es: %.2f\nAhorraste %.2f", preciof, ahorro);
                    break;
                
                case 'n':
                    ahorro = precio * 0;
                    preciof = precio - ahorro;
                    printf("Tu precio final es: %.2f\nAhorraste %.2f", preciof, ahorro);
                    break;
                
                default:
                    printf("Error\n opcion no valida");
                    break;
                }
            }
            else
                printf("El precio debe ser mayor o igual a 0");
        break;

        case 4:
            printf("Ingresa la distancia en Km: ");
            scanf("%f", &distancia);
            printf("Ingresa tu velocidad promedio: ");
            scanf("%f", &velp);

            if(distancia>= 0 && velp > 0)
            {
                temp_h= distancia/velp;
                printf("tu tiempo aproximado es %.2f", temp_h);
            } 

            else
            printf("Error\nDebe ser mayor a 0 la vel y igual o diferente la distancia");
        break;

        case 5:
            printf("Gracias por usar el menu\nAdios;)");
        break;

        default:
            printf("Ninguna Opcion seleccionada");
        break;
    }

}
