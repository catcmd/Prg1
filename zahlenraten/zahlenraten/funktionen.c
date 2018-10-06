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

void zahlenraten(int MaxZahl)
{
	//Randome variable
	srand((unsigned int)time(NULL));/*Gibt randome zahlen aus time(NULL) weil sonst aktuellen startwert*/
	unsigned int random;
	char antwort = "n";
	
	/*Die while funktion sorgt dafür das die rate funktion noch mal aufgerufen wird undman sich
			  zwischen spiel und neu spiel nochmal entscheiden kann*/
	while(1)
	{
		random = rand() % MaxZahl;
		rate(random);
		printf("Noch mal spielen? (j/n): \n");
		scanf("%c", &antwort);

		system("pause");
		
		if (antwort == 'n' || antwort == 'N')
		{
			printf("Servus!");
		}
	} 
}

void rate(int compZahl)
{
	//Variablen Deklaration
	//eingelesene unsigned int Zahl damit keine neg. eingabe
	char antwort = 0;
	unsigned int eingabe;

	printf("Ich habe mir eine Zahl zwischen 1 und 100 ausgedacht. Welche ist es?\n");
	
	while(1) //Die while schleife mit 1 aka true sorgt für eine konstante wiederholung der if und scanf's
	{
		scanf("%i", &eingabe);

		if (eingabe > compZahl)
		{
			printf("Die Zahl ist zu gross!\n");
		}
		else if (eingabe < compZahl)
		{
			printf("Die Zahl ist zu klein!\n");
		}
		else
		{
			printf("Richtig!\n");
			break;//mit dem break gehen wir aus der while schleife raus
		}
	} 
}