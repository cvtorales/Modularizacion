	






	/*   equalizer.h   */


	#define PI 3.14
	#define MAX_QUALITY_FACTOR_VALUE 10
	#define MIN_QUALITY_FACTOR_VALUE 0.2

	/******************************** Prototypes *******************************************/
	status_t calculate_simulated_inductance(double quality_factor, double r2, double f, double *l);
	status_t calculate_capacitor_c1(double l, double r1, double r2, double * c1);
	status_t calculate_capacitor_c2(double l, double f, double * c2);
	/***************************************************************************************/