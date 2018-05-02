





	#ifndef MAIN_H
	#define MAIN_H

	typedef enum {
					OK =0,
					ERROR_NULL_POINTER,
					ERROR_INVALID_DATA,
					ERROR_INVALID_RESISTOR_VALUES,


					ERROR_CALCULATE_SIMULATED_INDUCTANCE,
					ERROR_CALCULATE_CAPACITOR_VALUE
				 }status_t;



	typedef enum {
						OPTION_CALCULATE_C1 = 1,
						OPTION_CALCULATE_C2 = 2
				 }option_t;


	#endif

	#define LINE "************************************************************************"
	#define MSG_PRESENTATION "Programa para calcular variables para un ecualizador grafico."
	#define MSG_INDICATOR_OPTIONS "Ingrese la opcion de la magnitud que desea calcular:"
	#define MSG_OPTION_NUMBER_CALCULATE_C1 "1)"
	#define MSG_OPTION_NUMBER_CALCULATE_C2 "2)"
	#define MSG_OPTION_CALCULATE_C1 "Calcular capacitancia c1."
	#define MSG_OPTION_CALCULATE_C2 "Calcular capacitancia c2."

	#define MSG_ERROR_INVALID_OPTION "Se ha ingresado una opcion invalida."





