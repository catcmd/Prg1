//*******************************************************************
// Programm    : Dreieck                                          
// Verfasser   : Schmidt                                           
// Datum       : Urprogramm: 11.10.2012                                          
// Eingabe     : Seite + Winkel eines rechtwinkligen Dreiecks                            
// Verarbeitung: Berechnung aller Seiten und Winkel                   
// Ausgabe     : Ergebnis als Tabelle
// Änderungen  : 11.10.2012
//*******************************************************************

// Einbinden von nötigen Header-Dateien                              
#include <stdio.h>    // Standard Input/ Output  z.B. scanf, printf
#include <stdlib.h>   // Standard-Bibliothek, z.B. für system
#include <math.h>     // Standard-Bibliothek für math. Funktionen z.B. sqrt
#include "mainfile.h" // eigene Header-Datei mit Funktionsprototypen


int main() // Beginn Hauptprogramm          **************************
{
	// Aufgabe: Dreieck
	dreieck();

	system("pause");
	return(0);
} //***************** Ende Hauptprogramm ***************************

void dreieck(void)
{
	double a;  // Seitenlänge von Seite a
	double alpha_deg;  // Winkel in Grad

	double c; //Seitenlänge von c
	double gamma_deg = 90; //Winkel Gamma in Grad

	double b;
	double beta_deg;

/************************************************************************/

// Dialogeröffnung 
strich(50, '-');
printf("Rechtwinkliges Dreieck\n");
strich(50, '-');

// Seite/Winkel einlesen
printf("Bitte Laenge Seite a eingeben: ");
scanf("%lf", &a);

printf("Bitte Winkel Alpha in Grad eingeben: ");
scanf("%lf", &alpha_deg);

// Berechnung aller Seiten und Winkel
//Winkel
beta_deg = 180 - (alpha_deg + gamma_deg);

//Seite b
b = a + sin(beta_deg);

//Seite c
c = a * sin(gamma_deg) / sin(alpha_deg);

// speichern aller Ergebnisse in einer neuen Variablen
//Tmp Seiten
double a_tmp = a;
double b_tmp = b;
double c_tmp = c;

//Tmp Winkel
double alpha_tmp = alpha_deg;
double beta_tmp = beta_deg;
double gamma_tmp = gamma_deg;

// abrunden aller Seiten auf die nächste ganze Zahl
double a_down = round_down(a_tmp);
double b_down = round_down(b_tmp);
double c_down = round_down(c_tmp);

// aufrunden aller Seiten auf die nächste ganze Zahl
double a_up = round_up(a_tmp);
double b_up = round_up(b_tmp);
double c_up = round_up(c_tmp);

// (korrektes) runden aller Seiten auf die nächste ganze Zahl
double a_cor = round_correct(a_tmp);
double b_cor = round_correct(b_tmp);
double c_cor = round_correct(c_tmp);

// Eingabe: w_deg, Winkel in Grad
double alpha_rad = deg2rad(alpha_tmp);
double beta_rad = deg2rad(beta_tmp);
double gamma_rad = deg2rad(gamma_tmp);

// Ausgabe aller Seiten und Winkel
printf("       2 NK-Stellen   gerundet   abgerundet   aufgerundet\n");
strich(57, '-');
printf("a        %10.2f %10.0f   %10.0f    %10.0f\n", a, a, a_up, a_cor);
printf("b        %10.2f %10.0f   %10.0f    %10.0f\n", b, b, b_up, b_cor);
printf("c        %10.2f %10.0f   %10.0f    %10.0f\n\n", c, c, c_up, c_cor);

printf("Alpha (Grad):\t %10.2f\n", alpha_deg);
printf("Beta (Grad) :\t %10.2f\n", beta_deg);
printf("Gamma (Grad):\t %10.2f\n\n", gamma_deg);

printf("Alpha (Rad):\t %10.3f\n", alpha_rad);
printf("Alpha (Rad):\t %10.3f\n", beta_rad);
printf("Alpha (Rad):\t %10.3f\n", gamma_rad);

}
// Funktion abrunden aller Seiten auf die nächste ganze Zahl
double round_down(double value)
{
	double rest = fmod(value, 1);
	double temp = value - rest;
	return temp;
}

// Funktion aufrunden aller Seiten auf die nächste ganze Zahl
double round_up(double value)
{
	double rest = fmod(value, 1);
	double difference = 1 - rest;
	double temp = value + difference;
	return temp;
}

// Funktion (korrektes) runden aller Seiten auf die nächste ganze Zahl
double round_correct(double value)
{
	double temp;
	double rest = fmod(value, 1);

	if (rest >= 0.5)
	{
		temp = round_up(value);
	}
	else
	{
		temp = round_down(value);
	}
	return temp;
}



// Ausgabe: w_rad, Winkel in rad
double deg2rad(double w_deg)
{
	double w_rad = 0.0;
	// Grad in rad umrechnen, Ergebnis in w_rad

	w_rad = w_deg * (PI / 180);

	return w_rad;
}

// gibt n mal das Zeichen c aus 
void strich(int n, char c)
{
	int i;
	for (i = 1; i <= n; i++)
		printf("%c", c);
	printf("\n");
}


