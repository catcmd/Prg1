#ifndef _EURO_H_
#define _EURO_H_


typedef enum 
{
	ec_ok,				/* Seriennummer g�ltig */
	ec_pz_falsch,		/* Pr�fziffer falsch */
						/* (also: Rest bei Division durch 9 ungleich Null)*/
	ec_zukurz,			/* Seriennummer zu kurz */
	ec_zulang,			/* Seriennummer zu lang */
	ec_LCfalsch,		/* L�ndercode ist kein Gro�buchstabe */
	ec_SNkeineZiffer	/* 10-stellige Seriennummer oder */
						/* Pr�fziffer enth�lt Zeichen, */
						/* die nicht Ziffern sind */
} t_errcode;


/* Prototypen der ben�tigten Funktionen */
void strich (int n, char c); /* gibt n mal das Zeichen c aus  */
unsigned int einlesen(char *inputArray); /*liest einen string ein speicher auf input buffer und kontroliert ob 
										 string die gew�nschte l�nge hat buffer dazu da das ziel array
										 nicht corrupter wird*/
unsigned int quersumme(char *inputArray);/*berechnet die quersumme der werte aller stellen des arrays damit kein
										 conflict ensteht wurde der L�ndercode au�erhalb platziert und automatisch 
										 in einen ASCII code umgewandelt um aufsummiert zu werden*/
unsigned int prufziffer(int quersumme, int zuPruef);/*erzeugen der pr�fziffer in dem der quersumme die 11te stelle
													abgezogen wird und die richtige pr�fziffer erzeugt wird um
													diese mit der eingabepr�fziffer zuvergleichen*/
t_errcode eurotest(char *inputArray);/*t_errcode ist ein enum, aka aufz�hlungstyp stichwortverzeichnis und 
									 �berpr�ft*/
void fehlerAusgabe(t_errcode knoblauch);/*ausgabe der �berpr�fungen mithilfe eines case*/



#endif
