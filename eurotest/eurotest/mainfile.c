/*******************************************************************
// Programm    : Eurotest                                               
// Verfasser   : Schmidt                                             
// Datum       : Urprogramm: 21.11.2012                                           
// Aufgabe     : Prüfung von Euro-Banknoten Seriennummern
// Änderungen  : 21.11.2012
*******************************************************************/

#include <stdio.h>  /* Standard Input/Output  z.B. scanf, printf */
#include <stdlib.h>   /* Standard-Bibliothek, z.B. für system       */
#include "funktionen.h"


int main () 
{
	//Variablen Def
	char banknotenr[12];

	strich(50,'-');
	printf("Eurotest\n");
	strich(50,'-');

	/**********************************************************/
	/*	test quersumme ()									  */
	/**********************************************************/
	int test1, test2;

	//snprintf writes on a string with a cap of n or in this case sizeof(example)
	snprintf(banknotenr, sizeof(banknotenr), "P02571225193");
	test1 = quersumme(banknotenr);
	if (test1 == 114)
	{
		printf("Test 1: Correct!\n");
	}
	else
	{
		printf("Test 1: Test Failed! Output: %d\n", test1);
	}

	snprintf(banknotenr, sizeof(banknotenr), "D4328645732");
	test2 = quersumme(banknotenr);
	if (test2 == 112)
	{
		printf("Test 2: Correct!\n");
	}
	else
	{
		printf("Test 2: Test Failed! Output: %d\n", test2);
	}


	//einlesen(banknotenr);
	printf("\nServus! \n");
	system("pause");
	return 0;
}