/*******************************************************************
/ Programm    : Datentypen                                          
/ Verfasser   : Schmidt                                           
/ Datum       : Urprogramm: 17.10.2012                                          
/ Eingabe     : Vier Zeichen                            
/ Verarbeitung: diverse Berechnungen                   
/ Änderungen  : 17.10.2012
/*******************************************************************/

/* Einbinden von nötigen Header-Dateien                               */
#include <stdio.h>    /* Standard Input/ Output  z.B. scanf, printf */
#include <stdlib.h>   /* Standard-Bibliothek, z.B. für system */
#include "mainfile.h"
#include <limits.h> /* For INT_MAX */
#include <string.h>

char kleinstesZeichen(char c1, char c2, char c3, char c4);
char groesstesZeichen(char c1, char c2, char c3, char c4);

int main()
{
	char c1, c2, c3, c4, mit;
		

	strich(50, '-');
	printf("Bitte geben Sie vier einzelne Zeichen ein: ");
	scanf("%c %c %c %c", &c1, &c2, &c3, &c4);

		mit = (c1 + c2 + c3 + c4) / 4;
	
	float c1fl = c1;
	
	float mitfl = (c1fl + c2 + c3 + c4) / 4;

	strich(50, '*');

	printf("Es wurde folgt Eingegeben : %c %c %c %c\n", c1, c2, c3, c4);
	
	strich(50, '*');

	printf("ASCII-Code: %d %d %d %d\n", c1, c2, c3, c4);
	printf("ASCII int Mittelwert ist d: %d\n", mit);
	printf("ASCII int Mittelwert mit c: %x\n", mit);
	printf("ASCII float Mittelwert d: %f\n", mitfl);
	printf("ASCII Mittlereszeichen : %c\n", mit);
	printf("Kleinstes Zeichen ist: %c\n", kleinstesZeichen(c1, c2, c3, c4));//Funktion wird mit folgenden Zeichen aufgerufen
	printf("Groestes Zeichen ist: %c\n", groesstesZeichen(c1, c2, c3, c4));

	strich(50, '-');

	system("pause");
	return(0);
}


char kleinstesZeichen(char c1, char c2, char c3, char c4)//Char Zeichen werden von extern Eingegeben
{
	char min;

	char Zeichensatz[4] = { c1, c2, c3, c4 }; //Chars werden auf einen Char String geschmissen
	//hello
	min = Zeichensatz[0];

	for (int counter = 1; counter < sizeof(Zeichensatz); counter++) /*Durch inkludieren der #include <string.h> 
																	kann nun size of oder strlen() zugegegriffen werden
																	es wird der counter solang ab gezähl wie die länge des 
																	Zeichensatz sizeof()*/
	{
		if (Zeichensatz[counter] < min)//Zeichensatz wird copared und min überschrieben mit dem jew kleinsten
		{
			min = Zeichensatz[counter];
		}
	}

			return min; //min wird nun an die funktion oben returned
	/*
	min = c1;

	if (c1 >= c2)
	{
		min = c2;
	}
	
	if (min >= c3)
	{
		min = c3;
	}
	
	if (min >= c4)
	{
		min = c4;
	}*/

}

char groesstesZeichen(char c1, char c2, char c3, char c4)
{
	char max;

	char Zeichensatz[4] = { c1, c2, c3, c4 };

	max = Zeichensatz[0];
	
	for (int counter = 1; counter < sizeof(Zeichensatz); counter++)
	{
		if (Zeichensatz[counter] > max)
		{
			max = Zeichensatz[counter];
		}
	}

	return max;
}

void strich(int n, char c)
{
	for (int i = 1; i <= n; i++)
	{
		printf("%c", c);	
	}
	printf("\n");
}
