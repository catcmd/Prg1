/*******************************************************************
/ Programm    : Bruchrechnung                                         
/ Verfasser   : Schmidt                                           
/ Datum       : Urprogramm: 24.10.2012                                          
/ Eingabe     : 2 rationale Zahlen                          
/ Verarbeitung: diverse Berechnungen                   
/ Änderungen  : 24.10.2012
/ *******************************************************************/

/* Einbinden von nötigen Header-Dateien                             */
#include <stdio.h>    /* Standard Input/ Output  z.B. scanf, printf */
#include <stdlib.h>   /* Standard-Bibliothek, z.B. für system       */
#include "mainfile.h"

//Neuer Datentyp bruch_s
struct bruch_s
{
	int n; //Nenner
	int z; //Zaehler
	int n_kurz; //Gekürzt
	int rest_kurz; //Gek.
};

int main()
{
	//Main lok def var
	struct bruch_s b1, b2, sum, dif, prod, quot;

	printf("Bitte Zaehler und Nenner Bruch 1 eingeben: \n");
	scanf("%i %i", &b1.z, &b1.n);
	printf("Bitte Zaehler und Nenner Bruch 2 eingeben: \n");
	scanf("%i %i", &b2.z, &b2.n);

	sum = addition(b1, b2);
	dif = subtraktion(b1, b2);
	prod = multiplikation(b1, b2);
	quot = division(b1, b2);

	printf("Summe =	%i/%i \n", sum.z, sum.n);
	printf("Differenz = %i/%i \n", dif.z, dif.n);
	printf("Multi = %i/%i \n", prod.z, prod.n);
	printf("Div	= %i/%i \n", quot.z, quot.n);

	ggt(b1.n, b2.n);



	system("pause");
	return(0);
}


//Additionale berechnung des Produkts
struct bruch_s addition(struct bruch_s b1, struct bruch_s b2)
{
	//hello there u qty
	struct bruch_s sum;

	sum.z = b1.z*b2.n + b2.z*b1.n;
	sum.n = b1.n*b2.n;
/*
	produkt.n_kurz = produkt.z / produkt.n;
	
	produkt.rest_kurz = produkt.n - (produkt.z * produkt.n_kurz);*/
	//u qt
	
	sum = kuerz(sum); //der komplette struct bruch_s sum wird and kuerz übergeben die funktion darf sich dann den rest rauspicken

	return sum;
}

struct bruch_s subtraktion(struct bruch_s b1, struct bruch_s b2)//Parameter sind platz halter/ eingänge der funktionen über gibt man und Variablen definiert man
{
	struct bruch_s dif;

	dif.z = b1.z*b2.n - b2.z*b1.n;
	dif.n = b1.n*b2.n;


	
	return dif;
}

struct bruch_s multiplikation(struct bruch_s b1, struct bruch_s b2)
{
	struct bruch_s prod;

	prod.z = b1.z*b2.z;
	prod.n = b1.n*b2.n;

	return prod;
}

struct bruch_s division(struct bruch_s b1, struct bruch_s b2)
{
	struct bruch_s quot;

	quot.z = b1.z*b2.n;
	quot.n = b1.n*b2.z;

	return quot;
}

struct bruch_s kuerz(struct bruch_s value)// Value ist ein Platzhalter für einzugebende structs
{
	int gcd = ggt(value.n, value.z);

	value.n = value.n / gcd;
	value.z = value.z / gcd;
	
	
	return value;

}

int ggt(int value, int value2)//hier werden einzlene in values aus dem struct bruch_s übergeben also nenner und zähler hier primitive datentypen
{
	int ggt = 0;
	int a = value;
	int b = value2;

	while (b != 0)
	{
		a %= b;
		a ^= b;
		b ^= a;
		a ^= b;
	}

	ggt = a;
	
	return ggt;
}