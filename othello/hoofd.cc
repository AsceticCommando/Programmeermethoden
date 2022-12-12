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

	void info() {
		cout << "+---------------------------------------------------"
             << "---+" << endl << "| Programmeermethoden; eerste prog"
             << "rammeeropgave        |" << endl << "| Gemaakt op;   "
             << "       12-12-2022                      |" << endl
             << "| Gemaakt door:      Thijs Vijgeboom en Lotte Wulffe"
             << "le |" << endl << "| Studentnummers:    2648261      " 
             << "      3661814        |" << endl << "| Jaar van aanko"
             << "mst: 2019               2022           |" << endl
             << "| Studierichting:    Biologie           Wiskunde    "
             << "   |" << endl << "+---------------------------------"
             << "---------------------+" << endl << endl << "Welkom b"
             << "ij Othello. Een competitief spel voor met zijn twee."
             << " De bedoeling van Othello is om zoveel mogelijk gebi"
             << "ed te veroveren op het bord." << endl << "Dit doet u"
             << " door stenen van uw tegenstander in te sluiten met u"
             << "w eigen kleur stenen." << endl << "Indien u of uw te"
			 << "genstander geen zet meer kan doen is het spel voorbi"
			 << "j, worden de stenen geteld en de winnaar bepaald."
			 << endl << "Veel speel plezier en Othello-ze" << endl
			 << endl;
	}

    void Menu(bord & Othellobord, bool & exit) {
        bordvakje* wijzer;      //Houdt positie van A1 bij op het bord
		//stapel* opslaan = new stapel; WIP
        char menu;                                     //Menu karakter
		string speler;                  //Houdt de te zetten kleur bij
		string zet;              //Houdt de coordinaten van de zet bij
		Othellobord.maakBord(wijzer);               //Zie functie file
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
			cout << "| [x] Afsluiten | [z] Zet doen | [w] Check winna"
			     << "ar | Voer uw keuze in: ";
            cin >> menu;
            switch (menu) {
				case 'Z': case 'z': {
					cout << speler << " is aan de beurt: ";
					cin >> zet;
					//Othellobord.kopieer(opslaan, wijzer);
				    Othellobord.doeZet(wijzer, zet);
					Othellobord.afdrukken(wijzer);
					Othellobord.geefBeurt();
					break;
				}
				case 'W': case 'w': 
					Othellobord.winnaar(wijzer);
					exit = 1;
				case 'X': case 'x': {
                    exit = 1;
					break;
				}
                default:
				    cout << "Voer een geldige keuze in en probeer nog"
					     <<" een keer." << endl;
				    break;
			}
        }	
    }//Menu

    int main() {
		bool exit = false;       //bepaalt voortgang van het programma
	    int breedte;
        int hoogte;
		info();
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
		}//Mag niet
        bord Othellobord(breedte, hoogte);
        Menu(Othellobord, exit);
        return 0;
    }//main