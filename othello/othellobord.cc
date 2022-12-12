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
		spelerTracker = 1;
		speler = 'Z';
    }//constructor voor bord indien niks ingevoerd WIP

    bord::bord(int x, int y) {
        breedte = x;
        hoogte = y;
		spelerTracker = 1;
		speler = 'Z';
    }//Constructor voor het bord.

    bord::~bord() {
		bordvakje* schoonmaker;
		schoonmaker = huidigestand;
		int index = 2;
		while (schoonmaker != nullptr) {
        	bordvakje* verwijderen = schoonmaker;
			if (schoonmaker->buren[index] != nullptr) {
        	    schoonmaker = schoonmaker->buren[index];
				delete verwijderen;
			}
			else {
				index = (index + 2) % 8;
			}
		}
	}//Opgeruimt staat netjes

    char bord::geefSpeler() {
		return speler;
	}//Toegang tot de speler variabele

    void bord::maakRij(bordvakje* & ingang) {
        bordvakje* vorige;          //buren[6] <- [0] -> buren[2]
        vorige = nullptr;           //1. vorige <- huidige -> volgende    
        bordvakje* huidige;         //2. huidige <- volgende -> new
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
    }//Creëert een rij aan pointers mbv dubbelverbonden pointers

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
    }//Maakt het hele bord soortgelijk aan de maakRij functie
	 //pointers hebben hier de volgende structuur (4x4)
	 //|- - - -
	 //|- - - -
	 //|- - - -
	 //|- - - -

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
        }//Verticaal verbinden van nog niet verbonden vakken
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
                    middelste->buren[5] = middelste->buren[4]->buren[6];
                }
                if (middelste->buren[0] != nullptr 
                   && middelste->buren[6] != nullptr) {
                    middelste->buren[7] = middelste->buren[0]->buren[6];
                }
                kolom = kolom->buren[2];
            }
            rij = rij->buren[4];
        }
    }//Pointers zijn nu diagonaal, verticaal en horizontaal aan elkaar
	 //verbonden. (4x4)
	 //|x|x|x|x|
	 //|x|x|x|x|
	 //|x|x|x|x|
	 //|x|x|x|x|

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
    }//Zet alle vakjes volgens de juiste stelling (4x4)
	 //- - - -
	 //- W Z -
	 //- Z W -
	 //- - - -
    
    void bord::burenCheck(bordvakje* & wijzer) {
		bordvakje* zet = wijzer;
		bool zetGevonden = false;
		for (int i = 0; i < 8; i++) {
			bool mogelijk = 0;
			int gevonden = 1;
			zet = zet->buren[i];
            while (zet != nullptr && zet->kleur != speler 
			      && zet->kleur != '-') {
				mogelijk = 1;
                zet = zet->buren[i];
				gevonden++;
			}
			if (zet->kleur == speler && mogelijk) {
				zetGevonden = true;
                int anderekant = (i + 4) % 8;
				cout << i << " " << anderekant << endl;
				for (int j = 0; j <= gevonden; j++) {
                    zet->kleur = speler;
					zet = zet->buren[anderekant];
				}
			}
			zet = wijzer;
		}
		if (zetGevonden) {
			spelerTracker = !spelerTracker;
		}//Zet de speler om
		else {
			cout << "Deze zet is niet mogelijk, een geldige zet sluit"
			     << " stenen van de tegenstander in aan tenminste twe"
				 << "e tegenover liggende zijden." << endl;
		}//Waarschuwt tegen ongeldige zet.
		//else if (computer != speler) {
		//	cout << "Deze zet is niet mogelijk, een geldige zet sluit"
		//	     << " stenen van de tegenstander in aan tenminste twe"
		//		 << "e tegenover liggende zijden." << endl;
		//}
	}//Kijkt de zet na en zet de kleuren om, na het maken van een
	 //Juiste zet krijgt de andere speler de beurt

	void bord::geefBeurt() {
		if (spelerTracker) {
            speler = 'Z';
        }
        else {
            speler = 'W';
        }
	}//Veranderen van speler karakter

    void bord::doeZet(bordvakje* & wijzer, string zet) {
        bordvakje* z = wijzer;
		int beweegI;
		char rijZet;
        char kolomZet;
		int beweegJ;
        if (zet.length() != 2 
           || !((zet.at(0) >= 'A' && zet.at(0) < 'A' + breedte) 
           || (zet.at(0) >= 'a' && zet.at(0) < 'a' + breedte))
           || !(zet.at(1) > '0' && zet.at(1) <= '0' + breedte )) {
            cout << "Deze zet is niet geldig... om een zet te doen ty"
                 << "p je de coordinaten in door middel van schaaknot"
                 << "atie, i.e. [A1]." << endl;
        }
        else {
			kolomZet = zet.at(0);
            rijZet = zet.at(1);
			beweegI = rijZet - '1';
            if (kolomZet >= 'a' && kolomZet < 'a' + breedte) {
                beweegJ = kolomZet - 'a';
            }
            else {
                beweegJ = kolomZet - 'A';
            }
			for (int j = 0; j < beweegJ; j++) {
                z = z->buren[2];
            }
            for (int i = 0; i < beweegI; i++) {
                z = z->buren[4];
            }
            burenCheck(z);
        }
    }//Zet karakters om naar zetbare structuur en validatie

    //void bord::kopieer(stapel* & opslag, bordvakje* wijzer) {
    //    opslag->huidige = new bord(breedte, hoogte);
	//	bordvakje* nieuweWijzer;
	//	opslag->huidige->huidigestand = nieuweWijzer;
	//	opslag->huidige->maakBord(nieuweWijzer);
	//	opslag->huidige->breien(nieuweWijzer);
    //    bordvakje* rijLezer = wijzer;
    //    bordvakje* kolomLezer;
	//	bordvakje* rijPrinter = nieuweWijzer;
	//	bordvakje* kolomPrinter;
    //    while (rijLezer != nullptr) {
    //        kolomLezer = rijLezer;
	//		kolomPrinter = rijPrinter;
    //        while (kolomLezer != nullptr) {
    //            kolomPrinter->kleur = kolomLezer->kleur;
    //            kolomLezer = kolomLezer->buren[2];
	//			kolomPrinter = kolomPrinter->buren[2];
    //        }
    //        rijLezer = rijLezer->buren[4];
	//		kolomPrinter = kolomPrinter->buren[4];
    //    }
	//	opslag->huidige->speler = speler;
	//	opslag->huidige->spelerTracker = spelerTracker;
	//	stapel* nieuweStapel = new stapel;
	//	opslag->volgende = nieuweStapel;
	//	nieuweStapel->vorige = opslag;
	//	opslag = nieuweStapel;
	//}

    void bord::afdrukken(bordvakje* wijzer) {
        int ycoord = 1;
        bordvakje* rij = wijzer;
        bordvakje* kolom;
        cout << endl << "  ";
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
        cout << endl;
    }//Drukt alle pointers in het bord af

	void bord::winnaar(bordvakje* wijzer) {
		float score;
		int wit = 0;
		int zwart = 0;
		int totaal = 0;
		bordvakje* rij = wijzer;
		bordvakje* kolom;
		while (rij != nullptr) {
			kolom = rij;
			while (kolom != nullptr) {
				if (kolom->kleur == 'W') wit++;
				else if (kolom->kleur == 'Z') zwart++;
				totaal++;
				kolom = kolom->buren[2];
			}
			rij = rij->buren[4];
		}
		if (wit > zwart) {
			score = ((float) wit/totaal) * 100;
            cout << "Wit wint met een score van: " << score << "%";
		}
		else if (zwart > wit) {
			score = ((float) zwart/totaal) * 100;
            cout << "Zwart wint met een score van: " << score << "%";
		}
		else {
			cout << "Het is gelijk spel!";
		}
	}//Telt de scores en geeft aan welke speler gewonnen heeft in 
	 //de huidige stand

	//bool bord::gameOver(bordvakje* wijzer) {
	//	bordvakje* rij = wijzer;
	//	bordvakje* kolom;
	//	while (rij != nullptr) {
	//		kolom = rij;
	//		while (kolom != nullptr) {
	//			kolom = kolom->buren[2];
	//		}
	//		rij = rij->buren[4];
	//	}
	//	return true;
	//}