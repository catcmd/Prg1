/*******************************************************************
// Programm    : Primzahlen                                               
// Verfasser   : Schmidt                                             
// Datum       : Urprogramm: 13.11.2012                                           
// Aufgabe     : Primzahlberechnung nach Sieb des Eratosthenes
// Änderungen  : 13.11.2012
*******************************************************************/

#include <stdio.h>  /* Standard Input/Output  z.B. scanf, printf */
#include <stdlib.h>   /* Standard-Bibliothek, z.B. für system       */
#include "funktionen.h"
#define PRIM 1
#define nPRIM 0


int main () 
{
	//Variablen Def.

	unsigned int fill[OG - 1][2];
	int num = 2;

	strich(50,'-');
	printf("Sieb des Eratosthenes\n");
	strich(50,'-');

	//Initialisieren Array

	for (int counter = 0; counter < OG-1; counter++)
	{
		fill[counter][0] = num++;
		fill[counter][1] = PRIM;
	}


	printf("\nServus! \n");
	system("pause");
	return 0;
}