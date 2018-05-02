	






	/*   equalizer.h   */


	#define PI 3.14

	/******************************** Prototypes *******************************************/
	status_t calculate_simulated_inductance(double *l, double quality_factor, double r2, double f);
	status_t calculate_capacitor_1(double * c1, double l, double r1, double r2);
	status_t calculate_capacitor_2(double * c2, double l, double f);
	/***************************************************************************************/