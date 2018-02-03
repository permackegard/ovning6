#include<stdio.h>
#include<stdlib.h>
#include "libs/resistance/resistance.h"
#include "libs/power/power.h"
#include "libs/component/component.h"

int main()
{

    int voltage = 0;
    char koppling;
    int numberOfComponents = 0;
    float *resistorPtr = NULL;

    printf("Ange spänningskälla | V: ");
    scanf("%d", &voltage);
    printf("Ange koppling[S | P]: ");
    scanf(" %c", &koppling);
    printf("Antal komponenter: ");
    scanf(" %d", &numberOfComponents);

    resistorPtr = (float *) malloc( numberOfComponents * sizeof(float));

    for(int i = 0; i< numberOfComponents; i++)
    {
        printf("Komponent %d | ohm: ", i + 1);
        scanf("%f", &resistorPtr[i]);
    }

    float sum = calc_resistance( numberOfComponents, koppling, resistorPtr);
    if (sum < 0)
    {
        printf("Resistance bibliotektet returnerade error. Felaktig input?\n");
        return 0;
    }
    else
    {
        printf("Ersättningsresistans:\n");
        printf("%.1f ohm\n", sum);
    }

    float power_r = calc_power_r( voltage, sum);
    printf("Effekt:\n");
    printf("%.2f\n", power_r);

    float *e12Array = (float*) malloc(sizeof(float[3]));

    int count = e_resistance( sum, e12Array);

    printf("Ersättningsresistanser i E12-serien kopplade i serie: \n");
    
    for(int i = 0; i < count; i++)
    {
        printf("%.f\n", e12Array[i]);
    }

    free(resistorPtr);
    free(e12Array);

    return 0;
}
