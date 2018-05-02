	#include "main.h"

	#define MAX_STR 20 
	#define MULTIPLIER_RESISTANCE 1E3
	#define MULTIPLER_CAPACITANCE 1E-9
	#define MIN_RESISTANCE_VALUE 0.1     
	#define MAX_RESISTANCE_VALUE 1000
	#define UNIT_RESISTANCE " KOhms."
	#define UNIT_CAPACITANCE " nF."


	/******************************** Prototypes *******************************************/

	/**** Functions to read  ****/
	status_t read_resistor_value(const char * msg, double * val, double min, double max);



		/**** Functions to print ****/
	status_t print_resistor(double r, const char * str );
	status_t print_capacitor(double c, const char * str );

	/***************************************************************************************/