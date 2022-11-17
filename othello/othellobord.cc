    //Infoblok voor programmeurs
    //Compiler:          g++.exe (Rev1, Built by MSYS2 project) 12.2.0
    //Programmeerpgave:                                              1
    //Gemaakt op:                                           26-09-2022
    //Namen:                   Vijgeboom, Thijs;       Wulffele, Lotte
    //Studentnummers:                   2648261;               3661814
    //Jaar van aankomst:                   2019;                  2022
    //Studierichting:                  Biologie;              Wiskunde
    //Gebruikte IDE:         Visual Studio Code;          Sublime Text
    
    #include<othellobord.h>

    void zetervoor (char letter, vakje* & ingang) {
        vakje *p;
        p = new vakje;
        p -> info = letter;
        p -> volgende = ingang;
        ingang = p; // en niet 'p' deleten
    }//zetervoor

    void laatsteVakje() {
        vakje* ingang;
        ingang = new vakje;
        ingang -> info = '.';
        ingang -> volgende = nullptr;
    }//basisstructuur, pointer