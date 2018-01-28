#include "component.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

static bool resistance_matching(float orig_resistance, float in_resistance); 
static bool check_for_single_match(float orig_resistance, float *res_array); 
static void clear_array(int i, float *res_array);

static bool resistance_matching(float orig_resistance, float in_resistance)
{
    float difference = orig_resistance * 0.1;
    float min = orig_resistance - difference;
    float max = orig_resistance + difference;
    printf("Min: %f\n", min);
    printf("Max: %f\n", max);
    if(in_resistance >= min
        && in_resistance <= max)
    {   
        printf("Match\n");
        return true;
    }
    return false;
}

static bool check_for_single_match(float orig_resistance, float *res_array) 
{
    for(int i = 0; i < 3; i++)
    {
        if(resistance_matching(orig_resistance, res_array[i])) 
        {
            clear_array(i, res_array);
            return true; 
        }
    }
    return false;
}

static void clear_array(int i, float * res_array)
{
    for(int j = 0; j < 3; j++)
    {
        if(j != i)
        {
            res_array[j] = 0.0;
        }
    }
}


int e_resistance(float orig_resistance, float *res_array) 
{
    float total_resistance = 0.0;
    int count = 0;
// first check for if 
    if(check_for_single_match(orig_resistance, res_array)) 
    {
        return 1;
    }

    for(int i = 0; i < 3; i++)
    {   
        total_resistance += res_array[i];

        if(resistance_matching(orig_resistance, total_resistance))
        {
            clear_array(i, res_array);
            count++;
            return count;
        } 
        else
        {
            count++;
        }
    }

    return count;
}
