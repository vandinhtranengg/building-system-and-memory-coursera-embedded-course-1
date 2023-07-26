/**
 * @file data.c
 * This file do some very basic data manipulation
 *
 * @author Van Dinh Tran
 * @date Jul 24, 2023
 */

#include "data.h"
#include "memory.h"
#include "platform.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
	uint8_t i = 0;
   	int8_t sign = 0;
	uint8_t digit;

	if ( data < 0) { 
		sign = -1;	// record sign
		data = -data; // make data positive
	}

	do {
		  	// generate digits in reverse order
		
		digit = data % base;
		if(digit < 10)
			*(ptr + i++) = digit + '0';
		else // base 16 case: A,B,C,D,E,F
			*(ptr + i++) = digit + 'A' - 10;
		
		switch(base){
			case BASE_2:
				data = data >> 1;
			break;
			
			case BASE_8:
				data = data >> 3;
			break;
			
			case BASE_16:
				data = data >> 4;
			break;
			
			case BASE_10:
				data = data/10;
			break;

			default:
			PRINTF("Unknown BASE\n");
			return 0;
		}

	} while (data > 0 ); 


	if(sign < 0)
		*(ptr + i++) = '-';

	ptr = my_reverse(ptr, (size_t) i);
	*(ptr + i) = '\0';
	return i + 1;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
	uint8_t i;
	int32_t convert_int = 0;
	uint8_t ch;
	int8_t sign;

	ch = *(ptr);
	if(ch == '-'){
		i = 2;
		sign = -1;
		convert_int = (*(ptr + 1) < 'A') ? (*(ptr + 1) - '0') : (*(ptr + 1) - 'A' + 10);
	}else {
		i = 1;
		sign = 1;
		convert_int = (ch < 'A') ? (ch - '0') : (ch - 'A' + 10);
	}
	
	for(;i < digits - 1; i++){
		ch = *(ptr + i);
		if(ch < 'A'){
			convert_int = convert_int*base + (ch - '0');
		}	
		else{ // BASE_16 case
			convert_int = convert_int*base + (ch - 'A' + 10);
		}
	}
	
	return sign*convert_int;
}
