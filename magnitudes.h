


	
	/* magnitudes.h */

	#include "main.h"

	#define MAX_STR 20 
	#define MULTIPLIER_RESISTANCE 1E3
	#define MULTIPLIER_FREQUENCY 1
	#define MULTIPLER_CAPACITANCE 1E-9
	#define MIN_RESISTANCE_VALUE 0.1     
	#define MAX_RESISTANCE_VALUE 1000
	#define MIN_FREQUENCY_VALUE 20
	#define MAX_FREQUENCY_VALUE 20000
	#define UNIT_RESISTANCE " KOhms."
	#define UNIT_FREQUENCY " Hz."
	#define UNIT_CAPACITANCE " nF."
	#define MAX_QUALITY_FACTOR_VALUE 10
	#define MIN_QUALITY_FACTOR_VALUE 0.2


	/******************************** Prototypes *******************************************/

	/**** Functions to read  ****/
	status_t read_resistor_value(const char * msg, double * val, double min, double max);
	status_t read_central_frequency(const char * msg, double * f, double min, double max);
	status_t read_quality_factor(const char * msg, double * quality_factor, double min, double max);

	/**** Functions to print ****/
	status_t print_resistor_value(double r, const char * str );
	status_t print_central_frequency_value(double f, const char * str );
	status_t print_quality_factor_value(double quality_factor, const char * str );
	status_t print_capacitor_value(double c, const char * str );

	/***************************************************************************************/
