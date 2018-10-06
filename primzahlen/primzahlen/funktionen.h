#ifndef _PRIM_H_
#define _PRIM_H_
#include <stdbool.h>
#include <math.h>

/* Definition globale Konstanten  */
#define NICHT_PRIM 0
#define PRIM  1
#define OG 1000

//Neuer Datentyp definieren
struct zahl_s
{
	unsigned int wert;
	bool istPrim;
};

/* Prototypen der benötigten Funktionen */
void strich (int n, char c); /* gibt n mal das Zeichen c aus  */
void sieb(struct zahl_s *inputArray); /*siebt nach primzahlen im feld*/
void ausgabe(struct zahl_s *inputArray);



#endif
