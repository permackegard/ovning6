#include<stdio.h>
#include "libs/resistance/resistance.h"


static void testResistanceLib();


static void testResistanceLib()
{

	float testArray[3] = { 100, 50, 20};
	int count = 3;
	char conn ='P';

	float sum = calc_resistance( count, conn, testArray);


	printf("%f\n", sum);
}


 
int main()
{

	int voltage = 0;
	char koppling;
	int numberOfComponents = 0;


	printf("Ange spänningskälla i V: ");
	scanf("%d", &voltage);
	printf("Ange koppling[S | P]: ");
	scanf(" %c", &koppling);
	printf("Antal komponenter: ");
	scanf(" %d", &numberOfComponents);

	// ToDo: Add support for when user adds several components. Add dynmic allocation then.

	// Just for testing resistance lib right no
	testResistanceLib();
 
	return 0;
}