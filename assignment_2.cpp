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
    #include<fstream>
    #include<string>
    using namespace std;

    void info () { 
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


    int invertPin (int pin) {
        int invertedPin = 0;
        for (int p = 0; p < 4; p++) {
            invertedPin = invertedPin * 10 + pin % 10;
            pin = pin / 10;
        }
        return invertedPin;
    }//pincode omdraaien

    int invertNum (int num) {
        int invertedNum = 0;
        while (num > 0) {
            invertedNum = invertedNum * 10 + (num % 10);
            num /= 10;
        }
        return invertedNum;
    }//getallen omdraaien voor Lychrel

    bool checkPin (int pin) {
        if ( pin > 0 && pin < 10000 ) {
            return true;
        }
        else {
            return false;
        }
    }//Controle geldigheid pincode

    bool checkLychrel (int num, int & counter) {
        int storedNum = num;
        int invertedNum = invertNum(num);
        if (num == 0) {
            return false;
        }
        while (storedNum != invertedNum) {
            counter++;
            if (storedNum < INT_MAX / 10 
                && invertedNum < INT_MAX / 10) {
                storedNum += invertedNum;
                invertedNum = invertNum(storedNum);
            }
            else {
                return true;
            }//INTMAX bereikt voor een palindroom gevonden is
        }//Zolang het getal geen palindroom is,
         //getal omkeren en optellen
        return false;
    }//Lychrel-test

    int encryptFile (int pin, ifstream & input, ofstream & output, 
                     bool decrypt = false, bool testing = false) {
        char nextKar = input.get(); //Pakt volgende char uit de stream
        char kar;               //Voor uit te voeren operaties op char
        char decryptedKar;             //Bewerkte char voor decodering
        char nextDecryptedKar;           //Bewerkte volgende char voor 
                                         //getalherkenning

        int pinCount = 0;                   //Houdt de huidige pin bij
        int pinnum = pin;                //counter voor opslag pincode
        
        int foundNum = 0;                 //Slaat gevonden getallen op
        int lastPin = 0;         //Bewaart de laatst gebruikte pincode

        bool encounteredNum = false;  //Geeft aan of een getal bestaat
        bool pinFound = false;     //Geeft aan of er een nieuwe pin is

        char firstKar;            //Opslag variabelen voor 't','h','e'
        char secondKar;
        char lastKar;

        int countThe = 0;             //Houdt de hoeveelheid the's bij

        while (!input.eof()) {
            kar = nextKar;                //Hier worden de volgende te
            nextKar = input.get();        //bewerken karakters ingezet
            
            if (kar == '\r' || kar == '\n') {
                pinnum = pin;
                pinCount = 0;
                if (!testing) {
                    output.put(kar);
                }
                pinFound = false;
            }//carriage return/endline resetten
            else if (kar == '\t') {
                if (!testing) {
                    output.put(kar);
                }
            }//tabs overslaan
            else {
                int currNum;
                if (pinFound) {
                    pinCount++;
                    currNum = lastPin % 10;
                    pinFound = false;
                }//Bewaart de laatst gebruikte pin voor volgende char.
                else {
                    pinCount++;
                    currNum = pinnum % 10;
                }//Houdt de huidige pin bij
                decryptedKar = (kar - currNum + 63) % 95 + 32;
                //Te gebruiken voor vinden van getallen.
                if (!decrypt && !testing) {
                    output.put((kar + currNum - 32) % 95 + 32);
                }
                else if (decrypt && !testing) {
                    output.put(decryptedKar);
                }
                else {
                    firstKar = secondKar;
                    secondKar = lastKar;
                    lastKar = (kar - currNum + 63) % 95 + 32;
                    if ((firstKar == 't' || firstKar == 'T')
                        && (secondKar == 'h' || secondKar == 'H')
                        && (lastKar == 'e' || lastKar == 'E')) {
                        countThe++;
                    }//Houdt gevonden "the's" bij
                }
                if (pinCount == 4) {
                    pinnum = pin;
                    pinCount = 0;
                }//Reset pin indien 4 is berijkt
                else {
                    pinnum /= 10;
                }//Anders delen door 10
                if (kar >= '0' && kar <= '9' && !decrypt) {
                    encounteredNum = true;
                    if ((foundNum < INT_MAX / 10) || 
                        (foundNum == INT_MAX / 10 && 
                        (kar - '0') <= INT_MAX % 10)) {
                        foundNum = foundNum * 10 + (kar - '0');
                    }//Indien het gevonden nummer geen intmax bereikt
                     //Voeg het volgende getal toe
                    else {
                        foundNum = INT_MAX;
                    }//Anders nemen we aan dat het getal intmax is.
                }//Vindt getallen
                if ((nextKar < '0' || nextKar > '9')  
                    && encounteredNum == true && !decrypt) {
                    encounteredNum = false;
                    int counter = 0;      //Houdt het aantal iteraties
                                          //bij voor Lychrel getallen
                    if (checkPin(foundNum)) {
                        lastPin = pinnum;
                        pinnum = invertPin(foundNum);
                        pin = pinnum;
                        pinCount = 3;
                        pinFound = true;
                    }//Kijkt of het getal voldoet als pincode
                    if (!checkLychrel(foundNum, counter)) {
                        cout << "Het getal " << foundNum << " is geen"
                             << " Lychrel getal. Het vormt na " 
                             << counter << " iteraties een palind"
                             << "room." << endl;
                    }//Kijkt of het een Lychrel getal is.
                    else {
                        cout << "Het gevonden getal " << foundNum
                             << " wordt groter dan " << INT_MAX 
                             << " na " << counter << " iteraties zond"
                             << "er een palindroom te vormen en is du"
                             << "s vermoedelijk een Lychrel getal." 
                             << endl;
                    }//Confirmatie van vermoedelijk Lychrel getal
                    foundNum = 0;
                }//Vindt einde van een getal
                if (decryptedKar >= '0' && decryptedKar <= '9' 
                    && decrypt) {
                    encounteredNum = true;
                    int nextPin = pinnum % 10;
                    nextDecryptedKar = ((nextKar - (nextPin % 10)) 
                                        + 63) % 95 + 32;
                    if ((foundNum < INT_MAX / 10) || 
                        (foundNum == INT_MAX / 10 && 
                        (decryptedKar - '0') <= INT_MAX % 10)) {
                        foundNum = foundNum * 10 
                                   + (decryptedKar - '0');
                    }
                    else {
                        foundNum = INT_MAX;
                    }
                }//Dezelfde functie voor het getal bij decoderen
                if ((nextDecryptedKar < '0' || nextDecryptedKar > '9')  
                    && encounteredNum == true && decrypt) {
                    encounteredNum = false;
                    int counter = 0;
                    if (checkPin(foundNum)) {
                        lastPin = pinnum;
                        pinnum = invertPin(foundNum);
                        pin = pinnum;
                        pinCount = 3;
                        pinFound = true;
                    }
                    foundNum = 0;
                }//Vindt einde van het getal bij decoderen
            }
        }//Loop zolang end of file niet bereikt is.
        input.close();
        output.close();
        return countThe;
    }//Functie voor (de)coderen van de file, parameters zijn als volgt
     //pin: te gebruiken voor (de)coderen
     //if-/ofstream, bestand verwijzingen
     //decrypt: true = decoderen, false = coderen
     //testing: voorkomt wegschrijven van karakters voor lostPassword
     //Geeft het aantal "the's" als return value
    
    int lostPassword (string inputname, string outputname) {
        int maxThe = 0;  //Meest bereikte hoeveelheid "The's" in tekst
        int foundPin = 0;                    //De bijbehorende pincode
        for (int i = 0; i <= 9999; i++) {
            ifstream input(inputname);
            ofstream output(outputname);
            int count = encryptFile(invertPin(i), input, output, true,
                                    true);
            if (count > maxThe) {
                maxThe = count;
                foundPin = i;
            }//Wanneer meer "the's" gevonden zijn, wordt de nieuwe pin
        }//Loopt van 0 tot en met 9999 voor vinden van geldige pincode
        ifstream encrypted(inputname);   //Namen voor de uiteindelijke
        ofstream result(outputname);     //In- en uitvoer bestanden
        encryptFile(invertPin(foundPin), encrypted, result, true, 
                    false);
        return foundPin;
    }//Bij verloren pincode

    int main () {
        char toBe;                                   //Welke wordt het
        bool decrypt;       //Wil je coderen(false) of decoderen(true)
        int pincode;                             //Voor invoer pincode
        info();
        cout << "Wilt u een bestand coderen of decoderen? (C/D):  ";
        cin >> toBe;
        if (toBe == 'C' || toBe == 'c') {
            decrypt = false;
        }
        else if (toBe == 'D' || toBe == 'd') {
            decrypt = true;
        }
        else {
            cout << "Dat was geen optie, uit voorzorgsmaatregelen slu"
                 << "it het programma nu af." << endl;
            return 1;
        }//afsluiten bij invoer van foute char
        string inputname;     //Namen voor de in- en uitvoer bestanden
        string outputname;
        cout << "Voer de naam in van het te (de)coderen bestand: ";
        cin >> inputname;
        cout << "Voer de naam in van het doelbestand: ";
        cin >> outputname;
        ifstream input(inputname);     //Openen van betreffende in- en
        ofstream output(outputname);   //uitvoer bestanden
        cout << "Voer een geldige pincode in voor het (de)coderen van"
             << " het bestand, als u uw pincode niet weet, voer dan -"
             << "1 in: ";
        cin >> pincode;
        if (checkPin(pincode)) {
            encryptFile(invertPin(pincode), input, output, decrypt);
        }//Indien pincode geldig is, (de)coderen
        else if (pincode == -1 && decrypt) {
            cout << "De gevonden pincode is: " 
                 << lostPassword(inputname, outputname) << endl;
        }//Niet onthouden? dan deze proberen
        else {
            cout << "Dit is geen geldige optie, uit voorzorgsmaatrege"
                 << "len sluit het programma nu af." << endl;
            return 1;
        }//Dit mag niet
        return 0;
    }//main