	








	/*    magnitudes.c   */

	#include <stdlib.h>
	#include <stdio.h>
	#include "main.h"
	#include "magnitudes.h"

	status_t read_central_frequency(const char * msg, double * f, double min, double max)
	{
		char str[MAX_STR];
		char * temp;

		if(msg == NULL || f == NULL)
			return ERROR_NULL_POINTER;

		printf("%s%s\n", msg, UNIT_FREQUENCY);

		if( fgets( str, MAX_STR, stdin) == NULL)
			return ERROR_INVALID_DATA;

		*f = strtod(str, &temp);
		if(*temp && *temp != '\n')
			return ERROR_INVALID_DATA;

		if( *f == 0 )
			return ERROR_INVALID_DATA;

		*f = *f * MULTIPLIER_FREQUENCY;

		if(*f < MIN_FREQUENCY_VALUE || *f > MAX_FREQUENCY_VALUE)
			return ERROR_INVALID_DATA;

		return OK;
	}

	status_t print_central_frequency(double f, const char * str )
	{
		printf("%s%.2f%s\n", str, f, UNIT_FREQUENCY);
		return OK;
	}

	status_t read_quality_factor(const char * msg, double * quality_factor, double min, double max)
	{

		char str[MAX_STR];
		char * temp;

		if(msg == NULL || quality_factor == NULL)
			return ERROR_NULL_POINTER;
	
		printf("%s\n", msg);

		if( fgets( str, MAX_STR, stdin) == NULL)
			return ERROR_INVALID_DATA;

		*quality_factor = strtod(str, &temp);
		if(*temp && *temp != '\n')
			return ERROR_INVALID_DATA;

		if( *quality_factor == 0 )
			return ERROR_INVALID_DATA;

		if(*quality_factor < MIN_QUALITY_FACTOR_VALUE || *quality_factor > MAX_QUALITY_FACTOR_VALUE)
			return ERROR_INVALID_DATA;

		return OK;
	}

	status_t print_quality_factor(double quality_factor, const char * str )
	{
		printf("%s%.2f\n", str, quality_factor);	
		return OK;
	}

