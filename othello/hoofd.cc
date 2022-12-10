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


    int main() {
        int breedte = 8;
        int hoogte = 8;
        bordvakje* wijzer;
        bord Othellobord(breedte, hoogte);
        Othellobord.maakBord(wijzer);
        Othellobord.breien(wijzer);
        Othellobord.afdrukken(wijzer);
        return 0;
    }