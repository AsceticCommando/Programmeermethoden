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
    #include "othellobord.h"
    using namespace std;

    void Menu(bord* & Othellobord, bool & exit) {
        bordvakje* wijzer;
        int breedte;
        int hoogte;
        char menu;
        while (!exit) {
            cin >> menu;
            switch (menu) {
                case 'B': case 'b':
                    Othellobord = new bord(breedte, hoogte);
                    Othellobord->maakBord(wijzer);
                    Othellobord->breien(wijzer);
                    Othellobord->vulBord(wijzer);
                    Othellobord->afdrukken(wijzer);
                    break;
                case 'X': case 'x':
                    exit = 1;
                default:
                    break;
            }	
        }
    }

    int main() {
        bord* wijzer;
        bool exit = false;
        Menu(wijzer, exit);
        return 0;
    }