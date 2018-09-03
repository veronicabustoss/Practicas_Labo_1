#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num1, num2, num3, num4, num5, promedio;

    printf("Ingrese numero 1:");
    scanf("%f",&num1);
    printf("Ingrese numero 2:");
    scanf("%f",&num2);
    printf("Ingrese numero 3:");
    scanf("%f",&num3);
    printf("Ingrese numero 4:");
    scanf("%f",&num4);
    printf("Ingrese numero 5:");
    scanf("%f",&num5);

    promedio= (num1+ num2+ num3+ num4+ num5)/5;

    printf("El promedio es %.2f",promedio);
    return 0;
}
