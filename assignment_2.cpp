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

    bool checkPin(int pin) {
        if ( pin != 0 && pin < 10000 ) {
            return true;
        }
        else {
            return false;
        }
    }

    bool checkLychrel(int num, int & counter) {
        int storedNum = num;
        int invertedNum = invertNum(num);

        while (storedNum != invertedNum) {
            counter++;
            if (storedNum < INT_MAX / 10 && invertedNum < INT_MAX / 10) {
                storedNum += invertedNum;
                invertedNum = invertNum(storedNum);
            }
            else {
                return true;
            }
        }
        return false;
    }

    void encryptFile(int pin) {
        ifstream input("input.txt");
        ofstream output("output.txt");

        char nextKar = input.get();

        int pinCount = 0;
        int pinnum = pin;
        
        int foundNum = 0;
        bool encounteredNum = false;

        while (!input.eof()) {
            char kar = nextKar;
            nextKar = input.get();
            
            if (kar == '\r' || kar == '\n') {
                pinnum = pin;
                pinCount = 0;
                output.put(kar);
            }
            else if (kar == '\t') {
                output.put(kar);
            }
            else {
                pinCount++;
                int currNum = pinnum % 10;
                output.put((kar + currNum - 32) % 95 + 32);
                if (pinCount == 4) {
                    pinnum = pin;
                    pinCount = 0;
                }
                else {
                    pinnum /= 10;
                }
                if (kar >= '0' && kar <= '9') {
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
                    && encounteredNum == true) {
                    encounteredNum = false;
                    int counter = 0;
                    if (checkPin(foundNum)) {
                        pinnum = invertPin(foundNum);
                        pin = pinnum;
                        cout << "Nieuwe pincode is: " << foundNum 
                        << endl;
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
            }
        }
    }
    
    void decryptFile() {
        
    }

    int main() {
        int pincode = 0000;
        encryptFile(invertPin(pincode));
        return 0;
    }