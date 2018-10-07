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

	//if strlen inputBuffer has the same length as inputArray 
	//		destination, source, number of characters to be copied
	strncpy(inputArray, inputBuffer, 12);
	
}

unsigned int quersumme(char *inputArray)
{
	int sum = (int)inputArray[0];

	for (int counter = 1; counter < strlen(inputArray); counter++)
	{
		sum = (inputArray[counter] - 48) + sum;
	}

	return sum;
}

unsigned int prufziffer(int quersumme, int zuPruef)
{
	int prufNr = 0;

	prufNr = (quersumme - zuPruef) % 9;
	if (prufNr != 0)
	{
		prufNr = 9 - prufNr;
	}

	return prufNr;
}

t_errcode eurotest(char *inputArray)
{
	t_errcode error;
	int querS, prufZ;

	querS = quersumme(inputArray);
	prufZ = prufziffer(querS, inputArray[11]);

	
	if (prufZ != inputArray[11])
	{
		error = ec_pz_falsch;
	}
	else if (strlen(inputArray) < 12)
	{
		error = ec_zukurz;
	}
	else if (strlen(inputArray) > 12)
	{
		error = ec_zulang;
	}
	else if (inputArray[0] < 65 || inputArray[0] > 90)
	{
		error = ec_LCfalsch;
	}
	else if (inputArray[11] < 48 || inputArray[11] > 57)
	{
		error = ec_SNkeineZiffer;
	}
	else
	{
		error = ec_ok;
	}
	

	return error;
}
