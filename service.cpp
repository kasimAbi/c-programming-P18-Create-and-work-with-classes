#include"header.h"
#include"fehler_abfangen.h"
#include"service.h"



// durch Scope(::) - Operator die Methoden der Rechnen - Klasse definieren
void zahl_eingabe(float *zahlen_eins, float *zahlen_zwei, int *zahl_int_eins, int *zahl_int_zwei, int *is_int)
{
	// Initialisierungen
	char eingabe[20];
	int ok = 0;
	// löscht Programmzeile bis dahin
	system("cls");
	// Endlosschleife
	while (ok != 5)
	{
		cout << "geben sie ihre erste zahl ein: " << endl;
		cin >> eingabe;
		// prüft ob integer wert. wenn integer wert dann kriegt bool integer_oder_float true. ansonsten false. und je nachdem wird weiter
		// überprüft.
		*is_int = is_int_float(eingabe);
		if (*is_int)
		{
			*zahl_int_eins = wandeln_integer(eingabe);
			// damit er gleich in die if abfrage kann
			ok = 1;
		}
		else
		{
			// wenn ungültige zahl dann bekommt ok den wert 0.
			ok = pruefen_gueltig_float(eingabe);
			if (ok != 0)
			{
				*zahlen_eins = wandeln_float(eingabe);
			}
			else
			{
				system("cls");
				cout << "sie haben einen fehler gemacht." << endl;
			}
		}
		cout << "\n" << endl;

		if (ok != 0)
		{
			// wenn integer (also ok = 1)
			if (*is_int)
			{
				ok = 0;
				while (ok == 0)
				{
					cout << "geben sie ihre zweite zahl ein: " << endl;
					cin >> eingabe;
					// wenn ungültige zahl dann bekommt ok den wert 0.
					ok = pruefen_gueltig_integer(eingabe);
					if (ok != 0)
					{
						*zahl_int_zwei = wandeln_integer(eingabe);
						// um die endlosschleife zu verlassen ist die bedingung ok = 5.
						ok = 5;
					}
					else
					{
						system("cls");
						// fehlermeldung falls nciht der entsprechende datentyp eingegeben wurde, oder andere fehler auftreten.
						cout << "sie haben einen fehler gemacht.\nes muss derselbe datentyp wie die erste zahl sein.\n" << endl;
					}
				}
			}
			else
			{
				ok = 0;
				while (ok == 0)
				{
					cout << "geben sie ihre zweite zahl ein: " << endl;
					cin >> eingabe;
					// wenn ungültige zahl dann bekommt ok den wert 0.
					ok = pruefen_gueltig_integer(eingabe);
					if (ok == 0)
					{
						ok = pruefen_gueltig_float(eingabe);
						if (ok != 0)
						{
							*zahlen_zwei = wandeln_float(eingabe);
							// um die endlosschleife zu verlassen ist die bedingung ok = 5.
							ok = 5;
						}
						else
						{
							system("cls");
							// fehlermeldung falls nciht der entsprechende datentyp eingegeben wurde, oder andere fehler auftreten.
							cout << "sie haben einen fehler gemacht.\nes muss derselbe datentyp wie die erste zahl sein.\n" << endl;
						}
					}
					else
					{
						// fehlermeldung falls nciht der entsprechende datentyp eingegeben wurde, oder andere fehler auftreten.
						cout << "sie haben einen fehler gemacht.\nes muss derselbe datentyp wie die erste zahl sein.\n" << endl;
						ok = 0;
					}
				}
			}
		}
	}
}

// Datentyp überprüfen ob integer oder float wert.
int is_int_float(char eingabe[GROESSE])
{
	int laenge = 0, fehler = 0, index = 0, minus = 0, ok = 0, punkt = 0;
	// um herauszufinden wie groß der string ist
	laenge = strlen(eingabe);
	// überprüft ob ein + am anfang steht um es abzufangen
	if (eingabe[0] == '+') {
		// wenn ja dann dekrementiert er die länge um 2
		laenge--;
		// dient dazu um den + weg zu machen und um die zahlen zu vertauschen
		for (index = 0; index < laenge; index++) {
			// tauscht den ersten wert des arrays mit dem nächsten
			eingabe[index] = eingabe[index + 1];
			// setzt den nächsten wert des arrays auf 0
			eingabe[index + 1] = 0;
		}
	}
	if (eingabe[0] == '-')
	{
		index = 1;
	}
	else
	{
		index = 0;
	}
	// dient dazu um alle string- zeichen zu überprüfen ob auch alle zahlen sind
	// wenn eine 0 zurückgegeben wurde(also false) dann ist die stelle des arrays KEINE zahl und
	// die variable fehler wird incrementiert
	for (; index < laenge; index++) {
		if (isdigit(eingabe[index]) == 0) {
			fehler++;
			if (eingabe[index] == '.')
			{
				punkt++;
			}
		}
	}
	ok = 0;
	// bedingung erfüllt?
	if (fehler == 0 && eingabe[0] != '-') {
		ok = 1;
	}
	// bedingung erfüllt?
	if (fehler == 0 && eingabe[0] == '-') {
		ok = 1;
	}
	if (punkt == 1)
	{
		ok = 0;
	}
	return ok;
}

void ausgeben(int wahl, int is_int, int erg_int, float erg_float)
{
	// zum ausgeben von ergebnis
	// wählt wahl
	if (is_int)
	{
		system("cls");
		cout << "ihr Ergebnis lautet: " << erg_int << endl;
	}
	else
	{
		system("cls");
		cout << "ihr Ergebnis lautet: " << erg_float << endl;
	}
	cout << "\n\n" << endl;
}