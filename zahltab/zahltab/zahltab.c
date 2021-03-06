//*******************************************************************
// Programm    : Zahltab                                             
// Verfasser   : Feindor/Schmidt                                           
// Datum       : Urprogramm: 1.10.1996                                          
// Eingabe     : obere und untere Grenzen                            
// Verarbeitung: Berechnung von Standardfunktionen                   
// Ausgabe     : Zahlentabellen                                      
// �nderungen  : 03.10.20012
//*******************************************************************

// Einbinden von n�tigen Header-Dateien                              
#include <stdio.h>  // Standard Input/ Output  z.B. scanf, printf
#include <stdlib.h> // Standard-Bibliothek, z.B. f�r system
#include <math.h>   // Standard-Bibliothek f�r math. Funktionen z.B. sqrt
#define E 2.71828183 
//float e = exp(1);

// Prototypen der ben�tigten Funktionen 
void strich(int n, char c);  // gibt n mal das Zeichen c aus 
void tabelleAusgeben(const int von, const int bis, const int schritt);
int untereGrenzeEinlesen(void);
int obereGrenzeEinlesen(int ug);

int main() // Beginn Hauptprogramm          **************************
{
	//************************ Vereinbarungsteil **************************
	int von, bis, schritt;

	//************************ Anweisungsteil  ****************************
	// Dialoger�ffnung 
	strich(50,'-');
	printf ("Zahltab: Berechnung von Zahlentafeln\n");
	strich(50,'-');
	
	//grenzenEinlesen(&von, &bis);
	von = untereGrenzeEinlesen();
	bis = obereGrenzeEinlesen(von);

	// Einlesen Schrittweite
	printf ("Bitte Schrittweite eingeben: ");
	scanf ("%d",&schritt);

	tabelleAusgeben(von, bis, schritt);

	printf("Servus! \n");

	printf("Size of int: %d\n", sizeof(int));
	printf("Size of double: %2.lf\n", sizeof(double));
	printf("Size of float: %2.f\n", sizeof(float));

	system("pause");
	return(0);
} //***************** Ende Hauptprogramm ***************************


// Definition der ben�tigten Funktionen      

// gibt n mal das Zeichen c aus 
void strich (int n, char c) 
{
	int i;
	for (i=1; i<=n; i++)
		printf("%c", c);
	printf("\n");
}

// Einlesen und pr�fen der Tabellengrenzen

// Untergrenze
int untereGrenzeEinlesen(void)
{
	int ug;
	do // Einlesen untere Grenze und pr�fen
	{
		printf ("Bitte positive untere Grenze eingeben:  ");
		scanf  ("%d", &ug);
		if (ug <= 0 ) printf ("Bitte nur positive Zahlen!!\n");
		/*{
			scanf("%d", &ug);
			return ug;
		}*/
	} while (ug <= 0);

	return ug;
}

// Obergrenze
// �bergebener Parameter ug: vorher eingelesene Untergrenze
int obereGrenzeEinlesen(int ug)
{
	int og;

	do // Einlesen obere Grenze und pr�fen
	{
		printf ("Bitte obere Grenze eingeben:  ");
		scanf  ("%d", &og);
		if (og <= ug ) printf ("Bitte nur positive Zahlen!!\n");
	} while (og <= ug );

	return og;
}


// Ausgeben Tabelle
void tabelleAusgeben(const int von, const int bis, const int schritt)
{
	int i;

	printf("     i    i^2      i^3		Wurzel(i)	ln(i)		e^i \n");
	strich(22, '-');
	for(i = von; i <= bis; i = i + schritt)
	{
		float ifl = (float)i;

		printf("%6.f %6.f %8.f\t\t %.8f\t %.8f\t %f \n",
		ifl, ifl * ifl, pow(ifl,3), sqrt(ifl), log(ifl), pow(E,ifl));
	}
}
