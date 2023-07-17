/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file Van Dinh Tran 
 * @brief Simple C code performs some statistic annalytics on a data set(unsigned char array):
 * 	- Find Median
 * 	- Find Mean
 * 	- Find Maximum/Minimum
 * 	- Sort Array  
 *	
 * 
 * @author: Van Dinh Tran
 * @date: 15 June 2023
 *
 */


#include "stats.h"
#include "platform.h"
/* Size of the Data Set */
#define SIZE (40)

unsigned char test[SIZE] = {	34,	201,	190,	154,	8,	194,	2,	6,
                         	114,	88,	45,	76,	123,	87,	25,	23,
                              	200,	122,	150,	90,	92,	87,	177,	244,
                              	201,	6,	12, 	60,	8,	2,	5,	67,
                                7,	87,	250,	230,	99,	3,	100, 	90
				};



void print_statistic(unsigned char * ptr, unsigned int count){
#ifdef VERBOSE
	unsigned char median;
        unsigned char mean;
        unsigned char max;
        unsigned char min;

        median = find_median(ptr, count);
        PRINTF("The median is %d \n", median);

        mean = find_mean(ptr, count);
        PRINTF("The mean is %d \n", mean);

        max = find_maximum(ptr, count);
        PRINTF("The maximum is %d \n", max);

        min = find_minimum(ptr, count);
        PRINTF("The minimum is %d \n", min);

#endif
      	
}


void print_array(unsigned char * ptr, unsigned int count){
	unsigned int i;

	for(i = 0; i < count; i++){
		PRINTF("%d ", ptr[i]);
		//ptr++;
	}
}

void sort_array(unsigned char * ptr, unsigned int count){
	unsigned int i,j;
	unsigned char temp;
	for (i = 0 ; i < count; i++){
		for(j = i + 1; j < count; j++){
			if(ptr[i] < ptr[j]){
				temp = ptr[i];
				ptr[i] = ptr[j];
				ptr[j] = temp;
			}
		}
	}	

}

unsigned char find_median(unsigned char * ptr, unsigned int count){
	unsigned int i;
	unsigned char median;

	sort_array(ptr, count);
	if(count%2 == 0){
		median = (ptr[count/2] + ptr[count/2 - 1])/2;
	}
	else{
		median = ptr[count/2];
	}
       	
	return median;
}

unsigned char find_mean(unsigned char * ptr, unsigned int count){
	unsigned int i;
	unsigned int total = 0;
	unsigned char mean;
	if(ptr == NULL){
		return 0;
	}

	if(count <= 0){
		count = 1;
	}

	for(i = 0; i < count; i++){
		total = total + ptr[i];
	}
	mean = (total/count);
	return mean;	
}

unsigned char find_maximum(unsigned char * ptr, unsigned int count){
	unsigned int i;
	unsigned char max;

	max = ptr[0];
	for(i = 1; i < count; i++){
		if(max < ptr[i]){
			max = ptr[i];
		}
	}

	return max;

}

unsigned char find_minimum(unsigned char * ptr, unsigned int count){
        unsigned int i;
        unsigned char min;

        min = ptr[0];
        for(i = 1; i < count; i++){
                if(min > ptr[i]){
                        min = ptr[i];
                }
        }

        return min;

}
