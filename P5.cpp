#include"fehler_abfangen.h"
#include"service.h"
#include"header.h"

// main
int main(void)
{
	// intialisierungen/ Deklarationen
	char eingabe[GROESSE];
	int wahl = 0, ok = 0, zahl_int_eins = 0, zahl_int_zwei = 0, is_int = 0, erg_int = 0;
	float zahl_eins = 0.0, zahl_zwei = 0.0, erg_float = 0.0;
	// meine klasse
	Rechnen rechnen;
	while (wahl != 5)
	{
		// menü
		cout << "waehlen sie aus:\n (1) addition.\n (2) subtraktion.\n (3) multiplikation.\n (4) division.\n (5) programm beenden.\n" << endl;
		cin >> eingabe;
		wahl = wandeln_integer(eingabe);
		// wenn wahl eine gültige zahl hat
		if (wahl >= 1 && wahl <= 4)
		{
			// funktionsaufruge
			zahl_eingabe(&zahl_eins, &zahl_zwei, &zahl_int_eins, &zahl_int_zwei, &is_int);
			rechnen.Datentyp_pruefen(is_int);
			rechnen.zahlen_setzen(zahl_eins, zahl_zwei, zahl_int_eins, zahl_int_zwei);
		}
		if (wahl >= 1 && wahl <= 4)
		{
			if (is_int)
			{
				erg_int = rechnen.get_int_erg(wahl, &ok);
				if (ok == 0 &&  wahl == 4)
				{
					// fehlermeldung
					cout << "Division ohne 0.\n" << endl;
				}
				else
				{
					// ausgeben funktoin
					ausgeben(wahl, is_int, erg_int, erg_float);
				}
			}
			else
			{
				erg_float = rechnen.get_float_erg(wahl, &ok);
				if (ok == 0 && wahl == 4)
				{
					// fehlermeldung
					cout << "Division ohne 0.\n" << endl;
				}
				else
				{
					// ausgeben funktion
					ausgeben(wahl, is_int, erg_int, erg_float);
				}
			}
			cout << "\n\n" << endl;
		}
		if (wahl == 5)
		{
			// wenn programm beendet werden soll
			cout << "programm wird beendet.\n" << endl;
		}
		if (wahl > 5 || wahl < 1)
		{
			// fehlermeldung
			system("cls");
			cout << "falsche eingabe.\n" << endl;
		}
	}
	return 0;
}