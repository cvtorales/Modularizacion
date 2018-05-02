


	
	/* magnitudes.h */

	#include "main.h"
	#include "components.h"
	#include "equalizer.h"


	#define MIN_FREQUENCY_VALUE 20
	#define MAX_FREQUENCY_VALUE 20000
	#define MULTIPLIER_FREQUENCY 1
	#define UNIT_FREQUENCY " Hz."




	/******************************** Prototypes *******************************************/

	/**** Functions to read  ****/
	status_t read_central_frequency(const char * msg, double * f, double min, double max);
	status_t read_quality_factor(const char * msg, double * quality_factor, double min, double max);

	/**** Functions to print ****/
	status_t print_central_frequency(double f, const char * str );
	status_t print_quality_factor(double quality_factor, const char * str );

	/***************************************************************************************/
