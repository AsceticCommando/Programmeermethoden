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
            char kleur;
            bordvakje* buren[8];
            bordvakje();
    };//vakje

    class othellobord {
        private:
            bordvakje* ingang;
            int hoogte;
            int breedte;
        public:
            othellobord();
            ~othellobord();
            void drukaf();
    };