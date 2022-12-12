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

    bord::bord() {
        breedte = 8;
        hoogte = 8;
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

    void bord::maakRij(bordvakje* & ingang) {
        bordvakje* vorige;
        vorige = nullptr;
        bordvakje* huidige;
        huidige = ingang;
        bordvakje* volgende;
        for (int i = 0; i < breedte; i++) {
            huidige->buren[6] = vorige;
            if (i != breedte-1) volgende = new bordvakje;
            else volgende = nullptr;
            huidige->buren[2] = volgende;
            vorige = huidige;
            huidige = volgende;
        }
    }

    void bord::vulBord(bordvakje* & wijzer) {
        bordvakje* zetRij;
        bordvakje* zetKolom;
        zetRij = wijzer;
        zetKolom = wijzer;
        for (int i = 0; i < hoogte; i++) {
            for (int j = 0; j < breedte; j++) {
                if ((i == hoogte/2 - 1 && j == breedte/2 - 1) 
                   || (i == hoogte/2 && j == breedte/2))
                    zetKolom->kleur = 'W';
                else if ((i == hoogte/2 - 1 && j == breedte/2) 
                   || (i == hoogte/2 && j == breedte/2 - 1))
                    zetKolom->kleur = 'Z';
                else zetKolom->kleur = '-';
                zetKolom = zetKolom->buren[2];
            }
            zetRij = zetRij->buren[4];
            zetKolom = zetRij;
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
    
    void bord::doeZet(bordvakje* & wijzer, string zet) {
        bordvakje* z = wijzer;
        char speler;
        int rijZet;
        int kolomZet;
        if (zet.length() != 2 
           || !(zet.at(0) >= 'A' && zet.at(0) < 'A' + breedte) 
           || !(zet.at(0) >= 'a' && zet.at(0) < 'a' + breedte)
           || !(zet.at(1) > '0' && zet.at(1) <= '0' + breedte )) {
            cout << "Deze zet is niet geldig... om een zet te doen ty"
                 << "p je de coordinaten in door middel van schaaknot"
                 << "atie, i.e. [A1]." << endl;
        }
        else {
            rijZet = zet.at(1) - '0';
            if (zet.at(0) >= 'a' && zet[0] < 'a' + breedte) {
                kolomZet = zet.at(0) - 'a';
            }
            else {
                kolomZet = zet.at(0) - 'A';
            }
            if (spelerTracker) {
                speler = 'Z';
            }
            else {
                speler = 'W';
            }
            for (int i = 0; i < rijZet; i++) {
                z = z->buren[2];
            }
            for (int j = 0; j < kolomZet; j++) {
                z = z->buren[4];
            }
            z->kleur = speler;
            spelerTracker = !spelerTracker;
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
        //cout << wijzer << endl;
    }