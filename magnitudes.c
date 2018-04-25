#include "main.h"

#define MAX_STR 20 
#define MULTIPLIER_RESISTANCE 1
#define MULTIPLIER_FREQUENCY 1
#define MIN_RESISTANCE_VALUE 100
#define MAX_RESISTANCE_VALUE 10000
#define MIN_FREQUENCY_VALUE 20
#define MAX_FREQUENCY_VALUE 20000
#define UNIT_RESISTANCE "Ohms"
#define UNIT_FREQUENCY "Hz"
#define MAX_QUALITY_FACTOR_VALUE 10
#define MIN_QUALITY_FACTOR_VALUE 1


/******************************** Prototypes *******************************************/

/**** Functions to read  ****/
status_t read_resistor_value(const char * msg, double * val, double min, double max);
status_t read_central_frequency(const char * msg, double * f, double min, double max);
status_t read_quality_factor(const char * msg, double * quality_factor, double min, double max);

/**** Functions to print ****/
status_t print_resistor_value(double r, const char * str );
status_t print_central_frequency_value(double f, const char * str );
status_t print_quality_factor_value(double quality_factor, const char * str );
status_t print_capacitor_value();

/***************************************************************************************/

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

	if( *val == 0 )
		return ERROR_INVALID_DATA;

	*val = *val * MULTIPLIER_RESISTANCE;

	if(*val < MIN_RESISTANCE_VALUE || *val > MAX_RESISTANCE_VALUE)
		return ERROR_INVALID_DATA;

	return OK; 
}

status_t print_resistor_value(double r, const char * str )
{
	printf("%s%f%s\n", str, r/1000, "kOhms");

	return OK;
}

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


status_t print_central_frequency_value(double f, const char * str )
{
	printf("%s%f%s\n", str, f, "Hz");
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

status_t print_quality_factor_value(double quality_factor, const char * str )
{
	printf("%s%f\n", str, quality_factor);	
	return OK;
}