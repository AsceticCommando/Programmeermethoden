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
            bool torus;
            int pen;
        public:
            Puzzel() {
                hoogte = 5;
                breedte = 5;
                aan = 'X';
                uit = '.';
                maakSchoon();
            } // constructor
            void vulRandom();
            void zetParameters();
            int pakHoogte() {
                return hoogte;
            }
            int pakBreedte() {
                return breedte;
            }
            void schakel(int i, int j) {
                dewereld[i][j] = !dewereld[i][j];
            }

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

            void maakSchoon() {
                for (int i = 0; i < hoogte; i++) {
                    for (int j = 0; j < breedte; j++) {
                        dewereld[i][j] = false;
                    }
                }
            }

            void zetPercentage(int per) {
                percentage = (float)per/100;
            }
            bool doeZet(string zet) {
                char letter = zet.begin();
                zet.erase(0, 1);
                int nummer = leesGetal(zet);
                if ((letter >= 'A' && letter < 'A' + breedte) 
                    && (nummer > '0' && nummer <= '0' + hoogte)) {
                    int posi = ('0' + hoogte - nummer);
                    int posj = letter - 'A';
                    for (int i = -1; i <= 1; i++) {
                        for (int j = -1; j <= 1; j++) {
                            if ((posi + i >= 0 
                                && posi + i <= breedte - 1) 
                                && (posj + j >= 0 
                                && posj + j <= hoogte - 1) 
                                && (i == 0 || j == 0)) {
                                dewereld[posi + i][posj + j] = 
                                !dewereld[posi + i][posj + j];
                            }
                        }
                    }
                    return true;
                }
                else {
                    cout << "Deze zet is niet geldig. Gebruik schaakn"
                         << "otatie om een zet te doen (i.e. [A1])." 
                         << endl;
                    return false;
                }
            }

            void volg() {
                string verdeler(breedte*2+1, '-');
                cout << verdeler << endl;
                for (int i = hoogte - 1; i > 0; i--) {
                    for (int j = 0; j < breedte; j++) {
                        if (dewereld[hoogte - 1 - i][j]) {
                            string zet;
                            zet += ('A' + j);
                            zet += ('0' + i);
                            doeZet(zet);
                            drukAf();
                        }
                    }
                }
                cout << verdeler << endl;
            }
            
            void losOp() {
                if (breedte == 5 && hoogte == 5) {
                    volg();
                    while(percentage != (float)1) {
                        string rij;
                        for (int i = 0; i < breedte; i++) {
                            if (dewereld[4][i]) {
                                rij += ('0' + i);
                            }
                        }
                        if (rij == "34") {
                            doeZet("B5");
                        }
                        else if (rij == "2") {
                            doeZet("C5");
                        }
                        else if (rij == "14") {
                            doeZet("E5");
                        }
                        else if (rij == "123") {
                            doeZet("A5");
                            doeZet("B5");
                        }
                        else if (rij == "03") {
                            doeZet("A5");
                        }
                        else if (rij == "024") {
                            doeZet("A5");
                            doeZet("D5");
                        }
                        else if (rij == "01") {
                            doeZet("D5");
                        }
                        else {
                            cout << "Er is geen mogelijke oplossing gevonden." << endl;
                            break;
                        }
                        volg();
                    }
                }
                else {
                    cout << "Zet de hoogte en breedte op 5x5 om deze functie te gebruiken." << endl;
                }
            }
            // functie stoppen
            //  programma sluit af
            
            // functie terug
            // stuurt gebruiker terug naar hoofdmenu
            
            // functie maakschoon
            // alle lampen van het speelveld gaan uit
            
            // functie random
            // speelveld wordt random gevult door willekeurige lampen 
            //aan en uit te doen; hoeft geen oplosbare puzzel op 
            //te leveren
            
            // functie toggle
            // laat aan lampje uit, en uit lampje aan gaan
            // is geen zet!! enkel het lampje zelf reageerd
            
            // functie genereer
            // geen functie op ingevoerde getal uit te voeren
    };
    
    bool afsluiten = false;
    
    void sluitAf(bool & terug) {
        terug = true;
        afsluiten = true;
    }
    void Puzzel::zetParameters() {
        bool terug = false;
        cout << "U kunt hier uw eigen parameters kiezen:" 
             << endl;
        cout << "[T]erug, [B]reedte, [H]oogte, [P]ercentage, [A]an, [U]it, [T]orus, [P]en, a[F]sluiten"
             << endl;
        char keuze = cin.get()
        while (!terug) {
            switch(keuze) {
                case 'T': case 't':
                    terug = true;
                    break;
                case 'B': case 'b':
                    Puzzel::breedte =
                    break;
                case 'H': case 'h':
                    Puzzel::hoogte =
                    break;
                case 'P': case 'p':
                    Puzzel::percentage =
                    break;
                case 'A': case 'a':
                    Puzzel::aan =
                    break;
                case 'U': case 'u':
                    Puzzel::uit =
                    break;
                case 'T': case 't':
                    Puzzel::torus =
                    break;
                case 'P': case 'p':
                    Puzzel::pen =
                    break;
                case 'F': case 'f':
                    sluitAf(terug);
                    break;
            }
    //vraag en invoer fietsband-optie of gewoon speelveld
    //een pen (0/1/2) 0: bij lopen blijven lampen gelijk 
    //1: lopen doet lampen aan 2: lopen doet lampen uit
        }
    }
    // functie random getal
    //  geeft random getal tussen 0 en 999
    long randomgetal() {
        static long getal = 42;
        getal = (221 * getal + 1) % 1000;
        return getal;
    }// randomgetal
    void Puzzel::vulRandom() {
        maakSchoon();
        for (int i = 0; i < hoogte; i++) {
            for (int j = 0; j < breedte; j++) {
                if (randomgetal() >= Puzzel::percentage) {
                    dewereld[i][j] = true;
                }
            }
        }
    }

    void info() { 
        cout << "+---------------------------------------------------"
             << "---+" << endl << "| Programmeermethoden; tweede prog"
             << "rammeeropgave        |" << endl << "| Gemaakt op;   "
             << "       17-10-2022                      |" << endl
             << "| Gemaakt door:      Thijs Vijgeboom en Lotte Wulffe"             
             << "le |" << endl << "| Studentnummers:    2648261      " 
             << "      3661814        |" << endl << "| Jaar van aanko"
             << "mst: 2019               2022           |" << endl
             << "| Studierichting:    Biologie           Wiskunde    "
             << "   |" << endl << "+---------------------------------"
             << "---------------------+" << endl << endl << "Goedenda"
             << "g; u heeft een programma opgestart dat zowel voor co" 
             << "deren als voor decoderen kan worden"
             << " gebruikt." << endl << "Zo"
             << " zal ik u wat vragen stellen om helder te krijgen "
             << "wat u van mij verwacht" << endl << "Wat u van mij ku"
             << "nt verwachten?" << endl << "Ik zal coderen, decodere"
             << "n, verloren pincodes terugzoeken en u Lachrel-gerela"
             << "teerde informatie verschaffen omtrent getallen die i"
             << "n ene te coderen bestand voorkomen." << endl << "Wel"
             << "kom!" << endl << endl;
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

    // submenu tekenen
    void tekenMenu(Puzzel & mijnPuzzel) { // moet ongetwijfeld geen 'int' zijn, maar welke functie wel?
        char keuze;
        int cursorx = 0;
        int cursory = 0;
        bool terug = false;
        while (!terug) {
            mijnPuzzel.drukAf();
            cout << "[T]erug, s[C]hoon, [R]andom, t[O]ggle, [G]enereer, a[F]sluiten" << endl;
            cout << "Gebruik [WASD] en [ENTER] om de cursor te bewegen." << endl;
            cout << "Uw cursor staat op: " << (char)('A' + cursorx) << mijnPuzzel.pakHoogte() - cursory
                 << endl;
            keuze = cin.get();
            switch (keuze) {
                case 'T': case 't':
                    terug = true;
                    break;
                case 'W': case 'w':
                    if (mijnPuzzel.pakHoogte() - cursory < mijnPuzzel.pakHoogte()) {
                        cursory--;
                    }
                    break;
                    //omhoog
                case 'A': case 'a':
                    if (cursorx > 0) {
                        cursorx--;
                    }
                    break;
                    //links
                case 'S': case 's':
                    if (cursory < mijnPuzzel.pakHoogte() - 1) {
                        cursory++;
                    }
                    break;
                    //omlaag
                case 'D': case 'd':
                    if (cursorx < mijnPuzzel.pakBreedte() - 1) {
                        cursorx++;
                    }
                    break;
                    //rechts
                case 'C': case 'c':
                    mijnPuzzel.maakSchoon();
                    break;
                case 'R': case 'r':
                    mijnPuzzel.vulRandom();
                    break;
                case 'O': case 'o':
                    mijnPuzzel.schakel(cursory, cursorx);
                    break;
                case 'G': case 'g':
                    cout << "genereer" << endl;
                    break;
                case 'F': case 'f':
                    sluitAf(terug);
                    break;
            }
        }
    }
    
    // submenu puzzelen
    void puzzelMenu(Puzzel & mijnPuzzel) {
        char choice;
        bool terug = false;
        while (!terug) {
            mijnPuzzel.drukAf();
            cout << "[T]erug, [V]olg, [O]plossen van 5x5 puzzel, [A]fspelen oplossing, [Z]et doen, a[F]sluiten" << endl;
            cin >> choice;
            switch (choice) {
                case 'T': case 't':
                    terug = true;
                    break;
                case 'V': case 'v':
                    mijnPuzzel.volg();
                    break;
                    //volg
                case 'O': case 'o':
                    mijnPuzzel.losOp();
                    break;
                    //los op
                case 'A': case 'a':
                    break;
                    //los op en laat zien
                case 'F': case 'f':
                    sluitAf(terug);
                    break;
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
                        gevonden = mijnPuzzel.doeZet(zet);
                    }
                    break;
                    //doe een zet
            }
        }
    }

    void menu() {
        Puzzel mijnPuzzel;
        char choice;
        while (!afsluiten) {
            cout << "[T]ekenen, p[U]zzelen, [P]arameters, a[F]sluiten" << endl;
            cin >> choice;
            switch (choice) {
                case 'T': case 't':
                    tekenMenu(mijnPuzzel);
                    break;
                case 'U': case 'u':
                    puzzelMenu(mijnPuzzel);
                    break;
                case 'P': case 'p':
                    mijnPuzzel.zetParameters();
                    break;
                case 'F': case 'f':
                    afsluiten = true;
                    break;
            }
        }
    }

    int main() {
        menu();
        return 0;
    }