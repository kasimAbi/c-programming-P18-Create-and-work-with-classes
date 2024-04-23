#pragma once
#pragma comment(lib,"FehlerAbfangen.lib")
#include"fehler_abfangen.h"
#include"service.h"
// Klasse erstellen.
class Rechnen
{
private:
	float zahl_eins;
	float zahl_zwei;
	float ergebnis;
	int integer_zahl_eins;
	int integer_zahl_zwei;
	int integer_ergebnis;
	// integer = 1 also true, float = 0 also false.
	bool integer_oder_float;

private:
	void addition(void);
	void subtraktion(void);
	void multiplikation(void);
	int division(void);

public:
	// mit den funktionen kann man auf die privates zugreifen.
	void zahlen_setzen(float, float, int, int);
	void Datentyp_pruefen(int);
	int get_int_erg(int, int*);
	float get_float_erg(int, int*);
};

