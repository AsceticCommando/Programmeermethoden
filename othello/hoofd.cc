    //Infoblok voor programmeurs
    //Compiler:          g++.exe (Rev1, Built by MSYS2 project) 12.2.0
    //Programmeerpgave:                                              1
    //Gemaakt op:                                           26-09-2022
    //Namen:                   Vijgeboom, Thijs;       Wulffele, Lotte
    //Studentnummers:                   2648261;               3661814
    //Jaar van aankomst:                   2019;                  2022
    //Studierichting:                  Biologie;              Wiskunde
    //Gebruikte IDE:         Visual Studio Code;          Sublime Text
    
    #include <iostream>
	#include <string>
    #include "othellobord.h"
    using namespace std;

    void Menu(bord & Othellobord, bool & exit) {
        bordvakje* wijzer;
		//stapel* opslaan = new stapel;
        char menu;
		string speler;
		string zet;
		Othellobord.maakBord(wijzer);
        Othellobord.breien(wijzer);
        Othellobord.vulBord(wijzer);
        Othellobord.afdrukken(wijzer);
        while (!exit) {
			if (Othellobord.geefSpeler() == 'Z') {
				speler = "Zwart";
			}
			else {
				speler = "Wit";
			}
			cout << "| [x] Afsluiten | [z] Zet doen | Voer uw keuze i"
			     << "n: ";
            cin >> menu;
            switch (menu) {
                case 'X': case 'x':
                    exit = 1;
					break;
				case 'Z': case 'z': {
					cout << speler << " is aan de beurt: ";
					cin >> zet;
					//Othellobord.kopieer(opslaan, wijzer);
				    Othellobord.doeZet(wijzer, zet);
					Othellobord.afdrukken(wijzer);
					Othellobord.geefBeurt();
					if(Othellobord.gameOver(wijzer)) {
						Othellobord.winnaar(wijzer);
						exit = true;
					}
					break;
				}
                default:
				    cout << "Voer een geldige keuze in en probeer nog"
					     <<" een keer." << endl;
				    break;
			}
        }	
    }

    int main() {
		bool exit = false;
	    int breedte;
        int hoogte;
		cout << "Voer de hoogte in van het Othello bord." << endl
			 << "Dit moet een geheel, even getal zijn waarbij 0 < i <"
			 << " 9: ";
		cin >> hoogte;
		if (hoogte % 2 == 1 || hoogte == 0 || hoogte > 8) {
			cout << "Lees goed de instructie na!" << endl;
			return 1;
		}
		cout << "Voer de breedte in van het Othello bord." << endl
			 << "Dit moet een geheel, even getal zijn waarbij 0 < j <"
			 << " 9: ";
		cin >> breedte;
		if (breedte % 2 == 1 || breedte == 0 || breedte > 8) {
			cout << "Lees goed de instructie na!" << endl;
			return 1;
		}
        bord Othellobord(breedte, hoogte);
        Menu(Othellobord, exit);
        return 0;
    }