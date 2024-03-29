#include <stdio.h>
#include <stdlib.h>
#include "components.h"
#include "main.h"
#include "common.h"

	status_t read_resistor_value(const char * msg, double * val, double min, double max)
	{
		char str[MAX_STR];
		char * temp;

		if(msg == NULL || val == NULL)
			return ERROR_NULL_POINTER;
	
		printf("%s%s\n", msg, UNIT_RESISTANCE );

		if( fgets( str, MAX_STR, stdin) == NULL)
			return ERROR_INVALID_DATA;

		*val = strtod(str, &temp);
		if(*temp && *temp != '\n')
			return ERROR_INVALID_DATA;

		*val = (double) *val * MULTIPLIER_RESISTANCE;

		if(*val < MIN_RESISTANCE_VALUE || *val > MAX_RESISTANCE_VALUE)
			return ERROR_INVALID_DATA;

		return OK; 
	}

	status_t print_resistor(double r, const char * str )
	{
		printf("%s%.2f%s\n", str, r/MULTIPLIER_RESISTANCE, UNIT_RESISTANCE);

		return OK;
	}

	status_t print_capacitor(double c, const char * str )
	{
		printf("%s%.2f%s\n", str, c/MULTIPLER_CAPACITANCE, UNIT_CAPACITANCE);
		return OK;
	}