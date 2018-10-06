/*******************************************************************
// Programm    : Primzahlen                                               
// Verfasser   : Schmidt                                             
// Datum       : Urprogramm: 13.11.2012                                           
// Aufgabe     : Primzahlberechnung nach Sieb des Eratosthenes
// Änderungen  : 13.11.2012
*******************************************************************/

#include <stdio.h>  /* Standard Input/Output  z.B. scanf, printf */
#include "funktionen.h"


void strich (int n, char c) // gibt n mal das Zeichen c aus
{
	int i;
	for (i = 1; i <= n; i++)
		printf("%c", c);
	printf("\n");
}

void sieb(struct zahl_s *inputArray)
{
	//Variablen definition
	
	int wurzel;
	int rest;

	//Berechnung

	wurzel = sqrt(OG);

	/*Counter wird mit 0 init damit value array ab 0 hochgezählt wird in der spalte 0*/
	for (int counter = 0; counter <= wurzel; counter++)
	{
		/*Prüfen ob Zahl als Prim markiert ist*/
		if (inputArray[counter].istPrim == true)
		{
			/*mod aller zahlen bis wurzel, bis zur OG*/
			for (int index = counter + 1; index < (OG - 1); index++)
			{/*You shall test only when spalte = flagged as PRIM*/
				if (inputArray[index].istPrim == true)
				{
					rest = inputArray[index].wert % inputArray[counter].wert;
					/*flaggen aller zahlen die beim mod rechnen rest 0 haben*/
					if (rest == 0)
					{
						inputArray[index].istPrim = false;
					}
				}
			}
		}
	}
}

void ausgabe(struct zahl_s *inputArray)
{
	for (int counter = 0; counter < OG - 1; counter++)
	{
		if (inputArray[counter].istPrim == true)
		{
			printf("%i,", inputArray[counter].wert);
		}
	}
}