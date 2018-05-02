	







	/*  equalizer.c   */

	#include <stdio.h>
	#include "main.h"
	#include "equalizer.h"

	status_t calculate_capacitor_c1(double l, double r1, double r2, double * c1)
	{

		if( c1 == NULL )
			return ERROR_NULL_POINTER;

		if( r1 <= r2 )
			return ERROR_INVALID_RESISTOR_VALUES;

		*c1 = l / ((r1 - r2)*r2);

		return OK;
	}

	status_t calculate_simulated_inductance(double quality_factor, double r2, double f, double *l)
	{
		if( l == NULL )
			return ERROR_NULL_POINTER;

		*l = (quality_factor * r2) / ( 2 * PI * f);

		return OK;
	}

	status_t calculate_capacitor_c2(double l, double f, double * c2)
	{

		if( c2 == NULL )
			return ERROR_NULL_POINTER;

		*c2 = 1 / ((2 * PI * f)*(2 * PI * f)*l);

		return OK;
	}

