	






	/* common.c */
	
	#include "main.h"
	#include "common.h"


	status_t print_main_menu(void)
	{
		puts(LINE);
		puts(MSG_PRESENTATION);
		puts(MSG_INDICATOR_OPTIONS);
		printf("\n%s%s\n", MSG_OPTION_NUMBER_CALCULATE_C1, MSG_OPTION_CALCULATE_C1);
		printf("%s%s\n", MSG_OPTION_NUMBER_CALCULATE_C2, MSG_OPTION_CALCULATE_C2);
		puts(LINE);
		return OK;
	}


	status_t read_option(option_t * option)
	{
		char * temp; 
		char str[MAX_STR];

		if(fgets(str, MAX_STR, stdin) != NULL )
		{
			*option = strtoul(str, &temp, 10);
			if(*temp && *temp != '\n')
				return ERROR_INVALID_DATA;
		}
		return OK;
	}


	status_t process_option_calculate_c1( void )
	{
		double r1, r2, freq, q, l, c1;

		if(read_resistor_value(MSG_ENTER_R1_VALUE, &r1, MIN_RESISTANCE_VALUE, MAX_RESISTANCE_VALUE) != OK)	
		{
			fprintf(stderr, "%s\n", MSG_ERROR_INVALID_ENTER_RESISTOR_VALUE);
			return ERROR_INVALID_DATA;
		}
		if(read_resistor_value(MSG_ENTER_R2_VALUE, &r2, MIN_RESISTANCE_VALUE, MAX_RESISTANCE_VALUE) != OK)
		{
			fprintf(stderr, "%s\n", MSG_ERROR_INVALID_ENTER_RESISTOR_VALUE);
			return ERROR_INVALID_DATA;
		}
		if(read_central_frequency(MSG_ENTER_CENTRAL_FREQUENCY_VALUE, &freq, MIN_FREQUENCY_VALUE, MAX_FREQUENCY_VALUE) != OK )
		{
			fprintf(stderr, "%s\n", MSG_ERROR_INVALID_ENTER_CENTRAL_FREQUENCY_VALUE);
			return ERROR_INVALID_DATA;
		}
		if(read_quality_factor(MSG_ENTER_QUALITY_FACTOR_VALUE, &q, MIN_QUALITY_FACTOR_VALUE , MAX_QUALITY_FACTOR_VALUE) != OK)
		{
			fprintf(stderr, "%s\n", MSG_ERROR_INVALID_ENTER_QUALITY_FACTOR_VALUE);
			return ERROR_INVALID_DATA;
		}	



		if(calculate_simulated_inductance( &l, q, r2, freq) != OK)
		{
			fprintf(stderr, "%s\n", MSG_ERROR_CALCULATE_SIMULATED_INDUCTANCE);
			return ERROR_CALCULATE_SIMULATED_INDUCTANCE;
		}

		if(calculate_capacitor_1( &c1, l, r1, r2) != OK)
		{
			fprintf(stderr, "%s\n", MSG_ERROR_CALCULATE_CAPACITOR_VALUE);
			return ERROR_CALCULATE_CAPACITOR_VALUE;
		}


		     print_resistor_value( r1, MSG_R1_VALUE );
		     print_resistor_value( r2, MSG_R2_VALUE );
		     print_central_frequency_value( freq, MSG_CENTRAL_FREQUENCY_VALUE );
		     print_quality_factor_value( q, MSG_QUALITY_FACTOR_VALUE);
		     print_capacitor_value( c1, MSG_CAPACITANCE_C1_VALUE);



		return OK;
	}

	status_t process_option_calculate_c2( void )
	{
		double r2, freq, q, l, c2;

		if(read_resistor_value(MSG_ENTER_R2_VALUE, &r2, MIN_RESISTANCE_VALUE, MAX_RESISTANCE_VALUE) != OK)
		{
			fprintf(stderr, "%s\n", MSG_ERROR_INVALID_ENTER_RESISTOR_VALUE);
			return ERROR_INVALID_DATA;
		}
		if(read_central_frequency(MSG_ENTER_CENTRAL_FREQUENCY_VALUE, &freq, MIN_FREQUENCY_VALUE, MAX_FREQUENCY_VALUE) != OK )
		{
			fprintf(stderr, "%s\n", MSG_ERROR_INVALID_ENTER_CENTRAL_FREQUENCY_VALUE);
			return ERROR_INVALID_DATA;
		}
		if(read_quality_factor(MSG_ENTER_QUALITY_FACTOR_VALUE, &q, MIN_QUALITY_FACTOR_VALUE , MAX_QUALITY_FACTOR_VALUE) != OK)
		{
			fprintf(stderr, "%s\n", MSG_ERROR_INVALID_ENTER_QUALITY_FACTOR_VALUE);
			return ERROR_INVALID_DATA;
		}	

		if(calculate_simulated_inductance( &l, q, r2, freq) != OK)
		{
			fprintf(stderr, "%s\n", MSG_ERROR_CALCULATE_SIMULATED_INDUCTANCE);
			return ERROR_CALCULATE_SIMULATED_INDUCTANCE;
		}

		if(calculate_capacitor_2( &c2, l, freq) != OK )
		{
			fprintf(stderr, "%s\n", MSG_ERROR_CALCULATE_CAPACITOR_VALUE);
			return ERROR_CALCULATE_CAPACITOR_VALUE;
		}


	     print_resistor_value( r2, MSG_R2_VALUE );
	     print_central_frequency_value( freq, MSG_CENTRAL_FREQUENCY_VALUE);
	     print_quality_factor_value( q, MSG_QUALITY_FACTOR_VALUE);
	     print_capacitor_value( c2, MSG_CAPACITANCE_C2_VALUE);

		return OK;
	}