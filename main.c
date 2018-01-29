#include<stdio.h>
#include<stdlib.h>
#include "libs/resistance/resistance.h"
#include "libs/power/power.h"
#include "libs/component/component.h"

static void testResistanceLib();
static void testPowerLib();
static void testComponentLib();

static void testResistanceLib()
{

	float testArray[3] = { 100, 50, 20};
	int count = 3;
	char conn ='P';

	float sum = calc_resistance( count, conn, testArray);


	printf("%f\n", sum);
}

static void testPowerLib()
{

	float volt = 12;
	float resistance = 100; 
	float current  = 1;

	float power_r = calc_power_r( volt, resistance);

	float power_i = calc_power_i( volt, current);


	printf("power_r %f\n", power_r);
	printf("power_i %f\n", power_i);
}

static void testComponentLib() 
{
	float *testArray = (float*) malloc(sizeof(float[3]));
	float orig_resistance = 300;
	testArray[0] = 100;
	testArray[1] = 200;
	testArray[2] = 300;


	int count = e_resistance(orig_resistance, testArray);
	printf("0: %f\n", testArray[0]);
	printf("1: %f\n", testArray[1]);
	printf("2: %f\n", testArray[2]);
	printf("Count: %i\n", count); 


	orig_resistance = 1000;
	testArray[0] = 100;
	testArray[1] = 500;
	testArray[2] = 300;


	count = e_resistance(orig_resistance, testArray);
	printf("0: %f\n", testArray[0]);
	printf("1: %f\n", testArray[1]);
	printf("2: %f\n", testArray[2]);
	printf("Count: %i\n", count); 
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

	// Just for testing libs
	testResistanceLib();
	testPowerLib();
	testComponentLib();

	return 0;
}
