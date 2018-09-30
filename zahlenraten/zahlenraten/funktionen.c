/*******************************************************************
// Programm    : Zahlenraten / Funktionen                                               
// Verfasser   : Schmidt                                             
// Datum       : Urprogramm: 7.11.2012                                           
// Aufgabe     : Benutzer muss Zahl zwischen 1 und 100 erraten
// Änderungen  : 7.11.2012
*******************************************************************/
#include <stdio.h>  /* Standard Input/Output  z.B. scanf, printf */
#include "funktionen.h"

/* globale Konstanten für boolesche Ausdrücke */
const int FALSE = 0;
const int TRUE = 1;


void strich (int n, char c) // gibt n mal das Zeichen c aus
{
	int i;
	for (i=1; i<=n; i++)
		printf("%c", c);
	printf("\n");
}

