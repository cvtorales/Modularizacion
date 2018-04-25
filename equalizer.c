#include "main.h"

#define PI 3.14

/******************************** Prototypes *******************************************/
status_t calculate_simulated_inductance(double *l, double quality_factor, double r2, double f);
status_t calculate_capacitor_1(double * c1, double l, double r1, double r2);
status_t calculate_capacitor_2(double * c2, double l, double f);
/***************************************************************************************/

status_t calculate_capacitor_1(double * c1, double l, double r1, double r2)
{

	if( c1 == NULL )
		return ERROR_NULL_POINTER;

	if( r1 <= r2 )
		return ERROR_INVALID_RESISTOR_VALUES;

	*c1 = l / ((r1 - r2)*r2);

	return OK;
}

status_t calculate_simulated_inductance(double *l, double quality_factor, double r2, double f)
{
	if( l == NULL )
		return ERROR_NULL_POINTER;

	*l = (quality_factor * r2) / ( 2 * PI * f);

	return OK;
}

status_t calculate_capacitor_2(double * c2, double l, double f)
{

	if( c2 == NULL )
		return ERROR_NULL_POINTER;

	*c2 = 1 / ((2 * PI * f)*(2 * PI * f)*l);

	return OK;
}

