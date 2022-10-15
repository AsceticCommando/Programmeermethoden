    #include<iostream>
    #include<fstream>
    #include<string>
    using namespace std;

    int pincode = 1111;
    bool faultyPin = false;

    bool checkPin(int pin) {
        if ( pin < 0 || pin > 9999 ) {
            return false;
        }
        else {
            return true;
        }
    }

    int invertPin (int pin) {
        int invertedPin = 0;
        for (int p = 0; p < 4; p++) {
            invertedPin = invertedPin * 10 + pin % 10;
            pin = pin / 10;
        }
        return invertedPin;
    }

    void encryptFile(int pin) {
        ifstream input("input.txt");
        ofstream output("output.txt");

        char kar = input.get();
        char store[11];

        int pinCount = 0;
        int pinnum = pin;
        int newPin;
        int foundNum;
        int iterator;

        bool encounteredNum;
        bool isNumber[11];

        while (!input.eof()) {
            if (kar == '\r' || kar == '\n') {
                pinnum = pin;
                pinCount = 0;
                output.put(kar);
            }
            else if (kar == '\t') {
                output.put(kar);
            }
            else if (kar != '\t' && kar != '\r' && kar != '\n') {
                pinCount++;
                output.put(kar + (pinnum % 10));
                if (pinCount == 4) {
                    pinnum = pin;
                    pinCount = 0;
                }
                else {
                    pinnum /= 10;
                }
                for (int i = 0; i < 9; i++) {
                    store[i] = store[i+1];
                }
                store[9] = kar;
                if ((store[10] < '0' || store[10] > '9') &&
                    (store[9] >= '0' && store[9] <= '9')) {
                    isNumber[10] = false;
                    isNumber[9] = true;
                    for (int i = 0; i < 9; i++) {
                        if (store[i] >= '0' && store[i] <= '9') {
                            isNumber[i] = true;
                        }
                        else {
                            isNumber[i] = false;
                        }
                    }
                    cout << isNumber[0] << isNumber[1] << isNumber[2] << isNumber[3] << isNumber[4] << isNumber[5] << isNumber[6] << isNumber[7] << isNumber[8] << isNumber[9] << isNumber[10] << endl;
                }
            }
            kar = input.get();
        }
    }
    
    void decryptFile() {
        
    }

    int main() {
        if (!checkPin(pincode)) return 1;
        pincode = invertPin(pincode);
        encryptFile(pincode);
        return 0;
    }