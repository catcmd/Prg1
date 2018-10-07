#ifndef _EURO_H_
#define _EURO_H_


typedef enum 
{
	ec_ok,				/* Seriennummer gültig */
	ec_pz_falsch,		/* Prüfziffer falsch */
						/* (also: Rest bei Division durch 9 ungleich Null)*/
	ec_zukurz,			/* Seriennummer zu kurz */
	ec_zulang,			/* Seriennummer zu lang */
	ec_LCfalsch,		/* Ländercode ist kein Großbuchstabe */
	ec_SNkeineZiffer	/* 10-stellige Seriennummer oder */
						/* Prüfziffer enthält Zeichen, */
						/* die nicht Ziffern sind */
} t_errcode;


/* Prototypen der benötigten Funktionen */
void strich (int n, char c); /* gibt n mal das Zeichen c aus  */
unsigned int einlesen(char *inputArray); /*liest einen string ein speicher auf input buffer und kontroliert ob 
										 string die gewünschte länge hat buffer dazu da das ziel array
										 nicht corrupter wird*/
unsigned int quersumme(char *inputArray);/*berechnet die quersumme der werte aller stellen des arrays damit kein
										 conflict ensteht wurde der Ländercode außerhalb platziert und automatisch 
										 in einen ASCII code umgewandelt um aufsummiert zu werden*/
unsigned int prufziffer(int quersumme, int zuPruef);/*erzeugen der prüfziffer in dem der quersumme die 11te stelle
													abgezogen wird und die richtige prüfziffer erzeugt wird um
													diese mit der eingabeprüfziffer zuvergleichen*/
t_errcode eurotest(char *inputArray);/*t_errcode ist ein enum, aka aufzählungstyp stichwortverzeichnis und 
									 überprüft*/
void fehlerAusgabe(t_errcode knoblauch);/*ausgabe der überprüfungen mithilfe eines case*/



#endif
