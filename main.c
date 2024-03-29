	






	#include <stdio.h>
	#include <stdlib.h>
	#include "main.h"
	#include "common.h"

	int main(void)
	{
		option_t option;

		print_main_menu();

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


