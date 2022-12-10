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

    bord::bord() {

    }

    bord::~bord() {
        
    }
    void bord::maakRij(bordvakje* & wijzer, int breedte) {
        bordvakje* vorige;
        vorige = nullptr;
        bordvakje* huidige;
        huidige = new bordvakje;
        wijzer = huidige;
        bordvakje* volgende;
        for (int i = 0; i < breedte; i++) {
            huidige->kleur = '-';
            huidige->buren[2] = vorige;
            if (i != breedte-1) volgende = new bordvakje;
            else volgende = nullptr;
            huidige->buren[6] = volgende;
            vorige = huidige;
            huidige = volgende;
        }
    }
    void bord::afdrukken(bordvakje* wijzer) {
        bordvakje* hulp = wijzer;
        while (hulp != nullptr) {
            cout << hulp->kleur << " ";
            hulp = hulp->buren[2]
        }
    }