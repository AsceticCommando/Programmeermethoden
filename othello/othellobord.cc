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
    #include<string>
    #include "othellobord.h"
    using namespace std;

    bordvakje::bordvakje() {
        
    }

    bord::bord(int x, int y) {
        breedte = x;
        hoogte = y;
    }

    bord::~bord() {
        
    }

    void bord::breien(bordvakje* & wijzer) {
        bordvakje* rij1;
        bordvakje* rij2;
        rij1 = wijzer;
        rij2 = wijzer->buren[4];
        for (int i = 1; i < hoogte; i++) {
            bordvakje* kolom1 = rij1;
            bordvakje* kolom2 = rij2;
            for(int j = 1; j < breedte; j++) {
                kolom1 = kolom1->buren[2];
                if (kolom2 != nullptr) kolom2 = kolom2->buren[2];
                kolom1->buren[4] = kolom2;
                if (kolom2 != nullptr) kolom2->buren[0] = kolom1;
            }
            rij1 = rij2;
            if (rij2->buren[4] != nullptr) rij2 = rij2->buren[4];
            else rij2 = nullptr;
        }//Verticaal verbinden van overige vakken
        bordvakje* rij = wijzer;
        bordvakje* kolom;
        bordvakje* middelste;
        for (int i = 0; i < hoogte; i++) {
            kolom = rij;
            for (int j = 0; j < breedte; j++) {
                middelste = kolom;
                if (middelste->buren[0] != nullptr 
                   && middelste->buren[2] != nullptr) {
                    middelste->buren[1] = middelste->buren[0]->buren[2];
                }
                if (middelste->buren[4] != nullptr 
                   && middelste->buren[2] != nullptr) {
                    middelste->buren[3] = middelste->buren[2]->buren[4];
                }
                if (middelste->buren[4] != nullptr 
                   && middelste->buren[6] != nullptr) {
                    middelste->buren[5] = middelste->buren[0]->buren[6];
                }
                if (middelste->buren[0] != nullptr 
                   && middelste->buren[6] != nullptr) {
                    middelste->buren[7] = middelste->buren[0]->buren[6];
                }
                kolom = kolom->buren[2];
            }
            rij = rij->buren[4];
        }
    }

    void bord::maakRij(bordvakje* & wijzer) {
        bordvakje* vorige;
        vorige = nullptr;
        bordvakje* huidige;
        huidige = wijzer;
        bordvakje* volgende;
        for (int i = 0; i < breedte; i++) {
            huidige->kleur = '-';
            huidige->buren[6] = vorige;
            if (i != breedte-1) volgende = new bordvakje;
            else volgende = nullptr;
            huidige->buren[2] = volgende;
            vorige = huidige;
            huidige = volgende;
        }
    }

    void bord::maakBord(bordvakje* & wijzer) {
        bordvakje* vorige = nullptr;
        bordvakje* huidige;
        huidige = new bordvakje;
        wijzer = huidige;
        bordvakje* volgende;
        for (int i = 0; i < hoogte; i++) {
            maakRij(huidige);
            huidige->buren[0] = vorige;
            if (i != hoogte-1) volgende = new bordvakje;
            else volgende = nullptr;
            huidige->buren[4] = volgende;
            vorige = huidige;
            huidige = volgende;
        }
    }

    void bord::afdrukken(bordvakje* wijzer) {
        int ycoord = 1;
        bordvakje* rij = wijzer;
        bordvakje* kolom;
        cout << "  ";
        char xcoord = 'A';
        for (int i = 0; i < breedte; i++) {
            cout << xcoord << " ";
            xcoord++;
        }
        cout << endl;
        while (rij != nullptr) {
            kolom = rij;
            cout << ycoord << " ";
            while (kolom != nullptr) {
                cout << kolom->kleur << " ";
                kolom = kolom->buren[2];
            }
            cout << endl;
            ycoord++;
            rij = rij->buren[4];
        }
    }