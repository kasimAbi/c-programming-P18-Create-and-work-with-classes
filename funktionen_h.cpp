/* #include "fehler_abfangen.h"
#include "header.h"



// durch Scope(::) - Operator die Methoden der Rechnen - Klasse definieren
void zahl_eingabe(float *zahlen_eins, float *zahlen_zwei, int *zahl_int_eins, int *zahl_int_zwei)
{
	// Initialisierungen
	char eingabe[20];
	int ok = 0;
	int is_int = 0;
	Rechnen rechnen;
	// löscht Programmzeile bis dahin
	system("cls");
	// Endlosschleife
	while (ok != 5)
	{
		cout << "geben sie ihre erste zahl ein: " << endl;
		cin >> eingabe;
		// prüft ob integer wert. wenn integer wert dann kriegt bool integer_oder_float true. ansonsten false. und je nachdem wird weiter
		// überprüft.
		is_int = rechnen.Datentyp_pruefen(eingabe);
		if (is_int)
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
			if (is_int)
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
*/