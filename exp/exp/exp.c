/*******************************************************************
// Programm    : exp1                                                
// Verfasser   : Feindor/Schmidt                                             
// Datum       : Urprogramm: 1.10.1996                                           
// Eingabe     : obere und untere Grenzen                            
// Verarbeitung: Berechnung von Funktionen, Zählen, Summieren        
// Ausgabe     : Zahlentabellen                                      
// Änderungen  : 30.10.2012
*******************************************************************/

#include <stdio.h>  /* Standard Input/Output  z.B. scanf, printf */
#include <math.h>   /* Standard-Bibliothek für math. Funktionen  z.B. sqrt */
#include <stdlib.h>   /* Standard-Bibliothek, z.B. für system       */
#include "exp.h"


int main () 
{
	strich(50,'-');
	printf ("Exp: Berechnung von einfachen Funktionen\n");
	strich(50,'-');


	printf("Servus! \n");
	system("pause");
	return 0;
}


/* gibt n mal das Zeichen c aus */
void strich (int n, char c)
{
	int i;
	for (i=1; i<=n; i++)
		printf("%c", c);
	printf("\n");
}
