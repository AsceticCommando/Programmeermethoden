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
        int breedte;
        int hoogte;
        char menu;
		string zet;
        while (!exit) {
            cin >> menu;
            switch (menu) {
                case 'B': case 'b':
                    Othellobord.maakBord(wijzer);
                    Othellobord.breien(wijzer);
                    Othellobord.vulBord(wijzer);
                    Othellobord.afdrukken(wijzer);
                    break;
                case 'X': case 'x':
                    exit = 1;
					break;
				case 'Z': case 'z': {
					cin >> zet;
				    Othellobord.doeZet(wijzer, zet);
					Othellobord.afdrukken(wijzer);
					break;
                default:
                    break;
				}
            }	
        }
    }

    int main() {
        bord Othellobord(8, 8);
        bool exit = false;
        Menu(Othellobord, exit);
        return 0;
    }