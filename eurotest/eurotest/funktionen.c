/*******************************************************************
// Programm    : Eurotest                                               
// Verfasser   : Schmidt                                             
// Datum       : Urprogramm: 21.11.2012                                           
// Aufgabe     : Prüfung von Euro-Banknoten Seriennummern
// Änderungen  : 21.11.2012
*******************************************************************/

#include <stdio.h>  /* Standard Input/Output  z.B. scanf, printf */
#include <string.h>

#include "funktionen.h"



void strich (int n, char c) // gibt n mal das Zeichen c aus
{
	int i;
	for (i = 1; i <= n; i++)
		printf("%c", c);
	printf("\n");
}

unsigned int einlesen(char *inputArray)
{
	char inputBuffer[500];

	printf("Bitte geben sie die Banknoten Nummer ein: \n");
	scanf("%s", &inputBuffer);//copy into tmp Buffer so memory isn't killed

	if (strlen(inputBuffer) == strlen(inputArray))
	{
		//if strlen inputBuffer has the same length as inputArray 
		//		destination, source
		strcpy(inputArray, inputBuffer);
	}
	
}

unsigned int quersumme(char *inputArray)
{

}

