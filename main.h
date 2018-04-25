#ifndef MAIN_H
#define MAIN_H

typedef enum {
				OK =0,
				ERROR_NULL_POINTER,
				ERROR_INVALID_DATA,
				ERROR_INVALID_RESISTOR_VALUES
			 }status_t;



typedef enum {
					OPTION_CALCULATE_C1 = 1,
					OPTION_CALCULATE_C2 = 2
			 }option_t;


#endif

#define MSG_ERROR_INVALID_OPTION "Se ha ingresado una opcion invalida."


status_t read_option(option_t * option);
status_t process_option_calculate_c1( void );
status_t process_option_calculate_c2( void );  

