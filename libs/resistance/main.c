#include<stdio.h>
#include "resistance.h"


int main()
{

	float testArray[3] = { 100, 50, 20};
	int count = 3;
	char conn ='P';

	float sum = calc_resistance( count, conn, testArray);


	printf("%f\n", sum);

	return 0;
}