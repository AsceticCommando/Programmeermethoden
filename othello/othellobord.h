    //Infoblok voor programmeurs
    //Compiler:          g++.exe (Rev1, Built by MSYS2 project) 12.2.0
    //Programmeerpgave:                                              1
    //Gemaakt op:                                           26-09-2022
    //Namen:                   Vijgeboom, Thijs;       Wulffele, Lotte
    //Studentnummers:                   2648261;               3661814
    //Jaar van aankomst:                   2019;                  2022
    //Studierichting:                  Biologie;              Wiskunde
    //Gebruikte IDE:         Visual Studio Code;          Sublime Text

    class bordvakje {
        public:		                                       	   //7 0 1
            char kleur;                                        //6   2
            bordvakje* buren[8];                               //5 4 3
    };//vakje

    class bord {
        private:
		    bool spelerTracker = 1;
			bordvakje huidigestand;
			bord* vorigebeurt;
			bord* volgendebeurt;
            int breedte;
            int hoogte;
        public:
            bord();
            bord(int x, int y);
            ~bord();
            void maakRij(bordvakje* & ingang);
            void maakBord(bordvakje* & wijzer);
            void breien(bordvakje* & wijzer);
            void vulBord(bordvakje* & wijzer);
            void afdrukken(bordvakje* wijzer);
			void doeZet(bordvakje* & wijzer, string zet);
    };