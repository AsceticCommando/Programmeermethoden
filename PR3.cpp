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
    
    bool afsluiten = false;
    int leesGetal() {
        int getal = 0;
        char x = cin.get();
        while (x == '\n') {
            x = cin.get(); // naar volgende char bij \n
        }
        while (x < '0' || x > '9') {
            x = cin.get(); // naar volgende char bij niet-getal
        }
        while (getal < 1000 && x > '0' && x < '9') {
            getal = (getal * 10) + (x - '0');
            x = cin.get();
        }//checken of het niet boven de bovengrens komt vinden en
         //returnen getal achtereenvolgende nummers
        return getal;
    }//functie random getal
     //geeft random getal tussen 0 en 999
    long randomgetal() {
        static long getal = 42;
        getal = (221 * getal + 1) % 1000;
        return getal;
    }// randomgetal
    void sluitAf(bool & terug) {
        terug = true;
        afsluiten = true;
    }//functie stoppen
     //programma sluit af

    //klasse aanmaken
    class Puzzel {
        private:
            bool dewereld[20][20];  // daadwerkelijke MAX ipv 'MAX'; is de bedoeling toch?
            bool oplossing[20][20]; // daadwerkelijke MAX ipv 'MAX'; in de bedoeling toch?
            int hoogte, breedte;
            char aan, uit;
            float percentage;
            int pen;
        public:
            Puzzel() {
                hoogte = 5;
                breedte = 5;
                aan = 'X';
                uit = '.';
                percentage = 50;
                pen = 0;
                maakSchoon();
            } // constructor
            int pakPen() {
                return pen;
            }
            int pakHoogte() {
                return hoogte;
            }
            int pakBreedte() {
                return breedte;
            }
            void zetParameters() {
                bool terug = false;
                cout << "U kunt hier uw eigen parameters kiezen:" 
                     << endl;
                char keuze;
                while (!terug) {
                    cout << "[T]erug, [B]reedte, [H]oogte, [P]ercenta"
                         << "ge, [A]an, [U]it, p[E]n, a[F]sluiten"
                         << endl;
                    keuze = cin.get();
                    while (keuze == '\n') {
                        keuze = cin.get();
                    }
                    switch(keuze) {
                        case 'T': case 't':
                            terug = true;
                            break;
                        case 'B': case 'b': {
                            cout << "Voer een nieuwe breedte in"
                                 << " (2-20)" << endl;
                            int nieuweBreedte = leesGetal();
                            if (nieuweBreedte <= 20 && nieuweBreedte >= 2) {
                                breedte = nieuweBreedte;
                            }
                            break;
                        }
                        case 'H': case 'h': {
                            cout << "Voer een nieuwe hoogte in (2-20)"
                                 << endl;
                            int nieuweHoogte = leesGetal();
                            if (nieuweHoogte <= 20 && nieuweHoogte >= 2) {
                                hoogte = nieuweHoogte;
                            }
                            break;
                        }
                        case 'P': case 'p': {
                            cout << "Voer in welk percentage u wilt g"
                                 << "ebruiken voor de random functie "
                                 << "(0-100)" << endl;
                            int nieuwePerc = leesGetal();
                            if (nieuwePerc <= 100 
                                && nieuwePerc >= 0) {
                                percentage = nieuwePerc;
                            }
                            break;
                        }
                        case 'A': case 'a':
                            aan = cin.get();
                            break;
                        case 'U': case 'u':
                            uit = cin.get();
                            break;
                        case 'E': case 'e': {
                            int nieuwePen = leesGetal();
                            if (nieuwePen >= 0 && nieuwePen <= 2) {
                                pen = nieuwePen;
                            }
                            break;
                        }
                        case 'F': case 'f':
                            sluitAf(terug);
                            break;
                    }
            //vraag en invoer fietsband-optie of gewoon speelveld
            //een pen (0/1/2) 0: bij lopen blijven lampen gelijk 
            //1: lopen doet lampen aan 2: lopen doet lampen uit
                }
            }
            void vulRandom() {
                maakSchoon();
                for (int i = 0; i < hoogte; i++) {
                    for (int j = 0; j < breedte; j++) {
                        if (randomgetal() + 1 < percentage * 10) {
                            dewereld[i][j] = true;
                        }
                    }
                }
            }// functie random
             // speelveld wordt random gevult door willekeurige lampen 
             //aan en uit te doen; hoeft geen oplosbare puzzel op 
             //te leveren
            void schakel(int i, int j) {
                dewereld[i][j] = !dewereld[i][j];
            }// functie toggle
             // laat aan lampje uit, en uit lampje aan gaan
             // is geen zet!! enkel het lampje zelf reageerd
            void teken(int i, int j, bool stat) {
                dewereld[i][j] = stat;
            }//alternatieve functie voor aan- en uitzetten lampje        
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
            }// functie maakschoon
             // alle lampen van het speelveld gaan uit
            bool doeZet(string zet) {
                char letter = zet[0];
                zet.erase(0, 1);
                int nummer = 0;
                while (zet.size() != 0) {
                    nummer = nummer * 10 + (zet[0] - '0');
                    zet.erase(0, 1);
                }
                if ((letter >= 'A' && letter < 'A' + breedte) 
                    && (nummer > 0 && nummer <= hoogte)) {
                    int posi = (hoogte - nummer);
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
                            cout << "Er is geen mogelijke oplossing g"
                                 << "evonden." << endl;
                            break;
                        }
                        volg();
                    }
                }
                else {
                    cout << "Zet de hoogte en breedte op 5x5 om deze "
                         << "functie te gebruiken." << endl;
                }
            }// functie oplossen
             // lost 5x5 functie op
            
            // functie genereer
            // geen functie op ingevoerde getal uit te voeren
    };

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

    
    // aantal gedane zetten en lampjes die aan zijn afdrukken naast 
    //speelveld
    
    // functie leesGetal

    // submenu tekenen
    void tekenMenu(Puzzel & mijnPuzzel) {
        char keuze;
        int cursorx = 0;
        int cursory = 0;
        bool terug = false;
        while (!terug) {
            mijnPuzzel.drukAf();
            cout << "[T]erug, s[C]hoon, [R]andom, t[O]ggle, [G]eneree"
                 << "r, a[F]sluiten" << endl;
            cout << "Gebruik [WASD] en [ENTER] om de cursor te bewege"
                 << "n." << endl;
            cout << "Uw cursor staat op: " << (char)('A' + cursorx) 
                 << mijnPuzzel.pakHoogte() - cursory << endl;
            keuze = cin.get();
            while (keuze == '\n') {
                keuze = cin.get();
            }
            switch (keuze) {
                case 'T': case 't':
                    terug = true;
                    break;
                case 'W': case 'w':
                    if (mijnPuzzel.pakHoogte() 
                        - cursory < mijnPuzzel.pakHoogte()) {
                        cursory--;
                        if (mijnPuzzel.pakPen() == 1) {
                            mijnPuzzel.teken(cursory, cursorx, true);
                        }
                        else if (mijnPuzzel.pakPen() == 2) {
                            mijnPuzzel.teken(cursory, cursorx, false);
                        }
                    }
                    break;
                    //omhoog
                case 'A': case 'a':
                    if (cursorx > 0) {
                        cursorx--;
                        if (mijnPuzzel.pakPen() == 1) {
                            mijnPuzzel.teken(cursory, cursorx, true);
                        }
                        else if (mijnPuzzel.pakPen() == 2) {
                            mijnPuzzel.teken(cursory, cursorx, false);
                        }
                    }
                    break;
                    //links
                case 'S': case 's':
                    if (cursory < mijnPuzzel.pakHoogte() - 1) {
                        cursory++;
                        if (mijnPuzzel.pakPen() == 1) {
                            mijnPuzzel.teken(cursory, cursorx, true);
                        }
                        else if (mijnPuzzel.pakPen() == 2) {
                            mijnPuzzel.teken(cursory, cursorx, false);
                        }
                    }
                    break;
                    //omlaag
                case 'D': case 'd':
                    if (cursorx < mijnPuzzel.pakBreedte() - 1) {
                        cursorx++;
                        if (mijnPuzzel.pakPen() == 1) {
                            mijnPuzzel.teken(cursory, cursorx, true);
                        }
                        else if (mijnPuzzel.pakPen()) {
                            mijnPuzzel.teken(cursory, cursorx, false);
                        }
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
        char keuze;
        bool terug = false;
        while (!terug) {
            mijnPuzzel.drukAf();
            cout << "[T]erug, [V]olg, [O]plossen van 5x5 puzzel, [A]f"
                 << "spelen oplossing, [Z]et doen, a[F]sluiten" 
                 << endl;
            keuze = cin.get();
            while (keuze == '\n') {
                keuze = cin.get();
            }
            switch (keuze) {
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
                case 'Z': case 'z': {
                    cout << "Doe een zet doormiddel van schaaknotatie"
                         << " (i.e. [A1])." << endl;
                    string zet;
                    char z = cin.get();
                    int n = 0;
                    while (z == '\n') {
                        z = cin.get();
                    }
                    while (z >= 'A' && z <= 'Z') {
                        zet += z;
                        z = cin.get();
                    }
                    while (z >= '0' && z <= '9' && n <= 20) {
                        zet += z;
                        n = n * 10 + (z - '0');
                        z = cin.get();
                    }
                    mijnPuzzel.doeZet(zet);
                    break;
                }
            }
        }
    }

    void menu() {
        Puzzel mijnPuzzel;
        char keuze;
        while (!afsluiten) {
            cout << "[T]ekenen, p[U]zzelen, [P]arameters, a[F]sluiten"
                 << endl;
            keuze = cin.get();
            while (keuze == '\n') {
                keuze = cin.get();
            }
            switch (keuze) {
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