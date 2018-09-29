/*******************************************************************
// Programm    : exp1                                                
// Verfasser   : Feindor/Schmidt                                             
// Datum       : Urprogramm: 1.10.1996                                           
// Eingabe     : obere und untere Grenzen                            
// Verarbeitung: Berechnung von Funktionen, Z�hlen, Summieren        
// Ausgabe     : Zahlentabellen                                      
// �nderungen  : 30.10.2012
*******************************************************************/

#include <stdio.h>  /* Standard Input/Output  z.B. scanf, printf */
#include <math.h>   /* Standard-Bibliothek f�r math. Funktionen  z.B. sqrt */
#include <stdlib.h>   /* Standard-Bibliothek, z.B. f�r system       */
#include "exp.h"


int main () 
{
	strich(50,'-');
	printf ("Exp: Berechnung von einfachen Funktionen\n");
	strich(50,'-');

	int bis = obergrenzeEinlesen();
	strich(50, '-');

	tabelleAusgaben(bis);

	
	printf("Servus! \n");
	system("pause");
	return 0;
}

int tabelleAusgaben(unsigned int bis)
{
	int i;
	double e = 1;// ist nicht 0 weil fak !/0! = 1 + 1/1 = 1 + 1/2!... 2x die 1 also!

	strich(50, '-');

	printf("i\t1/i\t\tSumme(1/i)\ti!\t\t1/i!\t\tNaeherung an e\n");

	for (i = 1; i <= bis; i = i + 1)
	{
		e += (double)1 / fakultaet(i);
		//%.14 mit (double) cast erm�glicht h�here prezision
		printf("%d\t%f\t%f\t%f\t%.14f\t%.14f\t\n", i, (float)1/i, sum(i), fakultaet(i), (double)1/fakultaet(i), e);
	}
	
	return 0;

}

//obergrenze = bis liest ein
unsigned int obergrenzeEinlesen()
{
	unsigned int obergrenze;

	printf("Bitte positive Obergrenze eingeben (Ganzzahlig <= 20): ");
	scanf("%u", &obergrenze);
	
	return obergrenze;
}

float sum(float bis)
{
float summe = 0;
	
	for (int counter = bis; counter > 0; counter--)
	{
		summe = summe + (float)1 / counter;
	}
	return summe;
}

//Addiert die fakult�t auf der counter z�hlt ab
float fakultaet(float bis)
{
	float fak = 1;

	for (int counter = bis; counter > 0; counter--)
	{
		fak = fak * counter;
	}

	return fak;
}



/* gibt n mal das Zeichen c aus */
void strich (int n, char c)
{
	int i;
	for (i=1; i<=n; i++)
		printf("%c", c);
	printf("\n");
}
