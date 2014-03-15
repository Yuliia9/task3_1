/*
* @file			task3_1.cpp
* @brief		Program finds the longest word in inputed sentences and shows it's length

* Copyright 2014 by Yuliia Lyubchik Inc.,
*
* This software is the confidential and proprietary information
* of Yuliia Lyubchik. ("Confidential Information").  You
* shall not disclose such Confidential Information and shall use
* it only with permission from Yuliia.
*
*/



#include "stdafx.h"
#include "task3_1h.h" /*defines prototypes of used in this file functions*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


const unsigned char ERROR = 0;
const unsigned char SUCCESS = 1;
const unsigned int MAIN_SUCCESS = 0;




int main()
{
	Interface();

	char* riadok = NULL;
	unsigned char retCode;
	char* word = NULL;
	unsigned int max_len = 0;
	
	retCode = Input(&riadok);

	if (retCode == ERROR)
	{
		printf("Error occurs while trying to input string.\n");
		free(riadok);
		return (int) ERROR;
	}

	max_len = Get_longest_word(riadok, &word);
	if (max_len == (int) ERROR)
	{
		printf("Error occurs while trying to estimate the longest word. \n");
		free(riadok);
		return (int)ERROR;
	}
	printf("The longest word is: %s", word);


	free(riadok);
	system("pause");
	return MAIN_SUCCESS;
}



void Interface(void)
{
	printf("------------------------------------------------------------------\n");
	printf("Hi! Welcome to the genius word finder.\n ");
	printf(" Enter sentences and program will find for you the longest word.\n\n ");
	printf("Program made by Yuliia Lyubchik.\n");
	printf("------------------------------------------------------------------\n\n");
}



unsigned char Input(char** riad)
{
	do 
	{
		char temp;
		int count = 0;
		printf("Please enter sentence: ");
		do
		{
			scanf("%c", &temp);
			++count;
			*riad = (char*) realloc (*riad, count * sizeof(char));
			if (*riad != NULL) {
				
				*(*riad + count - 1) = temp;
			}
			else 
			{
				free(riad);
				puts("Error (re)allocating memory. \n");
				return ERROR;
			}

		} 
		while (temp != '\n' && temp != EOF);
		*(*riad + count - 1) = '\0';
	} 
	while (riad == NULL || strlen(*riad) == 0);
	
	return SUCCESS;
}



unsigned int Get_longest_word(char* riadok,char** word)
{
	if ( riadok == NULL )
	{
		printf("Error, can't get access to string. \n"); 
		return (int) ERROR;
	}

	char* temp;
	unsigned int len, maxl = 0;
	char* max;
	char delimiters[] = { ' ', ',', '-', '.', ':', ';', '(', ')', '[', ']', '!', '?' };

	temp = strtok(riadok, delimiters);
	while (temp != NULL)
	{
		len = strlen(temp);
		if (len > maxl)
		{
			*word = temp;
			maxl = len;
		}
		temp = strtok(NULL, delimiters);
	}
	return maxl;
}