




	/* common.h */
	#include "magnitudes.h"

	/******************* MENSAJES PARA INGRESO DE DATOS ******************/
	#define MSG_ENTER_R1_VALUE "Ingrese el valor resistencia 1 en "
	#define MSG_ENTER_R2_VALUE "Ingrese el valor resistencia 2 en "
	#define MSG_ENTER_CENTRAL_FREQUENCY_VALUE "Ingrese el valor de la frecuencia central en "
	#define MSG_ENTER_QUALITY_FACTOR_VALUE "Ingrese el valor del factor de calidad "
	/*********************************************************************/
	/************************* MENSAJES DE ERROR *************************/
	#define MSG_ERROR_INVALID_ENTER_RESISTOR_VALUE "No se ha ingresado una resistencia valida."
	#define MSG_ERROR_INVALID_ENTER_CENTRAL_FREQUENCY_VALUE "No se ha ingresado una frecuencia central valida."
	#define MSG_ERROR_INVALID_ENTER_QUALITY_FACTOR_VALUE "No se ha ingresado un factor de calidad valido."
	/*********************************************************************/
	/*************** MENSAJES DE IMPRESION DE VALORES *******************/
	#define MSG_R1_VALUE "El valor de la resistencia 1 es: "
	#define MSG_R2_VALUE "El valor de la resistencia 2 es: " 
	#define MSG_CENTRAL_FREQUENCY_VALUE "El valor de la frecuencia central es: "
	#define MSG_QUALITY_FACTOR_VALUE "El valor del factor de calidad es: "
	#define MSG_CAPACITANCE_C1_VALUE "El valor de la capacitancia 1 calculada es: "
	#define MSG_CAPACITANCE_C2_VALUE "El valor de la capacitancia 2 calculada es: "


	#define MSG_ERROR_CALCULATE_SIMULATED_INDUCTANCE "Se ingresaron datos invalidos, no se puede hacer el calculo."
	#define MSG_ERROR_CALCULATE_CAPACITOR_VALUE "No se puede calcular la capacitancia, se ingresaron datos invalidos."

	/*********************************************************************/

	status_t print_main_menu(void);
	status_t read_option(option_t * option);
	status_t process_option_calculate_c1( void );
	status_t process_option_calculate_c2( void );  