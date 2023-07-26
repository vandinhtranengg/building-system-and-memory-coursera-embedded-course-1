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
 * @file stats.h 
 * @brief header file for declarations and documentation of the functions from the stats.c file
 *
 * <Add Extended Description Here>
 *
 * @author Van Dinh Tran
 * @date 14 June 2023
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

#include <stddef.h>
#include "platform.h"


/* Add Your Declarations and Function Comments here */ 

/*************************************************
 * Function: print_statistic 
 *
 * Description:
 * 	This function prints the statistic of an array including minimum, maximum, mean, and median.
 *
 * Parameters:
 * 	unsigned char * ptr: 	Poiter to a data set
 * 	unsigned int 	count: 	Number of items in data set
 *
 * Return:
 * 	none
 *
 * 
 ************************************************/
void print_statistic(unsigned char * ptr, unsigned int count);


/*************************************************
 * Function: print_array
 *
 * Description:
 *	 This function prints the array to the screen.
 *
 * Parameters:
 *      unsigned char * ptr: Poiter to a data set
 *      unsigned int count: Number of items in data set
 *
 * Return:
 *      none
 *
 *
 ************************************************/
void print_array(unsigned char * ptr, unsigned int count);


/*************************************************
 * Function: find_median
 *
 * Description:
 *       This function takes unsigned char array and performs finding its median. 
 *
 * Parameters:
 *      unsigned char * ptr:	Poiter to a data set
 *      unsigned int count:	Number of items in data set
 *
 * Return:
 *      unsigned char median:	Median of the data set provided.
 ************************************************/
unsigned char find_median(unsigned char * ptr, unsigned int count);


/*************************************************
 * Function: find_mean
 *
 * Description:
 *       This function takes unsigned char array and performs finding its mean.
 *
 * Parameters:
 *      unsigned char * ptr: 	Poiter to a data set
 *      unsigned int 	count: 	Number of items in data set
 *
 * Return:
 *      unsigned char mean: 	Mean of the data set provided.
 ************************************************/
unsigned char find_mean(unsigned char * ptr, unsigned int count);
	


/*************************************************
 * Function: find_maximum
 *
 * Description:
 *       This function takes unsigned char array and performs finding the maximum item.
 *
 * Parameters:
 *      unsigned char * ptr:	Poiter to a data set
 *      unsigned int count:	Number of items in data set
 *
 * Return:
 *	unsigned char max:	Maximum value of the data set provided.
 ************************************************/
unsigned char find_maximum(unsigned char * ptr, unsigned int count);


/*************************************************
 * Function: find_minimum
 *
 * Description:
 *       This function takes unsigned char array and performs finding the minimum item.
 *
 * Parameters:
 *      unsigned char * ptr: 	Poiter to a data set
 *      unsigned int count: 	Number of items in data set
 *
 * Return:
 *      unsigned char min:	Minimum value of the data set provided.
 ************************************************/
unsigned char find_minimum(unsigned char * ptr, unsigned int count);


/*************************************************
 * Function:  sort_array
 *
 * Description:
 *       This function takes unsigned char array and sorts it from largest to smallest.
 *
 * Parameters:
 *      unsigned char * ptr:    Poiter to a data set
 *      unsigned int count:     Number of items in data set
 *
 * Return:
 *	sorted array from largest to smallest
 ************************************************/
void sort_array(unsigned char * ptr, unsigned int count);


#endif /* __STATS_H__ */
