    //Infoblok voor programmeurs
    //Compiler:          g++.exe (Rev1, Built by MSYS2 project) 12.2.0
    //Programmeerpgave:                                              1
    //Gemaakt op:                                           26-09-2022
    //Namen:                   Vijgeboom, Thijs;       Wulffele, Lotte
    //Studentnummers:                   2648261;               3661814
    //Jaar van aankomst:                   2019;                  2022
    //Studierichting:                  Biologie;              Wiskunde
    //Gebruikte IDE:         Visual Studio Code;          Sublime Text
    
    #include <iostream>
    #include <string>
    #include <fstream>
    using namespace std;
    
    //klasse aanmaken
    class Puzzel {
        private:
            bool dewereld[20][20];  // daadwerkelijke MAX ipv 'MAX'; is de bedoeling toch?
            bool oplossing[20][20]; // daadwerkelijke MAX ipv 'MAX'; in de bedoeling toch?
            int hoogte, breedte;
            char aan, uit;
            float percentage;
        public:
            Puzzel() {
                hoogte = 5;
                breedte = 5;
                aan = 'X';
                uit = '.';
                maakSchoon();
            } // constructor
            void drukAf() {
                for (int i = 0; i <= hoogte; i++) {
                    if (i != hoogte)
                        cout << hoogte - i;
                    for (int j = 0; j < breedte; j++) {
                        if (dewereld[i][j] && i != hoogte) {
                            cout << ' ' << aan;
                        }
                        else if (i != hoogte) {
                            cout << ' ' << uit;
                        }
                        else {
                            char letter = 'A' + j;
                            cout << ' ' << letter;
                        }
                    }// for j
                    cout << endl;
                }
                // for i
            }// functie drukaf
            void losOp() {
                for (int i = 0; i < hoogte; i++) {
                    for (int j = 0; j < breedte; j++) {
                        if (oplossing[i][j])
                            cout << ' ' << aan;
                        else
                            cout << ' ' << uit;
                    }// for j
                    cout << endl;
                } // for i
            }
            void vulRandom() {
                
            }
            void maakSchoon() {
                for (int i = 0; i < hoogte; i++) {
                    for (int j = 0; j < breedte; j++) {
                        dewereld[i][j] = false;
                    }
                }
            }
            void zetPercentage() {
                int correct = 0;
                for (int i = 0; i < hoogte; i++) {
                    for (int j = 0; j < breedte; j++) {
                        if (dewereld[i][j] == oplossing[i][j]) {
                            correct++; 
                        }
                    }
                }
                percentage = (float)correct/(hoogte*breedte);
            }
            void zetParameters() {
                cout << "U kunt hier uw eigen parameters kiezen:" << endl;
                cout << "Type als geheel getal (2-20) de door uw gewenste breedte van het speelvlak in." << endl;
                cin >> breedte;
                cout << "Type als geheel getal (2-20) de door uw gewenste hoogte van het speelvlak in." << endl;
                cin >> hoogte;
                cout << "Welk symbool wilt u gebruiken voor een lampje dat uit is?" << endl;
                cin >> uit;
                cout << "Welk symbool wilt u gebruiken voor een lampje dat aan is?" << endl;
                cin >> aan;
                maakSchoon();
                // vraag en invoer fietsband-optie of gewoon speelveld (j/n)
                // een pen (0/1/2) 0: bij lopen blijven lampen gelijk 1: lopen doet lampen aan 2: lopen doet lampen uit
            }
            void doeZet(string zet, bool & gevonden) {
                char letter = zet[0];
                char nummer = zet[1];
                if ((letter >= 'A' && letter < 'A' + breedte) && (nummer > '0' && nummer <= '0' + hoogte)) {
                    int posi = ('0' + hoogte - nummer);
                    int posj = letter - 'A';
                    cout << posi << " " << posj << endl;
                    for (int i = -1; i <= 1; i++) {
                        for (int j = -1; j <= 1; j++) {
                            if ((posi + i >= 0 && posi + i <= breedte - 1) && (posj + j >= 0 && posj + j <= hoogte - 1) && (i == 0 || j == 0)) {
                                cout << posi + i << " " << posj + j << endl;
                                char ervoor = dewereld[posi + i][posj + j];
                                cout << "Dit is ervoor: "<< ervoor << " ";
                                dewereld[posi + i][posj + j] = !dewereld[posi + i][posj + j];
                                char erna = dewereld[posi + i][posj + j];
                                cout << "Dit is erna: " << erna << endl;
                            }
                        }
                    }
                    gevonden = true;
                }
                else {
                    cout << "Deze zet is niet geldig. Gebruik schaaknotatie om een zet te doen (i.e. [A1])." << endl;
                }
            }

            // functie stoppen
            //  programma sluit af
            
            // functie terug
            // stuurt gebruiker terug naar hoofdmenu
            
            // functie maakschoon
            // alle lampen van het speelveld gaan uit
            
            // functie random
            // speelveld wordt random gevult door willekeurige lampen aan en uit te doen; hoeft geen oplosbare puzzel op te leveren
            
            // functie toggle
            // laat aan lampje uit, en uit lampje aan gaan
            // is geen zet!! enkel het lampje zelf reageerd
            
            // functie genereer
            // geen functie op ingevoerde getal uit te voeren
    };
    
    // submenu Parameters
    int genereerSpeelveld() {
        int g;
        cout << "Kies uw moeilijkheidsgraad. Gelieve een geheel, positief getal in te voeren." << endl;
        cin >> g;
        return g;
    }
    
    // functie oplossen
    // lost 5x5 functie op
    // aantal gedane zetten en lampjes die aan zijn afdrukken naast speelveld
    
    // functie leesGetal
    int getal = 0;
    void leesGetal() {
        char x = cin.get();
        while (x == '\n') {
            x = cin.get(); // naar volgende char bij \n
        }
        while (x < '0' || x > '9') {
            x = cin.get(); // naar volgende char bij niet-getal
        }
        while (getal < 1000 && 0 > x && x < 9) { // checken of getal niet boven de bovengrens komt vinden en returnen getal achtereenvolgende nummers
            getal = (getal * 10) + x;              // getal vormen
            x = cin.get();
        }
        while (x > -1 && x < 10) {
            x = x * 10;
            getal = x;
            x = cin.get();
        }
    }
    
    // functie random getal
    //  geeft random getal tussen 0 en 999
    int randomgetal() {
        static int getal = 42;
        getal = (221 * getal + 1) % 1000;
        return getal;
    } // randomgetal

    // submenu tekenen
    void tekenMenu() { // moet ongetwijfeld geen 'int' zijn, maar welke functie wel?
        char choice;
        bool back = false;
        while (!back) {
            cout << "[T]erug, s[C}hoon, [R]andom, t[O]ggle, [G]enereer" << endl;
            cout << "Gebruik [WASD] om de cursor te bewegen." << endl;
            cin >> choice;
            switch (choice) {
                case 'T': case 't':
                    back = true;
                    break;
                case 'W': case 'w':
                    //omhoog
                case 'A': case 'a':
                    //links
                case 'S': case 's':
                    //omlaag
                case 'D': case 'd':
                    //rechts
                case 'C': case 'c':
                    cout << "schoon" << endl;
                case 'R': case 'r':
                    cout << "random" << endl;
                case 'O': case 'o':
                    cout << "toggle" << endl;
                case 'G': case 'g':
                    cout << "genereer" << endl;
            }
        }
    }
    
    // submenu puzzelen
    void puzzelMenu(Puzzel mijnPuzzel) {
        char choice;
        bool back = false;
        while (!back) {
            mijnPuzzel.drukAf();
            cout << "[T]erug, [V]olg, [O]plossen van 5x5 puzzel, [A]fspelen oplossing, [Z]et doen" << endl;
            cin >> choice;
            switch (choice) {
                case 'T': case 't':
                    back = true;
                    break;
                case 'V': case 'v':
                    //volg
                case 'O': case 'o':
                    //los op
                case 'A': case 'a':
                    //los op en laat zien
                case 'Z': case 'z':
                    cout << "Doe een zet doormiddel van schaaknotatie (i.e. [A1])." << endl;
                    char z;
                    bool gevonden = false;
                    while (!gevonden) {
                        string zet;
                        while(zet.size() < 2) {
                            cin >> z;
                            zet += z;
                        }
                        mijnPuzzel.doeZet(zet, gevonden);
                    }
                    
                    //doe een zet
            }
        }
    }

    void menu() {
        Puzzel mijnPuzzel;
        char choice;
        bool exit = false;
        while (!exit) {
            cout << "[T]ekenen, p[U]zzelen, [P]arameters, [S]toppen" << endl;
            cin >> choice;
            switch (choice) {
                case 'T': case 't':
                    tekenMenu();
                    break;
                case 'U': case 'u':
                    puzzelMenu(mijnPuzzel);
                    break;
                case 'P': case 'p':
                    mijnPuzzel.zetParameters();
                    break;
                case 'S': case 's':
                    exit = true;
                    break;
            }
        }
    }

    int main() {
        menu();
        return 0;
    }