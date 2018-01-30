
#include "resistance.h"
#include "stdio.h"
#include "stdbool.h"

// Author Per Mackegård 20180128

static bool validateInput(int count, char conn, float *array);
static float calc_serial_resistance( int count, float *array);
static float calc_parallell_resistance( int count, float *array);


static float calc_serial_resistance( int count, float *array)
{

	float totalResistance = 0;

	for( int i = 0; i < count; i++)
	{
		totalResistance += array[i*sizeof(float)];
	}

	return totalResistance;

}


static float calc_parallell_resistance( int count, float *array)
{

	float totalResistance = 0;

	for( int i = 0; i < count; i++)
	{
		totalResistance += 1/array[i*sizeof(float)];
	}

	totalResistance = 1/totalResistance;


	return totalResistance;

}


static bool validateInput(int count, char conn, float *array)
{

	if(count <= 0)
	{
		printf("The count of items are incorrect: %d\n", count);
		return false;
	}
	else if( conn != 'S' && conn != 'P')
	{
		printf("Not a valid connection type: %c\n", conn);
		return false;
	}
	else if( array == NULL )
	{
		printf("Array is NULL\n");
		return false;	
	}

	for(int i = 0; i < count; i++)
	{
		if( array[i] < 0)
		{
			printf("The resistance is incorrect: %f\n", array[i]);
			return false;
		}
	}

	return true;

}



float calc_resistance(int count, char conn, float *array)
{

	float totalResistance = -1;

	// If validateInput returns  < 0 the input is incorrect

	if( !validateInput(count,conn,array) )
	{
		return -1;
	}
	
	switch(conn)
	{

		case('S'):
		{
			totalResistance = calc_serial_resistance( count, array);
			break;
		}
		case('P'):
		{
			totalResistance = calc_parallell_resistance( count, array);
			break;
		}
		default:
			break;
	}

	return totalResistance;

}
