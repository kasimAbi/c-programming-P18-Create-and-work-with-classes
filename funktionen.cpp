#include"fehler_abfangen.h"
#include"header.h"
#include"service.h"

void Rechnen::zahlen_setzen(float zahlen_eins, float zahlen_zwei, int zahl_int_eins, int zahl_int_zwei)
{
	// setzt zahlen gleich.
	// für float werte = false
	if (integer_oder_float == false)
	{
		zahl_eins = zahlen_eins;
		zahl_zwei = zahlen_zwei;
	}
	else
	{
		// int werte = true
		integer_zahl_eins = zahl_int_eins;
		integer_zahl_zwei = zahl_int_zwei;
	}
}

// durch Scope(::) - Operator die Methoden der Rechnen - Klasse definieren
void Rechnen::addition()
{
	// zahl + zahl
	// float = false
	if (integer_oder_float == false)
	{
		ergebnis = zahl_eins + zahl_zwei;
	}
	else
	{
		// int = true
		integer_ergebnis = integer_zahl_eins + integer_zahl_zwei;
	}
}

void Rechnen::subtraktion()
{
	// zahl - zahl
	// float = false
	if (integer_oder_float == false)
	{
		ergebnis = zahl_eins - zahl_zwei;
	}
	else
	{
		// int = true
		integer_ergebnis = integer_zahl_eins - integer_zahl_zwei;
	}
}

void Rechnen::multiplikation()
{
	// zahl * zahl
	// float = false
	if (integer_oder_float == false)
	{
		ergebnis = zahl_eins * zahl_zwei;
	}
	else
	{
		// int = true
		integer_ergebnis = integer_zahl_eins * integer_zahl_zwei;
	}
}

int Rechnen::division()
{
	int ok = 0;
	// zahl / zahl
	// ok soll für fehelrmeldung sorgen für den fall des division durch 0
	// float = false
	if (integer_oder_float == false)
	{
		if (zahl_eins != 0.0 && zahl_zwei != 0.0)
		{
			ergebnis = zahl_eins / zahl_zwei;
			// 1 = rechnung geht
			ok = 1;
		}
		else
		{
			// 0 = rechnung geht nciht
			ok = 0;
		}
	}
	else
	{
		// int = true
		if (integer_zahl_eins != 0 && integer_zahl_zwei != 0)
		{
			integer_ergebnis = integer_zahl_eins / integer_zahl_zwei;
			// rechnung geht = 1
			ok = 1;
		}
		else
		{
			// rechnung geht nciht
			ok = 0;
		}
	}
	return ok;
}

// guckt ob integer oder float
void Rechnen::Datentyp_pruefen(int is_int)
{
	if (is_int == 1)
	{
		// true für int
		integer_oder_float = 1;
	}
	else
	{
		// false für float
		integer_oder_float = 0;
	}
}

// ergebnis zurückgeben um auszugeben (für int)
int Rechnen::get_int_erg(int wahl, int* ok)
{
	// ok für fehlermeldung bei division
	switch (wahl)
	{
	case 1:
		// funktionsaufrufe
		addition();
		break;
	case 2:
		// funktionsaufrufe
		subtraktion();
		break;
	case 3:
		// funktionsaufrufe
		multiplikation();
		break;
	case 4:
		// funktionsaufrufe
		*ok = division();
		break;
	}
	return integer_ergebnis;
}

// ergbenis für float zurückgeben
float Rechnen::get_float_erg(int wahl, int* ok)
{
	// ok = fehlermeldung für division
	switch (wahl)
	{
	case 1:
		// funktionsaufrufe
		addition();
		break;
	case 2:
		// funktionsaufrufe
		subtraktion();
		break;
	case 3:
		// funktionsaufrufe
		multiplikation();
		break;
	case 4:
		// funktionsaufrufe
		 *ok = division();
		break;
	}
	// ergebnis zurückgeben(float)
	return ergebnis;
}
