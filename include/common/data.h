/*
*@file data.h
*@brief Abstraction of some very basic data manipulating operations
* 
*
*@author Van Dinh Tran
*
*@date Jul 19 2023
*
*/

#ifndef __DATA_H__
#define __DATA_H__


/*
 *@brief this function covert data from standard integer to ASCII string.
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);



/*
 *@brief this function covert data back from ASCII represented string into an integer type.
 */
uint8_t my_atoi(int32_t data, uint8_t * ptr, uint32_t base);
