    #include<iostream>
    #include<fstream>
    #include<string>
    using namespace std;

    int invertPin (int pin) {
        int invertedPin = 0;
        for (int p = 0; p < 4; p++) {
            invertedPin = invertedPin * 10 + pin % 10;
            pin = pin / 10;
        }
        return invertedPin;
    }

    int invertNum (int num) {
        int invertedNum = 0;
        while (num > 0) {
            invertedNum = invertedNum * 10 + (num % 10);
            num /= 10;
        }
        return invertedNum;
    }

    bool checkPin (int pin) {
        if ( pin > 0 && pin < 10000 ) {
            return true;
        }
        else {
            return false;
        }
    }

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
            }
        }
        return false;
    }

    int encryptFile (int pin, ifstream & input, ofstream & output, 
                     bool decrypt = false, bool testing = false) {
        char nextKar = input.get();
        char kar;
        char decryptedKar;
        char nextDecryptedKar;

        int pinCount = 0;
        int pinnum = pin;
        
        int foundNum = 0;
        int lastPin = 0;

        bool encounteredNum = false;
        bool pinFound = false;

        char firstKar;
        char secondKar;
        char lastKar;

        int countThe = 0;

        while (!input.eof()) {
            kar = nextKar;
            nextKar = input.get();
            
            if (kar == '\r' || kar == '\n') {
                pinnum = pin;
                pinCount = 0;
                if (!testing) {
                    output.put(kar);
                }
                pinFound = false;
            }
            else if (kar == '\t') {
                if (!testing) {
                    output.put(kar);
                }
            }
            else {
                int currNum;
                if (pinFound) {
                    pinCount++;
                    currNum = lastPin % 10;
                    pinFound = false;
                }
                else {
                    pinCount++;
                    currNum = pinnum % 10;
                }
                decryptedKar = (kar - currNum + 63) % 95 + 32;
                if (!decrypt && !testing) {
                    output.put((kar + currNum - 32) % 95 + 32);
                }
                else if (decrypt && !testing) {
                    output.put((kar - currNum + 63) % 95 + 32);
                }
                else {
                    firstKar = secondKar;
                    secondKar = lastKar;
                    lastKar = (kar - currNum + 63) % 95 + 32;
                    if ((firstKar == 't' || firstKar == 'T')
                        && (secondKar == 'h' || secondKar == 'H')
                        && (lastKar == 'e' || lastKar == 'E')) {
                        countThe++;
                    }
                }
                if (pinCount == 4) {
                    pinnum = pin;
                    pinCount = 0;
                }
                else {
                    pinnum /= 10;
                }
                if (kar >= '0' && kar <= '9' && !decrypt) {
                    encounteredNum = true;
                    if ((foundNum < INT_MAX / 10) || 
                        (foundNum == INT_MAX / 10 && 
                        (kar - '0') <= INT_MAX % 10)) {
                        foundNum = foundNum * 10 + (kar - '0');
                    }
                    else {
                        foundNum = INT_MAX;
                    }
                }
                if ((nextKar < '0' || nextKar > '9')  
                    && encounteredNum == true && !decrypt) {
                    encounteredNum = false;
                    int counter = 0;
                    if (checkPin(foundNum)) {
                        lastPin = pinnum;
                        pinnum = invertPin(foundNum);
                        pin = pinnum;
                        pinCount = 3;
                        pinFound = true;
                    }
                    if (!checkLychrel(foundNum, counter)) {
                        cout << "Het getal " << foundNum << " is geen"
                             << " Lychrel getal. Het vormt na " 
                             << counter << " iteraties een palind"
                             << "room." << endl;
                    }
                    else {
                        cout << "Het gevonden getal " << foundNum
                             << " wordt groter dan " << INT_MAX 
                             << " na " << counter << " iteraties zond"
                             << "er een palindroom te vormen en is du"
                             << "s vermoedelijk een Lychrel getal." 
                             << endl;
                    }
                    foundNum = 0;
                }
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
                }
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
                }
            }
        }
        input.close();
        output.close();
        return countThe;
    }
    
    int lostPassword (string inputname, string outputname) {
        int maxThe = 0;
        int foundPin = 0;
        for (int i = 0; i <= 9999; i++) {
            ifstream input(inputname);
            ofstream output(outputname);
            int count = encryptFile(invertPin(i), input, output, true,
                                    true);
            if (count > maxThe) {
                maxThe = count;
                foundPin = i;
            }
        }
        ifstream encrypted(inputname);
        ofstream result(outputname);
        encryptFile(invertPin(foundPin), encrypted, result, true, 
                    false);
        return foundPin;
    }

    int main () {
        char toBe;
        bool decrypt;
        int pincode;
        cout << "Wilt u een bestand coderen of decoderen? (C/D) ";
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
        }
        string inputname;
        string outputname;
        cout << "Voer de naam in van het te (de)coderen bestand: ";
        cin >> inputname;
        cout << "Voer de naam in van het doelbestand: ";
        cin >> outputname;
        ifstream input(inputname);
        ofstream output(outputname);
        cout << "Voer een geldige pincode in voor het (de)coderen van"
             << " het bestand, als u uw pincode niet weet, voer dan -"
             << "1 in: ";
        cin >> pincode;
        if (checkPin(pincode)) {
            encryptFile(invertPin(pincode), input, output, decrypt);
        }
        else if (pincode == -1 && decrypt) {
            cout << "De gevonden pincode is: " 
                 << lostPassword(inputname, outputname) << endl;
        }
        else {
            cout << "Dit is geen geldige optie, uit voorzorgsmaatrege"
                 << "len sluit het programma nu af." << endl;
            return 1;
        }
        return 0;
    }