#include "component.h"
#include "stdio.h"
#include "stdlib.h"

static float resistance_singular[12]      = {1.0, 1.2, 1.5, 1.8, 2.2, 2.7, 3.3, 3.9, 4.7, 5.6, 6.8, 8.2};
static float resistance_tens[12]      = {10.0, 12.0, 15.0, 18.0, 22.0, 27.0, 33.0, 39.0, 47.0, 56.0, 68.0, 82.0};
static float resistance_hundreds[12]  = {100.0, 120.0, 150.0, 180.0, 220.0, 270.0, 330.0, 390.0, 470.0, 560.0, 680.0, 820.0};
static float resistance_thousands[12] = {1000.0, 1200.0, 1500.0, 1800.0, 2200.0, 2700.0, 3300.0, 3900.0, 4700.0, 5600.0, 6800.0, 8200.0};
int count = 0;

static int find_fitting_resistance(float orig_resistance, float *res_array); 
static float insert_resistance(float orig_resistance, float *res_array, float *resistances); 

static int find_fitting_resistance(float orig_resistance, float *res_array)
{
    float current_resistance = orig_resistance;

    if(current_resistance >= 1000.0 && current_resistance <= 20600) 
    {
        current_resistance = insert_resistance(current_resistance, res_array, resistance_thousands);
    }
    if(current_resistance >= 100.0 && current_resistance < 1000) 
    {
        current_resistance = insert_resistance(current_resistance, res_array, resistance_hundreds);
    }
    if(current_resistance >= 10.0 && current_resistance < 100) 
    {
        current_resistance = insert_resistance(current_resistance, res_array, resistance_tens);
    }
    if(current_resistance >= 1.0 && current_resistance < 10) 
    {
        current_resistance = insert_resistance(current_resistance, res_array, resistance_singular);
    }
      
    return count;
}

static float insert_resistance(float orig_resistance, float *res_array, float *resistances)
{
    float current_resistance = orig_resistance;
    for(int i = 0; i < 11; i++)
    {
        if(count > 2)
        {
            break;
        }
        else if(current_resistance == resistances[i])
        {
            res_array[count] = resistances[i];
            current_resistance = 0;
            count++;
            break;
        }
        else if(current_resistance > resistances[i] 
            && current_resistance < resistances[i + 1])
        {
            res_array[count] = resistances[i];
            current_resistance = current_resistance - resistances[i];
            count++;
        }
        else if(current_resistance > resistances[11])
        {
            res_array[count] = resistances[11];
            current_resistance = current_resistance - resistances[11];
            count++;
        }
    }
    return current_resistance;
}

int e_resistance(float orig_resistance, float *res_array) 
{
    for(int i = 0; i < 3; i++)
    {
        res_array[i] = 0.0;
    }
    int count = find_fitting_resistance(orig_resistance, res_array);
    
    return count;
}
