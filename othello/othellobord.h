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
        public:
            char kleur;                                        //7 0 1
            bordvakje* buren[8];                               //6   2
            bordvakje();                                       //5 4 3
    };//vakje

    class bord {
        private:
            bordvakje* wijzer;
        public:
            bord();
            ~bord();
            void maakRij(bordvakje* & wijzer, int breedte);
            void maakBord(bordvakje* & wijzer, int breedte, int hoogte);
            void breien(bordvakje* & wijzer);
            void vulBord();
            void afdrukken(bordvakje* wijzer); 
    };