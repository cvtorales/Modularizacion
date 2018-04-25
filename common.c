#include "main.h"

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
	double r1, r2, freq, q;

	if(read_resistor_value("ingrese el valor r1", &r1, 100, 10000) != OK)	
	{
		fprintf(stderr, "%s\n", "No se ingreso una resistencia1 valida");
		return ERROR_INVALID_DATA;
	}
	if(read_resistor_value("ingrese el valor r2", &r2, 100, 10000) != OK)
	{
		fprintf(stderr, "%s\n", "No se ingreso una resistencia2 valida");
		return ERROR_INVALID_DATA;
	}
	if(read_central_frequency("ingrese la frec central", &freq, 20, 20000) != OK )
	{
		fprintf(stderr, "%s\n", "No se ingreso una frecuancia central valida");
		return ERROR_INVALID_DATA;
	}
	read_quality_factor("Ingrese el valor del factor de calidad:", &q, MIN_QUALITY_FACTOR_VALUE , MAX_QUALITY_FACTOR_VALUE);

	return OK;
}

status_t process_option_calculate_c2( void )
{
	double r2, freq, q;

	if(read_resistor_value("ingrese el valor r2", &r2, 100, 10000) != OK)
	{
		fprintf(stderr, "%s\n", "No se ingreso una resistencia2 valida");
		return ERROR_INVALID_DATA;
	}
	if(read_central_frequency("ingrese la frec central", &freq, 20, 20000) != OK )
	{
		fprintf(stderr, "%s\n", "No se ingreso una frecuancia central valida");
		return ERROR_INVALID_DATA;
	}
	read_quality_factor("Ingrese el valor del factor de calidad:", &q, MIN_QUALITY_FACTOR_VALUE , MAX_QUALITY_FACTOR_VALUE);

	return OK;
}