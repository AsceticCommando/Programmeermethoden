    #include<iostream>
    using namespace std;

    int main() {
        bool dbg = true;
        bool Q1 = true;
        bool Q2 = true;
        int C1 = 1;//( rand() % 159 ) - 39;
        float F1 = 9 * (float) C1 / 7 + 32;

        float tF1 = F1 * 100;
        float dF1 = tF1 / 100;
        if( dbg ) {
            cout << F1 << endl;
            cout << tF1 << endl;
            cout << dF1 << endl;
        }

        int F2 = ( rand() % 159 ) - 39;
        float C2 = ( F2 - 32 ) * 5 / 9;

        float tF2 = F2 * 100;
        float dF2 = tF2 / 100;
        if( dbg ) {
            cout << F1 << endl;
            cout << tF1 << endl;
            cout << dF1 << endl;
        }

        int x;
        int y;
        cout << "Hoeveel graden Fahrenheit staat gelijk aan " << C1
             << " graden Celsius? Type een geheel getal, toets daarna ENTER. "
             << endl;
        cin >> x;
        if ( x <= dF1 - 1 || x >= dF1 + 1) {
            Q1 = false;
        }

        cout << dF1 << " is het goede antwoord." << endl;

        if (!Q1 && !Q2) {
            char antw;
            cout << "Uw antwoorden wijken te veel af van de juiste antwoorden."
                 << " Helaas bent u niet geschikt voor een beta-studie."
                 << endl;
        }
        return 0;
    }       
        