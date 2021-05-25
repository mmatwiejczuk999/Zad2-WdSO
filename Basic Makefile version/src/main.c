#include <stdio.h>
#include "area.h"
#include "volume.h"

int main()
{   
    float area, volume, side;

    printf("Podaj bok figur: "); scanf("%f", &side);
    printf("\n");
    area = calcArea(side);
    volume = calcVolume(side);

    printf("Pole kwadratu: %f\n", area);
    printf("Pole calkowite szescianu: %f\n", 6*area);
    printf("Objetosc szescianu: %f\n", volume);

    return 0;
}