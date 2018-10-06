/*******************************************************************
// Programm    : Primzahlen                                               
// Verfasser   : Schmidt                                             
// Datum       : Urprogramm: 13.11.2012                                           
// Aufgabe     : Primzahlberechnung nach Sieb des Eratosthenes
// Änderungen  : 13.11.2012
*******************************************************************/

#include <stdio.h>  /* Standard Input/Output  z.B. scanf, printf */
#include <stdlib.h>   /* Standard-Bibliothek, z.B. für system       */
#include <math.h>
#include "funktionen.h"



int main () 
{
	//Variablen declaration 
	//Variablen Def.

	struct zahl_s zahlen[OG - 1]; //array an zahlen allocieren der speicher größe
	int num = 2;

	strich(50,'-');
	printf("Sieb des Eratosthenes\n");
	strich(50,'-');

	//Initialisieren Array

	for (int counter = 0; counter < OG-1; counter++)
	{
		zahlen[counter].wert = num++;
		zahlen[counter].istPrim = true;
	}

	//Init von sieb mit übergabe des Pointers des array zahlen
	sieb(zahlen);

	ausgabe(zahlen); //Init ausgabe mit array zahlen


	printf("\nServus! \n");
	system("pause");
	return 0;
}