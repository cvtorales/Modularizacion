#include <stdio.h>
#include <stdlib.h>
#include "magnitudes.c"
#include "main.h"
#include "equalizer.c"
#include "common.c"

int main(void)
{
	option_t option;

	if(read_option(&option)!= OK)
	{
		fprintf(stderr, "%s\n", MSG_ERROR_INVALID_OPTION );
		return EXIT_FAILURE;
	}

	switch(option)
	{

		case OPTION_CALCULATE_C1:
			if(process_option_calculate_c1() != OK)
				return EXIT_FAILURE;
			break;

		case OPTION_CALCULATE_C2:
			if(process_option_calculate_c2() != OK)
				return EXIT_FAILURE;
			break;		

		default:
			fprintf(stderr, "%s\n", MSG_ERROR_INVALID_OPTION);
				return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}


