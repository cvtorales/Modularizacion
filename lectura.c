






	/****************************************************************************************/
	/*
	   En este progrma se presenta la funcion para lectura del valor del resistor 
	   en la que se utilizo la funcion scanf(). Tener en cuenta que se reutilizaron 
	   funciones y macros de otros modulos. El programa simplemente lee el dato y 
	   lo imprime.
	*/
	/****************************************************************************************/

	#include <stdio.h>
	#include <stdlib.h>
	#include "magnitudes.h"
	#include "magnitudes.c"
	#include "main.h"
	#include "common.h"

	status_t read_new_resistor_value(const char * msg, double * val, double min, double max);

	int main(void)
	{

		double r1;

		if(read_new_resistor_value(MSG_ENTER_R1_VALUE, &r1, MIN_RESISTANCE_VALUE, MAX_RESISTANCE_VALUE) != OK)	
		{
			fprintf(stderr, "%s\n", MSG_ERROR_INVALID_ENTER_RESISTOR_VALUE);
			return EXIT_FAILURE;
		}

		print_resistor_value( r1, MSG_R1_VALUE );
	
		return EXIT_SUCCESS;
	}


	status_t read_new_resistor_value(const char * msg, double * val, double min, double max)
	{
		char aux, c;
		double ingreso;

		if(msg == NULL || val == NULL)
			return ERROR_NULL_POINTER;
	
		printf("%s%s\n", msg, UNIT_RESISTANCE );

		aux = scanf("%lf", &ingreso);
		if(aux !=1 || aux == EOF)       
			return ERROR_INVALID_DATA;
	
		while ((c=getchar())!='\n' && c!=EOF)
		{
			if(c == ' ')
				return ERROR_INVALID_DATA;
		} 
			if(c==EOF)
				return ERROR_INVALID_DATA;

		*val = ingreso;

		if(*val < MIN_RESISTANCE_VALUE || *val > MAX_RESISTANCE_VALUE)
			return ERROR_INVALID_DATA;

		*val = (double) *val * MULTIPLIER_RESISTANCE;


		return OK; 
	}