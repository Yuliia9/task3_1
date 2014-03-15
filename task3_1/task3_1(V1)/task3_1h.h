#ifndef TASK3_1_H_
#define TASK3_1_H_
/*
*@file		task3_1.h
*@brief		header file that defines prototypes of functions used in file task3_1.cpp
*/

#include "stdafx.h"


/**
* @brief				This function displays general information about program to users
* @param	void
* @return	void
*/
void Interface(void);


/*
* @brief					Function for inputing string
* @param	[in/out]		char** riadok - a pointer to null pointer to string for sentences
*						
*@return	unsigned char	Return ERROR if error occurs while trying to allocate memory for string
							Return SUCCESS if string was inputed
*/
unsigned char Input(char** riad);



/*
* @brief				Function estimates the longest word in sequence of sentences
* @param	[in]		char* riadok - a pointer to inputed sequence of sentences
			[in/out]	char** word - a pointer to pointer to longest word in sentences
*						

*/
unsigned int Get_longest_word(char* riadok, char** word);


#endif

