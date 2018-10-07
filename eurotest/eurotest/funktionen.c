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
	t_errcode error = ec_ok; // wenn kein error code ausgelöst wird wird ec_ok returned
	int querS, prufZ;

	querS = quersumme(inputArray);
	prufZ = prufziffer(querS, inputArray[11]);

	//um alle bedingungen durch zuführen muss if statt else if
	if (prufZ != inputArray[11])
	{
		error = ec_pz_falsch;
	}
	if (strlen(inputArray) < 12)
	{
		error = ec_zukurz;
	}
	if (strlen(inputArray) > 12)
	{
		error = ec_zulang;
	}
	if (inputArray[0] < 65 || inputArray[0] > 90)
	{
		error = ec_LCfalsch;
	}
	if (inputArray[11] < 48 || inputArray[11] > 57)
	{
		error = ec_SNkeineZiffer;
	}	

	return error;
}

//Case switch für fehler ausgabe der euro function
void fehlerAusgabe(t_errcode knoblauch)
{
	switch (knoblauch)
	{
	case ec_ok:
		printf("Seriennummer gueltisch!\n");
		break;
	case ec_pz_falsch:
		printf("Pruefziffer falsch!\n");
		break;
	case ec_zukurz:
		printf("Seriennummer zu kurz!\n");
		break;
	case ec_zulang:
		printf("Seriennummer zu lang!\n");
		break;
	case ec_LCfalsch:
		printf("Laendercode ist kein Grossbuchstabe!\n");
		break;
	case ec_SNkeineZiffer:
		printf("10-Stellieg Seriennummer oder Pruefziffer enthaelt Zeichen, die nicht Ziffern sind!\n");
		break;
	default:
		printf("Unbekannte Eingabe!\n");
	}

	return 0;	
}
