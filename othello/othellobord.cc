    //Infoblok voor programmeurs
    //Compiler:          g++.exe (Rev1, Built by MSYS2 project) 12.2.0
    //Programmeerpgave:                                              1
    //Gemaakt op:                                           26-09-2022
    //Namen:                   Vijgeboom, Thijs;       Wulffele, Lotte
    //Studentnummers:                   2648261;               3661814
    //Jaar van aankomst:                   2019;                  2022
    //Studierichting:                  Biologie;              Wiskunde
    //Gebruikte IDE:         Visual Studio Code;          Sublime Text
    #include<iostream>
    #include "othellobord.h"
    using namespace std;

    bord::bord(int x, int y) {
        hoogte = x;
        breedte = y;
    }

    bord::~bord() {
        
    }
    void bord::maakRij() {
        for (int i = 0; i < this->hoogte; i++) {}
    }
    void bord::afdrukken() {

    }