    //Infoblok voor programmeurs
    //Compiler:          g++.exe (Rev1, Built by MSYS2 project) 12.2.0
    //Programmeerpgave:                                              1
    //Gemaakt op:                                           26-09-2022
    //Namen:                   Vijgeboom, Thijs;       Wulffele, Lotte
    //Studentnummers:                   2648261;               3661814
    //Jaar van aankomst:                   2019;                  2022
    //Studierichting:                  Biologie;              Wiskunde
    //Gebruikte IDE:         Visual Studio Code;          Sublime Text

    //class bord;

    class bordvakje {
        public:		                                       	   //7 0 1
            char kleur;                                        //6   2
            bordvakje* buren[8];                               //5 4 3
    };//vakje

	//class stapel {
    //	public:
    //	    bord* huidige;
	//		stapel* vorige;
	//		stapel* volgende;
    //};

    class bord {
        private:
		    char computer;
		    char speler;
		    bool spelerTracker;
            int breedte;
            int hoogte;
        public:
			bordvakje* huidigestand;
            bord();
            bord(int x, int y);
            ~bord();
			char geefSpeler();
			void geefBeurt();
            void maakRij(bordvakje* & ingang);
            void maakBord(bordvakje* & wijzer);
            void breien(bordvakje* & wijzer);
            void vulBord(bordvakje* & wijzer);
			bool burenCheck(bordvakje* & wijzer);
			void doeZet(bordvakje* & wijzer, std::string zet);
			//void kopieer(stapel* & opslag, bordvakje* wijzer);
			void afdrukken(bordvakje* wijzer);
			bool gameOver(bordvakje* wijzer);
			void winnaar(bordvakje* wijzer);
    };